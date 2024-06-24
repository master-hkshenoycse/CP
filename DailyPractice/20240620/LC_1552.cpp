#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int lo=1,hi=1e9,ans=lo,n=position.size();

        while(hi>=lo){
            int mid=(hi+lo)/2;

            int prev=position[0],cnt=1;
            for(int i=1;i<n;i++){
                if(position[i]-prev>=mid){
                    cnt++;
                    prev=position[i];
                }
            }
            if(cnt>=m){
                ans=max(ans,mid);
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return ans;
    }
};