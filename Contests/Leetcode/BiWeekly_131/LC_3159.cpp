#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> help;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==x){
                help.push_back(i);
            }
        }
        
        vector<int> sol;
        for(auto q:queries){
            if(help.size() < q){
                sol.push_back(-1);
            }else{
                sol.push_back(help[q-1]);
            }
        }
        
        return sol;
    }
};