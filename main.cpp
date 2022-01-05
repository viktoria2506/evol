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

    auto *g_32_knn = new Graph (32, KNN);
    g_32_knn->RLS(1);
    delete g_32_knn;

    auto *g_64_knn = new Graph (64, KNN);
    g_64_knn->RLS(1);
    delete g_64_knn;

    auto *g_128_knn = new Graph (128, KNN);
    g_128_knn->RLS(1);
    delete g_128_knn;

    auto  *g_256_knn = new Graph(256, KNN);
    g_256_knn->RLS(1);
    delete g_256_knn;

    auto *g_512_knn = new Graph(512, KNN);
    g_512_knn->RLS(1);
    delete g_512_knn;

    auto *g_1024_knn = new Graph(1024, KNN);
    g_1024_knn->RLS(1);
    delete g_1024_knn;

    auto *g_2048_knn = new Graph (2048, KNN);
    g_2048_knn->RLS(1);
    delete g_2048_knn;

    auto *g_32_random = new Graph(32, RANDOM);
    g_32_random->RLS(1);
    delete g_32_random;

    auto *g_64_random = new Graph(64, RANDOM);
    g_64_random->RLS(1);
    delete g_64_random;

    auto *g_128_random = new Graph(128, RANDOM);
    g_128_random->RLS(1);
    delete g_128_random;

    auto *g_256_random = new Graph(256, RANDOM);
    g_256_random->RLS(1);
    delete g_256_random;

    auto *g_512_random = new Graph(512, RANDOM);
    g_512_random->RLS(1);
    delete g_512_random;

    auto *g_1024_random = new Graph(1024, RANDOM);
    g_1024_random->RLS(1);
    delete g_1024_random;

    auto *g_2048_random = new Graph(2048, RANDOM);
    g_2048_random->RLS(1);
    delete g_2048_random;

    // 1+1
    out.open("/Users/viktoria/CLionProjects/evol/out");
    out << "-----------------------\n";
    out << "1+1\n";
    out << "-----------------------\n";

    auto *g_32_knn_one = new Graph(32, KNN);
    g_32_knn_one->onePlusOneAlgorithm(1);
    delete g_32_knn_one;

    auto *g_64_knn_one = new Graph(64, KNN);
    g_64_knn_one->onePlusOneAlgorithm(1);
    delete g_64_knn_one;

    auto *g_128_knn_one = new Graph(128, KNN);
    g_128_knn_one->onePlusOneAlgorithm(1);
    delete g_128_knn_one;

    auto *g_256_knn_one = new Graph (256, KNN);
    g_256_knn_one->onePlusOneAlgorithm(1);
    delete g_256_knn_one;

    auto *g_512_knn_one = new Graph (512, KNN);
    g_512_knn_one->onePlusOneAlgorithm(1);
    delete g_512_knn_one;

    auto *g_1024_knn_one = new Graph (1024, KNN);
    g_1024_knn_one->onePlusOneAlgorithm(1);
    delete g_1024_knn_one;

    auto *g_2048_knn_one = new Graph (2048, KNN);
    g_2048_knn_one->onePlusOneAlgorithm(1);
    delete g_2048_knn_one;

    auto *g_32_kn_one = new Graph (32, KN);
    g_32_kn_one->onePlusOneAlgorithm(1);
    delete g_32_kn_one;

    auto *g_64_kn_one = new Graph (64, KN);
    g_64_kn_one->onePlusOneAlgorithm(1);
    delete g_64_kn_one;

    auto *g_128_kn_one = new Graph (128, KN);
    g_128_kn_one->onePlusOneAlgorithm(1);
    delete g_128_kn_one;

    auto *g_256_kn_one = new Graph (256, KN);
    g_256_kn_one->onePlusOneAlgorithm(1);
    delete g_256_kn_one;

    auto *g_512_kn_one = new Graph (512, KN);
    g_512_kn_one->onePlusOneAlgorithm(1);
    delete g_512_kn_one;

    auto *g_1024_kn_one = new Graph (1024, KN);
    g_1024_kn_one->onePlusOneAlgorithm(1);
    delete g_1024_kn_one;

    auto *g_2048_kn_one = new Graph (2048, KN);
    g_2048_kn_one->onePlusOneAlgorithm(1);
    delete g_2048_kn_one;

    auto *g_32_random_one = new Graph (32, RANDOM);
    g_32_random_one->onePlusOneAlgorithm(1);
    delete g_32_random_one;

    auto *g_64_random_one = new Graph (64, RANDOM);
    g_64_random_one->onePlusOneAlgorithm(1);
    delete g_64_random_one;

    auto *g_128_random_one = new Graph (128, RANDOM);
    g_128_random_one->onePlusOneAlgorithm(1);
    delete g_128_random_one;

    auto *g_256_random_one = new Graph (256, RANDOM);
    g_256_random_one->onePlusOneAlgorithm(1);
    delete g_256_random_one;

    auto *g_512_random_one = new Graph (512, RANDOM);
    g_512_random_one->onePlusOneAlgorithm(1);
    delete g_512_random_one;

    auto *g_1024_random_one = new Graph (1024, RANDOM);
    g_1024_random_one->onePlusOneAlgorithm(1);
    delete g_1024_random_one;

    auto *g_2056_random_one = new Graph (2056, RANDOM);
    g_2056_random_one->onePlusOneAlgorithm(1);
    delete g_2056_random_one;

    return 0;
}
