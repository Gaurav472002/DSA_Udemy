#include <iostream>
using namespace std;

void anagram(char arr1[], char arr2[]){

    int i=0, count=0;
    int hasharr[26];

    for (i = 0; arr1[i]; i++)
    {
        hasharr[arr1[i]-97]+=1;
    }

    for (i = 0; arr2[i]; i++)
    {
        hasharr[arr2[i]-97]-=1;

        if (((hasharr[i]-97)<0))
        {
            count++;
        }
        
        
    }
    if (arr2[i]=='\0')
    {
        cout<<"The strings are Anagram Strings"<<endl;
    }
    else if( count>1){
        cout<<"The Strings are not Anagram"<<endl;
    }
    
    
}

int main(){

    char str1[]="medical";
    char str2[]="decimal";

    anagram(str1,str2);
    
    return 0 ;
}