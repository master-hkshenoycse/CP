#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestGoodInteger(string num) {
        int v=-1,n=num.size();
        
        for(int i=0;i<n-2;i++){
            if(num[i]==num[i+1] and num[i+1]==num[i+2]){
                v=max(v,num[i]-'0');
            }
        }
            
        string sol;
        if(v==-1){
            return sol;
        }
        for(int i=0;i<3;i++){
            sol+=char('0'+v);
        }
        return sol;
    }   
};