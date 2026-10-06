#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_dist(int x,int y){
        return min(abs(x-y),10-abs(x-y));
    }
    int minRotations(int n, string s) {
        vector<int> pref(n,0);
        int init=0;
        int ans=1e9;
        for(int i=0;i<n;i++){
            pref[i]=get_dist(init,s[i]-'0');
            if(i-1>=0)
                pref[i]+=pref[i-1];
            init=s[i]-'0';
        }
        ans=pref[n-1];


        int suff=0;
        for(int i=n-2;i>=0;i--){
            suff=suff+get_dist(s[i]-'0',s[i+1]-'0');
            int ops=suff;
            if(i-1>=0)
                ops+=pref[i-1];
            
            if(i-1>=0)
                ops+=get_dist(s[i-1]-'0',s.back()-'0');
            else
                ops+=get_dist(s.back()-'0',0);
            ans=min(ans,ops);
        }
        return ans;
    }
};