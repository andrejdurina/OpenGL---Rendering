all: submodule main

submodule:
		g++ -c ./res/particleSystem/ParticleSystem.cpp
		g++ -c ./callbacks/callBacks.cpp

main:
		g++ -o main main.cpp ./res/Random.cpp ./res/particleSystem/Mouse.cpp ./renderer/buffers/IndexBuffer.cpp ./renderer/buffers/VertexBuffer.cpp ./renderer/layout/VertexArray.cpp ./renderer/objects/Shape.cpp ./renderer/texture/Texture.cpp ./renderer/Renderer.cpp callBacks.o ParticleSystem.o -lglut -lGLEW -lglfw -lGLU -lGL -lpthread -lX11 -lrt
		clear

clean:
		rm ParticleSystem.o
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
