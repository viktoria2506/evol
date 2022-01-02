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

    void setVecD(vector<int> nd);
    void setD(int nD);
    void setE(vector<int> ne);

    vector<int> getVecD();
    int getD();
    vector<int> getE();

    vector<int> countd(vector<int> e);
    int countD(vector<int> e);
    void createKn();
    void createKnn();
    void createRandom();

    void printMatrix();
    void printVec(vector<int> vec);

    void RLS(int iteration);
    void lambdaAlgorithm();
    void onePlusOneAlgorithm(int iteration);
};

#endif //EVOL_GRAPH_H
