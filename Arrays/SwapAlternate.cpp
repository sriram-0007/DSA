#include<bits/stdc++.h>
using namespace std;
void printArray(vector<int> v){
    for(auto i:v) cout<<i<<" ";
}
void swapAlternate(vector<int>& v){
    int n=v.size();
    for(int i=0;i<n;i+=2){
        if(i+1==n) break;
        swap(v[i],v[i+1]);
    }
}
int main(){
    vector<int> v;

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        v.push_back(ele);
    }

    swapAlternate(v);
    printArray(v);
    
    return 0;
}