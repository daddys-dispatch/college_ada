#include <stdio.h>

int ne = 1, min_cost = 0;

void main() {
    int n, i, j, min;
    int cost[20][20], a, u, b, v, source;
    int visited[20];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    for (i = 1; i <= n; i++)
        visited[i] = 0;

    printf("Enter the root node: ");
    scanf("%d", &source);
    visited[source] = 1;

    printf("\nMinimum cost Spanning tree is\n");
    while (ne < n) {
        min = 999;

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    if (visited[i] == 0)
                        continue;
                    else {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        if (visited[u] == 0 || visited[v] == 0) {
            printf("Edge %d\t(%d -> %d) = %d\n", ne++, a, b, min);
            min_cost += min;
            visited[b] = 1;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", min_cost);
}
