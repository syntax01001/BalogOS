ENTRY(_start)

SECTIONS
{
    /* Kernel bude nahr�n na adresu 2 MB */
    . = 0x00200000;

    /* Multiboot header sekce */
    .multiboot ALIGN(8) :
    {
        *(.multiboot)
    }

    /* Sekce pro k�d (text) */
    .text ALIGN(8) :
    {
        *(.text)
    }

    /* Konstantn� data (read-only data) */
    .rodata ALIGN(8) :
    {
        *(.rodata)
    }

    /* Inicializovan� data */
    .data ALIGN(8) :
    {
        *(.data)
    }

    /* Neinicializovan� data (BSS) */
    .bss ALIGN(8) :
    {
        *(COMMON)
        *(.bss)
    }
}
