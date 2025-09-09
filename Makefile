CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra

all: businessdb

businessdb: businessdb.o customer.o database.o
	$(CC) businessdb.o customer.o database.o -o businessdb

businessdb.o: businessdb.c database.h
	$(CC) $(CFLAGS) -c businessdb.c 

customer.o: customer.c customer.h
	$(CC) $(CFLAGS) -c customer.c 

database.o: database.c database.h customer.h
	$(CC) $(CFLAGS) -c database.c 

clean:
	rm -f businessdb businessdb_test
	rm -f *.o

format:
	clang-format -i -style=file *.[ch]