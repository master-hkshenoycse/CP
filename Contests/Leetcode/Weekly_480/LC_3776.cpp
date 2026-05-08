#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n=balance.size();
        vector<int> vis(n,0);
        int neg_index=-1;
        for(int i=0;i<n;i++){
            if(balance[i]<0)
                neg_index=i;
        }

        if(neg_index==-1)
            return 0;
        
        ll steps=0;

        for(int i=1;i<n;i++){
            int li=((neg_index-i)%n+n)%n;
            int ri=(neg_index+i)%n;

            if(vis[li]==0){
                ll req=min(abs(balance[neg_index]),balance[li]);
                steps=steps+i*1ll*req;
                balance[neg_index]+=req;
                vis[li]=1;
            }

            if(vis[ri]==0){
                ll req=min(abs(balance[neg_index]),balance[ri]);
                steps=steps+i*1ll*req;
                balance[neg_index]+=req;
                vis[ri]=1;
            }

        }

        if(balance[neg_index]<0)
            return -1;

        return steps;

    }
};