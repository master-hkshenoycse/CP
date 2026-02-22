#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check_component(int st,vector<int> col, vector<vector<int> >&adj){
        col[st]=1;
        queue<int> q;
        q.push(st);

        while(q.size()>0){
            int curr=q.front();
            q.pop();

            for(auto nx:adj[curr]){
                if(col[nx]==0){
                    col[nx]=3-col[curr];
                    q.push(nx);
                }else{
                    if(col[nx] == col[curr])
                        return 0;
                }
            }
        }

        return 1;
        
    }
    bool check_bipartite(int n,vector<vector<int> >&adj){
        vector<int> col(n,0);

        for(int i=0;i<n;i++){
            if(col[i]==0){
                if(check_component(i,col,adj)==0)
                    return 0;
            }
        }

        return 1;
    }
    bool check(int lim, vector<vector<int> >&manhattan){
        int n=manhattan.size();
        vector<vector<int> > adj(n);

        if(n==2){
            return 0;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                if(manhattan[i][j]<lim){
                    adj[i].push_back(j);
                }
            }
        }

        return check_bipartite(n, adj);
    }
    int maxPartitionFactor(vector<vector<int>>& points) {
        int ret=0,lo=0,hi=4e8;
        int n=points.size();
        vector<vector<int> > manhattan_dis(n,vector<int> (n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                manhattan_dis[i][j]=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
            }
        }

        while(hi>=lo){
            int mid=(hi+lo)/2;

            if(check(mid,manhattan_dis)){
                ret=max(ret,mid);
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }

        return ret;
    }
};