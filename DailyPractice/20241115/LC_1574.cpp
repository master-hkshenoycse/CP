#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        vector<int> suff_valid(n,0);
        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(i==n-1 or arr[i]<=arr[i+1]){
                suff_valid[i]=1;
                ans=max(ans,n-i);
            }else{
                break;
            }
        }
        
        for(int i=0;i<n;i++){
            if(i==0 or arr[i]>=arr[i-1]){
                int lo=i+1,hi=n-1,r=n;
                while(hi>=lo){
                    int mid=(hi+lo)/2;
                    if(suff_valid[mid]==1 && arr[mid]>=arr[i]){
                        r=min(r,mid);
                        hi=mid-1;
                    }else{
                        lo=mid+1;
                    }
                }

                ans=max(ans,i+1+n-r);
            }else{
                break;
            }
        }

        return n-ans;
    }
};