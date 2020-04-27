CC = g++

kth_most_frequent: kth_most_frequent.o
	$(CC) -o kth_most_frequent kth_most_frequent.o

kth_most_frequent.o: kth_most_frequent.cpp
	$(CC) -std=c++11 -c kth_most_frequent.cpp

check:
	./kth_most_frequent

clean:
	rm kth_most_frequent *.o
