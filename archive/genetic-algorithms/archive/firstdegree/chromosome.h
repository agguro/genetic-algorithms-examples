#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include <gene.h>
#include <bits/stdc++.h>

class Chromosome
{
public:
    unsigned int nrgenes;
    std::vector<Gene> gene;
    double  result;
    double fitness;
    double relativeProbability;
    double cumulativeProbability;

    Chromosome();
    Chromosome(unsigned int genes);
    ~Chromosome();
    void show();
    void operator =(Chromosome* chromosome);
};
#endif // CHROMOSOME_H
