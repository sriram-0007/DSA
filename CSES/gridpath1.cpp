#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int mod=1e9+7;
    vector<vector<char>>arr(n,vector<char>(n));
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i==n-1 && j==n-1){
                if(arr[i][j]=='.')dp[i][j]=1;
                else dp[i][j]=0;
            }
            else if(arr[i][j]=='*')dp[i][j]=0;
            else{
                if (i + 1 < n) dp[i][j] = (dp[i][j] + dp[i + 1][j]) % mod;
                if (j + 1 < n) dp[i][j] = (dp[i][j] + dp[i][j + 1]) % mod;
            }
        }
    }
    cout<< dp[0][0];
    return 0;
}