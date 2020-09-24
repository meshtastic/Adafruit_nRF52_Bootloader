#include "boards.h"
#include "uf2/configkeys.h"

__attribute__((used, section(".bootloaderConfig")))
const uint32_t bootloaderConfig[] =
    {
        /* CF2 START */
        CFG_MAGIC0, CFG_MAGIC1, // magic
        5, 100,                 // used entries, total entries

        204, 0x100000,                                // FLASH_BYTES = 0x100000
        205, 0x40000,                                 // RAM_BYTES = 0x40000
        208, (USB_DESC_VID << 16) | USB_DESC_UF2_PID, // BOOTLOADER_BOARD_ID = USB VID+PID, used for verification when updating bootloader via uf2
        209, 0xada52840,                              // UF2_FAMILY = 0xada52840
        210, 0x20,                                    // PINS_PORT_SIZE = PA_32

        0, 0, 0, 0, 0, 0, 0, 0
        /* CF2 END */
};

// We want output pin voltages to be 3.3V
__attribute__((section(".uicrREGOUT0"))) volatile uint32_t m_uicr_regout0 = 0xfffffff5;