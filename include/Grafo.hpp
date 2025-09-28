#ifndef GRAFO_H
#define GRAF0_H

#include "Node.hpp"

class Grafo{
private:
    int tamanho;
    No* vertices;
public:

    Grafo(int t);
    int GetTamanho();
    void addNo(No no);
    bool found(const int* vizinhos, int len, int x, const int cores[]);
    char isGreedy(int cores[]);

};


#endif
