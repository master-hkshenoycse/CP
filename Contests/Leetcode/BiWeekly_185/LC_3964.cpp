#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size();
        vector<int> vis(n,0);
        vector<vector<int> > intervals;
        for(int i=0;i<n;i++){
            if(lights[i]>0)
                intervals.push_back({max(i-lights[i],0),min(n-1,i+lights[i])});
        }
        sort(intervals.begin(),intervals.end());

        int l=-1,r=-1;
        for(auto it:intervals){
            if(it[0]>r){
                if(l!=-1){
                    for(int i=l;i<=r;i++)
                        vis[i]=1;
                }
                l=it[0];
                r=it[1];
            }else{
                r=max(r,it[1]);
            }
        }
        if(l!=-1)
            for(int i=l;i<=r;i++)
                vis[i]=1;
        

        int ans=0,i=0;
        while(i<n){
            if(vis[i])
                i++;
            else{
                int j=i,cnt=0;
                while(j<n && vis[j]==0)
                    j++,cnt++;
                ans=ans+(cnt+2)/3;
                i=j;
            }
        }

        return ans;

    }
};