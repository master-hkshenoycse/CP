#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int> pref(n+1,0);
        int min_one=n,ma_one=-1,c1=0,min_z=n,ma_z=-1,c0=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                c0++;
                min_z=min(min_z,i);
                ma_z=max(ma_z,i);
                pref[i+1]=1;
            }else{
                c1++;
                min_one=min(min_one,i);
                ma_one=max(ma_one,i);
            }
            pref[i+1]=pref[i+1]+pref[i];
            
        }
        
        if(c1==0 or c0==0)return 0;
        
        int ans=n+1;
        
        for(int i=1;i<=n;i++){
            if(i+c1-1<=n){
                ans=min(ans,pref[i+c1-1]-pref[i-1]);
            }
        }
        
        //cout<<endl;
        for(int i=0;i<=n;i++){
            int ch=pref[i];
            int lef=c1-i;
            
            if(lef<0){
                break;
            }
            
           // cout<<i<<" "<<pref[i]<<" "<<lef<<" "<<pref[n]-pref[n-lef]<<endl;
            ans=min(ans,pref[i]+(pref[n]-pref[n-lef]));
            
        }
    
        
        
        return ans;
        
        
    }
};