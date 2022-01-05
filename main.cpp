#include <iostream>
#include <fstream>
#include <ctime>
#include <stdlib.h>
#include "graph.h"

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    ofstream out;
    out.open("/Users/viktoria/CLionProjects/evol/out");
    out << "";

    unsigned int start_time =  clock();
    auto *g_32_kn = new Graph(32, KN);
    g_32_kn->RLS(1);
    delete g_32_kn;

    auto *g_64_kn = new Graph(64, KN);
    g_64_kn->RLS(1);
    delete g_64_kn;

    auto g_128_kn = new Graph(128, KN);
    g_128_kn->RLS(1);
    delete g_128_kn;

    auto g_256_kn = new Graph(256, KN);
    g_256_kn->RLS(1);
    delete g_256_kn;

    auto *g_512_kn = new Graph(512, KN);
    g_512_kn->RLS(1);
    delete g_512_kn;

    auto g_1024_kn = new Graph(1024, KN);
    g_1024_kn->RLS(1);
    delete g_1024_kn;

    auto g_2048_kn = new Graph(2048, KN);
    g_2048_kn->RLS(1);
    delete g_2048_kn;

    Graph g_32_knn(32, KNN);
    g_32_knn.RLS(1);

    Graph g_64_knn(64, KNN);
    g_64_knn.RLS(1);

    Graph g_128_knn(128, KNN);
    g_128_knn.RLS(1);

    Graph g_256_knn(256, KNN);
    g_256_knn.RLS(1);

    Graph g_512_knn(512, KNN);
    g_512_knn.RLS(1);

    Graph g_1024_knn(1024, KNN);
    g_1024_knn.RLS(1);

    Graph g_2048_knn(2048, KNN);
    g_2048_knn.RLS(1);

    unsigned int end_time = clock();
    unsigned int dur = end_time - start_time;

    out.open("/Users/viktoria/CLionProjects/evol/out");
    out << dur;
    return 0;
}
