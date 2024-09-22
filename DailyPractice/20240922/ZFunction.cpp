#include<bits/stdc++.h>
using namespace std;

//Source:https://www.youtube.com/watch?v=CpZh4eF8QBw
vector<int> get_z(string &s){
    int n=s.size();
    vector<int> z(n,0);
    int left=0,right=0;//latest window in which [left,right] is prefix of string

    for(int i=1;i<n;i++){
        if(i>right){
            left=i;
            right=i;
            while(right<n and s[right]==s[right-left]){
                right++;
            }
            z[i]=right-left;
            right--;//valid match till right-1;
        }else{
            int j=i-left;

            if(z[j]<right-i+1){//if boundary is not being breached
                z[i]=z[j];
            }else{
                left=i;

                while(right<n and s[right]==s[right-left]){
                    right++;
                }
                z[i]=right-left;
                right--;
            }

        }
    }




    return z;
}

void print_z(string &s){
    cout<<s<<endl;
    vector<int> z=get_z(s);
    for(int i=0;i<s.size();i++){
        cout<<"Z["<<i<<"]: "<<z[i]<<endl;
    }
    cout<<endl;
}

int main(){
    //For a strin s
    //Z[i]=longest substring starting at i which is also a prefix of s.

    string s;
    s="abaxabab";
    print_z(s);
}