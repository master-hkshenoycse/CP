#include<bits/stdc++.h>
using namespace std;
/*https://www.geeksforgeeks.org/largest-lexicographical-string-with-at-most-k-consecutive-elements/*/
string createString(int n, int k, string s) {
        // code here
        vector<int> cnt(26,0);
        for(auto ch:s){
            cnt[ch-'a']++;
        }
        
        string sol;
        
        
        for(int i=25;i>=0;){
            
            if(cnt[i]>k){
                
                int c=k;
                cnt[i]-=c;
                
                while(c--){
                    sol+=char('a'+i);
                }
                
                int j=i-1;
                int f=0;
                while(j>=0){
                    
                    if(cnt[j]>0){
                        f=1;
                        sol+=char('a'+j);
                        cnt[j]--;
                        break;
                    }
                    j--;
                }
                
                if(f==0){
                    break;
                }
                
            }else if(cnt[i]>0){
                int c=cnt[i];
                cnt[i]-=c;
                while(c--){
                    sol+=char('a'+i);
                }
                
                
            }else{
                i--;
            }
            
        }
        
        
        return sol;
        
        

        
    }