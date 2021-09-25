#ifndef GENE_H
#define GENE_H

#include <bits/stdc++.h>

class Gene
{
public:
    double geneticcode;

    Gene();                             //constructor
    Gene(double geneticcode);              //constructor with geneticcode
    ~Gene();                            //destructor
    void show();                        //show the geneticcode
    void set(double geneticcode);          //set the geneticcode
    double get();                          //get the genetic code
};

#endif // GENE_H
