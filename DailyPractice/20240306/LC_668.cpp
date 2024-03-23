#include<bits/stdc++.h>
using namespace std;
/* Binary search on answer and count the number of numbers <= mid in multuiplication table*/
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int ans=m*n,lo=1,hi=m*n;

        while(hi>=lo){
            int mid=(hi+lo)/2;
            int cnt=0;
            for(int i=1;i<=m;i++){
                cnt=cnt+min(mid/i,n);
            }

            if(cnt>=k){
                ans=min(ans,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        return ans;   
    }
};