#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        
        vector<vector<string> > sol;
        int n=words.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    for(int l=0;l<n;l++){
                        set<int> uniq;
                        uniq.insert(i);
                        uniq.insert(j);
                        uniq.insert(k);
                        uniq.insert(l);
                        if(uniq.size()==4){
                            string top=words[i];
                            string bottom=words[j];
                            string left=words[k];
                            string right=words[l];
                            if(top[0]==left[0] && top[3]==right[0] && bottom[0]==left[3] && bottom[3]==right[3])
                                sol.push_back({top,left,right,bottom});
                        }
                    }
                }
            }
        }
        

        sort(sol.begin(),sol.end());
        return sol;
    }
};