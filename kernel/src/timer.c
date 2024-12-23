#include "../include/timer.h"

#define PIT_FREQUENCY 1193182

// Funkce pro zápis do I/O portu
static inline void outb(unsigned short port, unsigned char val) {
    __asm__ volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
}

// Inicializace èasovaèe
void init_timer(int frequency) {
    int divisor = PIT_FREQUENCY / frequency;
    outb(0x43, 0x36);                  // Nastavení módu èasovaèe
    outb(0x40, divisor & 0xFF);        // Nižší byte
    outb(0x40, (divisor >> 8) & 0xFF); // Vyšší byte
}
