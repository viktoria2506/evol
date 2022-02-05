#include <iostream>
#include <fstream>
#include <ctime>
#include <stdlib.h>
#include "graph.h"

using namespace std;

enum TypeAlgo {
    RLS,
    ONEPLUSONE,
    LAMBDA
};

const int REPEAT = 80;

void runAlgo (Graph* graph, TypeGraph typeGraph, int size, TypeAlgo typeAlgo) {

    vector<int> result = vector<int> (REPEAT, 0);

    int sum = 0;
    int max = 0;
    int min = 100000000;

    for (int i = 0; i < REPEAT; i++) {
        if (typeAlgo == RLS) result[i] = graph->RLS(1);
        else if (typeAlgo == ONEPLUSONE) result[i] = graph->onePlusOneAlgorithm(1);
        else if (typeAlgo == LAMBDA) result[i] = graph->lambdaAlgorithm(1);

        sum += result[i];
        if (result[i] > max) max = result[i];
        if (result[i] < min) min = result[i];

        graph->reset();
    }

    double average = (double) sum / REPEAT;

    ofstream out("/Users/viktoria/CLionProjects/evol/out", ios_base::app);
    out << "результаты:\n";
    out << "размер графа - " << size << '\n';
    out << "тип графа - ";

    if (typeGraph == KN) {
        out << "KN\n";
    } else if (typeGraph == KNN) {
        out << "KNN\n";
    } else if (typeGraph == RANDOM) {
        out << "Random\n";
    }

    out << "алгоритм - ";
    if (typeAlgo == RLS) {
        out << "RLS\n";
    } else if (typeAlgo == ONEPLUSONE) {
        out << "(1 + 1)\n";
    } else if (typeAlgo == LAMBDA) {
        out << "(1 + (лямбда, лямбда))\n";
    }

    out << "время работы: ";
    for (int i =0; i < REPEAT; i++) {
        out << result[i] << ' ';
    }
    out << '\n';
    out << "границы - [" << min << ", " << max << "]\n";

    out << "среднее время работы - " << average << '\n';
    out << "нормированное по размеру задачи - " << (double) average / size << '\n';
}

void run (TypeGraph typeGraph, int size, vector<TypeAlgo> typesAlgo) {
    auto *graph = new Graph(size, typeGraph);

    for (auto & i : typesAlgo) {
        runAlgo(graph, typeGraph, size, i);
    }

}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    ofstream out;
    out.open("/Users/viktoria/CLionProjects/evol/out");
    out << "";

    vector<int> sizeGraph {2048}; //{32, 64, 128, 256, 512, 1024, 2048}
    vector<TypeAlgo> typesAlgo = {RLS, ONEPLUSONE, LAMBDA}; //{RLS, ONEPLUSONE, LAMBDA}
    vector<TypeGraph> typesGraph = {KN};  //{KNN, KN, RANDOM}


    for (int i = 0; i < typesGraph.size(); i++) {
            for (int j = 0; j < sizeGraph.size(); j++) {
                run(typesGraph[i], sizeGraph[j], typesAlgo);
            }
    }
    return 0;
}
