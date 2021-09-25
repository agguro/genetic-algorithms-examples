#include "population.h"

Population::Population()
{
}

Population::~Population()
{ 
}

Population::Population(unsigned int chromosomes,unsigned int genes)
{
    this->nrgenes = genes;
    this->nrchromosomes = chromosomes;
    for(unsigned int i = 0; i < this->nrchromosomes;i++)
    {
        Chromosome c(this->nrgenes);
        this->chromosome.push_back(c);
    }
}

void Population::show(bool details)
{
    for(unsigned i = 0;i < this->chromosome.size();i++){
        std::cout << "chromosome " << i << " ";
        this->chromosome.begin();
        this->chromosome.at(i).show();
        if(details){
            std::cout << " ==> result = " << this->chromosome.at(i).result;
            std::cout << " | fitness = " << this->chromosome.at(i).fitness;
            std::cout << " | relative probability = " << this->chromosome.at(i).relativeProbability;
            std::cout << " | cumulative probability = " << this->chromosome.at(i).cumulativeProbability;
        }
        std::cout << std::endl;
    }
    if(details){
        std::cout << "total fitness = " << this->fitness;
        std::cout << std::endl;
    }
}

void Population::calcObjective(Chromosome* c)
{
    this->objectiveFunction(c);
}

void Population::calcFitness(Chromosome* c)
{
    this->fitnessFunction(c);
}

void Population::random(double min, double max)
{
    // random fill in population
    std::srand(std::time(0));
    for(unsigned int i = 0; i < this->nrchromosomes;i++){
        for(unsigned int j = 0; j < this->chromosome[i].nrgenes;j++){
            (this->chromosome[i]).gene[j].geneticcode = min + (rand()/RAND_MAX)*(max-min)+1;
        }
    }
}

void Population::calculate(){
    this->fitness = 0.0;
    for(unsigned int i = 0; i < this->nrchromosomes;i++){
        this->calcObjective(&this->chromosome[i]);
        this->calcFitness(&this->chromosome[i]);
        this->fitness += this->chromosome[i].fitness;
    }
    for(unsigned int i = 0; i < this->nrchromosomes;i++){
        this->chromosome[i].relativeProbability = this->chromosome[i].fitness / this->fitness;
        if(i == 0){
            this->chromosome[i].cumulativeProbability = this->chromosome[i].relativeProbability;
        }else{
            this->chromosome[i].cumulativeProbability = this->chromosome[i].relativeProbability + this->chromosome[i-1].cumulativeProbability;
        }
    }
}

/*Population* Population::clone(){
    Population* clone = new Population(this->nrchromosomes,this->nrgenes);
    clone->copy(this);
    return clone;
}
*/

void Population::copy(Population* population){
    for(unsigned int c = 0; c < this->nrchromosomes;c++){
        for(unsigned int g = 0; g < this->nrgenes;g++){
            this->chromosome[c].gene[g].geneticcode = population->chromosome[c].gene[g].geneticcode;
        }
    }
}

bool Population::solutions()
{
    bool solutions = false;
    for(unsigned int i = 0; i < this->nrchromosomes; i++){
        if(this->chromosome[i].fitness==1){
            solutions = solutions || true;
            i = this->nrchromosomes;
        }
    }
    return solutions;
}

void Population::operator=(Population* population)
{
    this->copy(population);
}

void Population::setGene(unsigned int genenr,unsigned int value)
{
    unsigned int g = genenr % this->nrgenes;
    unsigned int c = genenr / this->nrgenes;
    // set the gene value
    this->chromosome[c].gene[g].geneticcode = value;

}
