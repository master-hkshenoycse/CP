#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size()+2;
        vector<int> degree(n,0);
        
        int sol=0;
        for(int i=0;i<n-2;i++){
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
            
            if(degree[edges[i][0]]>1)sol=edges[i][0];
            if(degree[edges[i][1]]>1)sol=edges[i][1];
        }
        return sol;
        
    }
};