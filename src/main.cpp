#include "Sorts.hpp"
#include <iostream>
#include <string>

int main() {

  try {

    // Cria grafo
    char metodo;
    int n_vertices, n_vizinhos;
    std::cin >> metodo >> n_vertices;
    Grafo grafo(n_vertices);

    for (int i = 0; i < n_vertices; i++) {
      std::cin >> n_vizinhos;

      if (!std::cin) {
        throw std::invalid_argument("Entrada inválida para 'n_vizinhos'");
      }

      No Vertice(i, n_vizinhos);
      for (int j = 0; j < n_vizinhos; j++) {
        int indice;
        std::cin >> indice;

        if (!std::cin) {
          throw std::invalid_argument("Entrada inválida para 'indice'");
        }

        Vertice.addVizinho(indice);
      }
      grafo.addNo(Vertice);
    }

    // Armazena cores em um array
    int cores[n_vertices];

    for (int i = 0; i < n_vertices; i++) {
      int cor;
      std::cin >> cor;

      if (!std::cin) {
        throw std::invalid_argument("Entrada inválida para 'cor'");
      }

      cores[i] = cor;
    }

    // Verifica se é guloso
    char resultado = grafo.isGreedy(cores);

    // Se for, realiza a permutação

    std::cout << '1';
    Sorts sort;
    switch (metodo) {
    case 'b':
      sort.Bubble(grafo, cores);
      std::cout << "\n";
      break;
    case 's':
      sort.Selection(grafo, cores);
      std::cout << "\n";
      break;
    case 'i':
      sort.Insertion(grafo, cores);
      std::cout << "\n";
      break;
    case 'q':
      sort.Quicksort(grafo, cores);
      std::cout << "\n";
      break;
    case 'm':
      sort.Mergesort(grafo, cores);
      std::cout << "\n";
      break;
    case 'p':
      sort.Heapsort(grafo, cores);
      std::cout << "\n";
      break;
    case 'y':
      sort.Own(grafo, cores);
      std::cout << "\n";
      break;
    default:
      std::cout << "ERRO: Metodo Invalido" << std::endl;
      break;
    }

  } catch (const std::exception &e) {
    std::cerr << "Erro: " << e.what() << std::endl;
  }
}
