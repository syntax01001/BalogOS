#ifndef INTERRUPT_H
#define INTERRUPT_H

#define MAX_INTERRUPTS 256

// Typ funkce obsluhy pøerušení
typedef void (*interrupt_handler_t)();

// Deklarace pole obsluh pøerušení
extern interrupt_handler_t interrupt_handlers[MAX_INTERRUPTS];

// Funkce pro nastavení obsluhy pøerušení
void set_interrupt_handler(int irq, interrupt_handler_t handler);

// Funkce pro volání obsluhy pøerušení
void handle_interrupt(int irq);

#endif // INTERRUPT_H
