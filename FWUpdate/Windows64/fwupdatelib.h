/*++

Copyright (C) 2019 Intel Corporation

SPDX-License-Identifier: BSD-2-Clause

File Name:
    fwpdatelib.h

Abstract:
    Handles full and partial firmware updates via HECI.

--*/

#ifndef __FW_UPDATE_LIB_H__
#define __FW_UPDATE_LIB_H__

#ifdef __cplusplus
    extern "C" {
#endif

#ifdef _FWUPDATE_DLL
#define DllExport __declspec(dllexport)
#define CALL_CONV __cdecl
#else
#define DllExport
#define CALL_CONV
#endif

#define FPT_PARTITION_NAME_FTPR         0x52505446
#define FPT_PARTITION_NAME_RBEP         0x50454252
#define FPT_PARTITION_NAME_NFTP         0x5054464E
#define FPT_PARTITION_NAME_PMCP         0x50434D50
#define FPT_PARTITION_NAME_PCHC         0x43484350
#define FPT_PARTITION_NAME_OEMP         0x504D454F
#define FPT_PARTITION_NAME_ISHC         0x43485349
#define FPT_PARTITION_NAME_IUNP         0x504E5549
#define FPT_PARTITION_NAME_LOCL         0x4C434F4C
#define FPT_PARTITION_NAME_WCOD         0x444F4357
#define FPT_PARTITION_NAME_IOMP         0x504D4F49
#define FPT_PARTITION_NAME_NPHY         0x5948504E
#define FPT_PARTITION_NAME_TBTP         0x50544254
#define FPT_PARTITION_NAME_SPHY         0x59485053
#define FPT_PARTITION_NAME_ISIF         0x46495349
#define FPT_PARTITION_NAME_SAMF         0x464D4153
#define FPT_PARTITION_NAME_PPHY         0x59485050
#define FPT_PARTITION_NAME_GBST         0x54534247
#define FPT_PARTITION_NAME_PSEP         0x50455350
#define FPT_PARTITION_NAME_ADSP         0x50534441

#define MFT_PART_INFO_EXT_UPDATE_ACTION_NONE         0
#define MFT_PART_INFO_EXT_UPDATE_ACTION_HOST_RESET   1
#define MFT_PART_INFO_EXT_UPDATE_ACTION_CSE_RESET    2
#define MFT_PART_INFO_EXT_UPDATE_ACTION_GLOBAL_RESET 3

#define FW_UPDATE_DISABLED                  0 // Full Disabled. Partial Enabled.
#define FW_UPDATE_ENABLED                   1 // Full Enabled.  Partial Enabled.
#define FW_UPDATE_FULL_AND_PARTIAL_DISABLED 3 // Full Disabled. Partial Disabled.

#define FWU_FW_TYPE_INVALID 0
#define FWU_FW_TYPE_RESERVED 1
#define FWU_FW_TYPE_SLIM 2
#define FWU_FW_TYPE_CONSUMER 3
#define FWU_FW_TYPE_CORPORATE 4

#define FWU_PCH_SKU_INVALID 0
#define FWU_PCH_SKU_H 1
#define FWU_PCH_SKU_LP 2

#define FWU_PRODUCT_SEGMENT_CLIENT 1
#define FWU_PRODUCT_SEGMENT_HEDT 2
#define FWU_PRODUCT_SEGMENT_WS 3
#define FWU_PRODUCT_SEGMENT_CONVERGED_MOBILITY 4
#define FWU_PRODUCT_SEGMENT_IOT 5
#define FWU_PRODUCT_SEGMENT_SMALL_CORE_ENTRY_LEVEL 6

#define FWU_POWER_SOURCE_UNKNOWN 0 
#define FWU_POWER_SOURCE_AC 1
#define FWU_POWER_SOURCE_DC 2


typedef struct __UUID
{
   UINT32 Data1;
   UINT16 Data2;
   UINT16 Data3;
   UINT8  Data4[8];
} _UUID;

/**
* @brief Starting a Full FW Update from a buffer.
*
* @param[in]  buffer        Buffer of Update Image read from Update Image file.
* @param[in]  bufferLength  Length of the buffer in bytes.
* @param[in]  oemId         OEM ID to compare with OEM ID in FW (if exist). Can be NULL.
* @param[in]  func          A callback function that reports the progress of sending the buffer
*                           to FW (not the progress of the update itself). Can be NULL.
*                           void* func(UINT32 bytesSentToFw, UINT32 totalBytesToSendToFw);
*
* @return SUCCESS  If Update started successfully. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuFullUpdateFromBuffer(IN  UINT8 *buffer,
                                         IN  UINT32 bufferLength,
                                         IN  _UUID *oemId,
                                         IN  void(*func)(UINT32, UINT32));

/**
* @brief Starting a Partial FW Update from a buffer.
*
* @param[in]  buffer        Buffer of Update Image read from Update Image file.
* @param[in]  bufferLength  Length of the buffer in bytes.
* @param[in]  partitionId   ID of partition to update. Only partitions that are allowed to be partially updated.
* @param[in]  func          A callback function that reports the progress of sending the buffer
*                           to FW (not the progress of the update itself). Can be NULL.
*                           void* func(UINT32 bytesSentToFw, UINT32 totalBytesToSendToFw);
*
* @return SUCCESS  If Update started successfully. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuPartialUpdateFromBuffer(IN  UINT8 *buffer,
                                            IN  UINT32 bufferLength,
                                            IN  UINT32 partitionId,
                                            IN  void(*func)(UINT32, UINT32));

/**
* @brief Check for Update progress.
*        If in progress, return the current percent.
*        If finished, return the status of the update, and the needed reset type after the update.
*        This function should be called only after starting the update by calling FwuUpdateFull/Partial...
*
* @param[out] inProgress       True if Update is still in progress. False if Update finished. Caller allocated.
* @param[out] currentPercent   Current percent of the update, if Update is in progress. Caller allocated.
* @param[out] fwUpdateStatus   FW error code status of the update, if it finished (success or error code). Caller allocated.
* @param[out] neededResetType  Needed reset type after the update, if it finished. Caller allocated.
*                              MFT_PART_INFO_EXT_UPDATE_ACTION_NONE         0
*                              MFT_PART_INFO_EXT_UPDATE_ACTION_HOST_RESET   1
*                              MFT_PART_INFO_EXT_UPDATE_ACTION_CSE_RESET    2
*                              MFT_PART_INFO_EXT_UPDATE_ACTION_GLOBAL_RESET 3
*
* @return SUCCESS  If Update is still in progress, or finished successfully. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuCheckUpdateProgress(OUT BOOL *inProgress,
                                        OUT UINT32 *currentPercent,
                                        OUT UINT32 *fwUpdateStatus,
                                        OUT UINT32 *neededResetType);

/**
* @brief Get FW Update enabling state.
*
* @param[out] enabledState  FW Update enabling state. Caller allocated.
*                           FW_UPDATE_DISABLED = 0. Full Disabled. Partial Enabled.
*                           FW_UPDATE_ENABLED = 1. Full Enabled. Partial Enabled.
*                           FW_UPDATE_FULL_AND_PARTIAL_DISABLED = 3. Full Disabled. Partial Disabled.
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuEnabledState(OUT UINT16 *enabledState);

/**
* @brief Set FW Update enabling state.
*        Supported only before EOP.
*
* @param[in]  enabledState  FW Update enabling state.
*                           FW_UPDATE_DISABLED = 0. Full Disabled. Partial Enabled.
*                           FW_UPDATE_ENABLED = 1. Full Enabled. Partial Enabled.
*                           FW_UPDATE_FULL_AND_PARTIAL_DISABLED = 3. Full Disabled. Partial Disabled.
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuSetEnabledState(IN  UINT32 enabledState);

/**
* @brief Get OEM ID from flash.
*
* @param[out] oemId  OEM ID from flash. Caller allocated.
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuOemId(OUT _UUID *oemId);

/**
* @brief Get FW Type, from the flash image.
*
* @param[out] fwType  FW Type. Caller allocated.
*                     FWU_FW_TYPE_INVALID 0
*                     FWU_FW_TYPE_RESERVED 1
*                     FWU_FW_TYPE_SLIM 2
*                     FWU_FW_TYPE_CONSUMER 3
*                     FWU_FW_TYPE_CORPORATE 4
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuFwType(OUT UINT32 *fwType);

/**
* @brief Get FW Type, from the Update Image buffer.
*
* @param[in]  buffer        Buffer of Update Image read from Update Image file.
* @param[in]  bufferLength  Length of the buffer in bytes.
* @param[out] fwType        FW Type. Caller allocated.
*                           FWU_FW_TYPE_INVALID 0
*                           FWU_FW_TYPE_RESERVED 1
*                           FWU_FW_TYPE_SLIM 2
*                           FWU_FW_TYPE_CONSUMER 3
*                           FWU_FW_TYPE_CORPORATE 4
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuFwTypeFromBuffer(IN  UINT8 *buffer,
                                     IN  UINT32 bufferLength,
                                     OUT UINT32 *fwType);

/**
* @brief Get FW Type, from the Update Image file.
*
* @param[in]  fileName  File name of Update Image.
* @param[out] fwType    FW Type. Caller allocated.
*                       FWU_FW_TYPE_INVALID 0
*                       FWU_FW_TYPE_RESERVED 1
*                       FWU_FW_TYPE_SLIM 2
*                       FWU_FW_TYPE_CONSUMER 3
*                       FWU_FW_TYPE_CORPORATE 4
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuFwTypeFromFile(IN  const char *fileName,
                                   OUT UINT32 *fwType);

/**
* @brief Get PCH SKU, from the flash image.
*
* @param[out] pchSku  PCH SKU. Caller allocated.
*                     FWU_PCH_SKU_INVALID 0
*                     FWU_PCH_SKU_H 1
*                     FWU_PCH_SKU_LP 2
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuPchSku(OUT UINT32 *pchSku);

/**
* @brief Get PCH SKU, from the Update Image buffer.
*
* @param[in]  buffer        Buffer of Update Image read from Update Image file.
* @param[in]  bufferLength  Length of the buffer in bytes.
* @param[out] pchSku        PCH SKU. Caller allocated.
*                           FWU_PCH_SKU_INVALID 0
*                           FWU_PCH_SKU_H 1
*                           FWU_PCH_SKU_LP 2
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuPchSkuFromBuffer(IN  UINT8 *buffer,
                                     IN  UINT32 bufferLength,
                                     OUT UINT32 *pchSku);

/**
* @brief Get PCH SKU, from the Update Image file.
*
* @param[in]  fileName  File name of Update Image.
* @param[out] pchSku    PCH SKU. Caller allocated.
*                       FWU_PCH_SKU_INVALID 0
*                       FWU_PCH_SKU_H 1
*                       FWU_PCH_SKU_LP 2
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuPchSkuFromFile(IN  const char *fileName,
                                   OUT UINT32 *pchSku);

/**
* @brief Get Product Segment, from the flash image.
*
* @param[out] productSegment  Product Segment. Caller allocated.
*                             FWU_PRODUCT_SEGMENT_CLIENT 1
*                             FWU_PRODUCT_SEGMENT_HEDT 2
*                             FWU_PRODUCT_SEGMENT_WS 3
*                             FWU_PRODUCT_SEGMENT_CONVERGED_MOBILITY 4
*                             FWU_PRODUCT_SEGMENT_IOT 5
*                             FWU_PRODUCT_SEGMENT_SMALL_CORE_ENTRY_LEVEL 6
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuProductSegmentFromFlash(OUT UINT32 *productSegment);

/**
* @brief Get Product Segment, from the Update Image buffer.
*
* @param[in]  buffer          Buffer of Update Image read from Update Image file.
* @param[in]  bufferLength    Length of the buffer in bytes.
* @param[out] productSegment  Product Segment. Caller allocated.
*                             FWU_PRODUCT_SEGMENT_CLIENT 1
*                             FWU_PRODUCT_SEGMENT_HEDT 2
*                             FWU_PRODUCT_SEGMENT_WS 3
*                             FWU_PRODUCT_SEGMENT_CONVERGED_MOBILITY 4
*                             FWU_PRODUCT_SEGMENT_IOT 5
*                             FWU_PRODUCT_SEGMENT_SMALL_CORE_ENTRY_LEVEL 6
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuProductSegmentFromBuffer(IN  UINT8 *buffer,
                                             IN  UINT32 bufferLength,
                                             OUT UINT32 *productSegment);

/**
* @brief Get Product Segment, from the Update Image file.
*
* @param[in]  fileName        File name of Update Image.
* @param[out] productSegment  Product Segment. Caller allocated.
*                             FWU_PRODUCT_SEGMENT_CLIENT 1
*                             FWU_PRODUCT_SEGMENT_HEDT 2
*                             FWU_PRODUCT_SEGMENT_WS 3
*                             FWU_PRODUCT_SEGMENT_CONVERGED_MOBILITY 4
*                             FWU_PRODUCT_SEGMENT_IOT 5
*                             FWU_PRODUCT_SEGMENT_SMALL_CORE_ENTRY_LEVEL 6
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuProductSegmentFromFile(IN  const char *fileName,
                                           OUT UINT32 *productSegment);

/**
* @brief Check if the Update Image, from buffer, is compatible to the Flash 
*        Image, by comparing TCB SVN, ARB SVN, VCN of all the updatable 
*        partitions in the Flash Image and in the Update Image.
*        It is not possible to update to a lower value.
*        Update may not be possible for other reasons, that are not checked
*        by this function.
* @param[in]  buffer        Buffer of Update Image read from Update Image file.
* @param[in]  bufferLength  Length of the buffer in bytes.
*
* @return SUCCESS  If compatible. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuCheckCompatibilityFromBuffer(IN UINT8 *buffer,
                                                 IN UINT32 bufferLength);

/**
* @brief Check if the Update Image, from file, is compatible to the Flash 
*        Image, by comparing TCB SVN, ARB SVN, VCN of all the updatable 
*        partitions in the Flash Image and in the Update Image.
*        It is not possible to update to a lower value.
*        Update may not be possible for other reasons, that are not checked
*        by this function.
* @param[in]  fileName  File name of Update Image.
*
* @return SUCCESS  If update is possible. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuCheckCompatibilityFromFile(IN  const char *fileName);

/**
* @brief Get version of a specific partition, from the flash image.
*
* @param[in]  partitionId  ID of partition. If the FW version of CSE is needed,
*                          use bup partition ID: FPT_PARTITION_NAME_FTPR/FPT_PARTITION_NAME_RBEP.
* @param[out] major        Major number of version. Caller allocated.
* @param[out] minor        Minor number of version. Caller allocated.
* @param[out] hotfix       Hotfix number of version. Caller allocated.
* @param[out] build        Build number of version. Caller allocated.
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuPartitionVersionFromFlash(IN  UINT32 partitionId,
                                              OUT UINT16 *major,
                                              OUT UINT16 *minor,
                                              OUT UINT16 *hotfix,
                                              OUT UINT16 *build);

/**
* @brief Get version of a specific partition, from the Update Image buffer.
*
* @param[in]  buffer        Buffer of Update Image read from Update Image file.
* @param[in]  bufferLength  Length of the buffer in bytes.
* @param[in]  partitionId   ID of partition. If the FW version of CSE is needed,
*                           use bup partition ID: FPT_PARTITION_NAME_FTPR/FPT_PARTITION_NAME_RBEP.
* @param[out] major         Major number of version. Caller allocated.
* @param[out] minor         Minor number of version. Caller allocated.
* @param[out] hotfix        Hotfix number of version. Caller allocated.
* @param[out] build         Build number of version. Caller allocated.
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuPartitionVersionFromBuffer(IN  UINT8 *buffer,
                                               IN  UINT32 bufferLength,
                                               IN  UINT32 partitionId,
                                               OUT UINT16 *major,
                                               OUT UINT16 *minor,
                                               OUT UINT16 *hotfix,
                                               OUT UINT16 *build);

/**
* @brief Get vendor ID of a specific partition, from the flash image.
*
* @param[in]  partitionId  ID of partition.
* @param[out] vendorId     Vendor ID of partition. Caller allocated.
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuPartitionVendorIdFromFlash(IN  UINT32 partitionId,
                                               OUT UINT32 *vendorId);

/**
* @brief Starting a Full FW Update from a file.
*
* @param[in]  fileName      File name of Update Image.
* @param[in]  oemId         OEM ID to compare with OEM ID in FW (if exist). Can be NULL.
* @param[in]  func          A callback function that reports the progress of sending the buffer
*                           to FW (not the progress of the update itself). Can be NULL.
*                           void* func(UINT32 bytesSentToFw, UINT32 totalBytesToSendToFw);
*
* @return SUCCESS  If Update started successfully. Error code otherwise.
**/
DllExport
UINT32 CALL_CONV FwuFullUpdateFromFile(IN  const char *fileName,
                                       IN  _UUID *oemId,
                                       IN  void(*func)(UINT32, UINT32));

/**
* @brief Starting a Partial FW Update from a file.
*
* @param[in]  fileName      File name of Update Image.
* @param[in]  partitionId   ID of partition to update. Only partitions that are allowed to be partially updated.
* @param[in]  func          A callback function that reports the progress of sending the buffer
*                           to FW (not the progress of the update itself). Can be NULL.
*                           void* func(UINT32 bytesSentToFw, UINT32 totalBytesToSendToFw);
*
* @return SUCCESS  If Update started successfully. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuPartialUpdateFromFile(IN  const char *fileName,
                                          IN  UINT32 partitionId,
                                          IN  void(*func)(UINT32, UINT32));

/**
* @brief Get version of a specific partition, from the Update Image file.
*
* @param[in]  fileName      File name of Update Image.
* @param[in]  partitionId   ID of partition. If the FW version of CSE is needed,
*                           use bup partition ID: FPT_PARTITION_NAME_FTPR/FPT_PARTITION_NAME_RBEP.
* @param[out] major         Major number of version. Caller allocated.
* @param[out] minor         Minor number of version. Caller allocated.
* @param[out] hotfix        Hotfix number of version. Caller allocated.
* @param[out] build         Build number of version. Caller allocated.
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuPartitionVersionFromFile(IN  const char *fileName,
                                             IN  UINT32 partitionId,
                                             OUT UINT16 *major,
                                             OUT UINT16 *minor,
                                             OUT UINT16 *hotfix,
                                             OUT UINT16 *build);

/**
* @brief Get the current instance ID and the expected instance ID of an IUP partition in the FW.
*
* @param[in]  partitionId         ID of an IUP partition.
* @param[out] currentInstanceId   Current instance ID. Caller allocated.
* @param[out] expectedInstanceId  Expected instance ID. Caller allocated.
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuPartitionInstances(IN  UINT32 partitionId,
                                       OUT UINT32 *currentInstanceId,
                                       OUT UINT32 *expectedInstanceId);

/**
* @brief Starting a Partial FW Update to a specific instance ID, from a buffer.
*
* @param[in]  buffer        Buffer of Update Image read from Update Image file.
* @param[in]  bufferLength  Length of the buffer in bytes.
* @param[in]  partitionId   ID of partition to update. Only partitions that are allowed to be partially updated.
* @param[in]  instanceId    Instance ID of partition to update to.
* @param[in]  func          A callback function that reports the progress of sending the buffer
*                           to FW (not the progress of the update itself). Can be NULL.
*                           void* func(UINT32 bytesSentToFw, UINT32 totalBytesToSendToFw);
*
* @return SUCCESS  If Update started successfully. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuPartialUpdateWithInstanceIdFromBuffer(IN  UINT8 *buffer,
                                                          IN  UINT32 bufferLength,
                                                          IN  UINT32 partitionId,
                                                          IN  UINT32 instanceId,
                                                          IN  void(*func)(UINT32, UINT32));

/**
* @brief Starting a Partial FW Update to a specific instance ID, from a file.
*
* @param[in]  fileName      File name of Update Image.
* @param[in]  partitionId   ID of partition to update. Only partitions that are allowed to be partially updated.
* @param[in]  instanceId    Instance ID of partition to update to.
* @param[in]  func          A callback function that reports the progress of sending the buffer
*                           to FW (not the progress of the update itself). Can be NULL.
*                           void* func(UINT32 bytesSentToFw, UINT32 totalBytesToSendToFw);
*
* @return SUCCESS  If Update started successfully. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuPartialUpdateWithInstanceIdFromFile(IN  const char *fileName,
                                                        IN  UINT32 partitionId,
                                                        IN  UINT32 instanceId,
                                                        IN  void(*func)(UINT32, UINT32));

/**
* @brief Get the the current image from the flash - Restore Point Image, and save it to buffer.
*
* @param[out] buffer        Buffer of the saved Restore Point Image.
*                           Allocated by the function, only in case of SUCCESS. NULL otherwise.
*                           Caller should free the buffer
*                           using free() in WIN, FreePool() in EFI.
* @param[out] bufferLength  Length of the buffer in bytes.
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuSaveRestorePointToBuffer(OUT UINT8 **buffer,
                                             OUT UINT32 *bufferLength);

/**
* @brief Get the the current image from the flash - Restore Point Image, and save it to file.
*
* @param[in]  fileName  File name to save Restore Point Image into.
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuSaveRestorePointToFile(IN  const char *fileName);

/**
* @brief Check if the power source is AC or DC.
*
* @param[out] powerSource  Power Source. Caller allocated.
*                          FWU_POWER_SOURCE_UNKNOWN = 0.
*                          FWU_POWER_SOURCE_AC  = 1.
*                          FWU_POWER_SOURCE_DC  = 2.
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuPowerSource(OUT UINT32 *powerSource);

/**
* @brief Get the recovery image from the FW, in to buffer.
*
* @param[in]  buffer        Buffer for the recovery image. The buffer should be pre-allocated by the caller.
* @param[in]  bufferLength  Length of the buffer in bytes.
* @param[out] imageLength   Length of the recovery image that was written in the buffer.
*
* @return SUCCESS  If succeeded. Error code otherwise.
*/
DllExport
UINT32 CALL_CONV FwuGetRecoveryImageToBuffer(IN  UINT8  *buffer,
                                             IN  UINT32  bufferLength,
                                             OUT UINT32 *imageLength);

#ifdef __cplusplus
    }
#endif
#endif
