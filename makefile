rshell: main.cpp Command.cpp CommandExecute.cpp GetInput.cpp BaseExecute.cpp
	g++ -o rshell main.cpp Command.cpp CommandExecute.cpp GetInput.cpp BaseExecute.cpp -I.
	mkdir bin
	cp rshell bin

