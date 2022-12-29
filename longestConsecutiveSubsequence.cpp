#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *A,int n){
    unordered_map<int,bool> present;
    for(int i=0;i<n;i++){
        present[A[i]]=true;
    }
    int max_length=0;
    int start;
    for(int i=0;i<n;i++){
        int current_start=A[i];
        int k=A[i];
        int current_length=0;
        while(present.count(k)==1){
            k++;
            current_length++;
        }
        k=current_start-1;
        while(present.count(k)==1){
            k--;
            current_length++;
            current_start--;
        }
        if(current_length>max_length){
            max_length=current_length;
            start=current_start;
        }
    }
    vector<int> answer;
    for(int i=start;i<start+max_length;i++){
        answer.push_back(i);
    }
    return answer;
}