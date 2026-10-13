sender: sender.o
	g++ sender.o -o sender $(shell pkg-config --libs opencv4)

sender.o: sender.cpp
	g++ -c sender.cpp -o sender.o $(shell pkg-config --cflags opencv4)

receiver.o: receiver.cpp
	g++ -c receiver.cpp -o receiver.o 

clean:
	rm -f *.o