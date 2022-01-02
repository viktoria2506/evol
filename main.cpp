#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "graph.h"

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    ofstream out;
    out.open("/Users/viktoria/CLionProjects/evol/out");
    out << "";

    Graph g_32_kn(32, KN);
    g_32_kn.RLS(1);

    Graph g_64_kn(64, KN);
    g_64_kn.RLS(1);

    Graph g_128_kn(128, KN);
    g_128_kn.RLS(1);

    Graph g_256_kn(256, KN);
    g_256_kn.RLS(1);

    Graph g_512_kn(512, KN);
    g_512_kn.RLS(1);

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
    return 0;
}
