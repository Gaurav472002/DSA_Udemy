#include <iostream>
#include <queue>

using namespace std;

void BFS(int vtx, int a[][8], int n)
{

    queue<int> Q;

    int visited[8]={0};
    cout<<vtx<<" ";

    visited[vtx]=1;
    Q.emplace(vtx);

    while (!Q.empty())
    {
        int u=Q.front();

        Q.pop();

        for (int v = 1; v <= n; v++)
        {
            if (a[u][v]==1 && visited[v]==0)
            {
                cout<<v<<" ";

                visited[v]=1;
                Q.emplace(v);
            }
            
        }
        
        
    }
    cout<<endl;
    

}
int main(){

    int grph[8][8]={
                   {0, 0, 0, 0, 0, 0, 0, 0},  // adjacency  matrix
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
    
    cout<<"BFS with starting vertex as ->1"<<endl;
    BFS(1,grph,8);

    cout<<"BFS with starting vertex as ->4"<<endl;
    BFS(4,grph,8);
    return 0 ;
}