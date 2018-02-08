makefile:
	objects = define.o hello.o common.o
	define: $(objects)
		gcc -o define$(objects)
	define.o: define.c hello.h common.h
		gcc -C define.c
	hello.o: hello.c hello.h
		gcc -C hello.c
	common.o: common.c common.h
		gcc -C common.c
	clean:
		rm define$(objects)
