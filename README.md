# Conway's Game of life
C implementation of the Cellular automaton running in a terminal for Windows and Unix-like systems
# Build
`gcc life.c -o life`
# Run
### Windows: `life.exe`
### Unix: `./life`
#### Warning! The program can work incorrectly on Windows, because it was designed for Unix-like systems
# You can configure the game, but there are 2 rules:
- The configuration starts with the "//config" comment and ends with the "/functions and fields" comment
- The square root can be extracted from the size variable
