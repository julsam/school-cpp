#ifndef _PEANO_H
#define _PEANO_H

#include <iostream>
#include <string.h>
#include <vector>

const int LGMAX = 10000;
class Peano
{
public:
    Peano();
    void succ() throw(std::string);
    Peano operator=(const Peano &q);
    Peano operator+(const Peano &q);
    Peano operator*(const Peano &q);
    bool operator==(const Peano &q);
    bool operator<(const Peano &q);
    static void display(const Peano &p);

private:
    char m_array[LGMAX];
};
#endif // _PEANO_H

