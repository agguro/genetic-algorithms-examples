#include "chromosome.h"

Chromosome::~Chromosome()
{
    this->result = 0;
    this->fitness = 0.0;
}

Chromosome::Chromosome(unsigned int nrgenes)
{
    this->nrgenes = nrgenes;
    this->result = 0;
    this->fitness = 0.0;

    for(unsigned int i = 0; i < this->nrgenes;i++)
    {
        Gene g;
        g.set(0.0);
        this->gene.push_back(g);
    }
}

void Chromosome::show(){
    std::cout << "(";
    for(unsigned int i = 0;i < this->gene.size();i++){
        this->gene.begin();
        std::cout << this->gene.at(i).get();
        if(i < nrgenes-1){
            std::cout << " ; ";
        }else{
            std::cout << ")";
        }
    }
}

void Chromosome::operator =(Chromosome* chromosome)
{
    for(unsigned int i = 0; i < this->nrgenes; i++){
        this->gene[0].geneticcode = chromosome->gene[0].geneticcode;
    }
}
