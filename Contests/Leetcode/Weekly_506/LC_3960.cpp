#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getLength(vector<int>& nums) {
        int ans=0,n=nums.size();
        
        for(int i=0;i<n;i++){
            map<int,int> freq,freq_freq;

            for(int j=i;j<n;j++){
                if(freq.find(nums[j])!=freq.end()){
                    freq_freq[freq[nums[j]]]--;
                    if(freq_freq[freq[nums[j]]]==0)
                        freq_freq.erase(freq[nums[j]]);
                }
                freq[nums[j]]++;
                freq_freq[freq[nums[j]]]++;
                //cout<<i<<" "<<j<<" "<<freq_freq.size()<<endl;
                if(freq_freq.size()==2){
                    int f1=(freq_freq.begin())->first;
                    int f2=(++freq_freq.begin())->first;
                    if(f2==2*f1)
                        ans=max(ans,j-i+1);
                }else if(freq.size()==1){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};