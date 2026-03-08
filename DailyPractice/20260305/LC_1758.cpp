#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(string s) {
        int ce1=0,ce0=0,co1=0,co0=0;
        int n=s.size();
        
        for(int i=0;i<n;i++){
            if(i%2){
                if(s[i]=='1')co1++;
                else co0++;
            }else{
                if(s[i]=='1')ce1++;
                else ce0++;
            }
        }
        return n-max(ce1+co0,ce0+co1);
    }
};