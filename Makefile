all: uthash-test-cli.o HashTable_print.o HashTable_promptAdd.o HashTable_promptDelete.o HashTable_promptFind.o HashTable_free.o
	gcc -o uthash-test-cli uthash-test-cli.o HashTable_print.o HashTable_promptAdd.o HashTable_promptDelete.o HashTable_promptFind.o HashTable_free.o

uthash-test-cli.o: uthash.h HashTable.h uthash-test-cli.c
	gcc -c uthash-test-cli.c

HashTable_print.o: uthash.h HashTable.h HashTable_print.c
	gcc -c HashTable_print.c

HashTable_promptAdd.o: uthash.h HashTable.h HashTable_promptAdd.c
	gcc -c HashTable_promptAdd.c

HashTable_promptDelete.o: uthash.h HashTable.h HashTable_promptDelete.c
	gcc -c HashTable_promptDelete.c

HashTable_promptFind.o: uthash.h HashTable.h HashTable_promptFind.c
	gcc -c HashTable_promptFind.c

HashTable_free.o: uthash.h HashTable.h HashTable_free.c
	gcc -c HashTable_free.c

.PHONY: clean
clean:
	rm uthash-test-cli
	rm uthash-test-cli.o
	rm HashTable_print.o
	rm HashTable_promptAdd.o
	rm HashTable_promptDelete.o
	rm HashTable_promptFind.o
	rm HashTable_free.o
