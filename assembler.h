#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <string>

/* hl->hl */
std::string remove_undos_hl(std::string moves);

/* ll->ll */
std::string remove_undos_ll(std::string moves);

/* hl->hl & ll->ll */
std::string remove_fours(std::string moves);

/* hl -> ll */
std::string assemble(std::string hlm);

#endif
