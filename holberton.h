#ifndef HOLBERTON_H
#define HOLBERTON_H

char * save_d (char * buffer, int position, int data);
char * save_c (char * buffer, int position, char data);
char * save_s (char * buffer, int position, char * data);
void put_in_place(char * new_buffer, char * buffer, int position, int data_len);
void _strncpy(char *dest, char *src, int init, int end, int data_len);
int _strlen(char *s);
char * c_number_to_arr(char * array_data, int n);
unsigned int cal_digits(unsigned int n);
int _putchar(char c);
int _printf(const char *format, ...);

#endif
