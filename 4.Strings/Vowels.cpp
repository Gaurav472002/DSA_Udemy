// Write a c++ program to read a string and find the number of vowels in it
#include <iostream>

using namespace std;





// The main method has separate conditions for lowercase and uppercase vowels. 
// We can convert each lowercase char to upper case and test for only one condition. 

bool isVowel(char c){
    // converts char to upper case if it was lowercase
    c = toupper(c);
    
    // returns true if any of the condition matches
    return c=='A'||c=='E'||c=='I'||c=='O' ||c=='U';
}

int main()
{
    char str[100] = "prepinsta";
    int vowels = 0, consonants =0;
    
    // can also do str[i] != '\0' in condition below both would work
    for(int i = 0; str[i]; i++)  
    {
        if(str[i]=='a'|| str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'
        ||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O' ||str[i]=='U')
        {
		    vowels++;
        }
        else if( str[i]>=65 && str[i]<=90 || str[i]>=97 && str[i]<=122){
                consonants++;

        }
    }
    

     // can also do str[i] != '\0' in condition below both would work
    for(int i = 0; str[i]; i++)  
    {
        if(isVowel(str[i]))
		    vowels++;
        
    }
    cout << "Total Vowels : " << vowels;
    cout << "Total Consonants : " << consonants;
    
    return 0;
}