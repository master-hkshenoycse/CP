#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        vector<pair<int,char> > rem;
        rem.push_back({a,'a'});
        rem.push_back({b,'b'});
        rem.push_back({c,'c'});

        string sol;
        while(1){
            int added=0;
        
            sort(rem.begin(),rem.end());
            for(int i=2;i>=0;i--){
                if(rem[i].first==0){
                    break;
                }

                char ch=rem[i].second;
                if(sol.size()>1 and sol[sol.size()-1]==ch and sol[sol.size()-2]==ch){
                    continue;
                }else{

                    added=1;
                    sol+=ch;
                    rem[i].first--;
                    break;
                }
            }

            if(added==0){
                break;
            }
        } 

        return sol;
    }
};