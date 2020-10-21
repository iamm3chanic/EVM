CC = wg++


ibfs: inode.o file_operation.o file_read_write.o Makefile
	$(CC)  -o ibfs inode.o file_operation.o file_read_write.o	
inode.o: inode.cpp inode.h Makefile
	$(CC)  -c inode.cpp
file_operation.o: file_operation.cpp inode.h Makefile
	$(CC)  -c file_operation.cpp
file_read_write.o: file_read_write.cpp inode.h Makefile
	$(CC)  -c file_read_write.cpp
clean:
	rm ibfs *.o vgcore*
