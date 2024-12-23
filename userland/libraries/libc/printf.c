#include "print.h"

#define VIDEO_MEMORY 0xB8000
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

static int cursor_x = 0, cursor_y = 0;
static char* video_memory = (char*)VIDEO_MEMORY;

void clear_screen() {
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT * 2; i += 2) {
        video_memory[i] = ' ';
        video_memory[i + 1] = 0x07; // Barva
    }
    cursor_x = cursor_y = 0;
}

void print(const char* str) {
    int i = 0;
    while (str[i]) {
        if (str[i] == '\n') {
            cursor_x = 0;
            cursor_y++;
        }
        else {
            int pos = (cursor_y * SCREEN_WIDTH + cursor_x) * 2;
            video_memory[pos] = str[i];
            video_memory[pos + 1] = 0x07;
            cursor_x++;
            if (cursor_x >= SCREEN_WIDTH) {
                cursor_x = 0;
                cursor_y++;
            }
        }
        i++;
    }
}
