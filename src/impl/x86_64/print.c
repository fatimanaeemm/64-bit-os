#include "print.h"

const static size_t NUM_COLS = 80;
const static size_t NUM_ROWS = 25;
const int height = 5;

struct Char {
    uint8_t character;
    uint8_t color;
};

struct Char* buffer = (struct Char*) 0xb8000;
size_t col = 0;
size_t row = 0;
uint8_t color = PRINT_COLOR_WHITE | PRINT_COLOR_BLACK << 4;

void clear_row(size_t row) {
    struct Char empty = (struct Char) {
        character: ' ',
        color: color,
    };

    for (size_t col = 0; col < NUM_COLS; col++) {
        buffer[col + NUM_COLS * row] = empty;
    }
}

void print_clear() {
    for (size_t i = 0; i < NUM_ROWS; i++) {
        clear_row(i);
    }
}

void print_newline() {
    col = 0;

    if (row < NUM_ROWS - 1) {
        row++;
        return;
    }

    for (size_t row = 1; row < NUM_ROWS; row++) {
        for (size_t col = 0; col < NUM_COLS; col++) {
            struct Char character = buffer[col + NUM_COLS * row];
            buffer[col + NUM_COLS * (row - 1)] = character;
        }
    }

    clear_row(NUM_COLS - 1);
}

void print_char(char character) {
    if (character == '\n') {
        print_newline();
        return;
    }

    if (col > NUM_COLS) {
        print_newline();
    }

    buffer[col + NUM_COLS * row] = (struct Char) {
        character: (uint8_t) character,
        color: color,
    };

    col++;
}

void print_str(char* str) {
    int i, j;
    for (i = 0; i < height; i++) {
        printS(i,j);
        giveSpace();
        printE(i,j);
        giveSpace();
        printE(i,j);
        giveSpace();
        printC(i,j);
        giveSpace();
        printS(i,j);
        print_newline();
    }
}

void printS(int i, int j)
{
    for (j = 0; j < height; j++) {
            if ((i == 0 || i == height / 2
                 || i == height - 1))
                print_char('*');
            else if (i < height / 2
                     && j == 0)
                print_char('*');
            else if (i > height / 2
                     && j == height - 1)
                print_char('*');
            else
                print_char(' ');
        }
        
}

void printE(int i, int j)
{
    print_char('*');
        for (j = 0; j < height; j++) {
            if ((i == 0 || i == height - 1)
                || (i == height / 2
                    && j <= height / 2))
                print_char('*');
            else
                print_char(' ');
        }
}

void printC(int i, int j)
{
        print_char('*');
        for (j = 0; j < (height - 1); j++) {
            if (i == 0 || i == height - 1)
                print_char('*');
            else
                print_char(' ');
        }
}

void giveSpace()
{
    for(int k=0;k<3;k++)
             print_char(' ');
}

void print_set_color(uint8_t foreground, uint8_t background) {
    color = foreground + (background << 4);
}
