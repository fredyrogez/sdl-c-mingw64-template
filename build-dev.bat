:: My Game Template - build-dev / MinGW-W64
windres ./src/my.rc my.o
gcc -g -std=gnu18 -O0 -Wall my.o ./src/*.c -o dist/game -I ./src/include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_net
if exist "my.o" (del my.o)
