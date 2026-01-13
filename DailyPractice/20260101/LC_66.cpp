#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c=0;
        int d=1;
        int n=digits.size();
        
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                int c_new=(c+digits[i]+1)/10;
                digits[i]=(c+digits[i]+1)%10;
                c=c_new;
            }else{
                int c_new=(c+digits[i])/10;
                digits[i]=(c+digits[i])%10;
                c=c_new;
            }
        }
        
        vector<int> sol;
        if(c>0) sol.push_back(c);
        for(int i=0;i<n;i++)sol.push_back(digits[i]);
        return sol;
    }
};