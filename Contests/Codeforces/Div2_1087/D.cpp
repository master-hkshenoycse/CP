#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int r,g,b;
        cin>>r>>g>>b;

        vector<pair<int,char> > chars={{r,'R'},{g,'G'},{b,'B'}};
        sort(chars.begin(),chars.end());
        reverse(chars.begin(),chars.end());

        int largest=chars[0].first;
        int others=chars[1].first+chars[2].first;
        int ret=r+g+b;

        string sol;

        if(others<largest-1){
            ret=2*others+1;
            



        }else{

        }

    }
}