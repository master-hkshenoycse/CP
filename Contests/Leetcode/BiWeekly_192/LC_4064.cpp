#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        vector<int> index_[k],index_double_[k];
        index_[0].push_back(0);
        int cs=0,n=nums.size();
        for(int i=1;i<=n;i++){
            cs=(cs+nums[i-1])%k;
            cs=(cs+k)%k;
            index_[cs].push_back(i);
            index_double_[((2*nums[i-1])%k+k)%k].push_back(i);
        }

        int ret=0;
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(index_[i].size()==0 || index_[j].size()==0)
                    continue;
                if(j==0)
                    ret=max(ret,index_[j].back());

                int mi=index_[i][0];
                int ma=index_[j].back();
                int req=(j-i+k)%k;

                if(ma<mi)
                    continue;
 
                //cout<<i<<" "<<j<<" "<<mi<<" "<<ma<<" "<<req<<endl;

                if(req==0 && ma!=mi)
                    ret=max(ret,ma-mi);
                else if(req!=0){
                    auto it=upper_bound(index_double_[req].begin(),index_double_[req].end(),mi);
                    if(it != index_double_[req].end() && (*it)<=ma)
                        ret=max(ret,ma-mi);
                }
            }
        }
        return ret;
    }
};