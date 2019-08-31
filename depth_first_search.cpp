#include<bits/stdc++.h>

using namespace std;

#define max_node 100

//creating a structure, each individual nodes will have these features
struct Struct
{
    int s_time;
    int f_time;
    int color;
    int parent;
};
Struct node[max_node]; //creating the structure array

int Time;
int v, e;

void add_edge(list<int> adj_list[], int m, int n){
    adj_list[m].push_back(n);
}

void dfs_visit(list<int> adj_list[], int s){

    node[s].color = 1;
    cout << s << " ";
    Time++;
    node[s].s_time = Time;
    list<int>::iterator it;
    for (it = adj_list[s].begin(); it != adj_list[s].end(); it++)
        if (node[*it].color == 0){
            node[*it].parent = s;
            dfs_visit(adj_list, *it);
        }

    node[s].color = 2;
    Time++;
    node[s].f_time = Time;
}

void dfs(list<int>adj_list[], int s){
    for (int i = 0; i < v; i++)//initializing all the nodes
        node[i].color = 0;
    dfs_visit(adj_list, s); //sending the source to dfs_visits
}

int main()
{
    cout<<"Enter number of vertices/nodes: ";
    cin>>v;
    cout<<"Enter number of edges: ";
    cin>>e;
    cout<<"Enter the connected pairs (first source then destination): "<<endl;

    list<int> adj_list[v];

    for(int i=0; i<e; i++){
        int m,n;
        cin>>m>>n;
        add_edge(adj_list, m, n);
    }

    cout<<"Enter node to start traversing: ";
    int s;
    cin>>s;
    dfs(adj_list, s);

    cout<<"\nEnter node to calculate its distance: ";
    int q;
    cin>>q;
    cout<<node[q].f_time - node[q].s_time<<endl;

    return 0;
}
