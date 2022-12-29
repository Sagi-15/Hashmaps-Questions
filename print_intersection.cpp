#include <iostream>
#include <unordered_map>
using namespace std;

void printIntersection(int arr1[], int arr2[], int n, int m){
    /*unordered_map<int,bool> present_arr1;
    for(int i=0;i<n;i++){
        if(present_arr1.count(arr1[i])==0){
            present_arr1[arr1[i]]=true;
        }
    }
    for(int i=0;i<m;i++){
        if(present_arr1[arr2[i]]==true){
            cout<<arr2[i]<<endl;
        }
    }*/
    unordered_map<int,int> present_arr1;
    for(int i=0;i<n;i++){
        if(present_arr1.count(arr1[i])==0){
            present_arr1[arr1[i]]=1;
        }
        else{
            present_arr1[arr1[i]]++;
        }
    }
    for(int i=0;i<m;i++){
        if(present_arr1[arr2[i]]>0){
            cout<<arr2[i]<<endl;
            present_arr1[arr2[i]]--;
        }
    }
}