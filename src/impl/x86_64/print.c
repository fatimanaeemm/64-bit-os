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
