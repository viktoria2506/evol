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
    long long D;
    vector<int> e;
public:
    int n;
    long long numberEdges;
    vector< vector<int> > matrix;
    TypeGraph type;

    Graph(int size, TypeGraph t);
    ~Graph();

    void setVecD(vector<int> nd);
    void setD(long long nD);
    void setE(vector<int> ne);

    vector<int> getVecD();
    long long getD();
    vector<int> getE();

    vector<int> countd(vector<int> e);
    long long countD(vector<int> e);
    void createKn();
    void createKnn();
    void createRandom();

    void printMatrix();
    void printVec(vector<int> vec);

    int RLS(int iteration);
    int lambdaAlgorithm(int iteration);
    int onePlusOneAlgorithm(int iteration);

    void reset();
};

#endif //EVOL_GRAPH_H
