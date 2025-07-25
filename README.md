
# C - printf

A simplified reimplementation of the ```printf``` function in C.


## Features

This project is a reimplementation of the ```printf``` function in C.
Our current implementation, ```_printf``` supports the following format specifiers:

```_printf```
- ```%c```: Print a single character
- ```%s```: Print a string
- ```%d```: Print an integer
- ```%i```: Print an integer
- ```%%```: Print a literal percent sign


## Requirements

To run this project, you will need:

- Ubuntu 20.x LTS
- GCC (GNU Compiler Collection)
- Git for cloning the repository and version management

## Installation

#### 1. Clone the repository

```bash
  git clone https://github.com/FrancesMP/holbertonschool-printf.git
  cd holbertonschool-printf
```

#### 2. Create your own branch and push it

```bash
  git checkout -b branch_name
  git push --set-upstream origin branch_name
``` 

#### 3. Compile

```bash
   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c
``` 


## Testing ```_printf```

To test the functionality of ```_printf``` and compare its output with the standard ```printf```, after compiling you can run the following test program:

```bash
    ./file_name
```

#### The test program

```
#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    return (0);
}
```
#### Expected Output
##### Once running the program the output should be like this
``` 
Let's try to printf a simple sentence.
Let's try to printf a simple sentence.
Length:[39, 39]
Length:[39, 39]
Negative:[-762534]
Negative:[-762534]
Character:[H]
Character:[H]
String:[I am a string !]
String:[I am a string !]
Percent:[%]
Percent:[%]
Len:[12]
Len:[12] 
```


## ```man``` _printf

A detailed manual page for _printf is available to provide comprehensive information on its usage, arguments, and return values.

``` man_3_printf```
## Flowchart

![App Screenshot](https://via.placeholder.com/468x300?text=App+Screenshot+Here)


## Authors

- [Frances](https://github.com/FrancesMP)
- [Sedra](https://github.com/SedraR78)
- [Rebecca](https://github.com/SG1-Rebecca)


## License
This project is licensed under the MIT License - see the [LICENSE](https://choosealicense.com/licenses/mit/) file for details.


