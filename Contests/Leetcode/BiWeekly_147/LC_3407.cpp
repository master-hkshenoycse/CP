#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> get_match(string &s,string &a){
        int n=s.size();
        vector<int> ret(n,0);

        if(a.size()==0){
            for(int i=0;i<n;i++){
                ret[i]=1;
            }
            return ret;
        }

        int a_size=a.size();
        for(int i=0;i+a_size-1<n;i++){
            if(s.substr(i,a_size)==a){
                ret[i]=1;
            }
        }

        return ret;

    }
    bool hasMatch(string s, string p) {
        string a,b;
        int f=0;
        for(auto ch:p){
            if(ch=='*'){
                f=1;
                continue;
            }
            if(f==0){
                a+=ch;
            }else{
                b+=ch;
            }
        }

        cout<<a<<" "<<b<<endl;

        int n=s.size();
        vector<int> a_match=get_match(s,a);
        vector<int> b_match=get_match(s,b);

        if(a.size()==0){
            for(int i=0;i<n;i++){
                if(b_match[i]==1){
                    return 1;
                }
            }
            return 0;
        }

        if(b.size()==0){
            for(int i=0;i<n;i++){
                if(a_match[i]==1){
                    return 1;
                }
            }
            return 0;
        }

        for(int i=0;i<n;i++){
            if(a_match[i]==1){
                for(int j=i+a.size();j<n;j++){
                    if(b_match[j]==1){
                        return 1;
                    }
                }
            }
        }
        return 0;

    }
};