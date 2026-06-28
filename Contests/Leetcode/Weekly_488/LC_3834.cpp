#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<ll> sol;

        for(auto e:nums){
            sol.push_back(e);

            while(sol.size()>1){
                ll x=sol.back();
                sol.pop_back();
                ll y=sol.back();
                sol.pop_back();

                if(x==y){
                    sol.push_back(x+y);
                }else{
                    sol.push_back(y);
                    sol.push_back(x);
                    break;
                }
            }
        }

        return sol;
    }
};