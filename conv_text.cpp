#include <stdint.h>
#include <stdio.h>
#include "conv.hpp"

int main() {

	conv_datatype input[INPUT_ROWS][INPUT_COLS];
	conv_datatype kernel[KERNEL_CH][KERNEL_ROWS][KERNEL_COLS];
	conv_datatype output[OUTPUT_CH][OUTPUT_ROWS][OUTPUT_COLS];

	for (int y = 0; y < INPUT_ROWS; y++) {
		for (int x = 0; x < INPUT_COLS; x++) {
			input[y][x] = 1;
		}
	}

	for (int c = 0; c < KERNEL_CH; c++) {
		kernel[c][0][0] = 0;
		kernel[c][0][1] = 0;
		kernel[c][0][2] = 0;
		kernel[c][1][0] = 1 * c;
		kernel[c][1][1] = 1 * c;
		kernel[c][1][2] = 1 * c;
		kernel[c][2][0] = 0;
		kernel[c][2][1] = 0;
		kernel[c][2][2] = 0;
	}

	conv(input, kernel, output);

	for (int c = 0; c < KERNEL_CH; c++) {
		printf("===== %d ===== \n", c);
		for (int y = 0; y < OUTPUT_ROWS; y++) {
			for (int x = 0; x < OUTPUT_ROWS; x++) {
				printf("%d ", output[c][y][x]);
			}
			printf("< \n");
		}
	}

	return 0;
}
