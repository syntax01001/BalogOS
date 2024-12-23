#include "interrupt.h"

// Pole pro uchov�v�n� obsluh p�eru�en�
interrupt_handler_t interrupt_handlers[MAX_INTERRUPTS] = { 0 };

// Nastaven� obsluhy p�eru�en�
void set_interrupt_handler(int irq, interrupt_handler_t handler) {
    if (irq >= 0 && irq < MAX_INTERRUPTS) {
        interrupt_handlers[irq] = handler;
    }
}

// Vol�n� obsluhy p�eru�en�
void handle_interrupt(int irq) {
    if (irq >= 0 && irq < MAX_INTERRUPTS && interrupt_handlers[irq]) {
        // Zavol� registrovanou obsluhu p�eru�en�
        interrupt_handlers[irq]();
    }
}
