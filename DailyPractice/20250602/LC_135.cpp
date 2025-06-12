#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int candy(vector<int>& ratings) {
            int n=ratings.size();
            vector<vector<int> > r;
            for(int i=0;i<n;i++){
                r.push_back({ratings[i],i});
            }   
            sort(r.begin(),r.end());
            
            vector<int> sol(n+2,0);
    
            for(int i=0;i<n;i++){
                int ind=r[i][1];
                int curr=0;
    
                if(ind-1>=0 and ratings[ind-1]<ratings[ind]){
                    curr=max(curr,sol[ind-1]);
                }
    
                if(ind+1<n and ratings[ind+1]<ratings[ind]){
                    curr=max(curr,sol[ind+1]);
                }
    
                sol[ind]=curr+1;
            }
    
            int ans=0;
            for(int i=0;i<n;i++){
                ans=ans+sol[i];
            }
            return ans;
    
        }
    };