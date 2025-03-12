#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool checkPowersOfThree(int n) {
            int po=1;
            vector<int> powers;
            while(po<=n){
                powers.push_back(po);
                po=po*3;
            }
            
            int m=powers.size();
            int lim=(1<<m);
    
            for(int i=1;i<lim;i++){
                int s=0;
               for(int j=0;j<m;j++){
                   if(i & (1<<j))s=s+powers[j];
               } 
               if(s==n)return 1;
            }
            return 0;
        }
    };