#include <bits/stdc++.h>

using namespace std;

#define MAX 10

#define WH 1
#define GR 2
#define BL 3

int color[MAX];

int Time=1;
int sTime[MAX];
int fTime[MAX];

int n,e;

vector <int> adj[MAX];

void dfsvisit(int at)
{
    color[at]=GR;
    sTime[at]=Time;
    ++Time;
    for(int i=0; i<adj[at].size(); i++)
    {
        int v=adj[at][i];
        if(color[v]==WH)
        {
            dfsvisit(v);
        }
    }
    color[at]=BL;
    fTime[at]=Time;
    ++Time;
    cout<<at<<" ";
}


void dfs()
{
    for(int k=0; k<n; k++)
    {
        color[k]=WH;
    }
    cout<<"DFS:"<<" ";
    for(int i=0; i<n; i++)
    {
        if(color[i]==WH)
            dfsvisit(i);
    }
}
int main()
{
    int u,v;
    cout<<"Total number of Node: ";
    cin>>n;
    cout<<"Total number of edges: ";
    cin>>e;
    cout<<"Enter the input like(0--->1):"<<endl;
    for(int i=0; i<e; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }
    dfs();
    cout<<endl;
    cout<<"The Starting and Finishing Time is:"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<i<<"--->"<<sTime[i]<<"/"<<fTime[i]<<endl;
    }

    return 0;
}
