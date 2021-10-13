#include<iostream> // bits/stdcpp.h
#include<stack> // stl library
using namespace std;
class node{
    public:
        int data;  //   |__|__|
        node* next;

        node(){
            data = 0;
            next = NULL;
        }
};
class adjacency_list{
    public:
        node* head;

        adjacency_list(){
            head = NULL;
        }
        void insert(int d){    
            node* n = new node();
            n->data = d;
            if(head == NULL){
                head = n;
            }
            else{
                node *ptr = head;
                while(ptr->next!=NULL){
                    ptr = ptr->next;
                }
                ptr->next = n;
            }
        }
};
int main(){
    int vertex,edge,v1,v2;
    stack<int> s;   
    cout<<"enter total vertices: ";
    cin>>vertex;
    cout<<"enter total edges: ";
    cin>>edge;
    adjacency_list* obj[vertex];   // 
    for (int i = 0; i < vertex; i++)
    {
            obj[i] = new adjacency_list();
            obj[i]->insert(i);
    } 
    for (int i = 0; i < edge; i++)
    {
        cout<<"enter vertex 1: ";    
        cin>>v1;
        cout<<"enter vertex 2: ";
        cin>>v2;
        obj[v1]->insert(v2);  
    }
    int arr[vertex];
    for (int i = 0; i < vertex; i++)
    {
        arr[i] = 0;
    }
    s.push(obj[0]->head->data); // initialization of iterator
    arr[obj[0]->head->data] = 1; // visited
    while (s.empty()==false)  //!(s.empty());
    {
        node* ptr = obj[s.top()]->head;    // iterator for nested loop
        cout<<s.top()<<"__";  // 0 2 3 1
        s.pop();
        while (ptr!=NULL)
        {
            if(arr[ptr->data]==0){
                s.push(ptr->data);
                arr[ptr->data] = 1;
            }
            ptr = ptr->next;
        }
    }
    return 0;
}
    