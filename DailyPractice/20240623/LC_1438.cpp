#include <bits/stdc++.h>
#define ll long long
using namespace std;
class Solution {
public:
    int get_val(multiset<int> &m){
        return *(--m.end())-*(m.begin());
    }
    int longestSubarray(vector<int>& nums, int limit) {
        
        int j=0,ans=0,n=nums.size();
        multiset<int> m;
        
        
        for(int i=0;i<n;i++){
            m.insert(nums[i]);
            
            while(j<i and get_val(m)>limit){
                m.erase(m.find(nums[j]));
                j++;
            }
            
            ans=max(ans,i-j+1);
        }
        
        return ans;
    }
};