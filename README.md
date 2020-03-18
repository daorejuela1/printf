
# 0x11. C - printf
## List of mandatory requirements
![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)
###### Have you ever dreamed on creating your own standar library function.
well in this case we are creating our homemade printf function with the following requirements


![Build Status](https://i.ibb.co/FxRfqr4/Printf-General-Logic-Flowchart-p-ginas-eliminadas-1-1.jpg)
## List of mandatory requirements

int _printf(const char *format, ...);

 - [x] Write output to stdout, the standard output stream.
 
 - [x] _printf: will print any special character if is preceded by a backslash ex: \”, \\,
 
 - [x] _printf: when you add a backslash then they become special: ex: \n, \a, \i
 
 - [x] Returns: the number of characters printed (excluding the null
       byte
           used to end output to strings).
 - [x] _printf: can take any number of arguments.

Read conversion specifiers when finds a %: 
: *%c    *%s    *%d    *%i

# Use Example
1. create a main.c, for example:

/* Main file to test specifiers*/ 

	

    /*Test function for save_c, save_s, save_d, and save_i 
	Thanks to [Juan Olivares Padilla] MED 
    functions */ 
    int main(void)
    {   unsigned int ui;
        int len;
        int len2;
        ui = (unsigned int)INT_MAX;
        len = _printf("asd%dasd %i, %d %i %d %c %s\n", ui, -42323, -999*9, 4444, 5, 'A', "Holberton");
        len2 = printf("asd%dasd %i, %d %i %d %c %s\n", ui, -42323, -999*9, 4444, 5, 'A', "Holberton");
        _printf("Length:[%d, %i]\n", len, len);
        printf("Length:[%d, %i]\n", len2, len2);
    }


> git clone https://github.com/nickarshadi/printf.git &
> cd printf &
> gcc -Wall -Werror -Wextra -pedantic *.c

to execute:

> ./a.out

# ToDo

 - [ ] Fix edge cases for printf("Hello %); 
 - [ ] Create an integer test file
