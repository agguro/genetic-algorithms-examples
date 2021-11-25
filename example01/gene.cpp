#include "gene.h"

Gene::Gene()
{
}

Gene::Gene(int geneticcode)
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

void Gene::set(int geneticcode)
{
    this->geneticcode = geneticcode;
}

int Gene::get(){
    return this->geneticcode;
}

