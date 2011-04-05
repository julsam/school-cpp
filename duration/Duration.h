#ifndef _DURATION_H
#define _DURATION_H

#include <string>

class Duration
{
public:
    Duration();
    Duration(const int h, const int m=0, const int s=0) throw(std::string);
    Duration(const Duration& d);

    void display(const std::string name="");

    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;

    Duration operator = (const Duration& d);
    bool operator < (const Duration& d);
    bool operator == (const Duration& d);

    void addOneSecond();
    static Duration addOneSecond(const Duration& d);

private:
    int m_hours;
    int m_minutes;
    int m_seconds;
};

#endif // _DURATION_H

