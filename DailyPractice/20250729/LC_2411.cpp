#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int> > csum(31,vector<int> (n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=0;j<31;j++){
                csum[j][i]=csum[j][i-1];

                if(nums[i-1]&(1<<j)){
                    csum[j][i]++;
                }
            }
        }

        vector<int> sol(n);
        
        for(int i=1;i<=n;i++){
            int lo=i,hi=n,ret=n;

            while(hi>=lo){
                int mid=(hi+lo)/2;
                int chk=1;
                for(int j=0;j<31;j++){
                    int c1 = csum[j][mid]-csum[j][i-1];
                    int c2 = csum[j][n] - csum[j][i-1];
                    if( c2>0 && c1==0){
                        chk=0;
                        break;
                    }
                }

                if(chk){
                    ret=min(ret,mid);
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }
            
            sol[i-1]=ret-i+1;
        }

        return sol;
    }
};