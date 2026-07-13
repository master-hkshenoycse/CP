#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
 
   vector<int> sequentialDigits(int low, int high) {
        vector<int> sol;
       
        for(ll i=1;i<=9;i++){
            ll no=i;
            for(ll j=i+1;j<=9;j++){
                no=(no*10+j);
                if(no>=low && no<=high)sol.push_back(no);
            }
            
        }
       sort(sol.begin(),sol.end());
       return sol;
        
        
    }
};