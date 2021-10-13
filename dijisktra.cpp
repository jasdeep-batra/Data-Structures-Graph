#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node()
    {
        data = 0;
        next = NULL;
    }
};
class adjacency_list
{
public:
    node *head;

    adjacency_list()
    {
        head = NULL;
    }
    void insert(int d)
    {
        node *n = new node();
        n->data = d;
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            node *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = n;
        }
    }
    void print()
    {
        if (head == NULL)
        {
            return;
        }
        else
        {
            node *ptr = head;
            while (ptr != NULL)
            {
                cout << ptr->data << "-------";
                ptr = ptr->next;
            }
        }
    }
};
int findi(int arr[], int fin, int vertx, vector<int> ob)
{
    int i = 0;
    int got;
    while (i < vertx)
    {
        vector<int>::iterator itr;

        if (arr[i] == fin)
        {
            itr = find(ob.begin(), ob.end(), i);
            if (itr != ob.end())
            {
                i++;
                continue;
            }
            else
            {
                got = i;
                break;
            }
        }
        i++;
    }
    return got;
}

int main()
{
    int vertex, edge, v1, v2, tew;
    int ew = 0;
    cout << "enter total vertices: ";
    cin >> vertex;
    cout << "enter total edges: ";
    cin >> edge;
    adjacency_list *obj[vertex];
    int adjacency_matrix[vertex][vertex];
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            adjacency_matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < vertex; i++)
    {
        obj[i] = new adjacency_list();

        obj[i]->insert(i);
    }
    for (int i = 0; i < edge; i++)
    {

        cout << "enter vertex 1: ";
        cin >> v1;
        cout << "enter vertex 2: ";
        cin >> v2;
        cout << "enter edge weight";
        cin >> ew;
        obj[v1]->insert(v2);
        adjacency_matrix[v1][v2] = ew;
        adjacency_matrix[v2][v1] = ew;
        tew += ew;
    }
    int distance[vertex];
    for (int i = 0; i < vertex; i++)
    {
        distance[i] = tew;
    }
    distance[0] = 0;
    priority_queue<int, vector<int>, greater<int>> dist;
    dist.push(distance[0]);
    vector<int> itr;
    while (itr.size() != vertex)
    {
        cout << "debug: " << itr.size() << endl;
        int fin = findi(distance, dist.top(), vertex, itr);
        node *temp = obj[fin]->head;
        node *ptr = temp->next;
        itr.push_back(temp->data);
        dist.pop();
        while (ptr != NULL)
        {
            if (distance[ptr->data] > (distance[temp->data] + adjacency_matrix[temp->data][ptr->data]))
            {
                distance[ptr->data] = distance[temp->data] + adjacency_matrix[temp->data][ptr->data];
            }
            dist.push(distance[ptr->data]);
            ptr = ptr->next;
        }
    }
    cout << "minimum distance of vertices from 0th vertex" << endl;
    for (int i = 0; i < vertex; i++)
    {
        cout << "vertex " << i << " : " << distance[i] << endl;
    }
    return 0;
}
