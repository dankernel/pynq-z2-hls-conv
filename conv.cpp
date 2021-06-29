#include "conv.hpp"

void conv(conv_datatype input[INPUT_ROWS][INPUT_COLS],
		conv_datatype kernel[KERNEL_CH][KERNEL_ROWS][KERNEL_COLS],
		conv_datatype output[OUTPUT_CH][OUTPUT_ROWS][OUTPUT_COLS]) {
#pragma HLS INTERFACE axis port=input
#pragma HLS INTERFACE axis port=kernel
#pragma HLS INTERFACE axis port=output
#pragma HLS INTERFACE ap_ctrl_none port=return

	conv_datatype temp_input[INPUT_ROWS][INPUT_COLS];
	conv_datatype temp_kernel[KERNEL_CH][KERNEL_ROWS][KERNEL_COLS];
	conv_datatype temp_output[OUTPUT_CH][OUTPUT_ROWS][OUTPUT_COLS];

	for (int y = 0; y < INPUT_ROWS; y++) {
		for (int x = 0; x < INPUT_COLS; x++) {
			temp_input[y][x] = input[y][x];
		}
	}
	for (int c = 0; c < KERNEL_CH; c++) {
		for (int y = 0; y < KERNEL_ROWS; y++) {
			for (int x = 0; x < KERNEL_COLS; x++) {
				temp_kernel[c][y][x] = kernel[c][y][x];
			}
		}
	}

	// CONV
	conv_datatype temp = 0;
	row: for (int i = 1; i < INPUT_ROWS - 1; i++) {
		col: for (int j = 1; j < INPUT_COLS - 1; j++) {
#pragma HLS PIPELINE
			// CNN
			for (int c = 0; c < KERNEL_CH; c++) {
#pragma HLS PIPELINE
				temp = 0;
#pragma HLS UNROLL
				for (int ky = 0; ky < KERNEL_ROWS; ky++) {
					for (int kx = 0; kx < KERNEL_COLS; kx++) {
						temp += temp_input[i + ky - 1][j + kx - 1] * temp_kernel[c][ky][kx];
					}
				}
				temp_output[c][i - 1][j - 1] = temp;
			}
		}
	}

	for (int c = 0; c < KERNEL_CH; c++) {
		for (int y = 0; y < OUTPUT_ROWS; y++) {
			for (int x = 0; x < OUTPUT_COLS; x++) {
				output[c][y][x] = temp_output[c][y][x];
			}
		}
	}
}

