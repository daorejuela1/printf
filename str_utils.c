#include <stdlib.h>
/**
 *cal_digits - Find the number of digits in the number
 *@n: Input number
 *Return: Number base
 */
unsigned int cal_digits(unsigned int n)
{
	if (n > 999999999)
		return (1000000000);
	else if (n > 99999999)
		return (100000000);
	else if (n > 9999999)
		return (10000000);
	else if (n > 999999)
		return (1000000);
	else if (n > 99999)
		return (100000);
	else if (n > 9999)
		return (10000);
	else if (n > 999)
		return (1000);
	else if (n > 99)
		return (100);
	else if (n > 9)
		return (10);
	else
		return (1);
}

/**
 *c_number_to_arr - Prints an int number by using putchar
 *@n: Input number
 *@array_data: Array to store final string
 *Return: None
 */
char *c_number_to_arr(char *array_data, int n)
{
	int i, position = 0;
	unsigned int handler;
	int num_digits;

	handler = n;
	if (n < 0)
	{
		handler = handler * -1;
		array_data[position] = '-';
		position++;
	}
	num_digits = cal_digits(handler);
	for (i = num_digits; i >= 1; i /= 10)
	{
		array_data[position] = (handler / i) % 10 + '0';
		position++;
		if (i == 1)
			break;
	}
	return (array_data);
}

/**
 *_strlen - Returns string
 *@s: input string
 *Return: lenght not counting NULL
 */
int _strlen(char *s)
{
	int counter = 0;

	if (s == NULL)
		return (0);
	while (*(s + counter) != 0)
	{
		counter++;
	}
	return (counter);
}

/**
 *_strncpy - copies one string to another, from start to end
 *@dest: destiny array to copy the string
 *@src: source string being copy
 *@init: initial index
 *@end: final index
 *@data_len: length of the added_data
 *Return: Nothing
 */
void _strncpy(char *dest, char *src, int init, int end, int data_len)
{
	int i, offset;

	offset = data_len + 2;
    /*if end equals to end of array then evaluates the offset of the data_len*/
	for (i = init; i <= end || (end == -1 && src[i - offset]); i++)
	{
		*(dest + i) = *(src + i - data_len);
	     /*Copies from original source to dest*/
	}
}
/**
 *put_in_place - Copies the start and enf of an array that sorrounds a new word
 *@new_buffer: Destiny array to copy the string
 *@buffer: Source string being copy
 *@position: Initial index.
 *@data_len: Lenght of the buffer not counting NULL
 *Return: Nothing.
 */
void put_in_place(char *new_buffer, char *buffer, int position, int data_len)
{
	_strncpy(new_buffer, buffer, 0, position, 0);
    /*Copies data from original buffer to new buffer from 0 to %x position*/
	_strncpy(new_buffer, buffer, position + data_len + 1, -1, data_len - 2);
	/*
	 *Copies data from original buffer to new buffer
	 *From %[x] position + datalenght
	 *till the end
	 */
}
