#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size(),lo=0,hi=1e9,ans=hi+1;
        
        while(hi>=lo){
            int mid=(hi+lo)/2ll;
            int i=0,cnt=0;
            while(i<n){
                if(bloomDay[i]>mid){
                    i++;
                    continue;
                }

                int j=i,tmp=0;
                while(j<n and bloomDay[j]<=mid){
                    j++;
                    tmp++;
                }
                cnt+=tmp/k;
                i=j;
            }

            if(cnt>=m){
                ans=min(ans,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }

        }

        if(ans>1e9){
            ans=-1;
        }

        return ans;
    }
};