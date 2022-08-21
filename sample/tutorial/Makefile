CC := g++
CFLAGS := -I/opt/opengl/include
LDFLAGS := -L/opt/opengl/lib/x86_64-linux-gnu -lglad -lglfw -ldl

all: hello_window

hello_window: prepare
	$(CC) -o out/triangle triangle.cpp $(CFLAGS) $(LDFLAGS)

prepare:
	mkdir -p out

clean:
	rm -rf out
