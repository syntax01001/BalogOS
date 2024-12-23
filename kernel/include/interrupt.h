#ifndef INTERRUPT_H
#define INTERRUPT_H

#define MAX_INTERRUPTS 256

// Typ funkce obsluhy přerušení
typedef void (*interrupt_handler_t)();

// Deklarace pole obsluh přerušení
extern interrupt_handler_t interrupt_handlers[MAX_INTERRUPTS];

// Funkce pro nastavení obsluhy přerušení
void set_interrupt_handler(int irq, interrupt_handler_t handler);

// Funkce pro volání obsluhy přerušení
void handle_interrupt(int irq);

#endif // INTERRUPT_H
