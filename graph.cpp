#include <vector>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "graph.h"

using namespace std;

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
    }
};

void Graph::printd() {
    cout << "массив потенциалов d:" << '\n';
    for (int i : d) {
        cout << i << " ";
    }
    cout << '\n' << "---------------------------" << '\n';
}

void Graph::printMatrix() {
    cout << "матрица смежности matrix:" << '\n';
    for (auto & i : matrix) {
        for (int j = 0; j < matrix.size(); j++) {
            cout << i[j] << " ";
        }
        cout << '\n';
    }
    cout << "---------------------------" << '\n';
    cout << "количество ребер: " << numberEdges << '\n';
    cout << "---------------------------" << '\n';
}

void Graph::printE() {
    cout << "e: ";
    for (int i : e) cout << i << ' ';
    cout << '\n' << "---------------------------" << '\n';
}

void Graph::countd () {
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix.size(); j++) {
            if(matrix[i][j] == 1) {
                if(e[i] == e[j]) {
                    d[i]++;
                    d[j]++;
                } else {
                    d[i]--;
                    d[j]--;
                }
            }
        }
    }
    for (int & i : d) {
        i /= 2;
    }
    printd();
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
    cout << "массив потенциалов: ";
    for (int & i : ans) {
        i /= 2;
        cout << i << ' ';
    }
    cout << '\n';
    return ans;
}


void Graph::countD () {
    countd();
    D = 0;
    for (int i : d) {
        D += i;
    }
    cout << "значение потенциала D: " << D << '\n';
    cout << "---------------------------" << '\n';
}

int Graph::countD (vector<int> newE) {
    vector<int> newd;
    int ans = 0;
    newd = countd(newE);

    for (int i : newd) {
        ans += i;
    }
    return ans;
}

void Graph::createKn () {
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
    printMatrix();
};

void Graph::createKnn () {
    matrix = vector< vector <int> >(n, vector<int> (n, 0));

    for (int i = 0; i < n/2; i++) {
        for (int j = n/2; j < n; j++) {
            matrix[i][j] = 1;
            matrix[j][i] = 1;
            numberEdges++;
        }
    }
    printMatrix();
};

void Graph::RLS () {
    //srand(static_cast<unsigned int>(time(0)));
    int pos = rand() % n;

    cout << "flip " << pos << '\n';

    vector<int> newE = e;
    newE[pos] = (newE[pos] + 1) % 2;
    printE();

    int newD = countD(newE);

    if (newD < D) {
        e = newE;
        countd();
        countD();
    }

    if (D > 0) {
        RLS();
    } else {
        cout << "разрезана половина ребер" << '\n';
    }
}

