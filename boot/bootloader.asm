section .multiboot
align 4
    dd 0x1BADB002            ; Magic number pro multiboot
    dd 0x00                  ; Flags (��dn� speci�ln� po�adavek)
    dd -(0x1BADB002 + 0x00)  ; Checksum (mus� se rovnat 0)

section .bss
align 4
stack_top:
    resb 8192                ; Alokace stacku (8 KB)

section .text
global _start
_start:
    ; Inicializace stacku
    mov esp, stack_top

    ; Vol�n� hlavn� funkce kernelu
    extern kernel_main
    call kernel_main

    ; Nekone�n� smy�ka, pokud se kernel_main vr�t�
    cli
.halt:
    hlt
    jmp .halt
