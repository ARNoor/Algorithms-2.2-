#include<bits/stdc++.h>

using namespace std;

#define max_node 100

//creating a structure, each individual nodes will have these features
struct Struct
{
    int color;
    int parent;
    int distance;
};
Struct node[max_node]; //creating the structure array

int v, e; //number of vertices and edges


void add_edge(list<int> adj_list[], int m, int n){
    adj_list[m].push_back(n);
}

void bfs(list<int>adj_list[], int s){
    for (int i = 1; i <= v; i++){
        node[i].color = 0;
        node[i].distance = INT_MAX;
    }//initializing all the nodes
    node[s].color = 1;
    node[s].distance = 0;
    queue<int> Q;
    Q.push(s);

    while(Q.empty() != true){
        int u = Q.front();
        Q.pop();
        cout << u << " ";
        list<int>::iterator it;
        for (it = adj_list[u].begin(); it != adj_list[u].end(); it++){
            if(node[*it].color == 0){
                node[*it].color = 1;
                node[*it].distance = node[u].distance + 1;
                node[*it].parent = u;
                Q.push(*it);
            }
        }
        node[u].color = 2;
    }
}

int main()
{
    cout<<"Enter number of vertices/nodes: ";
    cin>>v;
    cout<<"Enter number of edges: ";
    cin>>e;
    cout<<"Enter the connected pairs (first source then destination): "<<endl;

    list<int> adj_list[v+1];

    for(int i=0; i<e; i++){
        int m,n;
        cin>>m>>n;
        add_edge(adj_list, m, n);
        add_edge(adj_list, n, m);
    }

    cout<<"Enter node to start traversing: ";
    int s;
    cin>>s;
    bfs(adj_list, s);

    return 0;
}
