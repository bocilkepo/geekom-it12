
/*++
Copyright (c) 2018 Intel Corporation. All rights reserved
This software and associated documentation (if any) is furnished
under a license and may only be used or copied in accordance
with the terms of the license. Except as permitted by such
license, no part of this software or documentation may be
reproduced, stored in a retrieval system, or transmitted in any
form or by any means without the express written consent of
Intel Corporation.
Module Name:

FwUpdLclApp.c

Abstract:

FW Update Local Sample Code demonstrating usage of FW Update Library

--*/

#include <Windows.h>
#include <stdio.h>

#include "fwupdatelib.h"
#include "errorlist.h" // For error codes. For error messages use function GetErrorString() defined in errorlist.c (should be added to the compilation). This increases the size of the app. Do not include if error messages are not needed.

#define UPGRADE      1
#define DOWNGRADE    2
#define SAME_VERSION 3

#define CMD_LINE_STATUS_UPDATE_1        0
#define CMD_LINE_STATUS_UPDATE_2        1
#define CMD_LINE_STATUS_UPDATE_3        2
#define CMD_LINE_STATUS_UPDATE_4        3

int PerformUpdate(const char *fileName);

/**
* @brief Print error message according to error code.
*        GetErrorString() is defined in errorlist.c.
*        If error messages are needed, errorlist.c should be added to the compilation.
*
* @param[in]  errorCode  Error code.
*/
static void errorMessage(const UINT32 errorCode)
{
    printf("Error %u: %s\n", errorCode, GetErrorString(errorCode));
}

/**
* @brief A callback function that reports the progress of sending the update image buffer
*        to FW (not the progress of the update itself).
*
* @param[in]  bytesSentToFw         The number of bytes of the buffer, that were already sent to FW.
* @param[in]  totalBytesToSendToFw  The total number of bytes of the buffer.
*/
static void displaySendStatus(UINT32 bytesSentToFw, UINT32 totalBytesToSendToFw)
{
    UINT32 value = bytesSentToFw * 100 / totalBytesToSendToFw;

    if (value != 100)
    {
        printf("Sending the update image to FW for verification:  [ %u%% ]\r", value);
    }
    else
    {
        printf("Sending the update image to FW for verification:  [ COMPLETE ]\n");
    }
}

/**
* @brief Compare versions to determine if higher, lower or same.
*
* @param[in]   major1   Major number of version 1.
* @param[in]   minor1   Minor number of version 1.
* @param[in]   hotfix1  Hotfix number of version 1.
* @param[in]   build1   Build number of version 1.
* @param[in]   major2   Major number of version 2.
* @param[in]   minor2   Minor number of version 2.
* @param[in]   hotfix2  Hotfix number of version 2.
* @param[in]   build2   Build number of version 2.
*
* @return  Negative number if version 1 < 2.
* @return  0 if version 1 == 2.
* @return  Positive number if version 1 > 2.
*/
static INT32 versionCompare(IN  UINT16 major1, IN  UINT16 minor1, IN  UINT16 hotfix1, IN  UINT16 build1,
                            IN  UINT16 major2, IN  UINT16 minor2, IN  UINT16 hotfix2, IN  UINT16 build2)
{
    if (major1 != major2)
    {
        return ((INT32)major1 - (INT32)major2);
    }

    if (minor1 != minor2)
    {
        return ((INT32)minor1 - (INT32)minor2);
    }

    if (hotfix1 != hotfix2)
    {
        return ((INT32)hotfix1 - (INT32)hotfix2);
    }

    if (build1 != build2)
    {
        return ((INT32)build1 - (INT32)build2);
    }

    return 0;
}

/**
* @brief Check if update is upgrade, downgrade or same version.
*
* @param[in]   fileName    File name of Update Image.
* @param[out]  updateType  Type of the update operation. Caller allocated.
*                          UPGRADE      1.
*                          DOWNGRADE    2.
*                          SAME_VERSION 3.
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
static UINT32 checkUpdateType(IN  const char *fileName, IN  UINT32 *updateType)
{
    UINT32 status;
    UINT16 flashMajor = 0;
    UINT16 flashMinor = 0;
    UINT16 flashHotfix = 0;
    UINT16 flashBuild = 0;
    UINT16 fileMajor = 0;
    UINT16 fileMinor = 0;
    UINT16 fileHotfix = 0;
    UINT16 fileBuild = 0;
    INT32  comparedVersion = 0;

    if (fileName == NULL || updateType == NULL)
    {
        status = INTERNAL_ERROR;
        goto End;
    }

    status = FwuPartitionVersionFromFlash(FPT_PARTITION_NAME_RBEP, &flashMajor, &flashMinor, &flashHotfix, &flashBuild);
    if (status != SUCCESS)
    {
        goto End;
    }

    status = FwuPartitionVersionFromFile(fileName, FPT_PARTITION_NAME_RBEP, &fileMajor, &fileMinor, &fileHotfix, &fileBuild);
    if (status != SUCCESS)
    {
        goto End;
    }

    comparedVersion = versionCompare(fileMajor, fileMinor, fileHotfix, fileBuild,
                                     flashMajor, flashMinor, flashHotfix, flashBuild);

    if (comparedVersion < 0)
    {
        *updateType = DOWNGRADE;
    }
    else if (comparedVersion > 0)
    {
        *updateType = UPGRADE;
    }
    else
    {
        *updateType = SAME_VERSION;
    }

End:
    return status;
}

static void usage(void)
{
    printf(" -f <name>  Input file to perform Fwupdate.\n");
    printf(" -h     Display Usage options.\n");
    printf(" Note: Please run the Application with administrative privileges.\n");
    exit(0);
}

int __cdecl main(int argc, char *argv[])
{
    printf("Program name: %s\n\n", argv[0]);

    if (argc > 1 && argv[1][0] == '-')
    {
        switch (argv[1][1])
        {
        case 'f':
            printf("%s\n", &argv[1][2]);
            printf("Usage option: %s\n", &argv[1][1]);
            printf("sub param: %s\n", &argv[2][0]);
            PerformUpdate(&argv[2][0]);
            break;
        case 'h':
            usage();
            break;
        default:
            printf("Invalid Argument: %s\n", argv[1]);
            usage();
        }
    }
    return SUCCESS;
}

/**
* @brief Check if update image is compatible with the FW image (SKU, type, segment, SVN, VCN, etc.)
*
* @param[in]  fileName  File name of Update Image.
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
static UINT32 fwuCheckImageCompatibility(const char *fileName)
{
    UINT32 status;
    UINT32 flashPchSku = FWU_PCH_SKU_INVALID;
    UINT32 updatePchSku = FWU_PCH_SKU_INVALID;
    UINT32 flashFwType = FWU_FW_TYPE_INVALID;
    UINT32 updateFwType = FWU_FW_TYPE_INVALID;
    UINT32 flashProductSegment = 0;
    UINT32 updateProductSegment = 0;

    if (NULL == fileName)
    {
        return INTERNAL_ERROR;
    }

    status = FwuCheckCompatibilityFromFile(fileName);
    if (SUCCESS != status)
    {
        return status;
    }

    status = FwuPchSku(&flashPchSku);
    if (SUCCESS != status)
    {
        return status;
    }
    status = FwuPchSkuFromFile(fileName, &updatePchSku);
    if (SUCCESS != status)
    {
        return status;
    }
    if (flashPchSku != updatePchSku)
    {
        return FWU_ERROR_H_LP_MISMATCH;
    }

    status = FwuFwType(&flashFwType);
    if (SUCCESS != status)
    {
        return status;
    }
    status = FwuFwTypeFromFile(fileName, &updateFwType);
    if (SUCCESS != status)
    {
        return status;
    }
    if (flashFwType != updateFwType)
    {
        return FWU_ERROR_SKU_MISMATCH;
    }

    status = FwuProductSegmentFromFlash(&flashProductSegment);
    if (SUCCESS != status)
    {
        return status;
    }
    status = FwuProductSegmentFromFile(fileName, &updateProductSegment);
    if (SUCCESS != status)
    {
        return status;
    }
    if (flashProductSegment != updateProductSegment)
    {
        return FWU_ERROR_FW_TYPE_FTPR;
    }

    return SUCCESS;
}

int PerformUpdate(const char *fileName)
{
    UINT32 status;
    UINT16 major = 0;
    UINT16 minor = 0;
    UINT16 hotfix = 0;
    UINT16 build = 0;
    UINT16 enabledState = FALSE;
    UINT32 updateType = 0;
    UINT32 index = 0;
    UINT32 indexMod = 0;
    char symbol = '\0';
    BOOL inProgress = FALSE;
    UINT32 currentPercent = 0;
    UINT32 fwUpdateStatus = 0;
    UINT32 neededResetType = MFT_PART_INFO_EXT_UPDATE_ACTION_NONE;
    UINT32 timer = 0;
    UINT32 previousPercent = 0;
    
    printf("\nIntel (R) FW Update Sample Application\n");

    if (fileName == NULL)
    {
        status = FwuPartitionVersionFromFlash(FPT_PARTITION_NAME_RBEP, &major, &minor, &hotfix, &build);
        if (SUCCESS != status)
        {
            goto End;
        }

        printf("FW Version: %u.%u.%u.%u\n", major, minor, hotfix, build);
        goto End;
    }

    // check FWU enabled state
    status = FwuEnabledState(&enabledState);
    if (SUCCESS != status)
    {
        goto End;
    }

    switch (enabledState)
    {
    case FW_UPDATE_DISABLED:
        printf("FWUpdate is disabled\n");
        goto End;
    case FW_UPDATE_ENABLED:
        break;
    default:
        break;
    }
    
    printf("Checking firmware parameters...\n");

    // check if update is upgrade, downgrade or same version
    status = checkUpdateType(fileName, &updateType);
    if (SUCCESS != status)
    {
        goto End;
    }

    switch (updateType)
    {
    case UPGRADE:
        printf("FW Update type is: upgrade.\n");
        break;
    case DOWNGRADE:
        printf("FW Update type is: downgrade.\n");
        break;
    case SAME_VERSION:
        printf("FW Update type is: same version.\n");
        break;
    default:
        printf("FW Update type error.\n");
        status = INTERNAL_ERROR;
        goto End;
    }

    status = fwuCheckImageCompatibility(fileName);
    if (SUCCESS != status)
    {
        goto End;
    }

    status = FwuFullUpdateFromFile(fileName, NULL, &displaySendStatus);
    if (SUCCESS != status)
    {
        goto End;
    }

    printf("\n\n\n                        Do not Interrupt\r");
    fflush(stdout);

    // image was sent to FW Update client
    // poll the FW Update progress until finished
    do
    {
        // we mod4 the index to determine which ascii animation frame to display for this iteration
        // loop through (|) (/) (-) (\) (|) (/) ...
        indexMod = (++index % 4);
        switch (indexMod)
        {
        case CMD_LINE_STATUS_UPDATE_1:
            symbol = '|';
            break;
        case CMD_LINE_STATUS_UPDATE_2:
            symbol = '/';
            break;
        case CMD_LINE_STATUS_UPDATE_3:
            symbol = '-';
            break;
        case CMD_LINE_STATUS_UPDATE_4:
            symbol = '\\';
            break;
        default:
            break;
        }

        status = FwuCheckUpdateProgress(&inProgress,
                                        &currentPercent,
                                        &fwUpdateStatus,
                                        &neededResetType);
        if (status != SUCCESS) // update failed
        {
            break;
        }

        if (!inProgress) // update finished successfully
        {
            // print 100% for customers output consistency
            printf("FW Update:  [ 100%% (%c)]\r", symbol);
            fflush(stdout);
            break;
        }
        
        // update in progress
        printf("FW Update:  [ %3u%% (%c)]\r", currentPercent, symbol);
        fflush(stdout);

        Sleep(250); // wait 250 milliseconds before polling again
        if (timer >= 30000) // if 30 seconds passed
        {
            if (currentPercent == previousPercent) // if percent didn't change in 30 seconds
            {
                status = FWU_UPDATE_TIMEOUT;
                break;
            }
            
            // percent changed
            previousPercent = currentPercent;
            timer = 0;
        }
        else
        {
            timer += 250;
        }
    } while (TRUE);

    // new line after printing all the percents.
    printf("\n");

    if (SUCCESS != status)
    {
        goto End;
    }

    switch (neededResetType)
    {
    case MFT_PART_INFO_EXT_UPDATE_ACTION_NONE:
    case MFT_PART_INFO_EXT_UPDATE_ACTION_CSE_RESET:
        printf("FW Update completed successfully.\n");
        break;
    case MFT_PART_INFO_EXT_UPDATE_ACTION_HOST_RESET:
    case MFT_PART_INFO_EXT_UPDATE_ACTION_GLOBAL_RESET:
    default:
        printf("FW Update completed successfully and a reboot will run the new FW.\n");
        break;
    }
End:
    if (SUCCESS != status)
    {
        errorMessage(status);
    }
    return status;
}
