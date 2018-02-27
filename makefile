rshell: main.cpp Command.cpp CommandExecute.cpp GetInput.cpp
	g++ -o rshell main.cpp Command.cpp CommandExecute.cpp GetInput.cpp -I.
	mkdir bin
	cp rshell bin

