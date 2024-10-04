#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    vector<int> z_function(string &s){
        int n=s.size();
        vector<int> z(n);
        int l=0,r=0;
        for(int i=1;i<n;i++){
            if(i<r){
                z[i]=min(r-i,z[i-l]);
            }

            while(i+z[i]<n and s[z[i]]==s[i+z[i]]){
                z[i]++;
            }

            while(i+z[i]>r){
                l=i;
                r=i+z[i];
            }
        }

        return z;
    }
    int minStartingIndex(string s, string pattern) {
        int n=s.size(),m=pattern.size();
        string a=pattern+'#'+s;
        string b=s+'#'+pattern;
        reverse(b.begin(),b.end());

        vector<int> z_forward=z_function(a);
        vector<int> z_backward=z_function(b);

        for(int i=m+1;i<n+m+1;i++){
            if(i+m-1>n+m){
                break;
            }
            int x=z_forward[i];
            int id=i-m-1;// actual index in s
            if(x>=m-1){
                return id;
            }

            int req=m-x-1;
            
            int new_id=id+m-1;//suffix match from this
            new_id=n+m-new_id;
            if(z_backward[new_id]>=req){
                return id;
            }

        }

        return -1;





    }
};