#include <nsysnet/socket.h>
#include "Application.h"
#include "system/memory.h"
#include "utils/logger.h"
#include "utils/utils.h"
#include "dynamic_libs/padscore_functions.h"
#include "common/common.h"

/* Entry point */
extern "C" int Menu_Main(void)
{
    //!*******************************************************************
    //!                   Initialize function pointers                   *
    //!*******************************************************************
    socket_lib_init();
    //! do OS (for acquire) and sockets first so we got logging
    log_init("192.168.1.12");

    InitPadScoreFunctionPointers();
    log_printf("Function exports loaded\n");

    log_print("Initialize memory management\n");
    memoryInitialize();

    //!*******************************************************************
    //!                    Initialize heap memory                        *
    //!*******************************************************************

    log_printf("Start main application\n");
    Application::instance()->exec();

    Application::destroyInstance();
    
    log_deinit();
    
    return EXIT_SUCCESS;
}
