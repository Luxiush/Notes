src = randomized_select
$(src): main.o
	@g++ -o $(src) main.o 

main.o: $(src).cpp 
	@g++ -o main.o -c $(src).cpp 

.PHONY: clean
clean:
	@del *.o
	@del *.exe

.PHONY: run
run:
	@$(src) quick_sort_in.txt $(src)_output.txt