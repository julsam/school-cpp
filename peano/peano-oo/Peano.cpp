#include "Peano.h"


Peano::Peano()
{
    m_array[0] = '!';
}

void
Peano::succ() throw(std::string)
{
    int i;
    for (i = 0; m_array[i] != '!'; i++)
        m_array[i] = '*';

    m_array[i] = '*';
    i++;
    if (i >= LGMAX)
        throw std::string("Overflow");
    m_array[i] = '!';
}

Peano
Peano::operator=(const Peano &q)
{
    strcpy (m_array, q.m_array);
    return *this;
}

Peano
Peano::operator+(const Peano &q)
{
    Peano s;
    int i;
    for (i = 0; m_array[i] != '!'; i++)
        s.succ();
    for (int j = 0; q.m_array[j] != '!'; i++, j++)
        s.succ();

    return s;
}

Peano
Peano::operator*(const Peano &q)
{
    Peano s;
    int k = 0;

    for (int i = 0; k < (LGMAX - 1) && m_array[i] != '!'; i++)
    {
        for(int j = 0; k < (LGMAX - 1) && q.m_array[j] != '!'; j++, k++)
            s.succ();
    }

    return s;
}

bool
Peano::operator==(const Peano &q)
{
    int i = 0;
    while (m_array[i] != '!' && q.m_array[i] != '!')
        i++;
    return m_array[i] == q.m_array[i];
}

bool
Peano::operator<(const Peano &q)
{
    int i = 0;
    while (m_array[i] == q.m_array[i] && m_array[i] != '!')
        i++;
    return m_array[i] == '!' && q.m_array[i] != '!';
}

void
Peano::display(const Peano &p)
{
    int i = -1;
    do
    {
        i++;
        std::cout << p.m_array[i];
    } while (p.m_array[i] != '!');
    std::cout << std::endl;
}

