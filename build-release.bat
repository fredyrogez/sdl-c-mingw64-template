:: My Game Template - build-release / MinGW-W64
windres ./src/my.rc my.o
gcc -mwindows -std=gnu18 -O3 my.o ./src/*.c -o dist/game -I ./src/include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_net
if exist "my.o" (del my.o)
