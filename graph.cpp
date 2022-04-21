#include <vector>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <ctime>
#include <random>
#include <chrono>
#include "graph.h"

using namespace std;

const int LAMBDA = 10;

Graph::Graph(int size, TypeGraph t) {
    type = t;
    n = size;
    numberEdges = 0;
    e = vector<int> (size, 0);
    d = vector<int> (size, 0);

    if (type == KN) {
        createKn();
    } else if (type == KNN) {
        createKnn();
    } else if (type == RANDOM) {
        createRandom();
    }
};

}

void Graph::reset() {
    vector<int> ne = vector<int> (n, 0);
    setE(ne);
    setVecD(countd(getE()));
    setD(countD(getE()));
};

void Graph::setVecD(vector<int> nd) {
    d = move(nd);
};
void Graph::setD(long long nD) {
    D = nD;
};
void Graph::setE(vector<int> ne) {
    e = move(ne);
};

vector<int> Graph::getVecD() {
    return d;
};
long long Graph::getD(){
    return D;
};
vector<int> Graph::getE(){
    return e;
};

void Graph::printVec(vector<int> vec) {
    ofstream out("C:/Users/Viktoriya/CLionProjects/evol/out", ios_base::app);
    for (int i : vec) {
        out << i << " ";
    }
    out << '\n';
    out.close();
}

void Graph::printMatrix() {
    ofstream out("C:/Users/Viktoriya/CLionProjects/evol/out", ios_base::app);
    out << "количество вершин " << matrix.size() << '\n';
    /*out << "матрица смежности matrix:" << '\n';
    for (auto & i : matrix) {
        for (int j = 0; j < matrix.size(); j++) {
            out << i[j] << " ";
        }
        out << '\n';
    }*/
    //out << "---------------------------" << '\n';
    out << "количество ребер: " << numberEdges << '\n';
    out << "---------------------------" << '\n';
    out.close();
}

vector<int> Graph::countd (vector<int> newE) {
    vector<int> ans(n, 0);
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix.size(); j++) {
            if(matrix[i][j] == 1) {
                if(newE[i] == newE[j]) {
                    ans[i]++;
                    ans[j]++;
                } else {
                    ans[i]--;
                    ans[j]--;
                }
            }
        }
    }
    for (int & i : ans) {
        i /= 2;
    }
    return ans;
}

long long Graph::countD (vector<int> newE) {
    vector<int> newd;
    long long ans = 0;
    newd = countd(newE);

    for (int i : newd) {
        ans += i;
    }
    return ans;
}

void Graph::createKn () {
    ofstream out("C:/Users/Viktoriya/CLionProjects/evol/out", ios_base::app);
    out << "KN graph\n";
    matrix = vector< vector <int> >(n, vector<int> (n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                matrix[i][j] = 1;
                numberEdges++;
            }
        }
    }
    numberEdges /= 2;
    setVecD(countd(getE()));
    setD(countD(getE()));

    printMatrix();
};

void Graph::createKnn () {
    ofstream out("C:/Users/Viktoriya/CLionProjects/evol/out", ios_base::app);
    out << "KNN graph\n";
    matrix = vector< vector <int> >(n, vector<int> (n, 0));

    for (int i = 0; i < n/2; i++) {
        for (int j = n/2; j < n; j++) {
            matrix[i][j] = 1;
            matrix[j][i] = 1;
            numberEdges++;
        }
    }

    setVecD(countd(getE()));
    setD(countD(getE()));
    printMatrix();
};

void Graph::createRandom () {
    ofstream out("C:/Users/Viktoriya/CLionProjects/evol/out", ios_base::app);
    out << "RANDOM graph\n";
    matrix = vector< vector <int> >(n, vector<int> (n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
                int randEdge = rand() % 2;
                matrix[i][j] = randEdge;
                matrix[j][i] = randEdge;
                if (randEdge == 1) numberEdges++;
        }
    }

    setVecD(countd(getE()));
    setD(countD(getE()));
    printMatrix();
}



int binSearch (double x, vector<double> dist) {
    ofstream out("C:/Users/Viktoriya/CLionProjects/evol/out", ios_base::app);
    //out << "X   " << x <<'\n';
    int l = 0;
    int r = dist.size();

    while (r > l) {
        int m = (l + r) / 2;

        if (dist[m] - x < 1e-12) {
            l = m + 1;
        } else if (dist[m] - x >= 1e-12) {
            r = m - 1;
        } else {
            return m;
        }
    }
    if (l == dist.size()) return l;

    return l + 1;
}

int Graph::RLS (int iteration) {
    ofstream out("C:/Users/Viktoriya/CLionProjects/evol/out", ios_base::app);
    out << "---------------------------\n";
    //out << "iteration " << iteration << '\n';
    int pos = rand() % this->n;

    out << "flip " << pos << '\n';
    /*out << "prev e: ";
    for (int i : getE()) {
        out << i << " ";
    }
    out << '\n';*/

    vector<int> newE = getE();
    newE[pos] = (newE[pos] + 1) % 2;

    //out << "new e:  ";
    /*for (int i : newE) {
        out << i << " ";
    }
    out << '\n';*/

    long long newD = countD(newE);

    //out << "предыдущий массив потенциалов: ";
    /*for (int i : getVecD()) {
        out << i << " ";
    }
    out << '\n';*/

    vector<int> newd = countd(newE);
    //out << "новый массив потенциалов: ";

    /*for (int i : newd) {
        out << i << " ";
    }
    out << '\n';*/

    out << "старый потенциал = " << getD() << "\nпосле флипа = " << newD << '\n';

    if (newD <= getD()) {
        setE(newE);
        setVecD(countd(newE));
        setD(countD(newE));
        out << "good mutation\n";
    }

    if (getD() > 0) {
        iteration++;
        out.close();
        return RLS(iteration);
    } else {
        out << "---------------------------\n";
        out << "(" << this->n << ", ";
        if (this->type == KN) {
            out << "KN";
        } else if (this->type == KNN) {
            out << "KNN";
        } else {
            out << "Random";
        }
        out << ")\n";
        out << "разрезана половина ребер за " << iteration << " итераций\n";
        out << "---------------------------\n";
        return iteration;
    }
}

int Graph::onePlusOneAlgorithm(int iteration){
    ofstream out("C:/Users/Viktoriya/CLionProjects/evol/out", ios_base::app);
    out << "---------------------------\n";
    //out << "iteration " << iteration << '\n';
    //int l = rand() % this->n;
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    binomial_distribution<int> distribution(this->n,(double) 1/this->n);

    int l = distribution(generator);
    /*for (int i = 0; i< 10; i++) {
        int l = distribution(generator);

        out << "flip " << l << " bits\n";
    }*/


    out << "flip " << l << " bits\n";
    vector<int> newE = getE();

    vector<int> flipArr(this->n, 0);

    for (int i = 0; i < l; i++) {
        int index;

        while(true) {
            index = rand() % this->n;

            if (flipArr[index] != 1) {
                flipArr[index] = 1;
                newE[index] = (newE[index] + 1) % 2;
                break;
            }
        }
    }

    long long newD = countD(newE);

    out << "старый потенциал = " << getD() << "\nпосле флипа = " << newD << '\n';

    if (newD <= getD()) {
        setE(newE);
        setVecD(countd(newE));
        setD(countD(newE));
        out << "good mutation\n";
    }

    //setE(newE);
    //setVecD(countd(newE));
    //setD(newD);

    if (getD() > 0) {
        iteration++;
        out.close();
        return onePlusOneAlgorithm(iteration);
    } else {
        out << "---------------------------\n";
        out << "(" << this->n << ", " ;
        if (this->type == KN) {
            out << "KN";
        } else if (this->type == KNN) {
            out << "KNN";
        } else {
            out << "Random";
        }
        out << ")\n";
        out << "разрезана половина ребер за " << iteration << " итераций\n";
        out << "---------------------------\n";
        return iteration;
    }
}

int Graph::onePlusOneHeavyTailedAlgorithm(int iteration, vector<double> dist) {
    ofstream out("C:/Users/Viktoriya/CLionProjects/evol/out", ios_base::app);
    out << "---------------------------\n";

    /*random_device rd;
    mt19937 gen(rd());*/
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_real_distribution<> distribution(0.0, 1.0);

    double y =  distribution(generator);
    int l = binSearch(y, dist);

    //double x =  pow(((pow(this->n,(1-BETTA)) - 1)*y + 1) ,(1/(1-BETTA)));

    //int alpha = (int) x;

    //binomial_distribution<int> distribution_bin(this->n,(double) alpha/this->n);

    //int l = distribution_bin(generator);
    //int l = (int) x;

    out << "flip " << l << " bits\n";
    vector<int> newE = getE();

    vector<int> flipArr(this->n, 0);

    for (int i = 0; i < l; i++) {
        int index;

        while(true) {
            index = rand() % this->n;

            if (flipArr[index] != 1) {
                flipArr[index] = 1;
                newE[index] = (newE[index] + 1) % 2;
                break;
            }
        }
    }

    long long newD = countD(newE);

    out << "старый потенциал = " << getD() << "\nпосле флипа = " << newD << '\n';

    if (newD <= getD()) {
        setE(newE);
        setVecD(countd(newE));
        setD(countD(newE));
        out << "good mutation\n";
    }

    if (getD() > 0) {
        iteration++;
        out.close();
        return onePlusOneHeavyTailedAlgorithm(iteration, dist);
    } else {
        out << "---------------------------\n";
        out << "(" << this->n << ", " ;
        if (this->type == KN) {
            out << "KN";
        } else if (this->type == KNN) {
            out << "KNN";
        } else {
            out << "Random";
        }
        out << ")\n";
        out << "разрезана половина ребер за " << iteration << " итераций\n";
        out << "---------------------------\n";
        return iteration;
    }
}



int Graph::lambdaAlgorithm(int iteration) {
    ofstream out("C:/Users/Viktoriya/CLionProjects/evol/out", ios_base::app);
    out << "---------------------------\n";
    //out << "iteration " << iteration << '\n';

    //int l = rand() % this->n;

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    binomial_distribution<int> distribution(this->n,(double) 1/this->n);

    int l = distribution(generator);
    vector<int> x = getE();
    out << "flip " << l << " bits\n";

    if (l == 0) {
        iteration++;
        out.close();
        return lambdaAlgorithm(iteration);
    }

    vector<vector<int>> mutationArr(LAMBDA, x);

    for (int i = 0; i < LAMBDA; i++) {
        vector<int> flipArr(this->n, 0);

        for (int j = 0; j < l; j++) {
            int index;

            while(true) {
                index = rand() % this->n;

                if (flipArr[index] != 1) {
                    flipArr[index] = 1;
                    mutationArr[i][index] = (mutationArr[i][index] + 1) % 2;
                    break;
                }
            }
        }
    }

    int mutationWinIndex = 0;
    int bestMutD = countD(mutationArr[mutationWinIndex]);

    for (int i = 1; i < LAMBDA; i++) {
        int curD = countD(mutationArr[i]);

        if (curD < bestMutD) {
            mutationWinIndex = i;
            bestMutD = curD;
        }
    }

    out << "победитель мутации:  ";
    for (int i : mutationArr[mutationWinIndex]) {
        out << i << " ";
    }
    out << '\n';

    out << "старый потенциал = " << getD() << "\nпосле флипа = " << bestMutD << '\n';

    vector<vector<int>> y(LAMBDA, x);

    for (int i = 0; i < LAMBDA; i++) {
        for (int j = 0; j < y[i].size(); j++) {
            if(mutationArr[mutationWinIndex][j] != y[i][j]) {
                if ((double)rand() / (double)RAND_MAX < (double)1/LAMBDA) {
                    y[i][j] = (y[i][j] + 1) % 2;
                }
            }
        }
    }

    int crossoverWinIndex = 0;
    int bestCrossD = countD(y[crossoverWinIndex]);

    for (int i = 1; i < LAMBDA; i++) {
        int curD = countD(y[i]);

        if (curD < bestCrossD) {
            crossoverWinIndex = i;
            bestCrossD = curD;
        }
    }

    out << "победитель кроссовера:  ";
    for (int i : y[crossoverWinIndex]) {
        out << i << " ";
    }
    out << '\n';

    out << "старый потенциал = " << getD() << "\nпосле кроссовера = " << bestCrossD << '\n';

    if (getD() > bestCrossD) {
        setE(y[crossoverWinIndex]);
        setVecD(countd(y[crossoverWinIndex]));
        setD(bestCrossD);
        out << "good mutation\n";
    }

    if (getD() > 0) {
        iteration++;
        out.close();
        return lambdaAlgorithm(iteration);
    } else {
        out << "---------------------------\n";
        out << "(" << this->n << ", ";
        if (this->type == KN) {
            out << "KN";
        } else if (this->type == KNN) {
            out << "KNN";
        } else {
            out << "Random";
        }
        out << ")\n";
        out << "разрезана половина ребер за " << iteration << " итераций\n";
        out << "---------------------------\n";
        return iteration;
    }
}

