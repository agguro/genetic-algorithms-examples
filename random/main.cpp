/*
 *  project: genetic algorithms examples
 *  description: because of the need of a random generator for different types I defined
 *  a function that returns a number of type T.
 *  The main routine shows the use of it demonstrates the use of a typed pseudo random generator.
 *  This program should not be used for short int and short unsigned int.  The variation of generated numbers
 *  isn't spreaded enough.
*/

#include <time.h>
#include <iostream>
#include <math.h>
#include <limits.h>
#include <string>
#include <typeinfo>

using namespace std;

template <typename T>
T getRandom (T minimum, T maximum)
{
    if(minimum > maximum)
    {
        T dummy = minimum;
        minimum = maximum;
        maximum = dummy;
    }

    T result;

    if(typeid (T).name() == typeid (unsigned short int).name())
    {
        unsigned short int r = minimum + (unsigned short int)(rand()) / ((unsigned short int)USHRT_MAX / (maximum - minimum));
        result = r;
    }else
    {
        if(typeid (T).name() == typeid (signed short int).name())
        {
            signed short int r = minimum + (signed short int)(rand()) / ((signed short int)SHRT_MAX / (maximum - minimum));
            result = r;
        }
        else
        {
            if(typeid (T).name() == typeid (unsigned int).name())
            {
                //avoid implicit conversion warning/errors
                unsigned int m = UINT_MAX;
                unsigned int r = minimum + static_cast<T>(rand()) / (m / (maximum - minimum));
                result = r;
            }
            else
            {
                if(typeid (T).name() == typeid (signed int).name())
                {
                    signed int m = INT_MAX;
                    signed int r = minimum + static_cast<T>(rand()) / (m / (maximum - minimum));
                    result = r;
                }
                else
                {
                    signed int m = RAND_MAX;
                    result = minimum + static_cast<T>(rand()) / (m / (maximum - minimum));
                }
            }
        }
    }
    return result;
}

int main()
{

    srand(time(NULL));

    cout << "signed short int:" << endl;
    for(signed short int i = 0;i < 10;i++){
        signed short int min1 = -5365;
        signed short int max1= 8958;
        cout << getRandom<signed short int>(min1,max1) << endl;
    }
    cout << endl;

    cout << "unsigned int:" << endl;
    for(unsigned int i = 0;i < 10;i++){
        unsigned int min2 = 0;
        unsigned int max2 = UINT_MAX;
        cout << getRandom<unsigned int>(min2,max2) << endl;
    }
    cout << endl;

    cout << "signed int:" << endl;
    for(signed int i = 0;i < 10;i++){
        signed int min3 = 785468;
        signed int max3 = 10256325;
        cout << getRandom<signed int>(min3,max3) << endl;
    }
    cout << endl;

    cout << "unsigned long:" << endl;
    for(signed int i = 0;i < 10;i++){
        unsigned long min4 = 125452325;
        unsigned long max4 = 254523258;
        cout << getRandom<unsigned long>(min4,max4) << endl;
    }
    cout << endl;

    cout << "signed long" << endl;
    for(signed int i = 0;i < 10;i++){
        signed long min4 = -125452325;
        signed long max4 = 254523258;
        cout << getRandom<signed long>(min4,max4) << endl;
    }
    cout << endl;

    cout << "unsigned long long" << endl;
    for(signed int i = 0;i < 10;i++){
        unsigned long long min5 = 0;
        unsigned long long max5 = 254523258;
        cout << getRandom<unsigned long long>(min5,max5) << endl;
    }
    cout << endl;

    cout << "signed long long" << endl;
    for(signed int i = 0;i < 10;i++){
        signed long long min6 = -125452325;
        signed long long max6 = 254523258;
        cout << getRandom<signed long long>(min6,max6) << endl;
    }
    cout << endl;

    cout << "float" << endl;
    for(signed int i = 0;i < 10;i++){
        float min7 = -4523.23f;
        float max7 = 2523.258f;
        cout << getRandom<float>(min7,max7) << endl;
    }
    cout << endl;

    cout << "double" << endl;
    for(unsigned int i = 0;i < 10;i++){
        cout.precision(17);
        double min8 = -2562.12542;
        double max8 = 12542.365;
        cout << getRandom<double>(min8,max8) << endl;
    }
    cout << endl;

    cout << "long double" << endl;
    for(unsigned int i = 0;i < 10;i++){
        cout.precision(34);
        long double min9 = -85665856.23652;
        long double max9 = 95765656.28659;
        cout << getRandom<long double>(min9,max9) << endl;
    }
    cout << endl;

    cout << "random char " << endl;
    for(unsigned int i = 0;i < 10; i++){
        unsigned short int min = 0;
        unsigned short int max = 25;

        unsigned short r = getRandom<unsigned short int>(min,max) + int('A');
        cout << (char)r << " ";
    }
    cout << endl;

    return 0;
}
