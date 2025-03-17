#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
           
            int n=nums.size();
            int sz=queries.size();
            
            int lo=0,hi=sz,ret=sz+1;
            
            while(hi>=lo){
                int mid=(hi+lo)/2;
                
                set<int> poss[n];
                for(int i=0;i<n;i++){
                    poss[i].insert(0);
                }
                
                for(int i=0;i<mid;i++){
                    
                    int l=queries[i][0];
                    int r=queries[i][1];
                    int val=queries[i][2];
                    
                    
                    for(int j=l;j<=r;j++){
                        
                        if(poss[j].find(nums[j]) != poss[j].end()){
                            continue;
                        }
                        
                        set<int> ex;
                        
                        for(auto p:poss[j]){
                            if(p + val <= nums[j]){
                                ex.insert(p+val);
                            }
                        }
                        
                        for(auto p:ex){
                            poss[j].insert(p);
                        }
                        
                    }
                    
                    
                    
                }
                
                int f=1;
                for(int i=0;i<n;i++){
                    if(poss[i].find(nums[i]) == poss[i].end()){
                        f=0;
                        break;
                    }
                }
                
                if(f){
                    ret=min(ret,mid);
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }
            
            
            if(ret==sz+1){
                ret=-1;
            }
            
            return ret;
        }
    };