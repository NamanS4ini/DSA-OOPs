#include <iostream>
using namespace std;
class Time
{
private:
    int hours;
    int minutes;
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
    Time()
    {
        hours = 0;
        minutes = 0;
    }
    Time(int hours, int minutes)
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
    Time operator+(const Time &t) const
    {
        Time temp(this->hours, this->minutes);
        temp.addTime(t.hours, t.minutes);
        return temp;
    }
    Time operator-(const Time &t) const
    {
        Time temp(this->hours, this->minutes);
        temp.addTime(-t.hours, -t.minutes);
        return temp;
    }
};

int main()
{
    Time t1(10, 15);
    t1.displayTime();
    Time t2(5, 45);
    t2.displayTime();
    Time t3 = t1 - t2;
    t3.displayTime();
}
