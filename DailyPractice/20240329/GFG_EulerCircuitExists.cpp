#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool isEularCircuitExist(int v, vector<int>adj[]){
	    // Code here
	    for(int i=0;i<v;i++){
	        if(adj[i].size()%2){
	            return 0;
	        }
	    }
	    return 1;
	}

};