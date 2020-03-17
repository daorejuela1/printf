#include "holberton.h"
#include <stdlib.h>
/**
 *save_c - saves a character in a new buffer using the position flag
 *@buffer: input array to copy from
 *@position: position where the new character should be implemented
 *@data: Character that wants to be copy
 *Return: destiny array
 */
char *save_c(char *buffer, int position, char data)
{
	int data_len;
	char *new_buffer;

	data_len = 1;
	new_buffer = malloc((_strlen(buffer) - data_len) * sizeof(char));
	if (new_buffer == NULL)
		exit(1);
/*Stores in the heap the characters necessary to the modified buffer*/
	*(new_buffer + position + 1) = data;
/*Saves in the exact position of the buffer the character replacing %c*/
	put_in_place(new_buffer, buffer, position, data_len);
/*
 *puts the beggining and the end of the original buffer
 *in the end buffer to sorround the data
 */
	free(buffer);
	return (new_buffer);
}

/**
 *save_s - saves a String in a new buffer using the position flag
 *@buffer: input array to copy from
 *@position: position where the new character should be implemented
 *@data: String that wants to be copy
 *Return: destiny array
 */
char *save_s(char *buffer, int position, char *data)
{
	int data_len, i;
	char *new_buffer;

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
	free(buffer);
	return (new_buffer);
}

/**
 *save_d - saves a String in a new buffer using the position flag
 * taking as input an integer
 *@buffer: input array to copy from
 *@position: position where the new character should be implemented
 *@data: String that wants to be copy
 *Return: destiny array
 */
char *save_d(char *buffer, int position, int data)
{
	int data_len, i, num, counter = 0;
	char *data_converted;
	char *new_buffer;

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
	 *puts the beggining and the end of the original
	 *buffer in the end buffer to sorround the data
	 */
	free(data_converted);
	free(buffer);
	return (new_buffer);
}
