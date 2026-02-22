#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size(),m=b.size();
        int i=0;

        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        int c=0;


        string sol;

        while(i<n or i<m){
            int v1=0,v2=0;
            if(i<n)v1=a[i]-'0';
            if(i<m)v2=b[i]-'0';
            int nv=(v1+v2+c)%2;
            c=(v1+v2+c)/2;

            sol+=char('0'+nv);
            i++;
        }

        if(c>0){
            sol+=char('0'+c);
        }

        
        reverse(sol.begin(),sol.end());




        return sol;
    }
};