#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    int mod=1e9+7;
    vector<int>d(n);
    vector<int>dp(x+1,0);
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    dp[0]=1;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i>=d[j])
            dp[i]=(dp[i]+dp[i-d[j]])%mod;
        }
    }
    cout<< dp[x];
    
    return 0;
}