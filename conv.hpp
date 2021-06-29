
#ifndef __FUNCTION_CONV_H__
#define __FUNCTION_CONV_H__

#include <stdint.h>

typedef uint8_t conv_datatype;

#define INPUT_ROWS 28
#define INPUT_COLS 28
#define KERNEL_CH 6
#define KERNEL_ROWS 3
#define KERNEL_COLS 3
#define OUTPUT_CH 6
#define OUTPUT_ROWS 26
#define OUTPUT_COLS 26

void conv(
		conv_datatype input[INPUT_ROWS][INPUT_COLS],
		conv_datatype kernel[KERNEL_CH][KERNEL_ROWS][KERNEL_COLS],
		conv_datatype output[OUTPUT_CH][OUTPUT_ROWS][OUTPUT_COLS]);

#endif
