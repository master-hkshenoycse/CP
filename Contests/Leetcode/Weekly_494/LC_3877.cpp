#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void fill_subs(vector<int> &nums,int l,int r, map<int,int> &help){
        if(r<l){
            return;
        }
        int len=r-l+1;
        int lim=(1<<len);
        help[0]=0;
        for(int i=1;i<lim;i++){
            int sum=0,curr_len=0;
            for(int j=0;j<len;j++){
                if(i & (1<<j)){
                    sum=(sum^nums[l+j]);
                    curr_len++;
                }
            }
            if(help.find(sum)==help.end())
                help[sum]=curr_len;
            else
                help[sum]=max(help[sum],curr_len);
        }

    }
    int minRemovals(vector<int>& nums, int target) {
        map<int,int> h1,h2;
        int n=nums.size();

        fill_subs(nums,0,n/2,h1);
        fill_subs(nums,n/2+1,n-1,h2);

        int ans=-1;
        for(auto it:h1){
            if(it.first == target)
                ans=max(ans,it.second);
            
            if(h2.find(target ^ it.first) != h2.end())
                ans=max(ans,it.second + h2[target ^ it.first]);
        }

        for(auto it:h2){
            if(it.first==target)
                ans=max(ans,it.second);

            if(h1.find(target ^ it.first) != h1.end())
                ans=max(ans,it.second + h1[target ^ it.first]);
        }

        if(ans==-1)
            return ans;

        return n-ans;

               
    }
};