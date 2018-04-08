cc = gcc

objects = main.o hello.o common.o config.o

helloworld.exe: $(objects) 
	$(cc) -o helloworld.exe $(objects)
	del *.o
  
main.o: main.c hello.h common.h
	$(cc) -c main.c
  
hello.o: hello.c hello.h  
	$(cc) -c hello.c

common.o: common.c common.h
	$(cc) -c common.c
    
config.o: config.c config.h
	$(cc) -c config.c