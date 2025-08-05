#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    // Open the memory card
    FILE *card = fopen(argv[1], "r");

    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // While there's still data left to read from the memory card
    uint8_t buffer[BLOCK_SIZE];
    FILE *img = NULL;
    char filename[8];
    int file_count = 0;

    while (fread(buffer, BLOCK_SIZE, 1, card) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }

            sprintf(filename, "%03i.jpg", file_count++);
            img = fopen(filename, "w");
        }

        if (img != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, img);
        }
    }

    if (img != NULL)
    {
        fclose(img);
    }

    fclose(card);
    return 0;
}
