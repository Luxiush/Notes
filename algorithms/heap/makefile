heapsort: main.o
	@g++ -o heapsort main.o

main.o: main.cpp 
	@g++ -o main.o -c main.cpp 

.PHONY: clean
clean:
	@del *.o
	@del *.exe

run:
	@heapsort.exe heapsort_in.txt heapsort_out.txt