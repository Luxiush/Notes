quick_sort: quick_sort.o
	@g++ quick_sort.o -o quick_sort.exe

quick_sort.o: quick_sort.cpp
	@g++ -c quick_sort.cpp -o quick_sort.o
	
.PHONY: clean
clean:
	@del *.o
	@del *.exe
	
.PHONY: run
run:
	@quick_sort.exe quick_sort_in.txt quick_sort_out.txt