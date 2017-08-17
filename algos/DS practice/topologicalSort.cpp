#include<bits/stdc++.h>

using namespace std;

typedef struct Graph
{
    int v; //number of vertices
    list<int> *adj; //for maintaining adjacency list
};

void topoSort(Graph G)
{
    vector<int> indegree(G.v, 0);
    vector<int> topoSorted;
    queue<int> q;
    int i;

    //calculating in degrees of all vertices
    for(i=0; i<G.v; i++)
    {

        list<int>::iterator adjV;
        for(adjV = G.adj[i].begin() ; adjV!=G.adj[i].end(); adjV++)
        {
            indegree[*adjV]++;
        }
    }

    //Checking for nodes having 0 dependency, i.e. the entry nodes
    for(i=0; i<G.v; i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }

    //Processing the nodes which have 0 dependencies currently and adding more to this queue
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topoSorted.push_back(node);

        list<int>::iterator itr;
        for(itr=G.adj[node].begin() ; itr!= G.adj[node].end(); itr++)
        {
            if(--indegree[*itr] == 0)
            {
                q.push(*itr);
            }
        }
    }

    //printing the sorted result
    for(vector<int>::iterator itr=topoSorted.begin(); itr!= topoSorted.end(); itr++)
    {
        cout<<*itr<<", ";
    }
}

void insertEdge(Graph *G, int src, int dest)
{
    (G->adj[src]).push_back(dest);
}

int main()
{
    Graph G;
    G.v = 6;
    G.adj = new list<int>[G.v];

    insertEdge(&G, 5, 2);
    insertEdge(&G, 5, 0);
    insertEdge(&G, 4, 0);
    insertEdge(&G, 4, 1);
    insertEdge(&G, 2, 3);
    insertEdge(&G, 3, 1);

    topoSort(G);

}
