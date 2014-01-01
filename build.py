#! /usr/bin/python

import os

valid = []

for root, dirs, filenames in os.walk('./'):
    for f in filenames:
        if(f[f.find('.'):] == '.cpp' and (len(f) < 8 or f[f.find('.') - 4: f.find('.')] != 'test')):
            print f
            #valid.append(f)
            os.system('g++ -c -Wall -o bin/' + f + '.o ' + f)
            print 'g++ -c -Wall -o bin/' + f + '.o ' + f
#g++ -c -Wall cube.cpp
#g++ -c -Wall cubesolver.cpp

os.system('g++ -o bin/cubesolver bin/*.o')
print 'g++ -o bin/cubesolver bin/*.o'

#rm -rf *.o
