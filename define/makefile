cc = gcc
objects = main.o hello.o common.o config.o
hello: $(objects)
	cc -o hello $(objects)
	rm $(objects)
	./hello
main.o: hello.h common.h
hello.o: hello.h
common.o: common.h
config.o: config.h
clear:
	rm $(objects)
clean:
	rm hello $(objects)
