#include <iostream>
#include <fstream>
#include <ctime>
#include <stdlib.h>
#include <valarray>
#include "graph.h"

using namespace std;

enum TypeAlgo {
    RLS,
    ONEPLUSONE,
    LAMBDA,
    ONEPLUSONE_POWERLAW
};

const int REPEAT = 80;
const double BETTA = 1.5; // for power law
/*
void runAlgo ( TypeGraph typeGraph, int size, TypeAlgo typeAlgo) {
    vector<int> resultRls = vector<int> (REPEAT, 0);
    vector<int> resultOnePlusOne = vector<int> (REPEAT, 0);
    vector<int> resultLambda = vector<int> (REPEAT, 0);

    int sumRls = 0;
    int sumOnePlusOne = 0;
    int sumLambda = 0;

    int maxRls = 0;
    int maxOnePlusOne = 0;
    int maxLambda = 0;

    int minRls = 100000000;
    int minOnePlusOne = 100000000;
    int minLambda = 100000000;

    for (int i = 0; i < REPEAT; i++) {
        auto *graph = new Graph(size, typeGraph);

        if (typeAlgo == RLS) resultRls[i] = graph->RLS(1);
        else if (typeAlgo == ONEPLUSONE) resultOnePlusOne[i] = graph->onePlusOneAlgorithm(1);
        else if (typeAlgo == LAMBDA) resultLambda[i] = graph->lambdaAlgorithm(1);

        sumRls += resultRls[i];
        sumOnePlusOne += resultOnePlusOne[i];
        sumLambda += resultLambda[i];

        if (resultRls[i] > maxRls) maxRls = resultRls[i];
        if (resultOnePlusOne[i] > maxOnePlusOne) maxOnePlusOne = resultOnePlusOne[i];
        if (resultLambda[i] > maxLambda) maxLambda = resultLambda[i];

        if (resultRls[i] < minRls) minRls = resultRls[i];
        if (resultOnePlusOne[i] < minOnePlusOne) minOnePlusOne = resultOnePlusOne[i];
        if (resultLambda[i] < minLambda) minLambda = resultLambda[i];

        //graph->reset();
    }

    double averageRls = (double) sumRls / REPEAT;
    double averageOnePlusOne = (double) sumOnePlusOne / REPEAT;
    double averageLambda = (double) sumLambda / REPEAT;

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
    if (sumRls > 0) {

    }
    for (int i = 0; i < REPEAT; i++) {
        out << result[i] << ' ';
    }
    out << '\n';
    out << "границы - [" << min << ", " << max << "]\n";

    out << "среднее время работы - " << average << '\n';
    out << "нормированное по размеру задачи - " << (double) average / size << '\n';
    out << "----------------------------\n";
}*/

/*void run (TypeGraph typeGraph, int size, vector<TypeAlgo> typesAlgo) {
    //auto *graph = new Graph(size, typeGraph);

    for (auto & i : typesAlgo) {
        //auto *graph = new Graph(size, typeGraph);

        runAlgo(typeGraph, size, i);
    }

}*/

vector<double> powerLawDistribution (int n) {
    //ofstream out("C:/Users/Viktoriya/CLionProjects/evol/out", ios_base::app);
    vector<double> distribution (n, 0.0);
    double sumDist = 0.0;

    for (int i = 1; i <= n; i++) {
        double cur = pow(i, -BETTA);
        sumDist += cur;
    }

    distribution[0] = 1.0 / sumDist;

    for (int i = 1; i < n; i++) {
        distribution[i] = pow(i + 1 , -BETTA) / sumDist + distribution[i-1];
        //out << " " << distribution[i] << "  ";

    }

    return distribution;
}

void run (TypeGraph typeGraph, int size, vector<TypeAlgo> typesAlgo) {
    vector<vector<int>> result = vector<vector<int>> (typesAlgo.size(), vector<int>(REPEAT, 0));
    vector<int> sum = vector<int>(typesAlgo.size(), 0);
    vector<int> max = vector<int>(typesAlgo.size(), 0);
    vector<int> min = vector<int>(typesAlgo.size(), 100000000);

    for (int i = 0; i < REPEAT; i++) {
        auto *graph = new Graph(size, typeGraph);

        for (int j = 0; j < typesAlgo.size(); j++) {
            if (typesAlgo[j] == RLS) result[j][i] = graph->RLS(1);
            else if (typesAlgo[j] == ONEPLUSONE) result[j][i] = graph->onePlusOneAlgorithm(1);
            else if (typesAlgo[j] == ONEPLUSONE_POWERLAW) {
                vector<double> dist = powerLawDistribution(size);
                result[j][i] = graph->onePlusOneHeavyTailedAlgorithm(1, dist);
            }
            else if (typesAlgo[j] == LAMBDA) result[j][i] = graph->lambdaAlgorithm(1);

            graph->reset();

            sum[j] += result[j][i];
            if (result[j][i] > max[j]) max[j] = result[j][i];
            if (result[j][i] < min[j]) min[j] = result[j][i];
        }

    }

    vector<double> average = vector<double>(typesAlgo.size(), 0.0);

    for (int j = 0; j < typesAlgo.size(); j++) {
        average[j] = (double) sum[j] / REPEAT;
    }

    ofstream out("C:/Users/Viktoriya/CLionProjects/evol/out", ios_base::app);
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

    for (int i = 0; i < typesAlgo.size(); i++) {
        out << "алгоритм - ";

        if (typesAlgo[i] == RLS) {
            out << "RLS\n";
        } else if (typesAlgo[i] == ONEPLUSONE) {
            out << "(1 + 1)\n";
        } else if (typesAlgo[i] == ONEPLUSONE_POWERLAW) {
        out << "(1 + 1) Heavy-tailed\n betta = " << BETTA << "\n";
        } else if (typesAlgo[i] == LAMBDA) {
            out << "(1 + (лямбда, лямбда))\n";
        }

        out << "время работы: ";

        for (int j = 0; j < REPEAT; j++) {
            out << result[i][j] << ' ';
        }
        out << '\n';
        out << "границы - [" << min[i] << ", " << max[i] << "]\n";

        out << "среднее время работы - " << average[i] << '\n';
        out << "нормированное по размеру задачи - " << (double) average[i] / size << '\n';

    }
    out << "----------------------------\n";

}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    ofstream out;
    out.open("C:/Users/Viktoriya/CLionProjects/evol/out");
    out << "";

    vector<int> sizeGraph {2048}; //{32, 64, 128, 256, 512, 1024, 2048}
    vector<TypeAlgo> typesAlgo = { LAMBDA }; //{RLS, ONEPLUSONE, ONEPLUSONE_POWERLAW, LAMBDA}
    vector<TypeGraph> typesGraph = { KN };  //{KNN, KN, RANDOM}


    for (int i = 0; i < typesGraph.size(); i++) {
            for (int j = 0; j < sizeGraph.size(); j++) {
                run(typesGraph[i], sizeGraph[j], typesAlgo);
            }
    }
    return 0;
}
