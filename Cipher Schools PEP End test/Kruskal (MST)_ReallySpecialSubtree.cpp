//https://www.hackerrank.com/challenges/kruskalmstrsub/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

struct Edge {
    int start, end, weight;
};

struct subset {
    int parent;
    int rank;
};

int find(struct subset subsets[], int node) {
    if (subsets[node].parent != node) {
        subsets[node].parent = find(subsets, subsets[node].parent);
    }
    return subsets[node].parent;
}

void Union(struct subset subsets[], int node1, int node2) {
    int root1 = find(subsets, node1);
    int root2 = find(subsets, node2);
    if (subsets[root1].rank < subsets[root2].rank) {
        subsets[root1].parent = root2;
    } else if (subsets[root1].rank > subsets[root2].rank) {
        subsets[root2].parent = root1;
    } else {
        subsets[root2].parent = root1;
        subsets[root1].rank++;
    }
}

int edgeComparison(const void* a, const void* b) {
    struct Edge* edge1 = (struct Edge*)a;
    struct Edge* edge2 = (struct Edge*)b;
    return edge1->weight > edge2->weight;
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;
    struct Edge* edgeList = (struct Edge*) malloc(edges * sizeof(struct Edge));

    for (int i = 0; i < edges; ++i) {
        int start, end, weight;
        cin >> start >> end >> weight;
        edgeList[i].start = start;
        edgeList[i].end = end;
        edgeList[i].weight = weight;
    }

    qsort(edgeList, edges, sizeof(edgeList[0]), edgeComparison);

    struct Edge mst[vertices-1];
    int mstSize = 0;

    struct subset* subsets = (struct subset*) malloc(vertices * sizeof(struct subset));
    for (int v = 0; v < vertices; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    for(int i = 0; i < edges; i++) {
        struct Edge minEdge = edgeList[i];
        int x = find(subsets, minEdge.start - 1);
        int y = find(subsets, minEdge.end - 1);
        if (x != y) {
            mst[mstSize++] = minEdge;
            Union(subsets, x, y);
        }
        if(mstSize == vertices-1) {
            break;
        }
    }

    int totalWeight = 0;
    for(int i = 0; i < vertices-1; i++) {
        totalWeight += mst[i].weight;
    }
    cout << totalWeight << "\n";
    return 0;
}
