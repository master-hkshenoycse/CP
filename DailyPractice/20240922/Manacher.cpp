#include<bits/stdc++.h>
using namespace std;

class Manacher{
    string s;
    vector<int> p;

    public: 
    Manacher(string s){
        this->s=s;
        do_preprocess();
        build();
    }

    void do_preprocess(){
        string tmp;
        for(auto ch:s){
            tmp+='#';
            tmp+=ch;
        }
        tmp+='#';
        s=tmp;
    }

    void build(){
        int n=s.size();
        p.assign(n,1);

        int l=1,r=1;

        for(int i=1;i<n;i++){
            p[i]=max(0,min(r-i,p[r+l-i]));

            while(i+p[i]<n and i-p[i]>=0 and s[i+p[i]]==s[i-p[i]]){
                p[i]++;
            }

            if(i+p[i]>r){
                l=i-p[i];
                r=i+p[i];
            }
        }
    }
    
    void print(){
        cout<<"Printing the array"<<endl;
        cout<<s<<endl;
        for(int i=0;i<p.size();i++){
            cout<<p[i]<<" ";
        }
        cout<<endl;
    }

    //odd means odd length palindrome,use the arrya
    //even means center betweee two indices.

    int get_longest(int index,bool odd){
        int pos=2*index+1;
        if(odd==0){
            pos++;//center shifted to next
        }

        return p[pos]-1;
    }


    bool checkPalin(int l,int r){
        int center=(l+r)/2;
        int parity=((l%2)==(r%2));

        return (r-l+1)<=get_longest(center,parity);
    }



};

int main(){

    string s;
    s="babbabbabc";

    Manacher manacher(s);
    manacher.print();


    return 0;



}