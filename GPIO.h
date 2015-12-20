#ifndef GPIO_H
#define GPIO_H

#include <iostream>
#include <string>

using namespace std;

class GPIO{
    private:
        int pin;


    public:
        GPIO();
        GPIO(int pin);

        int getPin();
        void setPin(int pin);

        void output(int pin);
        void HIGH(string pin);

        bool value(string pin);

        void direction(string pin, string dir);

};


#endif
