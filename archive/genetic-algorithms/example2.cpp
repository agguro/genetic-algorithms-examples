// genetic algorith: solving a+2b+3c+4d-30=0
// solutions only elements of N (natural numbers)
// random string using Genetic Algorithm
// source: https://www.geeksforgeeks.org/genetic-algorithms/
  
#include <bits/stdc++.h>
#include <math.h>
#define  POPULATION 10

using namespace std;

int random_num(int start, int end);


class Chromosome{
public:
    long int gen[4];
    double fo;                     //objective function a+2b+3c+4d
    double fi;
    double prob;
    double cprob;
    
    void init(){
        for(int i = 0;i < 4; i++){
            this->gen[i] = random_num(1,30);
        }
    }
    
    void solve(){                //solve objective function
        this->fo = this->gen[0] + 2*this->gen[1] + 3*this->gen[2] + 4*this->gen[3] - 30;
    }
    
    void fitness(){
        this->fi = (double)(1 / (1 + abs(this->fo)));
    }
    
    void show(){
        this->solve();
        this->fitness();
        std::cout << this->gen[0] << "," << this->gen[1] << "," << this->gen[2] << "," << this->gen[3] << ": fo = " << this->fo << " , fi = " << this ->fi << std::endl; 
    }
};


// Function to generate random numbers in given range 
int random_num(int start, int end)
{
    int range = (end-start)+1;
    int random_int = start+(rand()%range);
    return random_int;
}

int main(){
    
    Chromosome *c[POPULATION];
    srand((unsigned)(time(0)));
    double total_fitness = 0;
    
    // create initial population
    for(int i = 0;i<POPULATION;i++)
    {
        c[i] = new Chromosome();
        c[i]->init();
        std::cout << "Chromosome " << i << ": ";
        c[i]->show();
        total_fitness += c[i]->fi;
    }
    
    //total of fitness
    std::cout << "total fitness: " << total_fitness << std::endl;
    
    //probability of each chromosome
    for(int i = 0;i<POPULATION;i++)
    {
        c[i]->prob = c[i]->fi / total_fitness;
        std::cout << "Chromosome " << i << " probability : " << c[i]->prob << std::endl;
    }
    
    //cumulative probability each chromosome
    for(int i = 0;i<POPULATION;i++)
    {
        if(i==0){
            c[i]->cprob = c[i]->prob;
        }else{
            c[i]->cprob = c[i]->prob + c[i-1]->cprob;
        }
        std::cout << "Chromosome " << i << " cumulative probability : " << c[i]->cprob << std::endl;
    } 
    
    //generate for each chromosome a random value that depends if a chromosome goes to the
    //following generation or not a.k.a. roulette wheel
    //create the next generation population
    // create initial population and a random number between 0 and 1 to define the chromosome
    std::cout << "Roulette wheel" << std::endl;
    Chromosome* n[POPULATION];
    for(int i = 0;i<POPULATION;i++)
    {
        double wheel = ((double) rand() / (RAND_MAX));
        int j = POPULATION-1;
        while(wheel < c[j]->cprob && j > 0){
            j--;
        }
        std::cout << "chromosome " << i << " replaced by chromosome " << j << std::endl;
        
        n[i] = new Chromosome();
        n[i]->gen[0] = c[j]->gen[0];
        n[i]->gen[1] = c[j]->gen[1];
        n[i]->gen[2] = c[j]->gen[2];
        n[i]->gen[3] = c[j]->gen[3];
        // next 2 steps aren't necessary, in later version the new population must calculate this instead of
        // repeatedly recalculating... either way the new population must be copied in the c chromosomes or
        // we're in troubles: solution -> Population class
        // an original Population and a population to work with.
        // for now I do the calculation to be sure I'm not messing too much up
        n[i]->solve();
        n[i]->fitness();
        std::cout << i << ":" << wheel << " - " << c[i]->cprob << std::endl;
    }
    
    std::cout << "New population:" << std::endl;
    /*
    for(int i = 0;i<POPULATION;i++)
    {
      //  std::cout << "new chromosome " << i << ": ";
        //n[i]->show();
    }
    
    //we have a new population in n
    //now define the crossover, the rate is pre defined and mostly 10% (from readings)
    double cor = 10.0/100.0;        //crossover rate
    */
    
    return 0;
}
