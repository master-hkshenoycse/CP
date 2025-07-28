#include <bits/stdc++.h>
using namespace std;

static bool compare(string &a,string &b){
    return (a+b)>(b+a);
}

string findLargest(vector<int> &a){
    vector<string> coll;
    for(auto e:a){
        coll.push_back(to_string(e));
    }

    sort(coll.begin(),coll.end(),compare);

    if(coll[0]=="0"){
        return "0";
    }

    string ret;
    for(auto s:coll){
        ret+=s;
    }
    return ret;
}
int main(){

    vector<int> arr = { 3, 30, 34, 5, 9 };
    cout << findLargest(arr) << endl; 

}