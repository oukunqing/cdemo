cc = gcc
objects = main.o hello.o common.o config.o
helloworld: $(objects)
	cc -o helloworld $(objects)
	rm $(objects)
main.o: hello.h common.h
hello.o: hello.h
common.o: common.h
config.o: config.h
clear:
	rm $(objects)
clean:
	rm helloworld $(objects)
