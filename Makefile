CC = g++
FILES = main.cpp
OUT_EXE = what_GPU
INCLUDES = -ld3d9 -ld3dcompiler -lgdi32 -static -static-libstdc++

build:$(FILES)
	$(CC) $(FILES) $(INCLUDES) -o $(OUT_EXE)
clean:
	rm -f *.o *.exe