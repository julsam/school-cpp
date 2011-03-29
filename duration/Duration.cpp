#include "Duration.h"
#include <iostream>

using namespace std;

Duration::Duration()
    : m_hours(0),
      m_minutes(0),
      m_seconds(0)
{
}

Duration::Duration(const int h, const int m, const int s) throw(std::string)
{
    if (h < 0) throw std::string("hours >= 0");
    if (m < 0 || m > 59) throw std::string("0 <= minutes <= 59");
    if (s < 0 || s > 59) throw std::string("0 <= seconds <= 59");

    m_hours = h;
    m_minutes = m;
    m_seconds = s;
}

void
Duration::display(const std::string name)
{
    cout << name << " Duration(" << m_hours << ", " << m_minutes << ", " << m_seconds << ")\n";
}

int
Duration::getHours() const
{
    return m_hours;
}

int
Duration::getMinutes() const
{
    return m_minutes;
}

int
Duration::getSeconds() const
{
    return m_seconds;
}


bool
Duration::operator < (const Duration d)
{
    int h = d.getHours(), m = d.getMinutes(), s = d.getSeconds();
    if (m_hours < h)
        return true;
    else if (m_hours == h && m_minutes < m)
        return true;
    else if (m_hours == h
            && m_minutes == m
            && m_seconds < s)
        return true;
    else
        return false;
    /*
      // works but unreadable
    return ( (m_hours < d.getHours()) || 
            (m_hours == d.getHours() &&
            (m_minutes < d.getMinutes() || (m_minutes == d.getMinutes()) 
                                           && (m_seconds < d.getSeconds()))))
    */
}

bool
Duration::operator == (const Duration d)
{
    return ( m_hours == d.getHours()
            && m_minutes == d.getMinutes()
            && m_seconds == d.getSeconds() );
}

Duration
Duration::operator = (const Duration d)
{
    m_hours     = d.getHours();
    m_minutes   = d.getMinutes();
    m_seconds   = d.getSeconds();
    return *this;
}


void
Duration::addOneSecond()
{
    if (m_seconds != 59)
        m_seconds++;
    else
    {
        m_seconds = 0;
        if (m_minutes != 59)
            m_minutes++;
        else
        {
            m_minutes = 0;
            m_hours++;
        }
    }
}
