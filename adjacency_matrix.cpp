#include<iostream>
using namespace std;
int main(){
    int vertex,edge,v1,v2;
    cout<<"enter no of vertx: ";
    cin>>vertex;
    cout<<"enter no of edges: ";
    cin>>edge;
    int adjacency_matrix[vertex][vertex];
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            adjacency_matrix[i][j] = 0;
        }
    }
    cout<<"MATRIX REPRESRRNTATION OF UNDIRECTED GRAPH"<<endl;
    for (int i = 0; i < edge; i++)
    {
        cout<<"enter vertex no.: ";
        cin>>v1;
        cout<<"enter connecting vertex: ";
        cin>>v2;
        adjacency_matrix[v1][v2] = 1;
        adjacency_matrix[v2][v1] = 1;
    }
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            cout<<adjacency_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}