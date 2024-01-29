#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    cin>>n>>t;
    vector<int>arr;
    for(int i=0;i<n-1;i++){
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    int i=0,flag=0;
    while(i<n-1){
        i+=arr[i];
        if(i==t-1){
            flag=1;
            break;
        }
    }
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    return 0;
}