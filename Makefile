sender.o: sender.cpp
	g++ -c sender.cpp -o sender.o $(pkg-config --cflags opencv4)

receiver.o: receiver.cpp
	g++ -c receiver.cpp -o receiver.o 

clean:
	rm -f *.o