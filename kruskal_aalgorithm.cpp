#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> edg;
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
int find_root(int v, int parent[]){
    int i = v;
    while (parent[i]!=i)   // 
    {
        i = parent[i];
    }
    return i;
}
void union_find(int v1 , int v2,  int parent[],int rank[], vector<pair<int,int>> result){
    if (find_root(v1,parent)==find_root(v2,parent))
    {
        return;
    }
    if (rank[find_root(v1,parent)]>rank[find_root(v2,parent)])
    {
        parent[find_root(v2,parent)] = find_root(v1,parent); 
    }
    else
    {
        parent[find_root(v1,parent)] = find_root(v2,parent);
        if (rank[find_root(v1,parent)]==rank[find_root(v2,parent)])
        {
            parent[find_root(v1,parent)] = find_root(v2,parent);
            rank[find_root(v2,parent)]++;
        }   
    }
    result.push_back(make_pair(v1,v2));
}
void kruskal(priority_queue<pair<int, edg> , vector<pair<int,edg>>, greater<pair<int,edg>> > pq, int vertex){
     int parent[vertex];
    int rank[vertex];
    vector<pair<int,int>> result;
    for (int i = 0; i < vertex; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
    while (pq.empty()==false)
    {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        // add result in result array
        union_find(x,y,parent,rank,result);
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout<<result[i].first<<" , "<<result[i].second<<endl;
    }
};
int main(){
    int vertex,edge,v1,v2;
    cout<<"enter total vertices: ";
    cin>>vertex;
    cout<<"enter total edges: ";
    cin>>edge;
    adjacency_list* obj[vertex];
    vector<vector<int> > edge_weight;  
    priority_queue<pair<int, edg> , vector<pair<int,edg>>, greater<pair<int,edg>> > pt;
    for (int i = 0; i < vertex; i++)
    {
            obj[i] = new adjacency_list();
            obj[i]->insert(i);
    } 
    for (int i = 0; i < edge; i++)
    {
        int ew;
        cout<<"enter vertex 1: ";
        cin>>v1;
        cout<<"enter vertex 2: ";
        cin>>v2;
        cout<<"enter edge weight: ";
        cin>>ew;
        cout<<"***************************************************"<<endl;
        obj[v1]->insert(v2); 
        obj[v2]->insert(v1);
        pt.push(make_pair(ew,make_pair(v1,v2)));        
    }
    return 0;
}