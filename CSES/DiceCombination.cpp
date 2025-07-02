#include<bits/stdc++.h>
using namespace std;

int solve(int n,int& mod,vector<int>&dp){
    if(n==0)return 1;
    if(n<0)return 0;
    if(dp[n]!=-1)return dp[n];
    int ans=0;
    for(int i=1;i<=6;i++){
        ans=(ans%mod+solve(n-i,mod,dp)%mod)%mod;
    }
    return dp[n]=ans;
}
int main(){
    int n;
    
    cin>>n;
    vector<int>dp(n+1,-1);
    int mod=1e9+7;
    cout<<solve(n,mod,dp);
    return 0;
}