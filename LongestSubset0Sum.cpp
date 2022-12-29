#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int* arr, int n){
    int sum=0;
    int max_length=0;
    unordered_map<int,int> sum_index;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        int current_length=0;
        if(sum_index.count(sum)==1){
            current_length=i-sum_index[sum];
        }
        if(max_length<current_length){
            max_length=current_length;
        }
        sum_index[sum]=i;
    }
    return max_length;
}