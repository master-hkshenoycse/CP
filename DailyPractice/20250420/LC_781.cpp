#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            map<int,int> cnt;
            for(auto e:answers){
                cnt[e]++;
            }
    
            int ans=0;
    
            for(auto it:cnt){
                int value = it.first+1;
                int people = it.second;
                int groups = (people+value-1)/value;
                //cout<<value<<" "<<groups<<endl;
                ans=ans+groups*value;
            }
    
            return ans;
        }
    };