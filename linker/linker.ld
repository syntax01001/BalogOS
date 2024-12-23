ENTRY(_start)

SECTIONS
{
    /* Kernel bude nahrán na adresu 2 MB */
    . = 0x00200000;

    /* Multiboot header sekce */
    .multiboot ALIGN(8) :
    {
        *(.multiboot)
    }

    /* Sekce pro kód (text) */
    .text ALIGN(8) :
    {
        *(.text)
    }

    /* Konstantní data (read-only data) */
    .rodata ALIGN(8) :
    {
        *(.rodata)
    }

    /* Inicializovaná data */
    .data ALIGN(8) :
    {
        *(.data)
    }

    /* Neinicializovaná data (BSS) */
    .bss ALIGN(8) :
    {
        *(COMMON)
        *(.bss)
    }
}
