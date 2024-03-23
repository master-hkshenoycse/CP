#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> a1,a2;
        a1.push_back(nums[0]);
        a2.push_back(nums[1]);
        
        int i=2;
        while(i<n){
            if(a1.back()>a2.back()){
                a1.push_back(nums[i]);
            }else{
                a2.push_back(nums[i]);
            }
            i++;
        }
        
        for(int i=0;i<a2.size();i++){
            a1.push_back(a2[i]);
        }
        return a1;
    }
};