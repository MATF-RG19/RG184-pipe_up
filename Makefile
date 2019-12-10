pipe:
	g++ -o pipe_up.out *.cpp -g -Wall -std=c++11 -lglut -lGL -lGLU; ./pipe_up.out

.PHONY: clean

clean:
	rm pipe_up.out