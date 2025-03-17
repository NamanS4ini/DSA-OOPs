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
    Time(int t)
    {
        hours = t / 60;
        minutes = t % 60;
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
    operator int(){
        return (hours*60) + minutes;
    }
    operator string(){
        return "Time is good";
    }
};

int main()
{
    //Primitive to user defined

    int dur = 77;
    Time t1= dur;
    t1.displayTime();

    // class obj to user defined
    Time t2(12,12);
    int duration = t2;
    string quote = t2;
    cout<< duration << quote;

}
