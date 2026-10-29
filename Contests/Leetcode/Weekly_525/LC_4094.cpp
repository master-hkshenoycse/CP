#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int ans=0,n=nums.size();
        
        for(int i=0;i<n;i++){
            int uniq=0;
            map<int,int> freq,index;
            for(int j=i;j<n;j++){
                freq[nums[j]]++;
                if(freq[nums[j]]==1){
                    uniq++;
                    index[nums[j]]=uniq;
                }

                int len_req=(uniq*(uniq+1))/2ll;
                if(j-i+1==len_req){
                    int f=1;

                    for(auto it:freq)
                        if(it.second != index[it.first])
                            f=0;
                
                    ans=ans+f;
                    
                }
            }
        }

        return ans;
    }
};