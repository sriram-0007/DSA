#include<bits/stdc++.h>
using namespace std;

vector<int> graph[500005];

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> ans(n);
    vector<int> vis(n, 0);

    for(int i = 0; i < m; i++){
        int k;
        cin >> k;
        vector<int> ver;
        for(int j = 0; j < k; j++){
            int ele;
            cin >> ele;
            ver.push_back(--ele);
        }
        for(int j = 0; j + 1 < k; j++){
            graph[ver[j]].push_back(ver[j + 1]);
            graph[ver[j + 1]].push_back(ver[j]);
        }
    }

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vector<int> component;
            while(!q.empty()){
                int front = q.front();
                q.pop();
                if(!vis[front]){
                    vis[front] = 1;
                    component.push_back(front);
                    for(auto it : graph[front]){
                        if(!vis[it]){
                            q.push(it);
                        }
                    }
                }
            }
            for(auto it:component)ans[it]=component.size();
        }
    }
    
    for(int i=0;i<n;i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}
