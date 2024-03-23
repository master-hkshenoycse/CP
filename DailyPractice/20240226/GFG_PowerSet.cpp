#include<bits/stdc++.h>
using namespace std;
/*https://www.geeksforgeeks.org/problems/power-set4302/1*/

vector<string> AllPossibleStrings(string s){
    // Code here
    int n=s.size();
    int lim=(1<<n);
    vector<string> sol;
    for(int i=1;i<lim;i++){
        string tmp;
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                tmp+=s[j];
            }
        }
        sol.push_back(tmp);
    }
    sort(sol.begin(),sol.end());
    return sol;
}