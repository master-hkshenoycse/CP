#include<bits/stdc++.h>
using namespace std;
/*Another way is to find shortest subbaryy which has aelements from all lists*/


class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>  ,vector<vector<int>  >,greater< vector<int> > > pq;
        int n=nums.size();
        
        int sol_mi,sol_ma,ans=INT_MAX,mi=INT_MAX,ma=INT_MIN;
        for(int i=0;i<n;i++){
            
            pq.push({nums[i][0],0,i});
            mi=min(mi,nums[i][0]);
            ma=max(ma,nums[i][0]);
        } 

        if(ma-mi<ans){
            ans=ma-mi;
            sol_mi=mi;
            sol_ma=ma;
        }


        

        while(1){

            int value=pq.top()[0];
            int ind=pq.top()[1];
            int list_no=pq.top()[2];

            pq.pop();

            mi=value;

            if(ma-mi<ans){
                ans=ma-mi;
                sol_mi=mi;
                sol_ma=ma;
            }

            if(ind+1<nums[list_no].size()){
              
                ma=max(ma,nums[list_no][ind+1]);
                pq.push({nums[list_no][ind+1],ind+1,list_no});
            }else{
                //can;t have 1 element from each list
                break;
            }   
        }

        return {sol_mi,sol_ma};
    }
};