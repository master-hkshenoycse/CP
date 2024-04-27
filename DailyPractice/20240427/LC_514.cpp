#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calc_rotation(int x,int y,int n){
        return min(abs(x-y),n-abs(x-y));
    }
    int findRotateSteps(string ring, string key) {
        vector<int> occ[26];
        int n=ring.size();

        for(int i=0;i<n;i++){
            occ[ring[i]-'a'].push_back(i);
        }

        map<int,int> help;
        help[0]=0;

        for(int i=0;i<key.size();i++){
            map<int,int> tmp;
            for(auto ind:occ[key[i]-'a']){
                tmp[ind]=INT_MAX;
                for(auto prev:help){
                    tmp[ind]=min(tmp[ind],help[prev.first]+calc_rotation(ind,prev.first,n)+1);
                }
            }

            help=tmp;
        }

        int ans=INT_MAX;
        for(auto it:help){
            ans=min(ans,it.second);
        }
        return ans;

    }
};