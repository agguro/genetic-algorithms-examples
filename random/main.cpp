// genetic algorithm to solve a+2b+3c+4d+5e+6f-750=0
// java source by Denny Hermawanto for a+2b+3c+4d-30=0
// rebuild (badly) for C++ by Roberto Aguas Guerreiro
// goal: rebuild it in assembly language on x86-64 Intel Core i9 for linux.

#include <time.h>
#include <math.h>
#include <bits/stdc++.h>

#define MINIMUM -10.0
#define MAXIMUM 10.0

using namespace std;

int main()
{
    srand((unsigned)(time(NULL)));
    for(unsigned int i = 0;i < 100;i++){
        std::cout << MINIMUM + ((double) rand()/RAND_MAX)*(MAXIMUM-MINIMUM) << std::endl;
    }
    return 0;
}
