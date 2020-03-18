#include "holberton.h"
#include <stdlib.h>
/**
 *save_c - saves a character in a new buffer using the position flag
 *@buffer: input array to copy from
 *@position: position where the new character should be implemented
 *@special: special character to handle %
 *@valist: Character that wants to be copy
 *
 *Return: destiny array
 */
char *save_c(char *buffer, int position, char special, va_list valist)
{
	int data_len;
	char data;
	char *new_buffer;

	if (special == '%')
		data = '%';
	else
		data = va_arg(valist, int);
	if (data == '\0')
		data_len = 0;
	else
	    data_len = 1;
	new_buffer = malloc((_strlen(buffer) + data_len - 2) * sizeof(char));
	if (new_buffer == NULL)
		exit(1);
/*Stores in the heap the characters necessary to the modified buffer*/
	*(new_buffer + position + 1) = data;
/*Saves in the exact position of the buffer the character replacing %c*/
	put_in_place(new_buffer, buffer, position, data_len);
/*
 *Puts the beggining and the end of the original buffer
 *In the end buffer to sorround the data
 */
	return (new_buffer);
}

/**
 *save_s - Saves a String in a new buffer using the position flag
 *@buffer: Input array to copy from
 *@position: Position where the new character should be implemented
 *@special: Special character to detect %
 *@valist: String that wants to be copy
 *Return: Destiny array
 */
char *save_s(char *buffer, int position, char special, va_list valist)
{
	int data_len, i;
	char *new_buffer, *data;

	data = va_arg(valist, char *);
	if (special == '%')
		data = "%";
	if (data == NULL)
		data = "(null)";
	data_len = _strlen(data);
	new_buffer = malloc((_strlen(buffer) + data_len - 2) * sizeof(char));
	if (new_buffer == NULL)
		exit(1);
    /*Stores in the heap the characters necessary to the modified buffer */
	for (i = 0; i < data_len; i++)
	{
		*(new_buffer + position + 1 + i) = *(data + i);
	/*
	 * Saves in the exact position of the buffer
	 * the string replacing %s
	 */
	}
	put_in_place(new_buffer, buffer, position, data_len);
	/*
	 *puts the beggining and the end of the original
	 *buffer in the end buffer to sorround the data
	 */
	return (new_buffer);
}


/**
 *save_d - Saves a String in a new buffer using the position flag
 * aking as input an integer
 *@buffer: Input array to copy from
 *@position: Position where the new character should be implemented
 *@special: character to represent % cases
 *@valist: String that wants to be copy
 *Return: destiny array
 */
char *save_d(char *buffer, int position, char special, va_list valist)
{
	int data_len, i, num, counter = 0;
	char *data_converted;
	char *new_buffer;
	int data;

	data = va_arg(valist, int);
	if (special == '%')
		data = '%';
	num = data;
	while ((num = num / 10))
		counter++;
	if (data < 0)
		counter = counter + 2;
	else
		counter = counter + 1;
	/*Obtains the number of digits in the data number +1 if possitive*/
	data_converted = malloc(counter * sizeof(char));
	if (data_converted == NULL)
		exit(0);
	data_converted = c_number_to_arr(data_converted, data);
	/*Converts number to string*/
	data_len = _strlen(data_converted);
	new_buffer = malloc((_strlen(buffer) + data_len - 2) * sizeof(char));
	if (new_buffer == NULL)
		exit(1);
    /*
     * Stores in the heap the characters necessary
     * to the modified buffer
     */
	for (i = 0; i < data_len; i++)
	{
		*(new_buffer + position + 1 + i) = *(data_converted + i);
    /*Saves in the exact position of the buffer the string replacing %d*/
	}
	put_in_place(new_buffer, buffer, position, data_len);
	/*
	 *Puts the beggining and the end of the original
	 *Buffer in the end buffer to sorround the data
	 */
	return (new_buffer);
}
