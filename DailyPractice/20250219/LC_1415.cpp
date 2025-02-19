#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void rec(string tmp,int n,vector<string> &coll){
            if(tmp.size()==n){
                coll.push_back(tmp);
                return;
            }
    
            for(char ch='a';ch<='c';ch++){
                if(tmp.size()==0 || tmp.back() != ch){
                    tmp+=ch;
                    rec(tmp,n,coll);
                    tmp.pop_back();
                }
            }
        }
        string getHappyString(int n, int k) {
            vector<string> coll;
            string tmp;
            rec(tmp,n,coll);
            sort(coll.begin(),coll.end());
    
            if(coll.size() < k){
                return tmp;
            }
            return coll[k-1];
    
    
        }
    };