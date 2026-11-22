#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkString(string s) {
        int n=s.size();
        int mi_b=n,ma_a=-1;
        
        for(int i=0;i<n;i++){
            if(s[i]=='a')ma_a=max(ma_a,i);
            if(s[i]=='b')mi_b=min(mi_b,i);
        }
        
        return ma_a<mi_b;
    }
};