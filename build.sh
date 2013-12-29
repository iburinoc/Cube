g++ -c -Wall cube.cpp
g++ -c -Wall cubesolver.cpp

g++ -o bin/cubesolver *.o

rm -rf *.o