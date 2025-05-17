#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> get_lps(string &p,string &s){
            string tmp = s;
            tmp+='$';
            tmp+=p;
    
            int n=tmp.size();
            vector<int> lps(n,0);
    
            int i=1,len=0;
            while(i<n){
                if(tmp[len]==tmp[i]){
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
        int countCells(vector<vector<char>>& grid, string pattern) {
            int n=grid.size(),m=grid[0].size();
            string row_string,col_string;
    
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    row_string+=grid[i][j];
                }
            }
    
            for(int j=0;j<m;j++){
                for(int i=0;i<n;i++){
                    col_string+=grid[i][j];
                }
            }
    
            vector<vector<int> > valid_marker_col(n,vector<int> (m,0));
            vector<vector<int> > valid_marker_row(n,vector<int> (m,0));
            vector<int> row_marker(n*m+1,0),col_marker(n*m+1,0);
            int p_len=pattern.size();
    
    
            vector<int> lps_row = get_lps(row_string,pattern);
            vector<int> lps_col = get_lps(col_string,pattern);
    
            int ans=0;
            for(int i=0;i<n*m;i++){
    
                if(lps_row[i+p_len+1]==p_len){
                    
                    row_marker[i-p_len+1]++;
                    row_marker[i+1]--;
                }
    
                if(lps_col[i+p_len+1]==p_len){
                    col_marker[i-p_len+1]++;
                    col_marker[i+1]--;
                }
            }
    
            for(int i=0;i<n*m;i++){
                if(i>0){
                    col_marker[i]+=col_marker[i-1];
                    row_marker[i]+=row_marker[i-1];
                }
    
               
    
                if(col_marker[i]>0){
                    valid_marker_col[i%n][i/n]=1;
                }
    
                if(row_marker[i]>0){
                    valid_marker_row[i/m][i%m]=1;
                }
            }
    
    
    
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(valid_marker_row[i][j]>0 && valid_marker_col[i][j]>0){
                        ans++;
                    }
                }
            }
    
            return ans;
    
    
        }
    };