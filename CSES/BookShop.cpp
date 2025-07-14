#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>pages(n),cost(n);
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(x+1,0));
    for(int i=1;i<=n;i++){
        for(int j=x;j>=0;j--){
            int c=cost[i-1];
            int p=pages[i-1];
            int skip=dp[i-1][j];
            int take=(j>=c)?dp[i-1][j-c]+p:0;
            dp[i][j]=max(skip,take);
        }
    }
    cout<<dp[n][x]<<endl;
    return 0;
}