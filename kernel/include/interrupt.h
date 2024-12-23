#ifndef INTERRUPT_H
#define INTERRUPT_H

#define MAX_INTERRUPTS 256

// Typ funkce obsluhy p�eru�en�
typedef void (*interrupt_handler_t)();

// Deklarace pole obsluh p�eru�en�
extern interrupt_handler_t interrupt_handlers[MAX_INTERRUPTS];

// Funkce pro nastaven� obsluhy p�eru�en�
void set_interrupt_handler(int irq, interrupt_handler_t handler);

// Funkce pro vol�n� obsluhy p�eru�en�
void handle_interrupt(int irq);

#endif // INTERRUPT_H
