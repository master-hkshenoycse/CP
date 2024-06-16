#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bit[100005];
    void upd(int ind,int n,int v){
        while(ind<=n){
            bit[ind]=bit[ind]+v;
            ind+=(ind & (-ind));
        }
    }
    
    int query(int ind){
        int s=0;
        while(ind>0){
            s=s+bit[ind];
            ind-=ind&(-ind);
        }
        return s;
    }
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> status(n+1,0);
        vector<int> a(n+1);
        
        for(int i=1;i<=n;i++){
            a[i]=nums[i-1];
        }
        
        for(int i=1;i<=n;i++){
            
            if(i-1>=1 and i+1<=n and a[i]>a[i-1] and a[i]>a[i+1]){
                status[i]=1;
                upd(i,n,status[i]);
            }
        }
        
        
        
        vector<int> sol;
        for(auto q:queries){
            if(q[0]==1){
                int l=q[1]+1;
                int r=q[2]+1;
                int ans=0;
                if(r-1>=l)ans=query(r-1)-query(l);
                sol.push_back(ans);
            }else{
                int index=q[1]+1;
                int value=q[2];
                
                a[index]=value;
                
                
                int prev=status[index];
                int curr=(index-1>=1 and index+1<=n and a[index]>a[index-1] and a[index]>a[index+1]);
                status[index]=curr;
                upd(index,n,curr-prev);
                
                
                if(index-1>=1){
                    int prev=status[index-1];
                    int curr=(index-1>=1 and index-2>=1 and index<=n and a[index-1]>a[index-2] and a[index-1]>a[index]);
                    status[index-1]=curr;
                    upd(index-1,n,curr-prev);
                }
                
                if(index+1<=n){
                    int prev=status[index+1];
                    int curr=(index+1<=n and index>=1 and index+2<=n and a[index+1]>a[index] and a[index+1]>a[index+2]);
                    status[index+1]=curr;
                    upd(index+1,n,curr-prev);
                }   
            }
            
        }
            
            return sol;
        }
    
};