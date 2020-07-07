
#include <iostream>
using namespace std;

int parent[20];
int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}
void kruskalMST(int ***cost, int g, int V)
{
    // Comparing the matrix for impossible case
    for (int i = 0; i < V; i++)
        for (int j = i + 1; j < V; j++)
            for (int k = j + 1; k < V; k++)
                if (cost[g][i][k] < cost[g][j][k] && cost[g][i][k] < cost[g][i][j] || //three rules up down left right
                    cost[g][i][j] < cost[g][i][k] && cost[g][i][j] < cost[g][j][k] ||
                    cost[g][j][k] < cost[g][i][j] && cost[g][j][k] < cost[g][i][k])
                {
                    cout << "Impossible" << endl;
                    return;
                }
    // else applying kruskal
    cout << V - 1 << endl;
    int index = 0;
    for (int i = 0; i < V; i++)
        parent[i] = i;
    int edge_count = 0;
    int count = 0;
    while (edge_count < V - 1)
    {
        int costEdge = 0, v1 = -1, v2 = -1;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (find(i) != find(j) && cost[g][i][j] > costEdge)
                {
                    costEdge = cost[g][i][j];
                    v1 = i;
                    v2 = j;
                }
            }
        }
        int a1 = find(v1);
        int b1 = find(v2);
        parent[a1] = b1;
        cout << v1 << " " << v2 << " " << costEdge << endl; //displaying paths with their costs.
        edge_count++;
    }
}

int main()
{
    int number, number2, number3;
    cin >> number;
    int graphCount = 0;
    int size[20];
    int var = 0;
    int k = 1;
    int ***mat;
    mat = new int **[number];
    while (graphCount < number)
    {
        cin >> number3;
        mat[graphCount] = new int *[number3];
        for (int l = 0; l < number3; l++)
        {
            mat[graphCount][l] = new int[number3];
        }
        size[var] = number3;
        var++;
        for (int t = 0; t < number3; t++)
        {
            for (int v = 0; v < number3; v++)
            {
                cin >> number2;
                mat[graphCount][t][v] = number2; //making matrix.
            }
        }
        cout << "Case #" << graphCount + 1 << ":";
        kruskalMST(mat, graphCount, size[graphCount]);
        graphCount++;
    }

    return 0;
}
