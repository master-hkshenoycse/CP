#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkOnesSegment(string s) {
        
        int c=0;
        int n=s.size();
        
        for(int i=0;i<n;i++)c+=(s[i]=='1');
        int i=0;
        
        while(i<n){
            if(s[i]=='0')i++;
            else{
                int chk=0;
                
                while(i<n and s[i]=='1')chk++,i++;
                
                
                return (chk==c);
            }
        }
        return 0;
    }
};