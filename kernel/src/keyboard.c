#include "keyboard.h"
#include "video.h"
#include "interrupt.h"
#include "io.h"

static const char keymap[128] = {
    0, 27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
    0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0, '\\',
    'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, '*', 0, ' ', 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '-', 0,
    0, 0, '+', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

void keyboard_interrupt_handler() {
    unsigned char scancode = inb(0x60); // Ètení ze vstupního portu klávesnice
    if (!(scancode & 0x80)) {
        char key = keymap[scancode];
        if (key) {
            print_char(key); // Výpis znaku na obrazovku
        }
    }
}

void init_keyboard() {
    set_interrupt_handler(33, keyboard_interrupt_handler); // IRQ1 = 33
}
