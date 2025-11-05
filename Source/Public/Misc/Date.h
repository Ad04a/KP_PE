#pragma once

class Date
{
    private:

    int Year;
    int Month;
    int Day;

    public:
    
    Date();
    Date(int InYear, int InMonth, int Day);

    bool IsValid();
};