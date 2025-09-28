#ifndef SORTS_H
#define SORTS_H

#include "Grafo.hpp"
#include <iostream>

class Sorts {
public:
  // Construtor Padrão
  Sorts() {};

  // Função para imprimir permutação
  void Imprime(int cores[], int len);

  // Métodos simples
  void Bubble(Grafo grafo, int cores[]);
  void Selection(Grafo grafo, int cores[]);
  void Insertion(Grafo grafo, int cores[]);

  // Método Quicksort
  void Quicksort(Grafo grafo, int cores[]);
  int Particao(int permutacao[], int cores[], int low, int high);
  void Ordena(int permutacao[], int cores[], int low, int high);

  // Método Mergesort
  void Mergesort(Grafo grafo, int cores[]);
  void MSort(int permutacao[], int cores[], int esq, int dir);
  void Merge(int permutacao[], int cores[], int esq, int meio, int dir);

  // Método Heapsort
  void Heapsort(Grafo grafo, int cores[]);
  void Heapify(int permutacao[], int cores[], int len, int maior);

  // Método Próprio
  void Own(Grafo grafo, int cores[]);
  int findMax(const int cores[], int len);
};

#endif
