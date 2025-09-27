#include<bits/stdc++.h>
using namespace std;
class Spreadsheet {
public:
    
    pair<int,int> get_index(string &s){
        int col=s[0]-'A';
        int row=0;
        
        for(int i=1;i<s.size();i++){
            row=row*10+(s[i]-'0');
        }
        
        row--;
        
        return {row,col};
        
    }
    
    int get_number(string &s){
        int ret=0;
        for(auto ch:s){
            ret=ret*10+(ch-'0');
        }
        return ret;
    }
    vector<vector<int> > sheet;
    Spreadsheet(int rows) {
        sheet.resize(rows+1,vector<int> (26,0));
    }
    
    void setCell(string cell, int value) {
        pair<int,int> index =get_index(cell);
        sheet[index.first][index.second]=value;
    }
    
    void resetCell(string cell) {
        pair<int,int> index = get_index(cell);
        sheet[index.first][index.second]=0;
    }
    
    int getValue(string formula) {
        string a1,a2;
        int start_a2=0;
        for(auto f:formula){
            if(f =='='){
                continue;
            }else if(f=='+'){
                start_a2=1;
                continue;
            }
            
            if(start_a2==0){
                a1+=f;
            }else{
                a2+=f;
            }
            
        }
        
        //cout<<a1<<" "<<a2<<endl;
        
        int ret=0;
        if(a1[0]>='A' && a1[0]<='Z'){
            pair<int,int> index =get_index(a1);
            ret+=sheet[index.first][index.second];
        }else{
            ret+=get_number(a1);
        }
        
        if(a2[0]>='A' && a2[0]<='Z'){
            pair<int,int> index =get_index(a2);
            ret+=sheet[index.first][index.second];
            
        }else{
            ret+=get_number(a2);
        }
        
        return ret;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */