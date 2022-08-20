all: hello_window

hello_window: prepare
	g++ -o out/hello_window hello_window.cpp -I/opt/opengl/include -L/opt/opengl/lib/x86_64-linux-gnu -lglad -lglfw -ldl

prepare:
	mkdir -p out

clean:
	rm -rf out
