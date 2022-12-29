#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> removeDuplicates(int A[],int size){
    vector<int> unique_element_vector;
    unordered_map<int,bool> seen;
    /*so jaise hi unique vector mei push
    our new element map mei uski value ko
    true kar de so map mei woh array A 
    ki value ka key present joh ki search in 
    O(1) in maps then usko wapis se not push*/
    for(int i=0;i<size;i++){
        if(seen.count(A[i])==0){
            /*matlab did not push that element to array
            as well*/
            seen[A[i]]=true;
            unique_element_vector.push_back(A[i]);
        }
        /*nahi toh kuch nahi kar ie.
        pehle se woh element in array toh kuch karne
        ki jarurat nhi*/
    }
    return unique_element_vector;
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
    vector<int> unique=removeDuplicates(A,n);
    for(int i=0;i<unique.size();i++){
        cout<<unique[i]<<" ";
    }
    cout<<endl;
}