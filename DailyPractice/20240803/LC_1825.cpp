#include <bits/stdc++.h>
using namespace std;
class MKAverage {
public:
    multiset<int> left,mid,right;
    vector<int> v;
    long sum,m,k,pos=0;
    
    
    MKAverage(int m, int k) {
       sum=0;
       v=vector<int> (m);
       this->m=m;
       this->k=k;
       pos=0;
    }
    void remove(int num){

        if(left.find(num) != left.end()){
            left.erase(left.find(num));
        }else if(mid.find(num) != mid.end()){
            mid.erase(mid.find(num));
            sum-=num;
        }else{
            right.erase(right.find(num));
        }


        if(left.size()<k){
            auto it=mid.begin();
            sum-=*it;
            left.insert(*it);
            mid.erase(it);
        }

        if(mid.size()<m-2*k){
            mid.insert(*right.begin());
            sum+=(*right.begin());
            right.erase(right.begin());
        }

    }

    void add(int num){
        left.insert(num);

        if(left.size()>k){
            auto it=(--left.end());
            
            mid.insert(*it);
            sum+=*it;
            left.erase(it);
            
        }

        if(mid.size()> m-2*k){
            auto it=(--mid.end());
            sum-=*it;
            right.insert(*it);
            mid.erase(it);
        }

    }
    void addElement(int num) {
        if(pos>=m){
            remove(v[pos%m]);
        }

        add(num);
        v[pos%m]=num;
        pos++;
    
    }
    
    int calculateMKAverage() {
        if(pos<m){
            return -1;
        }

        cout<<sum<<endl;

        return sum/(m-2*k);

    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */