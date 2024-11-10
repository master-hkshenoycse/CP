#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string get_sum(string &a,string &b){
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        string ret;
        int c=0,i=0;
        while(i<a.size() or i<b.size()){
            int v1=0,v2=0;
            if(i<a.size()){
                v1=a[i]-'0';
            }
            
            if(i<b.size()){
                v2=b[i]-'0';
            }
            
            int v=(v1+v2+c)%10;
            c=(v1+v2+c)/10;
            ret+=char('0'+v);
            
            i++;
            
        }
        
        if(c>0){
            ret+=char('0'+c);
        }
        

        reverse(ret.begin(),ret.end());
        

        
        i=0;
        while(i<ret.size() and ret[i]=='0'){
            i++;
        }
        
        ret=ret.substr(i);
        if(ret.size()==0){
            ret+='0';
        }
        
        return ret;
    }
    string minSum(vector<int> &arr) {
        // code here
        vector<int> cnt(10,0);
        for(auto ch:arr){
            cnt[ch]++;
        }
        
        string a,b;
        for(int i=0;i<=9;i++){
            for(int j=0;j<cnt[i];j++){
                if(a.size()<b.size()){
                    a+=char('0'+i);
                }else{
                    b+=char('0'+i);
                }
            }
        }
        

        return get_sum(a,b);
    }
};