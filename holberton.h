#ifndef HOLBERTON_H
#define HOLBERTON_H
/**
 * strukt Struktur - Struktur fuer special characters
 * @sp: special characters
 * @f: function make action for special characters
 */
typedef struct Struktur1   /*struktur special characters*/
{
	char *sp;
	void (*f)(char *string);
} struktur1;
typedef struct Struktur2
{
	char *fo;
	void (*f)(char *string);
} struktur2;

int _putchar(char c);

#endif
