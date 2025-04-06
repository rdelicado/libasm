rdelicad: @workspace  vas a revisar mi proyecto y me vas a crear un README.md para el github que explique de que trata este proyecto y como compilarlo y realizar el test

Workspace: Recopilando información del área de trabajo```markdown
# libasm

Este proyecto implementa versiones en ensamblador de funciones básicas de la biblioteca estándar de C. Las funciones implementadas son:

- `ft_strlen`: Calcula la longitud de una cadena.
- `ft_strcmp`: Compara dos cadenas.
- `ft_strcpy`: Copia una cadena.
- `ft_write`: Escribe datos en un descriptor de archivo.
- `ft_read`: Lee datos de un descriptor de archivo.
- `ft_strdup`: Duplica una cadena.

Las funciones se encuentran en el directorio [`src`](src) y se prueban mediante diversos tests en el directorio [`unitest`](unitest).

## Estructura del proyecto

```
Makefile
includes/
    libasm.h
    test_utils.h
obj/
src/
    ft_read.s
    ft_strcmp.s
    ft_strcpy.s
    ft_strdup.s
    ft_strlen.s
    ft_write.s
unitest/
    main.c
    test_read.c
    test_strcmp.c
    test_strcpy.c
    test_strdup.c
    test_strlen.c
    test_utils.c
    test_write.c
```

## Cómo compilar

Para compilar la librería en ensamblador y generar el archivo `libasm.a` ejecuta:

```sh
make
```

## Ejecutar los tests

Primero, asegúrate de compilar la librería. Luego, para compilar el ejecutable de tests y enlazarlo con la librería, ejecuta:

```sh
make test
```

Esto generará un ejecutable llamado `test`. Puedes correrlo con:

```sh
./test
```

## Limpieza

Para eliminar los archivos objeto y el ejecutable de tests, utiliza:

```sh
make clean
```

Para eliminar además la librería `libasm.a`, ejecuta:

```sh
make fclean
```

## Comentarios adicionales

- El proyecto utiliza el ensamblador NASM con los flags `-f elf64 -g -F dwarf` para la compilación de los archivos `.s`.
- La función `ft_write` (ver [src/ft_write.s](src/ft_write.s)) realiza una llamada al sistema para escribir los datos y gestiona los errores mediante `errno`.
- Los tests están escritos en C y se encuentran en el directorio [`unitest`](unitest).

Disfruta explorando y modificando este proyecto.
```

rdelicad: puedes crearme el README.md en ingles

GitHub Copilot: ```markdown
# libasm

This project implements assembly versions of some basic functions from the C standard library. The provided functions are:

- `ft_strlen`: Calculates the length of a string.
- `ft_strcmp`: Compares two strings.
- `ft_strcpy`: Copies a string.
- `ft_write`: Writes up to `count` bytes from a buffer to a file descriptor.
- `ft_read`: Reads up to `count` bytes from a file descriptor into a buffer.
- `ft_strdup`: Duplicates a string.

The assembly functions are written in NASM and are located in the [`src`](src) directory, while the tests (written in C) are located in the [`unitest`](unitest) directory.

## Project Structure

```
Makefile
includes/
    ├── libasm.h
    └── test_utils.h
obj/
src/
    ├── ft_read.s
    ├── ft_strcmp.s
    ├── ft_strcpy.s
    ├── ft_strdup.s
    ├── ft_strlen.s
    └── ft_write.s
unitest/
    ├── main.c
    ├── test_read.c
    ├── test_strcmp.c
    ├── test_strcpy.c
    ├── test_strdup.c
    ├── test_strlen.c
    ├── test_utils.c
    └── test_write.c
```

## How to Compile

To compile the assembly library and generate `libasm.a`, run:

```sh
make
```

## Running the Tests

First, ensure you have compiled the library. Then compile the test executable and link it with the library by running:

```sh
make test
```

This will create an executable named `test`. Run it with:

```sh
./test
```

## Cleaning the Build

To remove the object files and the test executable, run:

```sh
make clean
```

To remove the library `libasm.a` as well, run:

```sh
make fclean
```

## Additional Notes

- The project uses NASM with flags such as `-f elf64`, `-g`, and `-F dwarf` for compiling the assembly files.
- The `ft_write` function (see [src/ft_write.s](src/ft_write.s)) demonstrates how to use system calls in assembly and includes error handling by setting `errno` appropriately.
- The tests are written in C and verify the correct behavior of each assembly function.

Enjoy exploring and enhancing the project!
```