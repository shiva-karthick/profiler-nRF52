#include <zephyr/kernel.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <zephyr/logging/log.h>

void enable_cycle_counter(void)
{
	DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
}

uint32_t read_cycle_counter(void)
{
	return DWT->CYCCNT;
}

uint8_t copyTests(uint8_t dummyVal)
{

	// !- Enable the use DWT
	// * CoreDebug->DEMCR |= 0x01000000;
	// CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
	// printk("Starting DWT_CYCCNT \n");

	// volatile uint32_t cycleCount = 0xffffffff;
	uint16_t LENGTH_OF_ARRAY = 70;

	uint8_t array1[LENGTH_OF_ARRAY];
	for (uint8_t i = 0; i < LENGTH_OF_ARRAY; i++)
	{
		array1[i] = 5;
	}

	uint8_t array2[LENGTH_OF_ARRAY];
	for (uint8_t i = 0; i < LENGTH_OF_ARRAY; i++)
	{
		array2[i] = 5;
	}

	// * Reset cycle counter
	// DWT->CYCCNT = 0;
	// * DWT->CTRL |= 0x1;
	// DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;

	for (uint8_t i = 0; i < LENGTH_OF_ARRAY; i++)
	{
		array2[i] = array1[i] * 2;
	}

	// cycleCount = DWT->CYCCNT;
	// printk("copyTests LENGTH_OF_ARRAY %i\n", LENGTH_OF_ARRAY);
	// printk("copyTests forloop cycles: %u \n", cycleCount);

	// // Reset cycle counter
	// DWT->CYCCNT = 0;
	// DWT->CTRL |= 0x1;
	// memcpy(array2, array1, sizeof array1);
	// cycleCount = DWT->CYCCNT;

	// printk("copyTests memcpy cycles: %llu", cycleCount);

	// printk("IteratingforVsStdArray std::copy cycles: %llu", cycleCount);

	return 0;
}

int main(void)
{
	profiler_start("test1");

	profiler_event("start");
	copyTests(55);
	profiler_event("end");

	profiler_stop();
	return 0;
}
