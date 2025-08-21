#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> get_summary(int n){
        vector<int> cnt(10,0);
        
        while(n>0){
            cnt[n%10]++;
            n/=10;
        }
        
        return cnt;
    }
    
    bool chk(vector<int> a,vector<int> b){
        for(int i=0;i<10;i++){
            if(a[i]!=b[i])return 0;
        }
        return 1;
    }
    bool reorderedPowerOf2(int N) {
        
        
        int po=1;
        
        while(po<=INT_MAX){
            
            
            if(chk(get_summary(N),get_summary(po))){
                return 1;
            }
               
               
            
            
            
            if(po<INT_MAX/2){
                po=po*2;
            }else{
                break;
            }
            
            
        }
        
        
        return 0;
        
        
        
        
        
    }
};