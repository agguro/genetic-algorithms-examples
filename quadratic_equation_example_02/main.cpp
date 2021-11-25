// genetic algorithm to solve a*x*x+b*x+c=0
// in this example code : x²-x-30=0
// one root must be found, sometimes two roots are found.

#include <gene.h>
#include <chromosome.h>
#include <population.h>
#include <math.h>
#include <bits/stdc++.h>

#define ITERATIONS 200000
#define CHROMOSOMES 10
#define GENES 1
#define CROSSOVER 0.50
#define MUTATION 0.10
#define MINIMUM -10
#define MAXIMUM 10

using namespace std;

int aa = 1;
int bb = -1;
int cc = -30;

void objective(Chromosome* c){
    //the problem here is when one root is found the fitness will be 1 :
    //resulting in the second value is a non-root or the same value as the first root
    //so probably I need to rewrite the fitness function
    c->result = aa * c->gene[0].geneticcode * c->gene[0].geneticcode + bb * c->gene[0].geneticcode + cc;
}

void fitness(Chromosome* c){
    c->fitness = 1.0 / (1.0 + fabs(c->result));
}

int randomInt(int min, int max){
    return min + rand()%(max-min+1);
}

double randomFloat(){
    return (double)rand() / RAND_MAX;
}

void printObjective(Chromosome c){
    printf("x1 = %d",c.gene[0].geneticcode);
}

int main()
{
    Population *parent = new Population(CHROMOSOMES,GENES);
    Population *offspring = new Population(CHROMOSOMES,GENES);
    parent->objectiveFunction = objective;
    parent->fitnessFunction = fitness;
    parent->random(MINIMUM,MAXIMUM);
    bool solutions = false;
    int generation = 0;
    std::cout << "start genetic algorithm with " << CHROMOSOMES << " chromosomes, " << GENES << " genes/chromosome for maximum " << ITERATIONS << " generations. values between [" << MINIMUM << "," << MAXIMUM << "]" << std::endl;
    while(generation < ITERATIONS)
    {
        std::cout << ".";
        parent->calculate();
        solutions = parent->solutions();
        if(!solutions)
        {
            //SELECTION

            for(unsigned int i = 0; i < parent->nrchromosomes; i++)
            {
                double roulettewheel = (double)rand()/RAND_MAX;
                unsigned int j = parent->nrchromosomes-1;
                while(j > 0)
                {
                    if(roulettewheel > parent->chromosome[j].cumulativeProbability)
                    {
                        break;
                    }
                    j--;
                }
                for(unsigned int k = 0;k < parent->chromosome[i].nrgenes; k++){

                    offspring->chromosome[i].gene[k].geneticcode = parent->chromosome[j].gene[k].geneticcode;
                }
            }

            //CROSSOVER

            double crossoverrate = CROSSOVER;
            unsigned int mates = (unsigned int)(parent->nrchromosomes * crossoverrate + 0.5);

            int m[mates];
            for(unsigned int i = 0; i < mates;i++){
                // define first chromosome to mate
                int j = rand()%parent->nrchromosomes;
                m[i] = j;
                // next routine is to prevent chromosomes mating with itself, so combinations with the same chromosome
                // cannot exist.
                if(i != 0){
                    int k = (int)i-1;
                    while(k >= 0){
                        while(m[k]==m[i])
                        {
                            j = rand()%mates;
                            m[i] = j;
                            k = (int)i;
                            break;
                        }
                        k--;
                    }
                }
            }

            // we (should) have different chromosomes that will mate one with another, meaning
            // m[0] mates with m[1] to make a new chromosome 0
            // m[1] mates with m[2] to make a new chromosome 1
            // ...
            // m[n-1] mates with m[n] to make a new chromosome n-1
            // m[n] mates with m[0] to make a new chromosome n
            //
            // The crossover point will be a random number between 0 and nrgenes/chromosome
            // These values doesn't need to be different

            for(unsigned int i = 0; i < mates; i++)
            {
                unsigned int crossoverpoint = rand()%parent->nrgenes;

                // now swap the genes from one chromosome to the second one starting at the crossoverpoint
                int c1 = m[i];
                int c2 = 0;
                if(i==mates-1)
                {
                    c2=m[0];
                }
                else
                {
                    c2 = m[i+1];
                }

                // swap genetic code of gene s from chromosomes c1 and c2
                for(unsigned int s = crossoverpoint; s < parent->nrgenes; s++){
                    unsigned int swap = offspring->chromosome[c1].gene[s].geneticcode;
                    offspring->chromosome[c1].gene[s].geneticcode = offspring->chromosome[c2].gene[s].geneticcode;
                    offspring->chromosome[c2].gene[s].geneticcode = swap;
                }
            }

            // MUTATION

            double mutationrate = MUTATION;
            unsigned int totalgenes = offspring->nrgenes * offspring->nrchromosomes;
            unsigned int nrmutations = (unsigned int)((totalgenes * mutationrate) + 0.5);

            unsigned int mutations[nrmutations];

            for(unsigned int i = 0; i < nrmutations; i++){
                unsigned int j = (unsigned int)randomInt(0,totalgenes-1);
                mutations[i] = j;
                if(i != 0){
                    int k = (int)i-1;
                    while(k >= 0){
                        while(mutations[k]==mutations[i])
                        {
                            j = (unsigned int)randomInt(0,totalgenes-1);
                            mutations[i] = j;
                            k = (int)i;
                            break;
                        }
                        k--;
                    }
                }
            }

            for(unsigned int i = 0; i < nrmutations; i++){
                offspring->setGene(mutations[i],randomInt(MINIMUM,MAXIMUM));
            }
            parent->operator =(offspring);
        }
        else
        {
            break;
        }
        generation++;
    }
    std::cout << std::endl;
    parent->show(true);
    double maxfitness = 0.0;
    // search for the maximum fitness
    for(unsigned int i = 0; i < parent->nrchromosomes;i++)
    {
        if(parent->chromosome[i].fitness > maxfitness)
        {
            maxfitness = parent->chromosome[i].fitness;
        }
    }
    // display all chromosomes with the max fitness
    std::cout << std::endl  << "best solutions at generation " << generation << " :: fitness = " << maxfitness << std::endl;
    for(unsigned int i=0;i < parent->nrchromosomes; i++)
    {
        if(parent->chromosome[i].fitness == maxfitness)
        {
            std::cout << "chromosome " << i << " : ";
            printObjective(parent->chromosome[i]);
            std::cout << std::endl;
        }
    }

    return 0;
}
