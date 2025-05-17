#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int get_rots(vector<int> a,vector<int> b,int p){
            int sol=0;
            int n=a.size();
            for(int i=0;i<n;i++){
                if(a[i]==p ){
                    continue;
                }else if(a[i]!=p && b[i]==p){
                    sol++;
                }else{
                    return INT_MAX;
                }
            }
            
            
            return sol;
        }
        int minDominoRotations(vector<int>& A, vector<int>& B) {
            int ans=INT_MAX;
            
            for(int i=1;i<=6;i++) ans=min(ans,get_rots(A,B,i)),ans=min(ans,get_rots(B,A,i));
                
            
            
            if(ans==INT_MAX)return -1;
            return ans;
        }
    };