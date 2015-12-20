#include <iostream>
#include "GPIO.h"
#include <fstream>

using namespace std;

/*
 *
 *GPIO Class
 *
 */
GPIO::GPIO(int pin)
{
    this->pin = pin;
    cout << "[SYSTEM] GPIO object created." << endl;
}

/*
 *
 *Returns the GPIO pin number.
 *
 */
int GPIO::getPin()
{
    return pin;
}

void GPIO::setPin(int pin)
{
    this->pin = pin;
}

void GPIO::output(int pin)
{
    ofstream out;
    string file = "/sys/class/gpio/export";
    out.open("/sys/class/gpio/export");

    if(out.fail())
    {
        cout << "[SYSTEM] Failed to open " + file << endl;
    }

    out << pin << endl;

    cout << "[SYSTEM] Succesfully wrote to " + file << endl;

}

void GPIO::HIGH(string pin)
{
    string pin_number = pin;

    ofstream out;
    string file = "/sys/class/gpio/gpio" + pin_number + "/value";

    out.open(file.c_str());

    if(out.fail())
    {
        cout << "[SYSTEM] Failed to open " + file << endl;
    }

    cout << "[SYSTEM] Succesfully wrote to " + file << endl;

    out << 1 << endl;

}

bool GPIO::value(string pin)
{
    string pin_number = pin;
    ifstream in;

    string file = "/sys/class/gpio/gpio" + pin_number + "/value";

    if(in.fail())
    {
        cout << "[SYSTEM] Failed to read from " + file << endl;
    }

    unsigned value;
    in >> value;

    cout << value << endl;

    if(value)
    {
        return true;
    } else
    {
        return false;
    }

}

void GPIO::direction(string pin, string dir)
{
    ofstream out;
    string file = "/sys/class/gpio/gpio" + pin + "/direction";

    if(out.fail())
    {
        cout << "[SYSTEM] Failed to write to file " << endl;
    }



    out << dir << endl;
    out.close();

    cout << "[SYSTEM] Succesfully wrote to " + file << endl;


}


