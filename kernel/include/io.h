#ifndef IO_H
#define IO_H

#include <stdint.h>

// �ten� z I/O portu (8 bit�)
uint8_t inb(uint16_t port);

// Z�pis do I/O portu (8 bit�)
void outb(uint16_t port, uint8_t value);

// �ten� z I/O portu (16 bit�)
uint16_t inw(uint16_t port);

// Z�pis do I/O portu (16 bit�)
void outw(uint16_t port, uint16_t value);

#endif // IO_H
