#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> minOperations(string boxes) {
       vector<int> sol;
        int n=boxes.size();
        
        for(int i=0;i<n;i++){
            int s=0;
            
            for(int j=0;j<n;j++){
                if(boxes[j]=='1')s=s+abs(i-j);
            }
            
            
            sol.push_back(s);
        }
        
        return sol;
    }
};