#include<bits/stdc++.h>
using namespace std;
int solve(int x,vector<int>&d,vector<int>&dp){
    if(x==0)return 0;
    if(x<0)return 1e6+7;
    if(dp[x]!=-1)return dp[x];
    int ans=1e6+7;
    for(auto& it:d){
        ans=min(ans,1+solve(x-it,d,dp));
    }
    return dp[x]=ans;
}
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>dp(x+1,1e6+7);
    vector<int>d(n);
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    //int ans=solve(x,d,dp);
   // cout<<((ans==1e6+7)?-1:ans);
   dp[0]=0;
   for(int i=1;i<=x;i++){
    for(int j=0;j<d.size();j++){
        if(i>=d[j])
        dp[i]=min(dp[i],dp[i-d[j]]+1);
    }
   }
   cout<<((dp[x]>=1e6+7)?-1:dp[x]);
    return 0;
}