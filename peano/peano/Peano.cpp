#include "Peano.h"

using namespace std;

Peano
zero(void)
{
    Peano p;
    p.peano[0] = '!';
    return p;
}

Peano
succ(const Peano p) throw(std::string)
{
    Peano s;
    int i;
    for(i = 0; p.peano[i] != '!'; i++)
        s.peano[i] = '*';

    s.peano[i] = '*';
    i++;
    if(i >= LGMAX)
        throw std::string("Overflow");
    s.peano[i] = '!';
    return s;
}

Peano
add(const Peano p, const Peano q) throw(std::string)
{
    Peano sum;
    int i;
    int j;

    for(i = 0; p.peano[i] != '!'; i++)
        sum.peano[i] = '*';
    for(j = 0; q.peano[j] != '!' && i < LGMAX; j++, i++)
        sum.peano[i] = '*';

    if(i >= LGMAX)
        throw std::string("Overflow");
    sum.peano[i] = '!';
    return sum;
}

Peano
mult(const Peano p, const Peano q) throw(std::string)
{
    Peano prod;
    int k = 0;

    for(int i = 0; k < (LGMAX - 1) && p.peano[i] != '!'; i++)
    {
        for(int j = 0; k < (LGMAX - 1) && q.peano[j] != '!'; j++, k++)
            prod.peano[k] = '*';
    }
    if(k == LGMAX-1)
        throw std::string("Overflow");
    prod.peano[k] = '!';
    return prod;
}

bool
operator==(const Peano p, const Peano q)
{
    int i = 0;
    while(p.peano[i] != '!' && q.peano[i] != '!')
        i++;
    return p.peano[i] == q.peano[i];
}

bool
inf(const Peano p, const Peano q)
{
    int i = 0;
    while(p.peano[i] == q.peano[i] && p.peano[i] != '!')
        i++;
    return p.peano[i] == '!' && q.peano[i] != '!';
}

void
displayPeano(const Peano p)
{
    int i = -1;
    do
    {
        i++;
        cout << p.peano[i];
    } while(p.peano[i] != '!');
    cout << endl;
}
