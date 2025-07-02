#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,INT_MAX);
    dp[0]=0;
    // int count=0;
    // while(n>0){
    //     if(n<10){
    //         count++;
    //         n=0;
    //     }else{
    //         int md=0;
    //         int temp=n;
    //         while(temp>0){
    //             int d=temp%10;
    //             temp/=10;
    //             md=max(md,d);
    //         }
    //         n=n-md;
    //         count++;
    //     }
    // }
    for(int i=1;i<=n;i++){
        string digits=to_string(i);
        for(int j=0;j<digits.size();j++){
            int d=digits[j]-'0';
            if(d!=0 && i>=d)
            dp[i]=min(dp[i],1+dp[i-d]);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}