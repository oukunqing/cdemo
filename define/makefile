objects = main.o hello.o common.o
helloworld.out: $(objects)
	gcc -o helloworld.out $(objects)
	rm $(objects)
main.o: hello.h common.h
hello.o: hello.h
common.o: common.h
clear:
	rm $(objects)
clean:
	rm helloworld.out $(objects)
