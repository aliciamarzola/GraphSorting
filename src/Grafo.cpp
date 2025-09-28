#include "Grafo.hpp"

Grafo::Grafo(int t) {
  if (t <= 0) {
    throw std::invalid_argument("O tamanho do grafo deve ser maior que zero.");
  }
  tamanho = t;
  vertices = new No[t];
}

int Grafo::GetTamanho() { return tamanho; }

void Grafo::addNo(No no) {
  int index = no.GetIndice();
  if (index < 0 || index >= tamanho) {
    throw std::out_of_range("Índice fora do alcance.");
  }
  vertices[index] = no;
}

bool Grafo::found(int *vizinhos, int len, int x, int cores[]) {
  if (vizinhos == nullptr) {
    throw std::invalid_argument("A matriz de vizinhos não pode ser nula.");
  }
  for (int i = 0; i < len; i++) {
    int indice = vizinhos[i];
    if (cores[indice] == x) {
      return 1;
    }
  }
  return 0;
}

char Grafo::isGreedy(int cores[]) {
  if (cores == nullptr) {
    throw std::invalid_argument("A matriz de cores não pode ser nula.");
  }
  for (int i = 0; i < tamanho; i++) {
    if (cores[i] > 1) {
      int cor = cores[i];
      int *vizinhos = vertices[i].GetVizinhos();
      int len = vertices[i].GetNVizinhos();
      for (int x = cor - 1; x >= 1; x--) {
        if (!found(vizinhos, len, x, cores)) {
          return '0';
        }
      }
    }
  }
  return '1';
}
