#include <iostream>
using namespace std;
#include <string>
#include <unordered_map>

string uniqueChar(string str){
	unordered_map<char,char> seen;
    string output="";
    for(int i=0;i<str.size();i++){
        if(seen.count(str[i])==0){
            seen[str[i]]=str[i];
            output+=str[i]; //ie. tabhi add karlo to output instead of baad mei as then order ka dhyan baad mei nahi rkh paa
        }
    }
    return output;
}
int main(){
    string s="codingninjas";
    cout<<uniqueChar(s);
}