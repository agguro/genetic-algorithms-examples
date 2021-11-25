#ifndef POPULATION_H
#define POPULATION_H

#include <chromosome.h>
#include <bits/stdc++.h>

class Population
{
public:
    unsigned int nrchromosomes;                 //number of chromosomes in a population
    unsigned int nrgenes;                       //length of each chromosome
    std::string id;                             //id of population
    double fitness;
    std::vector<Chromosome> chromosome;
    std::function<void(Chromosome*)> objectiveFunction;
    std::function<void(Chromosome*)> fitnessFunction;

    Population();
    Population(std::string id);
    Population(unsigned int nrchromosomes,unsigned int nrgenes);
    Population(std::string id,unsigned int nrchromosomes,unsigned int nrgenes);
    ~Population();
    void show(bool details);
    void calcObjective(Chromosome* c);
    void calcFitness(Chromosome* c);
    void random(long int min, long int max);
    void calculate();
    Population* clone();
    void copy(Population* population);
    bool solutions();
    void swap(Chromosome* c1,Chromosome* c2);
    void operator =(Population* population);
    void setGene(unsigned int genenr,unsigned int value);
};

#endif // POPULATION_H
