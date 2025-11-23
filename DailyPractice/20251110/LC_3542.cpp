#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0,n=nums.size();

        stack<int> st;

        for(auto e:nums){
            while(st.size()>0 && st.top()>e){
                st.pop();
            }
            if(e==0){
                continue;
            }

            if(st.size()==0 || st.top()<e){
                ans++;
                st.push(e);
            }

        }
       
        
        return ans;
    }
};