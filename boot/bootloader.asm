section .multiboot
align 4
    dd 0x1BADB002            ; Magic number pro multiboot
    dd 0x00                  ; Flags (žádná speciální požadavek)
    dd -(0x1BADB002 + 0x00)  ; Checksum (musí se rovnat 0)

section .bss
align 4
stack_top:
    resb 8192                ; Alokace stacku (8 KB)

section .text
global _start
_start:
    ; Inicializace stacku
    mov esp, stack_top

    ; Volání hlavní funkce kernelu
    extern kernel_main
    call kernel_main

    ; Nekoneèná smyèka, pokud se kernel_main vrátí
    cli
.halt:
    hlt
    jmp .halt
