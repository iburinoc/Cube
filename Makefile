CC=g++
FLAGS=-std=c++11 -g -O3

MOVEASSEMBLERTARGETS=assembler_test.o trie.o assembler.o cube.o

.PHONY=moveassembler solution cv clean

moveassembler: $(MOVEASSEMBLERTARGETS)
	$(CC) $(MOVEASSEMBLERTARGETS) -o movatest	

SOLUTIONTARGETS=solution.o solution_test.o cube.o assembler.o trie.o

solution: $(SOLUTIONTARGETS)
	$(CC) $(SOLUTIONTARGETS) -o soltest

CVTARGETS=cubegui_test.o cubegui.o guiutil.o imganalyse.o cube.o serial.o
CVLIBS=-lopencv_core -lopencv_highgui -lopencv_imgproc

cv: $(CVTARGETS)
	$(CC) $(CVTARGETS) $(CVLIBS) -o cvtest

MINISOLVERTARGETS=minicubesolver.o cube.o trie.o assembler.o solution.o serial.o

minisolver: $(MINISOLVERTARGETS)
	$(CC) $(MINISOLVERTARGETS) -o minisolver

.cpp.o:
	$(CC) -c $(FLAGS) $< -o $@

clean:
	rm *.o

