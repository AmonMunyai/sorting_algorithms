#include "sort.h"

/**
 * swap_ints - swaps two integers.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */

void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order.
 * @array: an array of integers to sort.
 * @size: the size of the array.
 * Description: prints the array after each swap.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	int flag = 0;

	if (array == NULL || size < 2)
		return;

	while (flag == 0)
	{
		flag = 1;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				flag = 0;
			}
		}
		len--;
	}
}
