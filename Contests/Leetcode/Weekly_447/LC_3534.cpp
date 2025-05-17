#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        
        vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
           
            vector<vector<int> > v;
            for(int i=0;i<n;i++){
                v.push_back({nums[i],i});
            }
    
            sort(v.begin(),v.end());
            map<int,int> value_index_map;
            vector<vector<int> > binary_lift(n,vector<int> (20,-1));
        
    
            int j=0;
            for(int i=0;i<n;i++){
                value_index_map[v[i][1]]=i;
                while(j<n && v[j][0]-v[i][0]<=maxDiff){
                    j++;
                }
                if(j-1>i){
                    binary_lift[i][0]=j-1;
                }
            }
    
            for(int j=1;j<=19;j++){
                for(int i=0;i<n;i++){
                    if(binary_lift[i][j-1] != -1){
                        binary_lift[i][j]=binary_lift[binary_lift[i][j-1]][j-1];
                    }
                }
            }
    
            vector<int> res;
    
            for(auto q:queries){
                int x=value_index_map[q[0]];
                int y=value_index_map[q[1]];
                if(x>y){
                    swap(x,y);
                }
    
                int ret=-1;
                if(x==y){
                    ret=0;
                }else{
                    int steps=0,curr=x;
                    for(int j=17;j>=0;j--){
                        if(binary_lift[curr][j] != -1 && binary_lift[curr][j]<y){
                            curr=binary_lift[curr][j];
                            steps+=(1<<j);
                        }
                    }
    
                    if(binary_lift[curr][0]>=y){
                        ret=steps+1;
                    }
                }
             
                res.push_back(ret);
            }
    
            return res;
    
    
    
            
        }
    };