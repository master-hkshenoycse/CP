#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> findEvenNumbers(vector<int>& digits) {
            vector<int> c1(10,0);
            
            for(auto d:digits){
                c1[d]++;
            }
            
            vector<int> sol;
            for(int i=100;i<=998;i+=2){
                vector<int> c2(10,0);
                int v=i;
                
                while(v>0){
                    c2[v%10]++;
                    v/=10;
                }
                int f=1;
                for(int j=0;j<10;j++){
                    if(c1[j]<c2[j]){
                        f=0;
                    }
                }
                
                if(f){
                    sol.push_back(i);
                }
                
                
            }
            return sol;
        }
    };