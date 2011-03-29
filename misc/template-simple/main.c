#include <iostream>

using namespace std;

template<class T>
void permute(T &a, T&b);

int main()
{
    int x = 5, y = 8;
    float z = 2.5, t = 8.5;

    cout << "x = " << x << " y = " << y << endl;
    cout << "z = " << z << " t = " << t << endl;

    permute(x, y);
    permute(z, t);

    cout << "x = " << x << " y = " << y << endl;
    cout << "z = " << z << " t = " << t << endl;

    return 0;
}

template <class T>
void permute(T &a, T &b)
{
    T c;
    c = a;
    a = b;
    b = c;
}
