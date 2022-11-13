CC := g++
CFLAGS := -I/opt/opengl/include
LDFLAGS := -L/opt/opengl/lib/x86_64-linux-gnu -lglad -lglfw -ldl

all: triangle triangle_chroma triangle_color triangle_two rectangle test

triangle: prepare
	$(CC) -o out/triangle triangle.cpp $(CFLAGS) $(LDFLAGS)

triangle_chroma: prepare
	$(CC) -o out/triangle_chroma triangle_chroma.cpp $(CFLAGS) $(LDFLAGS)

triangle_color: prepare
	$(CC) -o out/triangle_color triangle_color.cpp $(CFLAGS) $(LDFLAGS)

triangle_two: prepare
	$(CC) -o out/triangle_two triangle_two.cpp $(CFLAGS) $(LDFLAGS)

triangle_main: prepare
	$(CC) -o out/triangle_main triangle_main.cpp $(CFLAGS) $(LDFLAGS)

rectangle: prepare
	$(CC) -o out/rectangle rectangle.cpp $(CFLAGS) $(LDFLAGS)

test: prepare
	$(CC) -o out/test test.cpp $(CFLAGS) $(LDFLAGS)

prepare:
	mkdir -p out

clean:
	rm -rf out
