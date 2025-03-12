#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
            int n=fruits.size(),m=baskets.size(),ans=0;
            for(int i=0;i<n;i++){
                int f=1;
                for(int j=0;j<m;j++){
                    if(baskets[j] >= fruits[i]){
                        baskets[j]=0;
                        f=0;
                        break;
                    }
                }
                
                ans=ans+f;
            }
            
            return ans;
        }
    };