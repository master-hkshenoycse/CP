#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minJumps(vector<int>& arr) {
        map<int,int> vis_num;
        map<int,vector<int> >same_num;
        int n=arr.size();
        vector<int> dis(n+1,INT_MAX);
        
        
        for(int i=0;i<n;i++)same_num[arr[i]].push_back(i);
        
        queue<int> q;
        q.push(0);
        dis[0]=0;
        
        while(q.size()){
            int v=q.front();
            q.pop();
            
            if(v-1>=0 and dis[v-1]>dis[v]+1){
                q.push(v-1);
                dis[v-1]=dis[v]+1;
            }
            
            if(v+1<n and dis[v+1]>dis[v]+1){
                q.push(v+1);
                dis[v+1]=dis[v]+1;
            }
            
            if(vis_num[arr[v]])continue;
            vis_num[arr[v]]=1;
            
            for(auto x:same_num[arr[v]]){
                if(dis[x]>dis[v]+1){
                    q.push(x);
                    dis[x]=dis[v]+1;
                }
            }
            
        }
        
        
        return dis[n-1];
    }
};