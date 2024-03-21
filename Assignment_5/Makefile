myint: driver.o myint.o
	g++ -o myint driver.o myint.o

driver.o: driver.cpp myint.h
	g++ -c driver.cpp

myint.o: myint.cpp myint.h
	g++ -c myint.cpp

clean:
	rm *.o myint
