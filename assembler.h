#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <string>

#include "trie.h"

//#define ASSEMBLER_DEBUG

extern Trie hltrie;
extern Trie lltrie;

Trie construct_trie(const char* fname);

std::string opt_trie(std::string in);

/* hl -> ll */
std::string assembler_O(std::string in);

/* hl -> ll */
std::string assemble(std::string hlm);

#endif
