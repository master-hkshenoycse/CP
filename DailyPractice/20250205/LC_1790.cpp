#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size();
        int c=0,ind_1=-1,ind_2=-1;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                c++;
                if(ind_1 == -1 )ind_1=i;
                else ind_2=i;
            }
        }
        
        if(c==0)return 1;
        if(c!=2) return 0;
        
        swap(s1[ind_1],s1[ind_2]);
        return s1==s2;
    }
};