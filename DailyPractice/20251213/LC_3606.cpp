#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkValid(string &code,string &bLine, bool active){
        if(active == 0) return 0;
        if(code.size()==0) return 0;
        for(auto ch:code){
            if(ch>='a' && ch<='z'){
                continue;
            }
            if(ch>='A' && ch<='Z'){
                continue;
            }
            if(ch>='0' && ch<='9'){
                continue;
            }
            if(ch=='_'){
                continue;
            }

            return 0;
        }
        if(bLine!="electronics" && bLine!="grocery" && bLine!="pharmacy" && bLine != "restaurant" ){
            return 0;
        }

        return 1;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string,string> > ord;
        vector<string> ret;
        int n=code.size();
        for(int i=0;i<n;i++){
            if(checkValid(code[i],businessLine[i],isActive[i])){
                ord.push_back(make_pair(businessLine[i],code[i]));
            }
        }

        sort(ord.begin(),ord.end());
        for(int i=0;i<ord.size();i++){
            ret.push_back(ord[i].second);
        }
        return ret;
    }
};