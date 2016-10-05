#include "Application.h"
#include "dynamic_libs/os_functions.h"
#include "dynamic_libs/gx2_functions.h"
#include "dynamic_libs/syshid_functions.h"
#include "dynamic_libs/vpad_functions.h"
#include "dynamic_libs/padscore_functions.h"
#include "dynamic_libs/socket_functions.h"
#include "dynamic_libs/sys_functions.h"
#include "dynamic_libs/ax_functions.h"
#include "dynamic_libs/fs_functions.h"
#include "fs/fs_utils.h"
#include "fs/sd_fat_devoptab.h"
#include "system/memory.h"
#include "utils/logger.h"
#include "utils/utils.h"
#include "common/common.h"

#include "main.h"
#include "common/common.h"

#include "utils/logger.h"

#include "system/memory.h"

/* Entry point */
extern "C" int Menu_Main(void){
    //!*******************************************************************
    //!                   Initialize function pointers                   *
    //!*******************************************************************
    //! do OS (for acquire) and sockets first so we got logging
    InitOSFunctionPointers();
    InitSocketFunctionPointers();
    InitGX2FunctionPointers();
    InitSysFunctionPointers();
    InitVPadFunctionPointers();
    InitPadScoreFunctionPointers();
    InitAXFunctionPointers();
    InitFSFunctionPointers();

    log_init("192.168.1.12");

    //Otherwise apply the patches!!!
    log_printf("GX2_template\n\n");

    //!*******************************************************************
    //!                    Initialize heap memory                        *
    //!*******************************************************************
    log_print("Initialize memory management\n");
    memoryInitialize();

    log_printf("Mount SD partition\n");
    mount_sd_fat("sd");
    log_printf("Start main application\n");
    Application::instance()->exec();

    Application::destroyInstance();
    log_printf("Unmount SD\n");
    unmount_sd_fat("sd");
    memoryRelease();

    log_print("Going back to the Homebrew launcher\n");

     log_deinit();
    return EXIT_SUCCESS;
}
