#ifndef _PEANO_H
#define _PEANO_H

#include <iostream>
#include <string.h>

const int LGMAX = 10000;
struct Peano
{
    char peano[LGMAX];
};

Peano zero(void);
Peano succ(const Peano p) throw(std::string);
Peano add(const Peano p, const Peano q) throw(std::string);
Peano mult(const Peano p, const Peano q) throw(std::string);
bool operator==(const Peano p, const Peano q);
bool inf(const Peano p, const Peano q);
void displayPeano(const Peano p);

#endif // _PEANO_H

