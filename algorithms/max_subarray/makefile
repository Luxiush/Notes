max_subarray: max_subarray.o
	@g++ -o max_subarray max_subarray.o
	@echo Done.

max_subarray.o: max_subarray.cpp
	@g++ -o max_subarray.o -c max_subarray.cpp

run:
	@max_subarray.exe max_subarray_in.txt max_subarray_out.txt
	
clean:
	@del *.o
	@del *.exe