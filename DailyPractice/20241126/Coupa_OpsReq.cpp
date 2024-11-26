#include<bits/stdc++.h>
using namespace std;
/*
https://www.geeksforgeeks.org/count-minimum-decrement-prefix-or-suffix-or-increment-all-operations-to-make-array-equal-to-0/*/
int makeZero(int N,int A[]){
    
    vector<int> rel_diff;
    int min_diff=INT_MAX;
    for(int i=1;i<N;i++){
        rel_diff.push_back(A[i]-A[i-1]);
        min_diff=min(min_diff,A[i]-A[i-1]);
    }

    int ans=0;
    for(auto e:rel_diff){
        cout<<e<<" ";
        ans=ans+e-min_diff;
    }

    cout<<endl;

    return ans+abs(min_diff);

}

int minimumOperations(int arr[], int n)
{
    int i;
 
    // It will count total no. of operations
    int operations = 0;
 
    for (int i = 0; i < n - 1; i++) {
 
        // Calculate the difference and
        // add its absolute value to
        // the no. of operations
        operations += abs(arr[i + 1] - arr[i]);
 
        // If the changes are done in prefix
        // then update first element of array
        if (arr[i + 1] - arr[i] < 0) {
            arr[0] -= (abs(arr[i + 1] - arr[i]));
        }
    }
 
    // Now all the elements of the array are
    // equal to arr[0], add absolute value
    // of arr[0] to the no. of operations
    operations += abs(arr[0]);
 
    // Return the total number of operations
    return operations;
}
int main(){
    int A[]={1 ,-2 ,3 ,-4,5};
    cout<<minimumOperations(A,5)<<endl;

    int B[]={4,-4,4,-4};
    cout<<minimumOperations(B,4);


}   
