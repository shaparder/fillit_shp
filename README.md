# fillit @ 42
Can you feel it?


After finishing [libft](https://github.com/shaparder/libft_shp), fillit is the
third mandatory project after [get_next_line](https://github.com/shaparder/get_next_line_shp).
The purpose is to make the smallest possible "square" (which can contain holes)
with a given list of tetriminos, but the disposition must be as such that it returns the first
possible solution when placing them recursively from the top left.

## Compiling
Run `make`, an executable called `fillit` should compile directly. Please submit
an issue if you run into any.

## Usage
`./fillit [file]`

Example:
```
~ ./fillit samples/test_8

.AABB..
AACCB..
.CC.BDD
.EE.DD.
EEFFGG.
.FFGGHH
....HH.
```
