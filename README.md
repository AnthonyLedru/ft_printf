# ft_printf
This project is a copy of the original printf function of C langage.

## Features

My ft_printf supports the following options:

Type|Name|
:-:|:-:
<kbd>Flags</kbd>|Change the color to red
<kbd>2</kbd>|Change the color to green
<kbd>3</kbd>|Change the color to blue
<kbd>4</kbd>|Change the color to yellow
<kbd>5</kbd>|Change the color to gray
<kbd>6</kbd>|Change the color to cyan
<kbd>7</kbd>|Change the color to purple
<kbd>Mouse Wheel</kbd>|Zoom on fractal
<kbd>^</kbd><br><kbd><</kbd><kbd>v</kbd><kbd>></kbd>|Move the fractal (X, Y)
<kbd>+</kbd> <kbd>-</kbd>|Change the iteration rate
<kbd>M</kbd>|Disable the mouse movement on Julia
<kbd>ESC</kbd>|Quit the program

## Compilation

Run `make` command to compile the libftprintf library.

## Usage

Compile your project with libftprintf.a.
Don't forget to include "ft_printf.h"

To compile with the repository main:
```
gcc -Wall -Werror -Wextra main.c libftprintf.a -Iincludes/
```

## Subject 
 
https://github.com/AnthonyLedru/ft_printf/blob/master/ft_printf.pdf
