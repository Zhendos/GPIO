#include <iostream>
#include "GPIO.h"

#include <unistd.h>

using namespace std;

int main()
{
    GPIO gpio(24);
    gpio.output(24);

    gpio.direction("24", "out");

    sleep(1);


    cout << gpio.getPin() << endl;

    //71760

    return 0;
}
