#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int st=0;
        int en=n-1;
        vector<int> sol(n);
        
        
        for(int i=n-1;i>=0;i--){
            if(abs(nums[st]) < abs(nums[en])){
                sol[i]=nums[en]*nums[en];
                en--;
            }else{
                sol[i]=nums[st]*nums[st];
                st++;
            }
        }
        return sol;
    }
};