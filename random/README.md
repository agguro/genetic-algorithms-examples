This is a random generator example that can be used for whatever your needs.

The code is a typed function that returns a random number between a minimum and a maximum boundary.

the function:
T getRandom (T minimum, T maximum)

use:

'min' and 'max' in the function is of the same type as the number to generate, here called 'r'

    unsigned short int r = getRandom<unsigned short int>(min,max);

    signed short int r = getRandom<signed short int>(min,max);

    unsigned int r = getRandom<unsigned int>(min,max);

    signed int r = getRandom<signed int>(min,max);

    unsigned r = getRandom<unsigned long>(min,max);

    signed r = getRandom<signed long>(min,max);

    unsigned long long r = getRandom<unsigned long long>(min,max);

    signed long long r = getRandom<signed long long>(min,max);

    float r = getRandom<float>(min,max);

    double r = getRandom<double>(min,max);

    long double r = getRandom<long double>(min,max);

The function checks if min is lower than max and changes both if applicable.

For random chars one can use

    short int r = getRandom(0,25) + int('A')

and typecast the unsigned short int to char with (char)r.  For lower case letters use

    short int r = getRandom(0,25) + int('a')

and typecast again.  In fact you can generate any ASCII with

    short int r = getRandom(0,255)

    
The main.cpp demonstrates some if not all calls to this function.

