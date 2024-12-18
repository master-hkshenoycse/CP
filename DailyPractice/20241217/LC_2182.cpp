#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        sort(s.begin(),s.end());
        reverse(s.begin(),s.end());
        int n=s.size();
        
        set<int> index[26];
        for(int i=0;i<n;i++){
            index[s[i]-'a'].insert(i);
        }
        
        int c=0;
        for(int i=0;i<n;i++){
            if(i==0)c++;
            else{
                if(s[i]==s[i-1])c++;
                else c=1;
            }
            if(c>repeatLimit){
                int ch=s[i]-'a';
                int f=0;
                for(int j=ch-1;j>=0;j--){
                    auto it=index[j].upper_bound(i);
                    if(it != index[j].end()){
                        
                        int ind=(*it);
                        swap(s[ind],s[i]);
                        
                        index[j].erase(ind);
                        index[j].insert(i);
                        index[ch].erase(i);
                        index[ch].insert(i);
                        
                        f=1;
                        break;
                    }
                }
                if(f==0){
                    s=s.substr(0,i);
                    break;
                }
            }
        }
        
        
        
        return s;
    }
};