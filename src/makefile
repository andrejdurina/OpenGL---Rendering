all: submodule main

submodule:
		g++ -c ./res/particleSystem/particles.cpp
		g++ -c ./callbacks/callBacks.cpp

main:
		g++ -o main main.cpp ./res/particleSystem/mouse.cpp ./renderer/buffers/IndexBuffer.cpp ./renderer/buffers/VertexBuffer.cpp ./renderer/layout/VertexArray.cpp ./renderer/objects/GenerateObject.cpp  callBacks.o particles.o -lglut -lGLEW -lglfw -lGLU -lGL -lpthread -lX11 -lrt
		clear


clean:
		rm particles.o
		rm callBacks.o
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
