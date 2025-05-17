#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            int ans=0;
            map<pair<int,int>,int> help;
            for(auto d:dominoes){
                int x=d[0];
                int y=d[1];
                if(x>y){
                    swap(x,y);
                }
    
                ans=ans+help[{x,y}];
                help[{x,y}]++;
            }
            return ans;
        }
    };