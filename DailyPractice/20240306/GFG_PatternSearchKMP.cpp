
#include<bits/stdc++.h>
using namespace std;

/*https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1*/

vector<int> get_lps(string &s){

    int n=s.size();
    vector<int> lps(n,0);
    int i=1,len=0;
    while(i<n){
        if(s[i]==s[len]){
            len++;
            lps[i]=len;
            i++;
        }else{
            if(len>0){
                len=lps[len-1];
            }else{
                i++;
            }
        }
    }
    return lps;
}
vector <int> search(string pattern, string text){
    //code here.
    vector<int> lps=get_lps(pattern);
    int m=pattern.size(),n=text.size();
    vector<int> sol;
    int i=0,j=0;
    
    while(i<n){
        if(text[i]==pattern[j]){
            i++;
            j++;
        }else{
            
            if(j==0){
                i++;
            }else{
                j=lps[j-1];
            }
            
        }
        
        if(j==m){
            sol.push_back(i-m+1);
            j=lps[j-1];
        }
    }
    
    
    return sol;
    
}