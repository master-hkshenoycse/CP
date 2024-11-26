#include<bits/stdc++.h>
using namespace std;
class Solution {
public: 
    bool check(vector<vector<int> >&queries,vector<int> &nums,int l){
        int mi=1e9;
        int ma=0;
        /*every adjacent element diff with -1 as interval*/
        for(auto q:queries){
            if(q[0] != -1){
                mi=min(mi,nums[q[0]]+l);
                ma=max(ma,nums[q[0]]-l);
            }

            if(q[1] != -1){
                mi=min(mi,nums[q[1]]+l);
                ma=max(ma,nums[q[1]]-l);
            }
        }

        if(mi>=ma){
            return 1;
        }

        for(auto q:queries){
            if(q[0]==-1 || q[1]==-1){
                continue;
            }

            int len=q[1]-q[0]-1;

            int m1=max(nums[q[1]],nums[q[0]]);
            int m2=min(nums[q[1]],nums[q[0]]);

            /*axxxxb*/
            if((abs(m1-mi)<=l && abs(m2-mi)<=l) || (abs(m1-ma)<=l && abs(m2-ma)<=l) ){
                continue;
            }
            
            /*axyb*/
            if(abs(ma-m1)<=l && abs(mi-m2)<=l && abs(ma-mi)<=l && len>1 ){
                continue;
            }

            return 0;

        }



        return 1;
    }
    int minDifference(vector<int>& nums) {
        int n=nums.size(),last=-1,min_poss=0;
        vector<vector<int> > queries_to_resolve;

        for(int i=0;i<n;i++){
            if(nums[i] != -1){
                if(i>0 && nums[i -1] != -1){
                    min_poss=max(min_poss,abs(nums[i]-nums[i-1]));
                }
                last=i;
                continue;
            }

            int p=i;
            while(p<n && nums[p]==-1){
                p++;
            }

            if(p==n){
                queries_to_resolve.push_back({last,-1});
            }else{
                queries_to_resolve.push_back({last,p});
            }

            i=p-1;

        }

        if(queries_to_resolve.size()==0){
            return min_poss;
        }

        int lo=min_poss,hi=1e9,ans=1e9;
        while(hi>=lo){
            int mid=(hi+lo)/2;

            if(check(queries_to_resolve,nums,mid)){
                ans=min(ans,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        return ans;
        
    }
};