//
// Created by VICTORIYA CHERNOOKAYA (DEVEXPRESS) on 26.09.2021.
//

#include <vector>

#ifndef EVOL_GRAPH_H
#define EVOL_GRAPH_H

using namespace std;

enum TypeGraph {
    KN,
    KNN,
    RANDOM
};

class Graph {
private:
    vector<int> d;
    int D;
    vector<int> e;
public:
    int n;
    int numberEdges;
    vector< vector<int> > matrix;
    TypeGraph type;

    Graph(int size, TypeGraph t);

    void countd();
    vector<int> countd(vector<int> e);
    void countD();
    int countD(vector<int> e);
    void createKn();
    void createKnn();
    void createRandom();
    void printd();
    void printMatrix();
    void printE();

    void RLS();
    void lambdaAlgorithm();
    void onePlusOneAlgorithm();
};

#endif //EVOL_GRAPH_H
