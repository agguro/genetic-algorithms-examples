#include "gene.h"

Gene::Gene()
{
}

Gene::Gene(double geneticcode)
{
    this->geneticcode = geneticcode;
}

Gene::~Gene()
{
}

void Gene::show()
{
    std::cout << this->geneticcode << std::endl;
}

void Gene::set(double geneticcode)
{
    this->geneticcode = geneticcode;
}

double Gene::get(){
    return this->geneticcode;
}

