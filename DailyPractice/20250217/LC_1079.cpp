#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int numTilePossibilities(string tiles) {
            sort(tiles.begin(),tiles.end());
            
            int n=tiles.size();
            set<string> poss;
    
            for(int i=1;i<(1<<n);i++){
                string tmp;
                for(int j=0;j<n;j++){
                    if(i & (1<<j)){
                        tmp+=tiles[j];
                    }
                }
                do{
                    poss.insert(tmp);
                }while(next_permutation(tmp.begin(),tmp.end()));
            }
            
    
            
            return poss.size();
        }
    };