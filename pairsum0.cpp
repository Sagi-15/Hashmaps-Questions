#include <iostream>
#include <unordered_map>
using namespace std;

int pairSum(int *arr, int n){
    unordered_map<int,int> store_frequency;
    for(int i=0;i<n;i++){
        if(store_frequency.count(arr[i])==0){
            store_frequency[arr[i]]=1;
        }
        else{
            store_frequency[arr[i]]++;
        }
    }
    int count_answer=0;
    for(int i=0;i<n;i++){
        if(store_frequency.count((-1)*(arr[i]))==1){
            count_answer+=store_frequency[-arr[i]];
            store_frequency[arr[i]]--;
        }
    }
    return count_answer;
}