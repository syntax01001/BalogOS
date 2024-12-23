#include <stddef.h>
#include <stdint.h>
#include "../include/keyboard.h"
#include "../include/video.h"

// Multiboot header (pro GRUB)
__attribute__((section(".multiboot")))
const uint32_t multiboot_header[] = {
    0x1BADB002,                // Magic number
    0x0,                       // Flags
    -(0x1BADB002 + 0x0)        // Checksum
};

// Hlavn� funkce j�dra
void kernel_main(void) {
    // Vyma�eme obrazovku
    clear_screen();

    // Vyp�eme uv�tac� zpr�vu
    const char* welcome_message = "BalogOS: Kernel je spusten!\n";
    for (size_t i = 0; welcome_message[i] != '\0'; i++) {
        print_char(welcome_message[i]);
    }

    // Inicializace kl�vesnice
    init_keyboard();

    // Nekone�n� smy�ka
    while (1) {
        __asm__ volatile ("hlt"); // �ek�n� na p�eru�en�
    }
}

// Startovac� funkce volan� bootloaderem
void _start(void) {
    kernel_main();
}
