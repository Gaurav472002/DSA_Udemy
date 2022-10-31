#include <iostream>
using namespace std;

void DFS(int start, int grph[][7], int n)
{

    static int visited[7] = {0};

    if (visited[start] == 0)
    {
        cout << start << " ";
        visited[start] = 1;

        for (int j = 1; j < n; j++)
        {
            if (grph[start][j] == 1 && visited[j] == 0)
            {
                DFS(j, grph, n);
            }
        }
    }
}

int main()
{

    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};
    DFS(1, G, 7);

    return 0;
}