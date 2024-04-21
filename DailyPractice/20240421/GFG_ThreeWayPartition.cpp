#include<bits/stdc++.h>
using namespace std;
void threeWayPartition(vector<int>& array,int a, int b)
    {
        // code here
        int n=array.size();
        int start=0,curr=0,end=n-1;
        
        while(curr<=end){
            if(array[curr]<a){
                swap(array[curr],array[start]);
                curr++;
                start++;
            }else if(array[curr]>=a and array[curr]<=b){
                curr++;
            }else if(array[curr]>b){
                swap(array[curr],array[end]);
                end--;
            }
        }
    }