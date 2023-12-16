#include "Sorts.hpp"

void Sorts::Imprime(int permutacao[], int len){
        for(int i=0; i<len; i++){
            std::cout << " " << permutacao[i];
        }
}


void Sorts::Bubble(Grafo grafo, int cores[]){
        int len = grafo.GetTamanho();
        int permutacao[len];
        
        for(int p=0; p<len; p++){
            permutacao[p] = p;
        }

        for(int i = 0; i < len-1; i++){
            for(int j = 1; j < len-i; j++){
                
                if (cores[j] < cores[j-1]){
                std::swap(cores[j-1], cores[j]);
                std::swap(permutacao[j-1], permutacao[j]);

                }
            }
        }

    Imprime(permutacao, len);
}

void Sorts::Selection(Grafo grafo, int cores[]){
        int len = grafo.GetTamanho();
        int permutacao[len];
        
        for(int p=0; p<len; p++){
            permutacao[p] = p;
        }

        for (int step = 0; step < len - 1; step++) {
            int min_idx = step;
            for (int i = step + 1; i < len; i++) {
                if (cores[i] < cores[min_idx]){
                    min_idx = i;
                }
            }

            int temp = cores[min_idx];
            cores[min_idx] = cores[step];
            cores[step] = temp;

            int temp2 = permutacao[min_idx];
            permutacao[min_idx] = permutacao[step];
            permutacao[step] = temp2;
        }
        Imprime(permutacao, len);
}


void Sorts::Insertion(Grafo grafo, int cores[]) {
    int i, j, aux;
    int len = grafo.GetTamanho();
    int permutacao[len];

    for (int p = 0; p < len; p++) {
        permutacao[p] = p;
    }

    for (i = 1; i < len; i++) {
        aux = cores[i];
        int auxPermutacao = permutacao[i];
        j = i - 1;

        while ((j >= 0) && (aux < cores[j])) {
            cores[j + 1] = cores[j];
            permutacao[j + 1] = permutacao[j];
            j--;
        }

        cores[j + 1] = aux;
        permutacao[j + 1] = auxPermutacao;
    }

    Imprime(permutacao, len);
}

int Sorts::Particao(int permutacao[], int cores[], int low, int high) {
    
    int pivot = cores[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (cores[j] < pivot) {
        i++;
        int t = cores[i];
        cores[i] = cores[j];
        cores[j] = t;
        int tp = permutacao[i];
        permutacao[i] = permutacao[j];
        permutacao[j] = tp;
    }
  }
  
    int t = cores[i+1];
    cores[i+1] = cores[high];
    cores[high] = t;
    int tp = permutacao[i+1];
    permutacao[i+1] = permutacao[high];
    permutacao[high] = tp;
  
  return (i + 1);
}

void Sorts::Ordena(int permutacao[], int cores[], int low, int high){
    if (low < high) {
    int pi = Particao(permutacao, cores, low, high);
    Ordena(permutacao, cores, low, pi - 1);
    Ordena(permutacao, cores, pi + 1, high);
  }
}

void Sorts::Quicksort(Grafo grafo, int cores[]){
    int len = grafo.GetTamanho();
    int permutacao[len];

    for (int p = 0; p < len; p++) {
        permutacao[p] = p;
    }

    Ordena(permutacao, cores, 0, len-1);
    Imprime(permutacao, len);
}

void Sorts::Mergesort(Grafo grafo, int cores[]){
    int len = grafo.GetTamanho();
    int permutacao[len];

    for (int p = 0; p < len; p++) {
        permutacao[p] = p;
    }

    MSort(permutacao, cores, 0, len-1);
    Imprime(permutacao, len);
}


void Sorts::MSort(int permutacao[], int cores[], int esq, int dir){
    if (esq < dir) {
        int x = (esq + dir)/2;
        MSort(permutacao, cores, esq, x);
        MSort(permutacao, cores, x + 1, dir);
        Merge(permutacao, cores, esq, x, dir);
    }
}

void Sorts::Merge(int permutacao[], int cores[], int esq, int x, int dir){
    
    int n1 = x - esq + 1;
    int n2 = dir - x;

    int L[n1], M[n2], P1[n1], P2[n2];

    for (int i = 0; i < n1; i++){
        L[i] = cores[esq + i];
        P1[i] = permutacao[esq + i];
    }
    for (int j = 0; j < n2; j++){
        M[j] = cores[x + 1 + j];
        P2[j] = permutacao[x + 1 + j];
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = esq;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            cores[k] = L[i];
            permutacao[k] = P1[i];
            i++;
        } else {
            cores[k] = M[j];
            permutacao[k] = P2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        cores[k] = L[i];
        permutacao[k] = P1[i];
        i++;
        k++;
    }

    while (j < n2) {
        cores[k] = M[j];
        permutacao[k] = P2[j];
        j++;
        k++;
    }
}


void Sorts::Heapsort(Grafo grafo, int cores[]){
    int len = grafo.GetTamanho();
    int permutacao[len];

    for (int p = 0; p < len; p++) {
        permutacao[p] = p;
    }

    for (int i = len / 2 - 1; i >= 0; i--){
      Heapify(permutacao, cores, len, i);
    }

    for (int i = len - 1; i >= 0; i--) {
      std::swap(cores[0], cores[i]);
      std::swap(permutacao[0], permutacao[i]);
      Heapify(permutacao, cores, i, 0);
    }
    Imprime(permutacao, len);
}


void Sorts::Heapify(int permutacao[], int cores[], int len, int i){

    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;
  
    if (esq < len && cores[esq] > cores[maior])
      maior = esq;
  
    if (dir < len && cores[dir] > cores[maior])
      maior = dir;
  
    if (maior != i) {
      std::swap(cores[i], cores[maior]);
      std::swap(permutacao[i], permutacao[maior]);
      Heapify(permutacao, cores, len, maior);
    }
}

int Sorts::findMax(int cores[], int len){
    int max = 0;
    for (int i = 0; i < len; i++) {
        if (cores[i] >= cores[max]) {
            max = i;
        }
    }
    return max;
}

void Sorts::Own(Grafo grafo, int cores[]) {
    int len = grafo.GetTamanho();
    int permutacao[len];

    for (int i = 0; i < len; ++i) {
        permutacao[i] = i;
    }

    for (int len_atual = len; len_atual > 1; len_atual--) {
        int maxIndex = findMax(cores, len_atual);
        std::swap(cores[maxIndex], cores[len_atual-1]);
        std::swap(permutacao[maxIndex], permutacao[len_atual-1]);
    }
    Imprime(permutacao, len);
}
