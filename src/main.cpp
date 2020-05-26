#include <nsysnet/socket.h>
#include <coreinit/ios.h>
#include "Application.h"
#include "system/memory.h"
#include "utils/logger.h"
#include "utils/utils.h"

/* Entry point */
extern "C" int Menu_Main(void)
{
    //!*******************************************************************
    //!                   Initialize function pointers                   *
    //!*******************************************************************
    socket_lib_init();
    //! do OS (for acquire) and sockets first so we got logging
    log_init();

    log_print("Initialize memory management\n");
    memoryInitialize();

    //!*******************************************************************
    //!                    Initialize heap memory                        *
    //!*******************************************************************

    log_printf("Start main application\n");
    Application::instance()->exec();

    Application::destroyInstance();	
	
    return 0;
}
