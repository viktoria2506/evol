#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    Graph g(8, KNN);
    g.countD();
    g.RLS();
    return 0;
}
