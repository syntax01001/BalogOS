#include "../include/timer.h"

#define PIT_FREQUENCY 1193182

// Funkce pro z�pis do I/O portu
static inline void outb(unsigned short port, unsigned char val) {
    __asm__ volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
}

// Inicializace �asova�e
void init_timer(int frequency) {
    int divisor = PIT_FREQUENCY / frequency;
    outb(0x43, 0x36);                  // Nastaven� m�du �asova�e
    outb(0x40, divisor & 0xFF);        // Ni��� byte
    outb(0x40, (divisor >> 8) & 0xFF); // Vy��� byte
}
