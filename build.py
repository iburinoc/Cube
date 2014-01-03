#! /usr/bin/python

import os
import sys

valid = []

o = '-O3 ' if len(sys.argv) >= 2 and sys.argv[1] == '-O' else ''

for root, dirs, filenames in os.walk('./'):
    for f in filenames:
        if(f[f.find('.'):] == '.cpp' and (len(f) < 8 or f[f.find('.') - 4: f.find('.')] != 'test')):
            print f
            #valid.append(f)
            os.system('g++ -c -Wall ' + o + '-o bin/' + f + '.o ' + f)
            print 'g++ -c -Wall ' + o + '-o bin/' + f + '.o ' + f
#g++ -c -Wall cube.cpp
#g++ -c -Wall cubesolver.cpp

os.system('g++ ' + o + '-o bin/cubesolver bin/*.o')
print 'g++ ' + o + '-o bin/cubesolver bin/*.o'

#rm -rf *.o
