#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findLucky(vector<int>& arr) {
            map<int,int> help;
            for(auto e:arr){
                help[e]++;
            }
    
            int ans=-1;
            for(auto it:help){
                if(it.second == it.first){
                    ans = it.first;
                }
            }
            
            return ans;
        }
    };