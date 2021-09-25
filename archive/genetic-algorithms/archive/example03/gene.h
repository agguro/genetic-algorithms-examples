#ifndef GENE_H
#define GENE_H

#include <bits/stdc++.h>

class Gene
{
public:
    int geneticcode;

    Gene();                             //constructor
    Gene(int geneticcode);              //constructor with geneticcode
    ~Gene();                            //destructor
    void show();                        //show the geneticcode
    void set(int geneticcode);          //set the geneticcode
    int get();                          //get the genetic code
};

#endif // GENE_H
