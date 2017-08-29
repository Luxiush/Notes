src = counting_sort
main: main.o
	@g++ -o main main.o 

main.o: $(src).cpp 
	@g++ -o main.o -c $(src).cpp 

.PHONY: clean
clean:
	@del *.o
	@del *.exe

.PHONY: run
run:
	@main.exe ../input.txt $(src)_output.txt