# FDF - Wireframe Model

![42](https://raw.githubusercontent.com/ararrojas/fun/main/42.png?token=GHSAT0AAAAAACXNQ5TJQK7K3IGFGLQDFXWGZXFR6CA)

This project involves creating a wireframe model of a 3D landscape where all surfaces are outlined in lines. The program reads coordinates from a `.fdf` file and renders the landscape in isometric projection using the MiniLibX library.

### Program Name

- `fdf`

### Files

- `Makefile`
- `*.h` files
- `*.c` files

### Makefile Rules

- `NAME`
- `all`
- `clean`
- `fclean`
- `re`

### Arguments

- A file in the format `*.fdf`

### Authorized Libraries

- `Libft`

## Description

The project requires creating a wireframe model of a landscape by linking various 3D points (x, y, z) with line segments (edges). For this program i used:

1. MiniLibX for graphical operations.
2. Include a Makefile that compiles the source files without relinking.

## Rendering

- The program must render the model in isometric projection.
- The landscape coordinates are stored in a `.fdf` file passed as a parameter to your program.

## Execution

To render the landscape using the example file `42.fdf`:

```bash
$> make
$> ./fdf maps/test_maps/*choose a map*
```
