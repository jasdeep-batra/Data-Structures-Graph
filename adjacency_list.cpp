#include<iostream>
using namespace std;
class node{
    public:
        int data;
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
        void print(){
            if(head==NULL){
                return;
            }
            else{
            node* ptr = head;
            while (ptr!=NULL)
            {   
                cout<<ptr->data<<"-------";
                ptr = ptr->next;
            }
            }
        }
};
int main(){
    int vertex,edge,v1,v2;
    cout<<"enter total vertices: ";
    cin>>vertex;
    cout<<"enter total edges: ";
    cin>>edge;
    adjacency_list* obj[vertex];
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
    for (int i = 0; i < vertex; i++)
    {
            obj[i]->print();
    }
    return 0;
}