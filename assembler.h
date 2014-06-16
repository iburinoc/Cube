#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <string>

#include "trie.h"

//#define ASSEMBLER_DEBUG

/* The Trie structures representing high-level to low-level optimizer tries 
 * and low-level to low-level optimizer tries */
extern Trie hltrie;
extern Trie lltrie;

/* Constructs a radix trie from the file at the give filename
 * File must contain only lines of the following format:
 * key->value */
Trie construct_trie(const char* fname);

/* optimize a low-level moveset using the lltrie structure */
std::string opt_trie(std::string in);

/* assemble the given high-level move sequence using a set of
 * optimizations */
std::string assembler_O(std::string in);

/* assemble a sequence of high-level cube face rotations into
 * low-level robot instructions */
std::string assemble(std::string hlm);

#endif
