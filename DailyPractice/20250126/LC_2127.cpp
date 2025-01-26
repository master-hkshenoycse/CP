#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n=favorite.size();
        vector<int> in_deg(n,0),chainLength(n,0),vis(n,0);

        for(auto f:favorite){
            in_deg[f]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(in_deg[i]==0){
                q.push(i);
            }
        }

        while(q.size()>0){
            int node=q.front();
            q.pop();
            vis[node]=1;

            int next=favorite[node];
            chainLength[next]=chainLength[node]+1;
            in_deg[next]--;

            if(in_deg[next]==0){
                q.push(next);
            }
    
        }

        int maxCycle=0,totalChain=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){

                int current=i,cycLen=0;
                while(!vis[current]){
                    vis[current]=true;
                    current=favorite[current];
                    cycLen++;
                }

                if(cycLen==2){
                    totalChain+=2+chainLength[i]+chainLength[favorite[i]];
                }else{
                    maxCycle=max(maxCycle,cycLen);
                }
            }
        }

        return max(maxCycle,totalChain);

        
    }
};