/*++

Copyright (C) 2009-2021 Intel Corporation

SPDX-License-Identifier: BSD-2-Clause

File Name:
    errorlist.h

Abstract:
    List of all error codes, categories and error strings.

--*/

#ifndef _ERRORLIST_H
#define _ERRORLIST_H



// Sringisize preprocessor define
#ifndef ME_STR
#define ME_STR "ME"
#endif
#ifndef FW_STR
#define FW_STR "FW"
#endif
#ifndef PCH_STR
#define PCH_STR "PCH"
#endif
#ifndef CSE_STR
#define CSE_STR "CSE"
#endif
#ifndef MEI_STR
#define MEI_STR "MEI"
#endif

#ifndef MAKE_STR
#define MAKE_STR(x) _MAKE_STR(x)
#define _MAKE_STR(x) #x
#endif


typedef enum
{
    CATEGORY_SUCCESS = 0,
    CATEGORY_INTERNAL_ERROR,
    CATEGORY_WARNING,
    CATEGORY_UNSUPPORTED_OS,
    CATEGORY_UNSUPPORTED_HW,
    CATEGORY_MEMORY_ALLOCATION,
    CATEGORY_SYSTEM_API_CALL_ERROR,
    CATEGORY_SYSTEM_API_NOT_FOUND,
    CATEGORY_IO_ERROR,
    CATEGORY_PERIPHERALS_VALIDATION_FAILURE,
    CATEGORY_ME_COMMUNICATION_FAILURE,
    CATEGORY_HECI_COMMUNICATION_FAILURE,
    CATEGORY_INVALID_CLI_OPTIONS,
    CATEGORY_CSE_FILE_INVALID_INPUT_VALUE,
    CATEGORY_CSE_FILE_READ_ERROR,
    CATEGORY_CSE_FILE_UPDATE_ERROR,
    CATEGORY_CSE_FILE_COMPARE_GENERAL_ERROR,
    CATEGORY_PCI_ACCESS_ERROR,
    CATEGORY_OS_DEVICE_COMMUNICATION_FAILURE,
    CATEGORY_USER_INPUT_FILE_ERROR,
    CATEGORY_SPI_ACCESS_ERROR,
    CATEGORY_SMBUS_ACCESS_ERROR,
    CATEGORY_SMBIOS_ACCESS_ERROR,
    CATEGORY_TOOL_INITIALIZATION_ERROR,
    CATEGORY_XML_USER_FILE_ERROR,
    CATEGORY_KEYBOX_INVALID_RESPONSE,
    CATEGORY_KEYBOX_INVALID_STATUS,
    CATEGORY_MEMANUF_TEST_RUN_ERROR,
    CATEGORY_MEMANUF_TEST_RESULT_READ_ERROR,
    CATEGORY_MEMANUF_BIST_TEST_FAILED,
    CATEGORY_MEMANUF_EOL_TEST_FAILED,
    CATEGORY_MEMANUF_OPERATION_FAILED,
    CATEGORY_MEINFO_FEATURE_NOT_FOUND,
    CATEGORY_MEINFO_FEATURE_COMPARE_ERROR,
    CATEGORY_MEINFO_FEATURE_EXECUTION_ERROR,
    CATEGORY_FPT_INVALID_SPI_CONF,
    CATEGORY_INVALID_USER_INPUT,
    CATEGORY_FWU_FW_ERROR,
    CATEGORY_FWU_RESTORE_POINT_ERROR,
    CATEGORY_INVALID_PARTITION,
    CATEGORY_FWU_OPERATION_FAILED,
    CATEGORY_TOOL_FEATURE_EXECUTION_ERROR,
    CATEGORY_GENERAL_ERROR,
    CATEGORY_ICC_FW_ERROR,
    CATEGORY_SOFTSTRAP_INVALID_INPUT_VALUE,
    CATEGORY_SOFTSTRAP_UPDATE_ERROR,
    MESSAGING_LIBRARY,
    CATEGORY_FWU_RECOVERY_IMAGE_ERROR,
    ERROR_CATEGORIES_COUNT,
}ErrorCategories;


typedef enum
{
    SUCCESS = 0,
    TOOL_COMMON_ERROR,
    PASSED_WITH_WARNING,
    INTERNAL_ERROR,
    ERROR_UNSUPPORTED_OS,
    ERROR_MEMORY_ALLOC,
    SM_BIOS_ERROR_PROCADDR,
    SM_BIOS_ERROR_GENERAL,
    SM_BIOS_ERROR_PERMISSION,
    COMMIT_SVN_FAILED,
    FILE_READ_ERROR,
    FILEIO_ERROR_GETTING_CWD,
    FILEIO_ERROR_GETTING_CWD_PERMISSIONS,
    FILEIO_ERROR_OPEN_FILE,
    FILEIO_ERROR_SEEK,
    FILEIO_ERROR_WRITE,
    SERVICE_EXISTS,
    ITOUCH_STOPPING_DRIVER_FAILED,
    FILEIO_ERROR_INVALID_ARGUMENT,
    FAILED_TO_WRITE_TO_IO_PORT,
    HECI_STATUS_LOCATE_DEVICE_ERROR,
    HECI_STATUS_WRITE_REGISTER_ERROR,
    HECI_STATUS_BUFFER_OVEREFLOW_ERROR,
    HECI_STATUS_MSG_TRANSMISSION_ERROR,
    HECI_STATUS_VERSION_MISMATCH,
    HECI_STATUS_TIMEOUT_ERROR,
    HECI_STATUS_UNEXPECTED_RESPONSE,
    HECI_STATUS_CANNOT_FOUND_HOST_CLIENT,
    HECI_STATUS_CANNOT_FOUND_ME_CLIENT,
    HECI_STATUS_CANNOT_DISCONNECT,
    HECI_STATUS_CLIENT_ALREADY_CONNECTED,
    HECI_STATUS_NO_FREE_CONNECTION,
    HECI_STATUS_FLOW_CONTROL_ERROR,
    HECI_STATUS_NO_MESSAGE,
    HECI_STATUS_BUFFER_TOO_LARGE,
    HECI_STATUS_BUFFER_TOO_SMALL,
    CERTIFICATE_NAME_TOO_LONG,
    CLI_ERROR_INVALID_COMMAND_ARGUMENT,
    CLI_ERROR_INVALID_OPTION,
    LPC_DID_ERROR_PCH_NOT_SUPPORTED,
    SAFE_FUNC_ERROR_INVALID_SIZE,
    SAFE_FUNC_ERROR_COMPOSE_STR_FROM_LIST,
    SAFE_FUNC_ERROR_COMPOSE_STR,
    SAFE_FUNC_ERROR_MEMNCPY,
    SAFE_FUNC_ERROR_STRNCPY,
    SAFE_FUNC_ERROR_STRNCAT,
    SAFE_FUNC_ERROR_TOKEN_STR,
    DISPLAY_ERROR_PRINTF,
    NVAR_SUPPORT_FAILED_VAR,
    NVAR_SKU_DEP_SUPPORT_FAILED_VAR,
    PLAT_INFO_NO_MATCHED_LOCL,
    CANNOT_ACCESS_PCI,
    MEMANUF_ERROR_EOL_RPMB_NOT_SUPPORTED,
    OS_STATUS_NOT_PERMITTED,
    OS_STATUS_PERMISSION_FAILURE,
    DEVICE_NOT_FOUND,
    OS_STATUS_INTEGRITY_CHECK_FAILED,
    FPF_COMPARE_FAILURE,
    INVALID_CSE_FILE_NAME,
    ERROR_BG_MUST_BE_ENABLED,
    FPT_INVALID_CONFIG_FORMAT,
    FW_REGISTER_READ_ERROR,
    TOOL_ERROR_CREATE_LOG_FILE,
    ERROR_UNKNOWN_UNSUPPORTED_HW,
    FAILED_TO_INIT_SPI,
    FPT_VAR_UPDATE_FAILED,
    CANNOT_UPDATE_FPT_VAR,
    MEINFO_ERROR_PARAM_NOT_FOUND,
    MEINFO_ERROR_PARAM_INVALID,
    MEINFO_ERROR_PARAM_NOT_EQUAL,
    ERROR_FW_STATUS_FAILURE,
    ERROR_BG_FW_STATUS_FAILURE,
    FPT_CERT_INVALID_FILE,
    FPT_CERT_UPDATE_MISSING_COMPONENTS,
    ERROR_TOOL_INIT,
    FPT_MASTER_ACCESS_VALUE_INVALID,
    MEINFO_ERROR_PARAM_RETRIEVE,
    FPT_MASTER_ACCESS_VALUE_EXCEED,
    MEINFO_ERROR_FIT_VER,
    MEINFO_ERROR_INT_VER,
    FPT_MASTER_DUPLICATE_REGION,
    MEMANUF_ERROR_OPT_FAILED,
    FPT_MASTER_ACCESS_INVALID_ACCESS_NODE,
    FPT_MASTER_ACCESS_INVALID_REQUIRED_NODE,
    NVAR_MCA_WRONG_SERVER_ADDRESS,
    MEMANUF_ERROR_BIST_NOTSTARTED,
    MEMANUF_ERROR_BIST_NOTFINISHED,
    MEMANUF_ERROR_BIST_RUNNING_RETRY,
    MEMANUF_ERROR_CFGGEN,
    MEMANUF_ERROR_NOM3BIST_ON_FLASH,
    MEMANUF_ERROR_M3_BIST_CONFIGURATION,
    ERROR_SMBUS_READ_BYTE_STATUS_NOT_READY,
    ERROR_SMBUS_READ_BYTE_STATUS_FAILURE,
    ERROR_SMBUS_READ_BYTE_STATUS_TIMED_OUT,
    SPI_SIGN_INVALID,
    ERROR_M3_LIVE_HEAP_TEST_DO_NOT_MATCH,
    ERROR_M3_LIVE_HEAP_TEST_OUT_OF_MEMORY,
    M3_LIVE_HEAP_TEST_FAILED_GET_POWER_PACKAGE,
    WLAN_POWER_WELL_FAILED_GET_TEST_RESULT,
    ERROR_WLAN_POWER_WELL_FAILED_GET_PACKAGE,
    ERROR_WLAN_POWER_WELL_TEST_FAILED_GET_RULE,
    ERROR_WLAN_POWER_WELL_TEST_CFG_INCORRECT,
    ERROR_CPU_MISSING_TEST_FAILED_GET_RESULT,
    ERROR_CPU_MISSING_TEST_FAILED_GET_PLAT_ATTR,
    ERROR_CPU_MISSING_TEST_GET_LOGIC_RULE,
    ERROR_CPU_MISSING_TEST_LOGIC_INCORRECT,
    ERROR_GET_PASSWORD_FAILED,
    ERROR_PASSWORD_LENGTH_IS_INCORRECT,
    ERROR_CALL_IsLocalPwdModified_FAILED,
    ERROR_PASSWORD_INVALID,
    ERROR_SB_SELF_TEST_FAILED,
    ERROR_LAN_HW_NOT_READY,
    ERROR_LAN_NIC_FAILURE,
    ERROR_ILLEGAL_LENGTH,
    ERROR_ILLEGAL_VALUE,
    ERROR_EHBC_STATE_FLASH_READ_ERROR,
    ERROR_EHBC_STATE_PRIV_LEVEL_MISMATCH,
    ERROR_WLAN_CODE_INVALID,
    ERROR_WLAN_NIC_FAILURE,
    ERROR_INVALID_HASH_LENGTH,
    ERROR_INVALID_HASH_VALUE,
    ERROR_INVALID_HASH_ALGORITHM,
    ERROR_INVALID_NAME_LENGTH,
    ERROR_UNABLE_TO_COMPRESS,
    ERROR_INVALID_COMPRESSION_VAL,
    ERROR_USBR_NVAR_WRONG_CONFIG,
    ERROR_USBR_IN_USE,
    ERROR_EC_UNABLE_TO_GET_SOURCE,
    ERROR_EC_POWER_NOT_AC,
    ERROR_POWER_WELL_LAN_INCORRECT,
    ERROR_POWER_WELL_WLAN_INCORRECT,
    MEMANUF_ERROR_EOL_UUIDCHECK_ALLZERO,
    MEMANUF_ERROR_EOL_UUIDCHECK_ALLF,
    MEMANUF_ERROR_EOL_MANUFJMPCHECK,
    MEMANUF_ERROR_EOL_EOPCHECK,
    MEMANUF_ERROR_EOL_FOVLOCKCHECK_UNKNOWN,
    MEMANUF_ERROR_EOL_FOVLOCKCHECK_NOT_EOM,
    MEMANUF_ERROR_EOL_RPMC_FUSE_EN_DISABLED,
    MEMANUF_ERROR_EOL_MISMATCH,
    FPROG_SYSTEM_FOLDER_WRITE_ACCESS,
    MEMANUF_ERROR_NO_AMT,
    MEMANUF_MFS_CORRUPTED_ERROR,
    MEMANUF_PCH_ID_MISMATCH_ERROR,
    MEMANUF_ERROR_FAILED_HIBERNATION,
    MEMANUF_ERROR_TEST_FAILED,
    MEMANUF_ERROR_TEST_NOT_RUN,
    ROOT_NODE_ADDING_SIBLING_ERROR,
    EMPTY_FILE_ERROR,
    XML_PARSING_FAILURE,
    XML_PARSING_OVERFLOW_FAILURE,
    XML_INVALID_ERROR_CODE_CONVERSION,
    XML_PARSER_ERROR_NO_MEMORY,
    XML_MISSING_REQUIRED_NODE,
    XML_INCORRECT_REGION_NAME,
    MEMANUF_ERROR_FAILED_QUERY_TEST,
    MEMANUF_ERROR_FAILED_BIST_BISTRESULT_CMD,
    MEMANUF_ERROR_RETRIEVE_EOL_CFG,
    MEMANUF_ERROR_RETRIEVE_EOL_VAR,
    MEMANUF_CONFIG_FILE_NO_NAME_FOR_TEST,
    MEMANUF_CONFIG_FILE_PARSING_ERROR,
    MEMANUF_CONFIG_FILE_WRITE_NO_FILE_PATH,
    MEMANUF_CONFIG_FILE_WRITE_NO_DATA,
    MEMANUF_CONFIG_FILE_INVALID_ERRACTION_DATA,
    SPI_INIT_INCOMPATIBLE_DEVICES,
    INVALID_DESC,
    SPI_LOADDEVFILE_NO_MEMORY,
    SPI_LOADFILE_PARSE_FAILED,
    SPI_PROTECTED_RANGE_ACCESS_DENIED,
    HECI_STATUS_DRIVER_ACCESS_DENIED,
    SPI_READ_ACCESS_DENIED,
    SPI_READ_OUT_OF_RANGE,
    FEAT_NOT_RELEVANT,
    FPT_INVALID_BLOCK_ERASE_SIZE,
    FPT_INVALID_WRITE_GRANULARITY,
    ERASE_SIZE,
    SPI_DEV_INFO_INVALID_INDEX,
    SPI_REGION_INVALID_DESC,
    SPI_REGION_NO_EXIST,
    SPI_WRITE_OUT_OF_RANGE,
    SPI_ERASE_OUT_OF_RANGE,
    SPI_ERASE_ALIGNMENT_ERROR,
    SPI_HARDWARE_TIMEOUT_OCCURRED,
    SPI_INIT_DEVICE_NOT_SUPPORTED,
    SPI_UNRECOGNISED_HSFSTS_VALUE,
    SPI_STATUS_AEL,
    SPI_STATUS_FCERR,
    MEMANUF_EOL_CHECKING_VAR_FAILED,
    NVAR_MCA_WRONG_VPRO_NIC_TBT_ADDRESS,
    FPROG_FOV_INVALID_VAR_NAME,
    FPROG_FILE_DOESNOT_EXISTS,
    FPROG_VERIFY_LOCK_SETTINGS_FAILED,
    FPROG_ERROR_GET_MASTER_BASE_ADDR,
    NVAR_MCA_WRONG_RETIMER_TBT_ADDRESS,
    FPROG_INVALID_VALUE_LENGTH,
    FPROG_INVALID_HASH_FILE,
    FPROG_VERIFY_GLOBAL_LOCKED_FAILED,
    NVAR_MCA_POLICY_CFG_RULES_WRONG_MANUF_STATE,
    FPROG_VALIDATION_PARAM_FAILED,
    ME_DISABLED_OLD,
    FPROG_FAILED_GET_DEVICE_INFO,
    FPROG_ERROR_READ_FLASH_DESC,
    FPROG_DESC_INVALID_SIGNATURE,
    FPT_FOV_COMMIT_FAILED,
    FPROG_ACCESS_DENIED_FILE_OPEN,
    FPROG_FAILED_FILE_READ_ENTIRE,
    FPROG_READ_ADDR_OUTSIDE_BOUNDARY,
    FPROG_CANNOT_WRITE_FLASH,
    FPROG_VERIFY_MISMATCH_FOUND,
    FPROG_FAILED_WRITE_FLASH_TO_FILE,
    FPROG_ERROR_READ_MAPPING_DATA,
    NVAR_MCA_INVALID_PASSWORD,
    FPROG_ERROR_READ_COMPONENT_DATA,
    FPROG_ERROR_READ_BASE_LIMIT,
    FPROG_ERROR_READ_MASTER_ACCESS_DATA,
    FPROG_FLASH_NOT_BLANK,
    NVAR_MCA_WRONG_PAVP_EDP_CONFIG_VALUE,
    SETTING_GLOBAL_RESET_FAILED,
    ME_DISABLE_NOT_NEEDED,
    ME_ALREADY_DISABLED,
    FPT_ME_DISABLE_FAILURE,
    FPT_GBE_ERROR_SAVING_GBE_DATA,
    FPT_MISSING_REQUIRED_PARAMETER,
    FPF_COMMIT_NOT_ALLOWED,
    FPF_ALREADY_COMMITTED,
    NVAR_MCA_WRONG_PAVP_LSPCON_CONFIG_VALUE,
    FPF_COMMIT_SPECIFIC_NOT_SUPPORTED,
    KEYBOX_FILE_SIZE_ERROR,
    NVAR_MCA_WRONG_ALL_HASHES_STATE,
    NVAR_MCA_WRONG_IDLE_TIMEOUT,
    NVAR_MCA_WRONG_PROV_STATE,
    KEYBOX_PROVISION_CEK_INVALID,
    KEYBOX_PROVISION_CEK_NOT_AVAILABLE,
    KEYBOX_PROVISION_AFTER_EOM,
    NVAR_MCA_WRONG_REDIR_STATE,
    KEYBOX_PROVISION_BAD_CRC,
    KEYBOX_PROVISION_BAD_MAGIC,
    NVAR_MCA_WRONG_EHBC_STATE,
    KEYBOX_NOT_PROVISIONED,
    SPI_WRITE_ACCESS_DENIED,
    USER_CANCELLED_OPERATIION,
    HECI_RESP_LEN_INVALID,
    SYS_STATE_ERROR,
    HECI_STATUS_CANNOT_LOCATE_DRIVER,
    FWU_FW_NOT_FOUND,
    MEMANUF_ERROR_CONFIG_FILE_INVALID_STATE,
    ERROR_ISH_SRV_BIST_TEST_ERROR,
    ERROR_ISH_SRV_BIST_IUP_NOT_FOUND_ERROR,
    HID_STATUS_LOCATE_DEVICE_ERROR,
    HID_STATUS_GET_FEATURE_REPORT_FAILED,
    ERROR_BIST_TEST_MCTP_SMBUS3_FAILED,
    MEMANUF_ERROR_CONFIG_FILE_MISSING_STATE,
    MEMANUF_ERROR_CONFIG_FILE_MISSING_REQ_VALUE,
    MEMANUF_ERROR_CFG_FILE_MISSING_ERR_ACTION,
    ERROR_TOUCH_STATUS_ACCESS_DENIED,
    ERROR_TOUCH_STATUS_NOT_READY,
    ERROR_TOUCH_STATUS_NO_SENSOR_FOUND,
    ERROR_TOUCH_STATUS_OUT_OF_MEMORY,
    ERROR_TOUCH_STATUS_SENSOR_DISABLED,
    ERROR_TOUCH_STATUS_COMPAT_CHECK_FAIL,
    ERROR_TOUCH_STATUS_SENSOR_UNEXPECTED_RESET,
    ERROR_TOUCH_STATUS_RESET_FAILED,
    ERROR_TOUCH_STATUS_TIMEOUT,
    ERROR_TOUCH_STATUS_TEST_MODE_FAIL,
    ERROR_TOUCH_STATUS_SENSOR_FAIL_FATAL,
    ERROR_TOUCH_STATUS_SENSOR_FAIL_NONFATAL,
    ERROR_TOUCH_STATUS_INVALID_DEVICE_CAPS,
    ERROR_TOUCH_STATUS_QUIESCE_IO_IN_PROGRESS,
    NVAR_MCA_NO_FILE,
    NVAR_MCA_INVALID_CFG_RULE,
    NVAR_MCA_NO_FILE_ATTRIBUTE,
    CSE_FILE_HASH_ERROR,
    NVAR_MCA_AFTER_LOCK,
    NVAR_MCA_INVALID_INPUT,
    FPF_MCA_FILE_NOT_WRITTEN,
    NVAR_MCA_WRONG_PRIVACY_LEVEL,
    FILE_INVALID,
    HDCP_RX_PROVISION_AFTER_EOM,
    HDCP_RX_PROVISION_CERT_VERIFICATION_FAILED,
    HDCP_RX_NOT_PROVISIONED,
    FPROG_INVALID_STRING,
    ME_RECOVERY_MODE,
    FPT_DELETE_TOKEN_FAILED,
    SIZE_FAILURE,
    INVALID_HEX_FAILURE,
    ERROR_BIST_TEST_PAVP_SET_EDP_FAILED,
    ERROR_BIST_TEST_PAVP_SET_LSPCON_FAILED,
    ERROR_PAVP_CHECK_EDP_LSPCON_CONFIG_FAILED,
    MEMANUF_ERROR_CHECK_EC_REGION_WRITE,
    NVAR_SUPPORT_FILE_SIZE_MISMATCH,
    FW_PHASE_IN_BUP,
    MEMANUF_ERROR_CHECK_GBE_REGION_WRITE,
    FPT_SETDAM_FAILED,
    MEMANUF_ERROR_CHECK_ME_REGION_WRITE,
    MEMANUF_ERROR_EOL_MISMATCH_UEP_VS_HW,
    MEMANUF_ERROR_EOL_FPF_NOT_COMMITTED,
    MEMANUF_ERROR_CHECK_BIOS_REGION_WRITE,
    MEMANUF_ERROR_READING_FPF_HW,
    MEMANUF_ERROR_FPF_CONFIG_NOT_SET,
    MEMANUF_ERROR_EOL_FPF_LOCK_BIT_NOT_SET,
    MEMANUF_ERROR_READING_FPF_UEP,
    MEMANUF_ERROR_EOL_FWUPDATE_OEM_ID,
    MEMANUF_ERROR_EOL_FWUPDATE_OEM_ID_UNKNOWN,
    MEMANUF_ERROR_CHECK_BIOS_REGION_READ,
    MEMANUF_ERROR_CHECK_ME_REGION_READ,
    MEMANUF_ERROR_CHECK_GBE_REGION_READ,
    MEMANUF_ERROR_CHECK_EC_REGION_READ,
    MEMANUF_ERROR_EOL_RPMC_NOT_ENABLED,
    MEMANUF_ERROR_EOL_RPMC_NOT_BOUND,
    MEMANUF_ERROR_HW_BINDING_CHECK,
    FPROG_VAR_NOT_UPDATABLE_ERROR,
    NVAR_DEP_SUPPORT_FAILED_VAR,
    ERROR_PCH_UNLOCK_STATE,
    ERROR_BAD_SIGNATURE,
    ERROR_SIGNATURE_VERIFICATION_FAILED,
    ERROR_READ_FAIL,
    MEMANUF_INVALID_REQUIRED_VALUE_FORMAT,
    ERROR_BTG_CONFIGURATION,
    ERROR_CONFIRM_ARB_SVN,
    FWU_FW_INVALID,
    ERROR_PLATFORM_NAME_FOUND,
    FPROG_CLEAR_FPF_ERROR,
    STORAGE_TYPE_NOT_SUPPORTED,
    REGION_NOT_SUPPORTED,
    FPROG_SIZE_EXCEED_LIMIT,
    INVALID_VALUE_FOR_CVAR,
    VAR_COMPARE_FAILURE,
    ERROR_FLASH_LOGS_EXIST,
    HECI_REQUEST_REPLY_SIZE_MISMATCH,
    HECI_UNSUPPORTED_MSG_TYPE,
    PART_NOT_PRESENT,
    FWU_NO_FPT_IN_IMAGE,
    FWU_ALLOWSV_MISSING,
    FWU_RESTORE_POINT_FAILURE,
    FWU_INVALID_PARTID,
    FWU_PID_NOT_EXPECTED,
    FWU_INVALID_IMG_LENGTH,
    FWU_UPD_PROCESS,
    FWU_SKU_MISMATCH,
    FWU_VER_MISMATCH,
    FWU_ERROR_CREATING_FT,
    FWU_SAL_NOTIFICATION,
    FWU_FW_DEVICE_ERROR,
    FWU_UPDATE_TIMEOUT,
    FWU_LOCAL_DIS,
    FWU_INVALID_OEM_ID,
    FWU_DISPLAY_FW_VERSION,
    FWU_DOWNGRADE_VETOED,
    FWU_FW_WRITE_FILE_FAIL,
    FWU_PARTITION_LAYOUT_NOT_COMP,
    FWU_FLASH_CODE_PARTITION_INVALID,
    FWU_FLASH_NFT_PARTITION_INVALID,
    FWU_HOST_RESET_REQUIRED,
    FWU_LOWER_TCB_SVN,
    FWU_INSTID_IS_NOT_EXPECTED_ID,
    FWU_REJ_IPU_FULL_UPDATE_NEEDED,
    FWU_IPU_NAMEID_NOT_FOUND,
    FWU_RESTORE_POINT_OPERATION_NOT_ALLOWED,
    FWU_LOWER_VCN,
    FWU_INVALID_SVN,
    FWU_OUT_OF_SVN_RESOURCES,
    FWU_RESTORE_POINT_REQUEST_FLASH_IN_RECOVERY,
    FWU_DISPLAY_PART_VERSION,
    FWU_RESTORE_POINT_REQUEST_RESTART_NEEDED,
    FWU_ERROR_PMC_INSTANCE,
    FWU_ERROR_H_LP_MISMATCH,
    FWU_ERROR_UPD_IMG_TOO_BIG,
    FWU_ERROR_INVALID_MANIFEST_SIZE,
    FWU_ERROR_364,
    FWU_ERROR_365,
    FWU_ERROR_366,
    FWU_ERROR_367,
    FWU_ERROR_SKUMGR_FAILED,
    FWU_ERROR_CFGMGR_FAILED,
    FWU_ERROR_MAN_NOT_FOUND,
    FWU_ERROR_371,
    FWU_ERROR_VER_MAN_FAILED_FTPR,
    FWU_ERROR_VER_MAN_FAILED_NFTP,
    FWU_ERROR_VER_MAN_FAILED_DLMP,
    FWU_ERROR_VER_MAN_FAILED_RBEP,
    FWU_ERROR_VER_MAN_FAILED_PMCP,
    FWU_ERROR_VER_MAN_FAILED_OEMP,
    FWU_ERROR_VER_MAN_FAILED_WCOD,
    FWU_ERROR_VER_MAN_FAILED_LOCL,
    FWU_ERROR_VER_MAN_FAILED_PCHC,
    FWU_ERROR_VER_MAN_FAILED_IOMP,
    FWU_ERROR_VER_MAN_FAILED_NPHY,
    FWU_ERROR_VER_MAN_FAILED_TBTP,
    FWU_ERROR_VER_MAN_FAILED_ISHC,
    FWU_ERROR_VER_MAN_FAILED_IUNP,
    FWU_ERROR_GET_EXT_FAILED_FTPR,
    FWU_ERROR_GET_EXT_FAILED_NFTP,
    FWU_ERROR_GET_EXT_FAILED_DLMP,
    FWU_ERROR_GET_EXT_FAILED_RBEP,
    FWU_ERROR_GET_EXT_FAILED_PMCP,
    FWU_ERROR_GET_EXT_FAILED_OEMP,
    FWU_ERROR_GET_EXT_FAILED_WCOD,
    FWU_ERROR_GET_EXT_FAILED_LOCL,
    FWU_ERROR_GET_EXT_FAILED_PCHC,
    FWU_ERROR_GET_EXT_FAILED_IOMP,
    FWU_ERROR_GET_EXT_FAILED_NPHY,
    FWU_ERROR_GET_EXT_FAILED_TBTP,
    FWU_ERROR_GET_EXT_FAILED_ISHC,
    FWU_ERROR_GET_EXT_FAILED_IUNP,
    FWU_ERROR_INTEGRITY_FAILED_FTPR,
    FWU_ERROR_INTEGRITY_FAILED_NFTP,
    FWU_ERROR_INTEGRITY_FAILED_DLMP,
    FWU_ERROR_INTEGRITY_FAILED_RBEP,
    FWU_ERROR_INTEGRITY_FAILED_PMCP,
    FWU_ERROR_INTEGRITY_FAILED_OEMP,
    FWU_ERROR_INTEGRITY_FAILED_WCOD,
    FWU_ERROR_INTEGRITY_FAILED_LOCL,
    FWU_ERROR_INTEGRITY_FAILED_PCHC,
    FWU_ERROR_INTEGRITY_FAILED_IOMP,
    FWU_ERROR_INTEGRITY_FAILED_NPHY,
    FWU_ERROR_INTEGRITY_FAILED_TBTP,
    FWU_ERROR_INTEGRITY_FAILED_ISHC,
    FWU_ERROR_INTEGRITY_FAILED_IUNP,
    FWU_ERROR_API_VER_MAJOR_FTPR,
    FWU_ERROR_API_VER_MAJOR_NFTP,
    FWU_ERROR_API_VER_MAJOR_DLMP,
    FWU_ERROR_API_VER_MAJOR_RBEP,
    FWU_ERROR_API_VER_MAJOR_PMCP,
    FWU_ERROR_API_VER_MAJOR_OEMP,
    FWU_ERROR_API_VER_MAJOR_WCOD,
    FWU_ERROR_API_VER_MAJOR_LOCL,
    FWU_ERROR_API_VER_MAJOR_PCHC,
    FWU_ERROR_API_VER_MAJOR_IOMP,
    FWU_ERROR_API_VER_MAJOR_NPHY,
    FWU_ERROR_API_VER_MAJOR_TBTP,
    FWU_ERROR_API_VER_MAJOR_ISHC,
    FWU_ERROR_API_VER_MAJOR_IUNP,
    FWU_ERROR_PART_SIZE,
    FWU_ERROR_BACKUP_OUTSIDE_NFTP,
    FWU_ERROR_MAX_IUPS,
    FWU_ERROR_NOT_IUP,
    FWU_ERROR_IUP_MISSING_UPDATE,
    FWU_ERROR_PMC_MISSING_UPDATE,
    FWU_ERROR_NOT_PARTIAL_IUP,
    FWU_ERROR_PARTIAL_TCSS,
    FWU_ERROR_FTPR_VER,
    FWU_ERROR_FTPR_SVN,
    FWU_ERROR_FTPR_VCN,
    FWU_ERROR_FTPR_VER_MAJOR,
    FWU_ERROR_IUP_SVN,
    FWU_ERROR_IMAGE_LEN,
    FWU_ERROR_IUP_VCN,
    FWU_ERROR_PV_BIT,
    FWU_ERROR_REVENUE,
    FWU_ERROR_SVN_UPGRADE,
    FWU_ERROR_SVN_HOTFIX,
    FWU_ERROR_IUP_MISSING_FLASH,
    FWU_ERROR_PARTITION_NOT_FOUND,
    FWU_ERROR_ENGINEERING_MISMATCH,
    FWU_ERROR_OEMP_MISSING,
    FWU_ERROR_IUPS_NOT_COMPATIBLE,
    FWU_ERROR_OEMP_IN_UPDATE,
    FWU_ERROR_WRONG_IUP,
    FWU_ERROR_IMAGE_IUP_SIZE,
    FWU_ERROR_OPEN_IUP,
    FWU_ERROR_SPI_IUP,
    FWU_ERROR_ENABLED_INVALID,
    FWU_ERROR_PWR_FAILED,
    FWU_ERROR_SPI_FAILED,
    FWU_ERROR_RESTORE_POINT_ALREADY_STARTED,
    FWU_ERROR_RESTORE_POINT_OFFSET_INVALID,
    FWU_ERROR_WRONG_HECI_MSG_LENGTH,
    FWU_ERROR_ENV_INVALID,
    FWU_ERROR_WRONG_DATA_OPERATION,
    FWU_ERROR_NVM_FAILED,
    FWU_ERROR_UFS_EOP,
    FWU_ERROR_API_VER_MAJOR_SPHY,
    FWU_ERROR_INTEGRITY_FAILED_SPHY,
    FWU_ERROR_GET_EXT_FAILED_SPHY,
    FWU_ERROR_VER_MAN_FAILED_SPHY,
    FWU_ERROR_SVN_TCB_ARB,
    FWU_INVALID_PARTID_ALL,
    FWU_DISPLAY_PART_VENDOR_ID,
    FWU_ERROR_INVALID_UPDATE_IMAGE,
    FWU_ERROR_INVALID_FLASH_IMAGE,
    FWU_ERROR_PG_FAILURE,
    FWU_ERROR_IPK_FAILURE,
    FWU_ERROR_FLUSH_NVM_ERR,
    FWU_ERROR_WRONG_END_OPERATION,
    FWU_ERROR_DATA_LENGTH_INVALID,
    FWU_INVALID_HECI_CMD,
    HECI_STATUS_CANNOT_DETECT_ME_STATE,
    MEMANUF_ERROR_EOL_RPMB_NOT_POST_BIND,
    ERROR_DROP_SHIP_NOT_SUPPORTED,
    ERROR_SETUP_LOCK_NOT_SUPPORTED,
    SLIM_SKU_UNSUPPORTED_COMMAND,
    UNIQUE_VARS_ALREADY_SET,
    ERROR_FILE_ALREADY_EXIST,
    MEMANUF_ERROR_EOL_FW_VERSIONCHECK,
    MEMANUF_ERROR_EOL_GBE_VERSIONCHECK,
    MEMANUF_ERROR_EOL_BIOS_VERSIONCHECK,
    MEMANUF_ERROR_EOL_UUIDCHECK_MISMATCH,
    MEMANUF_ERROR_EOL_MACCHECK_MISMATCH,
    MEMANUF_ERROR_EOL_WLAN_MACCHECK_MISMATCH,
    MEMANUF_ERROR_EOL_WLAN_UCODE_MISMATCH,
    MEMANUF_ERROR_EOL_FWU_OEM_ID_MISMATCH,
    MEMANUF_ERROR_EOL_TOUCH_VENDORID_CHECK,
    NVAR_MCA_WRONG_PKI_SUFFIX,
    FWU_LOWER_ARB_SVN,
    FWU_ERROR_FTPR_BUILD,
    FWU_ERROR_501,
    FPT_COMMITFPF_RPMB_FUSE_SET,
    FWU_ERROR_PCHC_MISSING_UPDATE,
    MEMANUF_ERROR_EOL_MISMATCH_UEP_HW,
    FWU_SMALL_BUFFER,
    FWU_CORRUPTED,
    FWU_FULL_INVALID,
    FWU_PARTIAL_INVALID,
    FWU_MANDATORY_INVALID,
    FWU_MAX_IUP_ERROR,
    MEMANUF_ERROR_CFG_FILE_UNKNOWN_TEST,
    FWU_MAN_NOT_FOUND,
    FWU_EXT_NOT_FOUND,
    VAR_INVALID_DATA_SIZE,
    FWU_ALLOCATED_BUFFER_SMALL,
    FWU_FWSTS_REG,
    FWU_FW_READ_FILE_FAIL,
    FWU_PG_IN_PROGRESS,
    FWU_ALLOWSV_RS_MISSING,
    ICC_INVALID_MPHY_LENGTH,
    FWU_FW_ISH_CFG,
    ERROR_LAN_PCIE_NOT_READY,
    ERROR_LAN_SMBUS_NOT_READY,
    ERROR_EDP_LSPCON_VALUES_OVERLAP,
    ERROR_SRV_FQDN_INVALID_VALUE,
    NVAR_MCA_WRONG_HOST_FQDN,
    NVAR_MCA_WRONG_GPIO_OWN_MODE,
    NVAR_MCA_WRONG_GPIO_PAD_MODE,
    NVAR_MCA_WRONG_GPIO_FEATURE_IN_USE,
    NVAR_MCA_WRONG_GPIO_FEATURE,
    NVAR_MCA_WRONG_CERT_HASH_VALUE,
    NVAR_MCA_WRONG_HOST_FQDN_DOMAIN,
    NVAR_MCA_WRONG_HOST_FQDN_HOSTNAME,
    ERROR_UPID_PSR_CONFIGURATION,
    NVAR_MCA_POLICY_SYSINTID_WRONG_DATA,
    NVAR_MCA_WRONG_GPIO_PAD_ADDR_PARAM,
    NVAR_MCA_WRONG_GPIO_PAD_ADDR_IN_USE,
    NVAR_MCA_PRE_PROV_INVALID_STATE,
    NVAR_MCA_EHBC_STATE_PRIV_LEVEL_MISMATC,
    FWU_ERROR_FWSTS_INVALID,
    FWU_ERROR_BURN_INVALID,
    FPROG_CLEAR_HASH_ERROR,
    FWU_ERROR_NVM_COMPAT_FTPR,
    ICC_FW_ERROR_INCORRECT_API_VERSION,
    FWU_ERROR_NVM_COMPAT_RBEP,
    FWU_ERROR_NVM_COMPAT_NFTP,
    FWU_ERROR_NVM_COMPAT_IUP,
    ICC_FW_ERROR_FLASH_WEAR_OUT_VIOLATION,
    ICC_FW_ERROR_FLASH_CORRUPTION,
    ICC_FW_ERROR_PROFILE_NOT_SELECTABLE_BY_BIOS,
    ICC_FW_ERROR_TOO_LARGE_PROFILE_INDEX,
    ICC_FW_ERROR_NO_SUCH_PROFILE_IN_FLASH,
    ICC_FW_ERROR_CMD_NOT_SUPPORTED_AFTER_END_OF_POST,
    ICC_FW_ERROR_NO_SUCH_RECORD,
    ICC_FW_ERROR_FILE_NOT_FOUND,
    ICC_FW_ERROR_INVALID_RECORD_FORMAT,
    ICC_FW_ERROR_TOO_LARGE_UOB_RECORD,
    ICC_FW_ERROR_CLOCK_NOT_CONFIGURABLE,
    ICC_FW_ERROR_REGISTER_IS_LOCKED,
    ICC_FW_ERROR_NO_VALID_PRE_UOB,
    ICC_FW_ERROR_NO_VALID_PERM_UOB,
    ICC_FW_ERROR_NO_DATA_FOR_THIS_CLOCK,
    ICC_FW_ERROR_PROFILE_INDEX_IS_CURRENT,
    ICC_FW_ERROR_NO_BCLK_ADJUSTMENT_FOUND,
    ICC_FW_ERROR_WARM_RESET_RAMP_NOT_SUPPORTED,
    ICC_FW_ERROR_UOB_RECORD_IS_ALREADY_INVALID,
    ICC_FW_ERROR_NO_PROFILES_EXIST,
    ICC_FW_ERROR_AUTH_FAILURE,
    ICC_FW_ERROR_ERROR_READING_FILE,
    MEMANUF_ERROR_EOL_RPMB_REBINDING_NOT_ALLOWED,
    ICC_FW_ERROR_FREQ_TOO_HIGH,
    ICC_FW_ERROR_PENDING_REVERT_TO_DEFAULT,
    ICC_FW_ERROR_PENDING_SET_PROFILE,
    ICC_FW_ERROR_UNVALID_PROFILE,
    ICC_FW_ERROR_UNVALID_OEM_DATA,
    ICC_FW_ERROR_ERROR_READING_DYNAMIC_RECORD,
    MEMANUF_ERROR_EOL_RPMB_FATAL_ERROR,
    ICC_FW_ERROR_FREQ_TOO_LOW,
    MEMANUF_ERROR_EOL_RPMB_FUSE_DISABLED,
    ICC_FW_ERROR_SSC_MODE_CHANGE_NOT_SUPPORTED,
    ICC_FW_ERROR_RANGE_VIOLATION_SSC_TOO_HIGH,
    ICC_FW_ERROR_SURVIVABILITY_SYNC_DISABLED,
    ICC_FW_ERROR_WARM_RESET_FREQ_TOO_LOW,
    ICC_FW_ERROR_NO_SUCH_TARGET_ID,
    ICC_FW_ERROR_NO_SUCH_REGISTER,
    ICC_FW_ERROR_INVALIDATE_SUCCESSFUL,
    MEMANUF_ERROR_EOL_RPMB_FUSE_RB_DISABLED,
    ICC_FW_ERROR_VALID_UOB_ALREADY_PRESENT,
    ICC_FW_ERROR_WAITING_FOR_POWER_CYCLE,
    ICC_FW_ERROR_SURVIVABILITY_TABLE_ACCESS_VIOLATION,
    ICC_FW_ERROR_SURVIVABILITY_TABLE_TOO_LARGE,
    ICC_FW_ERROR_NO_SUCH_EID,
    ICC_FW_ERROR_SUCCESS_TRANSLATE_ONLY,
    ICC_FW_ERROR_PCIE_FAIL_READING_DATA,
    ICC_FW_ERROR_PCIE_FAIL_WRITING_DATA,
    ICC_FW_ERROR_PCIE_CONFIG_INVALID,
    ICC_FW_ERROR_CMD_NOT_SUPPORTED_BEFORE_DID,
    ICC_FW_ERROR_FIA_MUX_CONFIG_SKU_MISMATCH,
    ICC_FW_ERROR_FIA_MUX_NO_CONFIG_FOUND,
    ICC_FW_ERROR_FIA_MUX_ERROR_GETTING_LANES_LIMIT,
    ICC_FW_ERROR_FIA_MUX_ERROR_READING_CONF_FROM_FILE,
    ICC_FW_ERROR_FIA_MUX_ERROR_PROMPTING_TO_GLOBAL_RESET,
    ICC_FW_ERROR_FIA_MUX_INVALID_FIA_MUX_CONFIG,
    ICC_FW_ERROR_FIA_MUX_ERROR_WRITING_CONF_TO_FILE,
    ICC_FW_ERROR_FIA_MUX_ERROR_READING_CONF_FROM_STRAPS,
    ICC_FW_ERROR_MAX_BUNDLES_PER_RECORD_REACHED,
    ICC_FW_ERROR_PLL_UNSUPPORTED,
    ICC_FW_ERROR_DATA_ITEM_UNSUPPORTED,
    ICC_FW_ERROR_OEM_PROFILE_CRDR_VIOLATION,
    MEMANUF_ERROR_EOL_RPMB_RB_DISABLED,
    ICC_SW_INVALID_BUF_LEN,
    ICC_SW_INVALID_ARG,
    AMT_IPV6_DISABLED,
    AMT_INTERFACE_DOES_NOT_EXIST,
    NVAR_MCA_WRONG_UC_POLICY,
    FEAT_ARB_SVN_DISABLED,
    INPUT_FILE_TOO_LARGE,
    MEMANUF_ERROR_EOL_PCHC_VERSIONCHECK,
    FWU_ERROR_ENGINEERING_PART,
    ERROR_UNKNOWN_HW,
    ERROR_UNSUPPORTED_HW,
    ERROR_CFG_FILE_CONTAINS_DUPLICATES,
    FWU_ERROR_API_VER_MAJOR_ISIF,
    FWU_ERROR_INTEGRITY_FAILED_ISIF,
    FWU_ERROR_GET_EXT_FAILED_ISIF,
    FWU_ERROR_VER_MAN_FAILED_ISIF,
    HTM_COMMAND_EXEC_ERROR,
    ERROR_NON_INITALIZED_NVAR_FILE,
    ME_DISABLED,
    UNKNOWN_GFX_BDF,
    FWU_ERROR_FW_TYPE_FTPR,
    FWU_ERROR_API_VER_MAJOR_SAMF,
    FWU_ERROR_INTEGRITY_FAILED_SAMF,
    FWU_ERROR_GET_EXT_FAILED_SAMF,
    FWU_ERROR_VER_MAN_FAILED_SAMF,
    FWU_ERROR_API_VER_MAJOR_PPHY,
    FWU_ERROR_INTEGRITY_FAILED_PPHY,
    FWU_ERROR_GET_EXT_FAILED_PPHY,
    FWU_ERROR_VER_MAN_FAILED_PPHY,
    FPROG_ERROR_READ_SPI_DATA,
    MEMANUF_ERROR_EOL_UPID_OEM_ID_EMPTY,
    ICC_SW_UNSUPPORTED,
    FWU_ERROR_API_VER_MAJOR_GBST,
    FWU_ERROR_INTEGRITY_FAILED_GBST,
    FWU_ERROR_GET_EXT_FAILED_GBST,
    FWU_ERROR_VER_MAN_FAILED_GBST,
    MEMANUF_ERROR_EOL_UPID_OEM_PLAT_ID_EMPTY,
    MEMANUF_ERROR_EOL_AMT_HW_NVAR,
    MEMANUF_ERROR_EOL_AMT_HW_EFS,
    ICC_FW_ERROR_SURVIVABILITY_TABLE_REJECTED_BY_PMC,
    ERROR_LAN_I2C_FAILURE,
    ERROR_IPL_BIST_STATUS_UNDEFINED,
    ERROR_IPL_BIST_STATUS_MEM_ERROR,
    ERROR_IPL_BIST_STATUS_DISABLED,
    ERROR_IPL_BIST_STATUS_GENERIC_FAILURE,
    ERROR_IPL_BIST_STATUS_LOAD_FAILURE,
    ERROR_IPL_BIST_STATUS_VERIFY_FAILURE,
    ERROR_IPL_BIST_STATUS_READ_FAILURE,
    ERROR_IPL_BIST_STATUS_HW_FAILURE,
    ERROR_ISH_BIST_STATUS_UNDEFINED,
    ERROR_ISH_BIST_STATUS_MEM_ERROR,
    ERROR_ISH_BIST_STATUS_DISABLED,
    ERROR_ISH_BIST_STATUS_GENERIC_FAILURE,
    ERROR_ISH_BIST_STATUS_LOAD_FAILURE,
    ERROR_ISH_BIST_STATUS_VERIFY_FAILURE,
    ERROR_ISH_BIST_STATUS_READ_FAILURE,
    ERROR_ISH_BIST_STATUS_HW_FAILURE,
    FWU_ERROR_UNLOCK,
    MEMANUF_ERROR_EOL_SAMF_PPHY_PRESENCE,
    MEMANUF_ERROR_EOL_SAMF_PRESENCE,
    MEMANUF_ERROR_EOL_PPHY_PRESENCE,
    MEMANUF_ERROR_EOL_ATTR_KB_EMPTY,
    ATTKB_FILE_SIZE_ERROR,
    ATTKB_FILE_DATA_INVALID_ERROR,
    ATTKB_NOT_PROVISIONED,
    NVAR_MCA_WRONG_SEAL_POLICY,
    NVAR_MCA_WRONG_RESEAL_TIMEOUT,
    READ_PCI_FAILURE,
    WRITE_PCI_FAILURE,
    READ_MMIO_FAILURE,
    WRITE_MMIO_FAILURE,
    REBOOT_FAILURE,
    SPI_MMIO_FAILURE,
    EXTRACT_RES_FAILURE,
    TEMP_FOLDER_FAILURE,
    DRIVER_PATH_FAILURE,
    WOW64_FAILURE,
    DELETE_DRIVER_FAILURE,
    DRIVER_CREATE_FAILURE,
    DRIVER_START_FAILURE,
    DRIVER_STOP_FAILURE,
    DRIVER_REMOVE_FAILURE,
    DRIVER_OPERATION_FAILURE,
    WDF_INSTALLER_FAILURE,
    DRIVER_INSTALL_FAILURE,
    DRIVER_UNINSTALL_FAILURE,
    RESERVED_FILE_NAME,
    SVN_MISMATCH,
    MEMANUF_ERROR_EOL_GLITCH_DETECTION_DISABLED,
    MEMANUF_ERROR_EOL_GLITCH_DETECTION_ENABLED,
    MEMANUF_ERROR_EOL_PLATFORM_BINDING_STATUS_ENABLED,
    MEMANUF_ERROR_EOL_PLATFORM_BINDING_STATUS_DISABLED,
    MANUF_ERROR_EOL_MRC_INIT_STATUS,
    MANUF_ERROR_EOL_GFX_FW_VERSION,
    MANUF_ERROR_HDA_CONTROLLER_INIT_STATUS,
    MANUF_ERROR_MASTER_ACCESS_PERMISSIONS_CHECK,
    MANUF_ERROR_EOL_OPROM_VERSION,
    ERROR_GFX_BIST_STATUS_FID_NOT_REACHED,
    ERROR_GFX_BIST_STATUS_FATAL_ERROR_OCCURED,
    ERROR_GFX_BIST_STATUS_FSP_FAILURE,
    ERROR_GFX_BIST_STATUS_CSE_RESET_ON_ERROR_OCCURED,
    VERIFY_EOM_CONFIG_WRONG_SIZE,
    FWU_GSC_BP_COPY,
    MANUF_EOL_VAR_WITHOUT_CONFIG,
    FWU_ERROR_INCOMPLETE_DATA,
    MANUF_EOL_EOM_NOT_SET,
    MEMANUF_ERROR_EOL_UPID_NOT_SUPPORTED,
    UPID_MAX_COUNTER_EXCEEDED,
    UPID_INVALID_INPUT_PARAMETER,
    MEMANUF_ERROR_EOL_EOM_CFG_LOCKCHECK_NOT_EOM,
    MEMANUF_ERROR_SYSTEM_IS_EOP,
    MEMANUF_ERROR_EOL_FLASHLOCKCHECK_NOT_EOM,
    FPT_FPF_AMT_ENABLED,
    HECI_COMMAND_NOT_SUPPORTED,
    MKHI_COMMAND_GENERAL_ERROR,
    FWU_ERROR_SKU_MISMATCH,
    MEMANUF_ERROR_EOL_UPID_OEM_PLAT_ID_NOT_SET,
    FWU_ERROR_VER_MAN_FAILED_PSEP,
    FWU_ERROR_GET_EXT_FAILED_PSEP,
    FWU_ERROR_INTEGRITY_FAILED_PSEP,
    FWU_ERROR_API_VER_MAJOR_PSEP,
    MULTIPLE_GFX_SETUP_ERROR,
    D3_AWAKE_FAILED,
    D3_RELEASE_FAILED,
    DISPLAY_LIB_NOT_INIT,
    FILE_STREAM_NOT_INIT,
    FAILED_TO_INIT_DISPLAY_LIB,
    FILE_SCREEN_STREAMS_NOT_INIT,
    INVALID_SOFTSTRAP_NAME,
    INVALID_SOFTSTRAP_VALUE,
    SOFTSTRAP_NOT_UPDATEABLE,
    SOFTSTRAP_NOT_SUPPORTED_ON_SKU,
    SS_DEP_SUPPORT_FAILED_VAR,
    AMT_PROHIBIT_SHA1_HASH,
    ERROR_CHASSIS_BIST_STATUS_UNDEFINED,
    ERROR_CHASSIS_BIST_STATUS_GENERIC_FAILURE,
    ERROR_CHASSIS_BIST_STATUS_LOAD_FAILURE,
    ERROR_CHASSIS_BIST_STATUS_VERIFY_FAILURE,
    ERROR_CHASSIS_BIST_STATUS_READ_FAILURE,
    ICC_SDK_BCLK_IS_NOT_SUPPORTED,
    AMT_ERROR_DISABLE_NETWORK_SERVICES,
    FWU_ERROR_VER_MAN_FAILED_ADSP,
    FWU_ERROR_GET_EXT_FAILED_ADSP,
    FWU_ERROR_INTEGRITY_FAILED_ADSP,
    FWU_ERROR_API_VER_MAJOR_ADSP,
    SAVE_MAC_SXID_CORPORATE_ONLY,
    NVAR_INVALID_LSPCON_PORT_COUNT,
    FWU_HECI_CLIENT_UNMAPPED_ERROR,
    MCA_HECI_CLIENT_UNMAPPED_ERROR,
    HCDP_PAVP_HECI_CLIENT_UNMAPPED_ERROR,
    HCI_HECI_CLIENT_UNMAPPED_ERROR,
    HOTHAM_HECI_CLIENT_UNMAPPED_ERROR,
    ICC_FIXED_HECI_CLIENT_UNMAPPED_ERROR,
    AMT_HECI_CLIENT_UNMAPPED_ERROR,
    UPID_HECI_CLIENT_UNMAPPED_ERROR,
    UNKNOWN_HECI_CLIENT_GUID,
    FWU_ERROR_VER_MAN_FAILED_OUT_OF_RESOURCES,
    MPHY_TABLE_DONT_EXIST,
    VERIFY_WRONG_ALG_SET,
    FPT_FPF_AMT_DISABLED,
    NO_GFX_DEVICES,
    COMMIT_FVC_FAILED,
    ERROR_CONFIRM_FVC_SVN,
    FWU_ERROR_FVC_TCB_ARB,
    FEAT_FVC_SVN_DISABLED,
    FVC_SVN_MISMATCH,
    FWU_LOWER_FVC_SVN,
    MESSAGING_LIBRARY_MISSING_FORMAT_STRING,
    MESSAGING_LIBRARY_INCORRECT_PARAMETER,
    MANUF_ERROR_EOL_HDAS_VENDOR_ID,
    MANUF_ERROR_EOL_HDAS_DEVICE_ID,
    MANUF_ERROR_EOL_GIS_VENDOR_ID,
    MANUF_ERROR_EOL_GIS_DEVICE_ID,
    FWU_ERROR_KM_LOWER_SVN,
    FWU_ERROR_IUP_KM_SVN,
    MANUF_ERROR_EOL_PSR_EMPTY,
    PSR_HECI_CLIENT_UNMAPPED_ERROR,
    ERROR_PSR_NOT_ALLOWED,
    ERROR_SPI_RECOVERY_DESC_ACCESS,
    PSR_NOT_SUPPORTED,
    PSR_NOT_STARTED,
    FWU_RECOVERY_IMAGE_FAILURE,
    FWU_ERROR_GET_RECOVERY_NOT_ALLOWED,
    FWU_ERROR_GET_RECOVERY_FLASH_IN_RECOVERY,
    FWU_ERROR_GET_RECOVERY_ALREADY_STARTED,
    FWU_ERROR_GET_RECOVERY_NOT_STARTED,   
    FWU_ERROR_GET_RECOVERY_OFFSET_INVALID,
    FWU_ERROR_GET_RECOVERY_AFTER_EOP,
    FWU_ERROR_RECOVERY_IMAGE_FAILURE,
    FWU_ERROR_DMA_FAILURE,
    FWU_ERROR_DMA_BUFFER_NOT_ALIGNED,
    FWU_ERROR_EPS_LICENSE,
    FWU_ERROR_PV_BIT_MISMATCH,
    ERROR_CODES_COUNT,
}ErrorCodes;


#define MAX_LIBRARY_NAME_LENGTH 64
#define MAX_FILE_NAME_LENGTH 260

typedef struct _ErrorObject
{
    ErrorCodes  id;
    char        library_name[MAX_LIBRARY_NAME_LENGTH];
    char        function_name[MAX_FILE_NAME_LENGTH];
    int         line_number;
}ErrorObject;

#ifdef __linux__
#ifdef __cplusplus
#define ERROR_OBJECT(id) ErrorObject{(ErrorCodes)id, __LIBRARY_NAME__, __FILE__, __LINE__}
#else
#define ERROR_OBJECT(id) (ErrorObject){(ErrorCodes)id, __LIBRARY_NAME__, __FILE__, __LINE__}
#endif
#else
#ifdef __cplusplus
#define ERROR_OBJECT(id) ErrorObject{(ErrorCodes)id, __LIBRARY_NAME__, __FUNCTION__, __LINE__}
#else
#define ERROR_OBJECT(id) (ErrorObject){(ErrorCodes)id, __LIBRARY_NAME__, __FUNCTION__, __LINE__}
#endif
#endif

#define ERROR_OBJECT_ID(obj) obj.id

/**
@brief  Return the error string matching the error id
@param[in]  errorId - Error Id enum
@return Error string
**/
const char* GetErrorString(const ErrorCodes errorId);

/**
@brief  Return the error category number matching the error id
@param[in]  errorId - Error Id enum
@return Error category number
**/
unsigned char GetErrorCategory(const ErrorCodes errorId);

/**
 * \brief Returns description string associated with specific category
 * \param errorCategory category ID
 * \return category
 */
const char* GetErrorCategoryString(const ErrorCategories errorCategory);

#endif // _ERRORLIST_H
