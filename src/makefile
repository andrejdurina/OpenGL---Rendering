all: submodule main

submodule:
		g++ -c ./res/particleSystem/particles.cpp
		g++ -c ./callbacks/callBacks.cpp
		g++ -c ./buffers/VertexBuffer.cpp
		g++ -c ./buffers/IndexBuffer.cpp
		g++ -c ./objects/GenerateObject.cpp
main:
		g++ -o main main.cpp ./res/particleSystem/mouse.cpp GenerateObject.o VertexBuffer.o IndexBuffer.o callBacks.o particles.o -lglut -lGLEW -lglfw -lGLU -lGL -lpthread -lX11 -lrt
		clear


clean:
		rm particles.o
		rm callBacks.o
		rm VertexBuffer.o
		rm IndexBuffer.o
		rm GenerateObject.o
		rm main
		clear

run:
		./main

monitor:
		wmctrl -r Test -e 0,0,0,3840,1080


particles:
		g++ -c ./res/particleSystem/particles.cpp


callbacks:
		g++ -c ./callbacks/callBacks.cpp
		
math:
		g++ -c ./math/math.cpp
