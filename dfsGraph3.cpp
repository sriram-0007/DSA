#include<bits/stdc++.h>
#define _USE_MATH_DEFINES
using namespace std;
long long dfs(int i,vector<long long>&price,vector<long long>&vis,vector<long long> graph[]){
    long long Cost=price[i];
    vis[i]=1;
    long long min=price[i];
    for(auto it:graph[i]){
        if(!vis[it]){
        vis[it]=1;
        long long s=dfs(it,price,vis,graph);
        Cost=std::min(s,Cost);
        }
    }
    return Cost;

}
int main(){
    long long n,m;
    long long ans=0;
    cin>>n>>m;
    vector<long long>price(n+1,-1);
    for(long long i=1;i<=n;i++){
        long long a;
        cin>>a;
        price[i]=a;
    }
    vector<long long> graph[n+1];
    for(long long i=1;i<=m;i++){
        long long v,e;
        cin>>v>>e;
        graph[v].push_back(e);
        graph[e].push_back(v);
    }
    vector<long long>vis(n+1,0);
    vis[0]=1;
    long long cost=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cost+=dfs(i,price,vis,graph);
        }
        
    }
    cout<<cost<<endl;
    return 0;
}