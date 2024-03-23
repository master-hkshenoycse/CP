#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        
        int n=positions.size();
        vector<int> sol(n,0),h_seg(n,0);
        int ma=0;       

        for(int i=0;i<n;i++){
            int l=positions[i][0];
            int r=l+positions[i][1];
            
            int h_curr=positions[i][1];
            int h_=0;
            
            for(int j=0;j<i;j++){
                int st=positions[j][0];
                int en=st+positions[j][1];
                
                if(st>=r or en<=l){
                    continue;
                }
                h_=max(h_,h_seg[j]);
            }
            
            ma=max(ma,h_+h_curr);
            h_seg[i]=h_+h_curr;
            
            sol[i]=ma;
        }
        
        return sol;
    }
};