#include <iostream> // bits/stdcpp.h
#include <queue>    // stl library
using namespace std;
class node
{
public:
    int data; //   |__|__|
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
};
int main()
{
    int vertex, edge, v1, v2;
    queue<int> q;
    cout << "enter total vertices: ";
    cin >> vertex;
    cout << "enter total edges: ";
    cin >> edge;
    adjacency_list *obj[vertex]; //
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
        obj[v1]->insert(v2);
    }
    int check_visit[vertex]; // array
    for (int i = 0; i < vertex; i++)
    {
        check_visit[i] = 0;
    }
    node *ptr = obj[0]->head;   //
    q.push(obj[0]->head->data); // 0
    check_visit[ptr->data] = 1;
    while (q.empty() == false)
    {
        node *ptr2 = obj[q.front()]->head;
        while (ptr2 != NULL)
        {
            int visit = ptr2->data;
            if (check_visit[visit] == 0)
            {
                q.push(ptr2->data); // 0 1 2 3
                check_visit[visit] = 1;
            }
            ptr2 = ptr2->next;
        }
        cout << q.front() << "__";
        q.pop();
    }
    return 0;
}