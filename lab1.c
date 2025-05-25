#include <stdio.h>

int ne = 1, min_cost = 0;

void main() {
    int n, i, j, w, min, a, u, b, v;
    int cost[20][20], parent[20];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);

    for (i = 1; i <= n; i++)
        parent[i] = 0;

    printf("\nThe edges of Spanning tree are\n");

    while (ne < n) {
        int min = 999;

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        while (parent[u])
            u = parent[u];

        while (parent[v])
            v = parent[v];

        if (u != v) {
            printf("Edge %d\t(%d -> %d) = %d\n", ne++, a, b, min);
            min_cost += min;
            parent[v] = u;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", min_cost);
}

/*
Algorithm : Kruskal(G)
// Kruskal’s algorithm for constructing a minimum spanning tree
// Input: A weighted connected graph G = (V, E)
// Output: ET, the set of edges composing a minimum spanning tree of G
{
    Sort E in non-decreasing order of the edge weights w(e1) <= ... <= w(e|E|)
    ET ← ∅ ; ecounter ← 0 // Initialize the set of tree edges and its size
    k ← 0                 // Initialize the number of processed edges
    while ecounter < |V| - 1 do
    {
        k ← k + 1
        if ET ∪ {ek} is acyclic
        {
            ET ← ET ∪ {ek}
            ecounter ← ecounter + 1
        }
    }
    return ET
}
*/
