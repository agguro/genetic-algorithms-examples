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

    some output:

    signed short int:
    -5436
    -17213
    6215
    2687
    -6962
    -18491
    -21486
    9051
    3140
    328

    unsigned int:
    333663159
    1726110633
    1543435926
    1350853756
    1519111460
    1298758376
    218952841
    1810276586
    580717477
    20352783

    signed int:
    4793024
    9537687
    3547045
    3445368
    2037644
    9211798
    1042946
    2570106
    6228469
    6177628

    unsigned long:
    231845207
    201650682
    166373121
    153682687
    148436456
    246687289
    210447510
    218111497
    207252803
    256770237

    signed long
    93202537
    203041839
    210490393
    -27607008
    43715860
    84815955
    232144667
    87506429
    17374543
    -81208567

    unsigned long long
    135643319
    202480263
    6467094
    213657884
    9186999
    41841093
    183266254
    16460760
    92257130
    68595595

    signed long long
    144610529
    -66880421
    228135370
    275557078
    23456739
    301684592
    234012236
    295441334
    168697215
    66277039

    float
    2229.87
    -3156.45
    -3034.73
    694.989
    -1551.16
    -259.293
    -2901.76
    -2730.78
    -3811.9
    -558.485

    double
    2836.0394427064525
    6595.1100084762566
    2225.2907248944935
    3199.9338927382519
    3512.8520894550043
    2742.2304038639772
    5554.2741620788711
    -1279.5006343775869
    3668.4545720535457
    10745.454796155447

    long double
    -23896537.84027223362863878719508648
    -78174983.4913634240729152224957943
    -82507488.63697873237833846360445023
    -55962651.29363391817605588585138321
    91222680.36626494259689934551715851
    -19604106.67986458741870592348277569
    -56959502.41591044503002194687724113
    61639120.51110846217488870024681091
    -23238285.95168723213282646611332893
    67297546.28689080975891556590795517

    random char 
    G O H E Q E O X N L 
