#ifndef IO_H
#define IO_H

#include <stdint.h>

// Ètení z I/O portu (8 bitù)
uint8_t inb(uint16_t port);

// Zápis do I/O portu (8 bitù)
void outb(uint16_t port, uint8_t value);

// Ètení z I/O portu (16 bitù)
uint16_t inw(uint16_t port);

// Zápis do I/O portu (16 bitù)
void outw(uint16_t port, uint16_t value);

#endif // IO_H
