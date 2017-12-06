#include<bits/stdc++.h>
using namespace std;
#define MX 100

struct Edge
{
    int u;
    int v;
    int w;
};

bool operator < (Edge a , Edge b)
{
    return a.w < b.w;
}

int parent[MX];
vector<Edge> E;

int findParent(int u)
{
    if(parent[u] == u) return u;
    else return parent[u] = findParent(parent[u]);
}


int kruskal()
{
    sort(E.begin() , E.end());

    int sz = E.size();

    int ans = 0;
    for(int i = 0 ; i < sz ; i++)
    {
        if(findParent(E[i].u) != findParent(E[i].v))
        {
            //union
            parent[parent[E[i].u]] = parent[E[i].v];
            cout << "PRINT " ;
            cout << E[i].u << " " << E[i].v << " " << E[i].w << endl;
            ans+=E[i].w;
        }
    }
    return ans;
}

int main()
{
    freopen("prims.txt" , "r" , stdin);
    int vertex , edge;
    cin >> vertex >> edge;
    for(int i = 0 ; i < vertex ; i++)
    {
        parent[i] = i;
    }
    for(int i = 0 ; i < edge ; i++)
    {
        Edge e;
        cin >> e.u >> e.v >> e.w;
        E.push_back(e);
    }
    cout << kruskal() << endl;
}

