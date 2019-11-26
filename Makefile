pipe:
	g++ -o pipe_up.out main.cpp -g -Wall -std=c++11 -lglut -lGL -lglut

.PHONY: clean

clean:
	rm pipe_up.out