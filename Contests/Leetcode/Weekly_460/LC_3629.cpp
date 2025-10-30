#include<bits/stdc++.h>
using namespace std;
int isp[1000005];
int done=0;

void prec(){
    if(done){
        return;
    }
    done=1;
    isp[1]=1;
    for(int i=2;i<=1000000;i++){
        if(isp[i]==0){
            for(int j=2*i;j<=1000000;j+=i){
                isp[j]=1;
            }
        }
    }
}
class Solution {
public:
    int minJumps(vector<int>& nums) {

        prec();
        int n=nums.size();
        vector<int> vis(n,-1);
        queue<int> q;
        vis[0]=0;
        q.push(0);

        map<int,vector<int> > help;
        for(int i=0;i<n;i++){
            help[nums[i]].push_back(i);        
        }

        while(q.size()>0){
            int v=q.front();
            q.pop();

            if(v-1>=0 && vis[v-1]==-1){
                vis[v-1]=vis[v]+1;
                q.push(v-1);
            }

            if(v+1<n && vis[v+1]==-1){
                vis[v+1]=vis[v]+1;
                q.push(v+1);
            }

            if(isp[nums[v]]==0){
                if(help.find(nums[v]) == help.end()){
                    continue;
                }
                for(int j=nums[v];j<=1000000;j+=nums[v]){
                    if(help.find(j) == help.end()){
                        continue;
                    }
                    while(help[j].size()>0){
                        if(vis[help[j].back()]==-1){
                            vis[help[j].back()]=vis[v]+1;
                            q.push(help[j].back());
                        }
                        help[j].pop_back();
                    }
                    help.erase(j);
                }
            }
        }

        return vis[n-1];
        
    }
};