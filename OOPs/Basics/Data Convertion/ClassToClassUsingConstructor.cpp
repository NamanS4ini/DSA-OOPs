#include <iostream>
using namespace std;
class Time24
{
public:
    int hours;
    int minutes;

private:
    void normalize()
    {
        if (minutes < 0)
        {
            hours -= (-minutes + 59) / 60;
            minutes = (minutes % 60 + 60) % 60;
        }
        if (hours < 0)
            hours = 0;

        if (minutes >= 60)
        {
            hours += minutes / 60;
            minutes %= 60;
        }
        if (hours >= 24)
            hours %= 24;
    }

public:
    Time24()
    {
        hours = 0;
        minutes = 0;
    }
    Time24(int t)
    {
        hours = t / 60;
        minutes = t % 60;
    }
    Time24(int hours, int minutes)
    {
        this->hours = hours;
        this->minutes = minutes;
        normalize();
    }
    void displayTime()
    {
        hours < 10 ? cout << "0" << hours << ":" : cout << hours << ":";
        minutes < 10 ? cout << "0" << minutes << "\n" : cout << minutes << "\n";
    }
    void addTime(int hours)
    {
        addTime(hours, 0);
    }
    void addTime(int hours, int minutes)
    {
        this->hours += hours;
        this->minutes += minutes;
        normalize();
    }
};
class Time12
{
public:
    int hours;
    int minutes;

private:
    void normalize()
    {
        if (minutes < 0)
        {
            hours -= (-minutes + 59) / 60;
            minutes = (minutes % 60 + 60) % 60;
        }
        if (hours < 0)
            hours = 0;

        if (minutes >= 60)
        {
            hours += minutes / 60;
            minutes %= 60;
        }
        if (hours >= 12)
            hours %= 12;
    }

public:
    Time12()
    {
        hours = 0;
        minutes = 0;
    }
    Time12(int t)
    {
        hours = t / 60;
        minutes = t % 60;
    }
    Time12(int hours, int minutes)
    {
        this->hours = hours;
        this->minutes = minutes;
        normalize();
    }
    // Method 1 using constructor
    Time12(Time24 t)
    {
        this->hours = t.hours;
        this->minutes = t.minutes;
        normalize();
    }
    void displayTime()
    {
        hours < 10 ? cout << "0" << hours << ":" : cout << hours << ":";
        minutes < 10 ? cout << "0" << minutes << "\n" : cout << minutes << "\n";
    }
    void addTime(int hours)
    {
        addTime(hours, 0);
    }
    void addTime(int hours, int minutes)
    {
        this->hours += hours;
        this->minutes += minutes;
        normalize();
    }
};

int main()
{
    // Uses Constructor to convert Time24 to Time12
    Time24 t1(23,11);
    Time12 t2 = t1;
    t2.displayTime();
}