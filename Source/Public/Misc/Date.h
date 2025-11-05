#pragma once

#include <iostream>

using namespace std;

class Date
{
    private:

    int Year;
    int Month;
    int Day;

    public:
    
    Date();
    Date(int InYear, int InMonth, int Day);

    int GetYear() const;
    void SetYear(int InYear);
    int GetMonth() const;
    void SetMonth(int InMonth);
    int GetDay() const;
    void SetDay(int InDay);

    bool IsValid() const;

    friend ostream& operator<<(ostream& os, const Date& InDate);
    friend istream& operator>>(istream& is, Date& OutDate);
};