#include <vector>
#include <iostream>
#include <stdlib.h>
#include <fstream>
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

void Graph::setVecD(vector<int> nd) {
    d = move(nd);
};
void Graph::setD(int nD) {
    D = nD;
};
void Graph::setE(vector<int> ne) {
    e = move(ne);
};

vector<int> Graph::getVecD() {
    return d;
};
int Graph::getD(){
    return D;
};
vector<int> Graph::getE(){
    return e;
};

void Graph::printVec(vector<int> vec) {
    ofstream out("/Users/viktoria/CLionProjects/evol/out", ios_base::app);
    for (int i : vec) {
        out << i << " ";
    }
    out << '\n';
    out.close();
}

void Graph::printMatrix() {
    ofstream out("/Users/viktoria/CLionProjects/evol/out", ios_base::app);
    out << "количество вершин " << matrix.size() << '\n' << "матрица смежности matrix:" << '\n';
    for (auto & i : matrix) {
        for (int j = 0; j < matrix.size(); j++) {
            out << i[j] << " ";
        }
        out << '\n';
    }
    out << "---------------------------" << '\n';
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
    setVecD(countd(getE()));
    setD(countD(getE()));

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

    setVecD(countd(getE()));
    setD(countD(getE()));
    printMatrix();
};

void Graph::RLS (int iteration) {
    ofstream out("/Users/viktoria/CLionProjects/evol/out", ios_base::app);
    out << "---------------------------\n";
    out << "iteration " << iteration << '\n';
    int pos = rand() % this->n;

    out << "flip " << pos << '\n';
    out << "prev e: ";
    for (int i : getE()) {
        out << i << " ";
    }
    out << '\n';

    vector<int> newE = getE();
    newE[pos] = (newE[pos] + 1) % 2;

    out << "new e:  ";
    for (int i : newE) {
        out << i << " ";
    }
    out << '\n';

    int newD = countD(newE);

    out << "предыдущий массив потенциалов: ";
    for (int i : getVecD()) {
        out << i << " ";
    }
    out << '\n';

    vector<int> newd = countd(newE);
    out << "новый массив потенциалов: ";

    for (int i : newd) {
        out << i << " ";
    }
    out << '\n';

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
        RLS(iteration);
    } else {
        out << "---------------------------\n";
        out << "(" << this->n << ", " << this->type << ")\n";
        out << "разрезана половина ребер за " << iteration << " итераций\n";
        out << "---------------------------\n";
    }
}

void Graph::onePlusOneAlgorithm(int iteration){
    
}

