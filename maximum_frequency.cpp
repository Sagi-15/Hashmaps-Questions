#include <iostream>
#include <unordered_map>
using namespace std;

int highestFrequency(int A[],int n) {
    unordered_map<int,int> number_frequency_map;
    //1st int represents number in map
    //2nd int repersents frequency in map
    int max_frequency=0,max_frequency_walla_number;
    for(int i=0;i<n;i++){
        if(number_frequency_map.count(A[i])==0){
            /*matlab woh number ka abhi tak 
            map mei registration/add nahi kar
            so present toh add to the map*/
            number_frequency_map[A[i]]=1; //pehli baar number dekh toh uski freq will be 1
        }
        else if(number_frequency_map.count(A[i])==1){
            /*matlab now just frequency update*/
            number_frequency_map[A[i]]++;
        }
        /*as below do in both if aur else so 
        do baar likhne ke bajai ek hi baar mei*/
        if(max_frequency<number_frequency_map[A[i]]){
                max_frequency=number_frequency_map[A[i]];
                max_frequency_walla_number=A[i];
        }
    }
    return max_frequency_walla_number;
}
int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    int max_freq=highestFrequency(A,n);
    cout<<max_freq;
}