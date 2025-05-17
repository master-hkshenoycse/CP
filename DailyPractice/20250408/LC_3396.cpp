#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            int n=nums.size();
            set<int> x;
            int len=0;
            for(int i=n-1;i>=0;i--){
                if(x.find(nums[i])==x.end()){
                    len++;
                    x.insert(nums[i]);
                }else{
                    break;
                }
            }
            
            return (n-len+2)/3;
            
        }
    };