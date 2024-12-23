#include "interrupt.h"

// Pole pro uchovávání obsluh pøerušení
interrupt_handler_t interrupt_handlers[MAX_INTERRUPTS] = { 0 };

// Nastavení obsluhy pøerušení
void set_interrupt_handler(int irq, interrupt_handler_t handler) {
    if (irq >= 0 && irq < MAX_INTERRUPTS) {
        interrupt_handlers[irq] = handler;
    }
}

// Volání obsluhy pøerušení
void handle_interrupt(int irq) {
    if (irq >= 0 && irq < MAX_INTERRUPTS && interrupt_handlers[irq]) {
        // Zavolá registrovanou obsluhu pøerušení
        interrupt_handlers[irq]();
    }
}
