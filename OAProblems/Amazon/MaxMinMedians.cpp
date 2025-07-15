/*
An Amazon intern encountered a challenging task.

The intern has an array of n integers, where the value of the i-th element is represented by the array values[i]. He is interested in playing with arrays and subsequences.

Given:

An integer n — the number of elements in the array,

An integer array values of length n,

An integer k — the desired length of subsequences,

the task is to find:

The maximum median, and

The minimum median

across all subsequences of length k
source:https://www.reddit.com/r/leetcode/comments/1lwa6ez/i_lost_hope_i_give_up_amazon_oa/
*/
#include<bits/stdc++.h>
using namespace std;
void minMaxSubsequenceK(vector<int> &a,int n,int k){
    sort(a.begin(),a.end());

    cout<<"Min Median: "<<a[k/2]<<endl;
    cout<<"Max Median: "<<a[n-(k+1)/2]<<endl;
}
int main(){ 
    vector<int> a={1,2,3,4,5};
    minMaxSubsequenceK(a,5,2);
}