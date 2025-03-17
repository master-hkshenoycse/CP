#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
            map<int,vector<int> > index_by_num;
            int n=nums.size();
            
            for(int i=0;i<n;i++){
                index_by_num[nums[i]].push_back(i);
            }
            
            vector<int> sol;
            
            for(int i=0;i<queries.size();i++){
                int q=nums[queries[i]];
                
                int d=1e9;
                int sz=index_by_num[q].size();
                if(sz>1){
                    
                    int ind=lower_bound(index_by_num[q].begin(),index_by_num[q].end(),queries[i])-index_by_num[q].begin();
                    int prev=(ind-1+sz)%sz;
                    int nx=(ind+1)%sz;
                    //cout<<ind<<" "<<prev<<" "<<nx<<" "<<sz<<endl;
                    int prev_d=min(abs(index_by_num[q][ind]-index_by_num[q][prev]),n-abs(index_by_num[q][ind]-index_by_num[q][prev]));
                    int nx_d=min(abs(index_by_num[q][ind]-index_by_num[q][nx]),n-abs(index_by_num[q][ind]-index_by_num[q][nx]));
                    
    
                    if(prev_d < d){
                        d=prev_d;
                    }
                    
                    if(nx_d < d){
                        d=nx_d;
                    }
                }
                
                if(d==1e9){
                    d=-1;
                }
                sol.push_back(d);
                
            }
            
            return sol;
        }
    };