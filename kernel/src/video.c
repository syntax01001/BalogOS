#include "video.h"
#include "io.h" // Pro funkce inb() a outb()

#define VGA_ADDRESS 0xB8000
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

// Ukazatel na pamÏù VGA
static unsigned short* const video_memory = (unsigned short*)VGA_ADDRESS;

// Sou¯adnice kurzoru
static unsigned int cursor_x = 0;
static unsigned int cursor_y = 0;

// Vymaûe obrazovku a nastavÌ kurzor na zaË·tek
void clear_screen() {
    for (unsigned int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        video_memory[i] = (0x07 << 8) | ' '; // Barva svÏtle öed· na ËernÈ pozadÌ
    }
    cursor_x = 0;
    cursor_y = 0;
    update_cursor();
}

// VypÌöe znak na aktu·lnÌ pozici kurzoru
void print_char(char c) {
    if (c == '\n') {
        cursor_x = 0;
        cursor_y++;
    }
    else {
        unsigned int pos = cursor_y * SCREEN_WIDTH + cursor_x;
        video_memory[pos] = (0x07 << 8) | c; // NastavenÌ barvy a znaku
        cursor_x++;
        if (cursor_x >= SCREEN_WIDTH) {
            cursor_x = 0;
            cursor_y++;
        }
    }

    if (cursor_y >= SCREEN_HEIGHT) {
        scroll_screen();
    }
    update_cursor();
}

// Posune obrazovku o jednu ¯·dku nahoru
void scroll_screen() {
    for (unsigned int y = 1; y < SCREEN_HEIGHT; y++) {
        for (unsigned int x = 0; x < SCREEN_WIDTH; x++) {
            video_memory[(y - 1) * SCREEN_WIDTH + x] = video_memory[y * SCREEN_WIDTH + x];
        }
    }

    // Vypr·zdnÏnÌ poslednÌho ¯·dku
    for (unsigned int x = 0; x < SCREEN_WIDTH; x++) {
        video_memory[(SCREEN_HEIGHT - 1) * SCREEN_WIDTH + x] = (0x07 << 8) | ' ';
    }
    cursor_y--;
}

// Aktualizuje polohu kurzoru
void update_cursor() {
    unsigned short pos = cursor_y * SCREEN_WIDTH + cursor_x;
    outb(0x3D4, 0x0F);
    outb(0x3D5, (unsigned char)(pos & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (unsigned char)((pos >> 8) & 0xFF));
}
