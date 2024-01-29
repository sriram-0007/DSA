#include<bits/stdc++.h>
using namespace std;
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
    queue<long long> st;
    
    for(long long i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            long long minPrice=INT_MAX;
            minPrice=min(minPrice,price[i]);
            st.push(i);
            while(!st.empty()){
                long long top=st.front();
                st.pop();
                for(auto it:graph[top]){
                    minPrice=min(minPrice,price[it]);
                    if(!vis[it]){
                    vis[it]=1;
                    st.push(it);
                    }
                }
            }
            ans+=minPrice;
        }
    }
    cout<<ans<<endl;
    return 0;

}