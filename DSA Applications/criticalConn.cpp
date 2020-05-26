
void bfs(int n,vector<int> &visited,vector< vector<int> > adj,int index)
{
    visited[n]=1;
    queue<int> q;
    q.push(n);
    int l;
    while(!q.empty())
    {
     int k=q.front();
        q.pop();
        visited[k]=1;
        for(int i=0;i<adj[k].size();i++)
        {
            l=adj[k][i];
            if(l!=index)
            {
                if(visited[l]==-1)
                {
                    q.push(l);
                    visited[l]==1;
                }
            }
        }
    }
    
}


vector<int> criticalConn(vector < vector<int> > connections, int v){
    vector< vector<int> > adj(v);
    vector<int> res;
    for(int i=0;i<connections.size();i++)
    {
        int a=connections[i][0];
        int b=connections[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
   
    for(int i=0;i<v;i++)
    {
        vector<int> visited(v,-1);
        if(i==0)
        bfs(1,visited,adj,i);
        else
            bfs(0,visited,adj,i);
        int l=0;
        for(int j=0;j<v;j++)
        {
            if(visited[j]==-1)
            {
                l++;
            }
        }
        if(l>1)
        res.push_back(i);
    }
    return res;
}

int main() {
   
    
    vector < vector<int> > connections{{0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 5}, {5, 6}, {3, 4}};
    int v=7;
    
    for(auto v: criticalConn(connections,v)){
        cout << v <<endl;
    }
}
