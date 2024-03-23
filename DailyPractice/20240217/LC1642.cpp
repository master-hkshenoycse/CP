#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> h;
    bool chk(int ind,int b,int l){
        if(ind==0){
            return 1;
        }
        
        vector<int> req;
        for(int i=1;i<=ind;i++){
            if(h[i]-h[i-1]>0)req.push_back(h[i]-h[i-1]);
        }
        
        sort(req.begin(),req.end());
        reverse(req.begin(),req.end());
        
        if(req.size()<l){
            return 1;
        }
        
        int s=0;
        for(int i=l;i<req.size();i++)s+=req[i];
        
        return s<=b;
    
        
        
    }
    int furthestBuilding(vector<int> heights, int bricks, int ladders) {
        int n=heights.size();
        if(n==0){
            return 0;
        }
        
        
        h=heights;
        
        int lo=0;
        int hi=n-1;
        int ans=0;
        
        while(hi>=lo){
            int m=(hi+lo)/2;
            
            if(chk(m,bricks,ladders)){
                ans=max(ans,m);
                lo=m+1;
            }else{
                hi=m-1;
            }
            
        }
        
        return ans;
        
    }
};

int main(){
    Solution obj;
    cout<<obj.furthestBuilding({4,2,7,6,9,14,12},5,1)<<endl;
    cout<<obj.furthestBuilding({4,12,2,7,3,18,20,3,19},10,2)<<endl;
    cout<<obj.furthestBuilding({14,3,19,3},17,0)<<endl;

}