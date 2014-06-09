CC=g++
FLAGS=-std=c++11 -g -O0

MOVEASSEMBLERTARGETS=assembler_test.o trie.o assembler.o cube.o

moveassembler: $(MOVEASSEMBLERTARGETS)
	$(CC) $(MOVEASSEMBLERTARGETS) -o movatest	

.cpp.o:
	$(CC) -c $(FLAGS) $< -o $@

