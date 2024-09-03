#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string get_str(int n){
        string ret=to_string(n);
        while(ret.size()<4){
            ret='0'+ret;
        }
        return ret;
    }
    int generateKey(int num1, int num2, int num3) {
        string a=get_str(num1);
        string b=get_str(num2);
        string c=get_str(num3);
        
        string sol;
        for(int i=0;i<4;i++){
            sol+=min({a[i],b[i],c[i]});
        }
        
        int v=0;
        for(auto c:sol){
            v=v*10+(c-'0');
        }
        return v;
    }
};