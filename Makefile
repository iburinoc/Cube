CC=g++
FLAGS=-std=c++11 -g -O0

MOVEASSEMBLERTARGETS=assembler_test.o trie.o assembler.o cube.o

moveassembler: $(MOVEASSEMBLERTARGETS)
	$(CC) $(MOVEASSEMBLERTARGETS) -o movatest	

SOLUTIONTARGETS=solution.o solution_test.o cube.o assembler.o trie.o

solution: $(SOLUTIONTARGETS)
	$(CC) $(SOLUTIONTARGETS) -o soltest

.cpp.o:
	$(CC) -c $(FLAGS) $< -o $@

