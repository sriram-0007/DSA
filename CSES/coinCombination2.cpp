#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    int mod=1e9+7;
    vector<int>d(n);
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(x+1,0));
    for(int i=0;i<n;i++)dp[i][0]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=x;j++){
            int skip=dp[i+1][j];
            int pick=0;
            if(j>=d[i])pick=dp[i][j-d[i]];
            dp[i][j]=(skip+pick)%mod;
        }
    }
    cout<<dp[0][x];
    return 0;
}