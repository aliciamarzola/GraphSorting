# Graph Sorting and Greedy Coloring Checker

This C++ project aims to implement various sorting algorithms and verify greedy coloring for pre-colored graphs. It provides functionalities to sort vertices based on their color numbers using standard and custom sorting methods.

## Overview

The program's primary functionalities include:

- **Sorting Methods Implementation**: Incorporates sorting algorithms such as Bubble Sort, Selection Sort, Insertion Sort, Quicksort, Mergesort, and Heapsort, adapted to organize vertices based on their color numbers.
- **Greedy Coloring Verification**: Validates if the pre-colored graph adheres to the greedy coloring approach, stopping execution if the coloring fails the criteria.

### Input and Output

Instances are read from standard input following this structure:

- **Input Format**:
  - The first line contains a character 'c' and an integer 'n':
    - 'c' indicates the sorting method to be used.
    - 'n' represents the number of vertices in graph G.
    - Values for 'c':
      - 'b': Bubble Sort
      - 's': Selection Sort
      - 'i': Insertion Sort
      - 'q': Quicksort
      - 'm': Mergesort
      - 'p': Heapsort
      - 'y': Custom sorting method
  - The following 'n' lines contain vertex neighborhoods:
    - Each line starts with an integer 'm' indicating the number of neighbors for the vertex, followed by 'm' integers indicating its neighbors.
  - The last line consists of 'n' integers indicating the colors of each vertex.

- **Output**:
  - If the coloring isn't a greedy coloring, output '0'.
  - Otherwise, print '1' followed by the permutation of vertices used. In case of tie in color class, vertices should be sorted by label.
