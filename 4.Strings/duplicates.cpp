#include <iostream>
#include<bits/stdc++.h>
using namespace std;


void duplicate(string s)  // naive approach //O(n^2)
{
    int count;
    int l = s.length();
    for (int i = 0; i < l; i++)
    {
        count = 1; // Updates the count again to 1 for every new character

        for (int j = i + 1; j < l; j++)
        {
            if (s[i] == s[j] && s[i] != ' ')
            {
                count++;
                // Set string[j] to 0 to avoid printing the visited character
                s[j] = '0';
            }
        }

        // A character is considered as duplicate if count is greater than 1

        if (count > 1 && s[i] != '0')
            cout <<"The duplicates are "<< s[i]<<endl;
    }
}


void printDups1(string str) //O(nlogn) // better approach
{
    map<char, int> count;
    for (int i = 0; i < str.length(); i++) {
        count[str[i]]++;
    }
 
    for (auto it : count) {
        if (it.second > 1)
            cout << it.first << ", count = " << it.second
                 << "\n";
    }
}

//it.first stores the character and it.second stores the frequency of the character

// Hashtable_approach


void printDups(string str)  //O(n) // Best approach
{
	unordered_map<char, int> count;
	for (int i = 0; i < str.length(); i++) {
		count[str[i]]++; //increase the count of characters by 1
	}

	for (auto it : count) { //iterating through the unordered map
		if (it.second > 1) //if the count of characters is greater then 1 then duplicate found
			cout << it.first << ", count = " << it.second
				<< "\n";
	}
}



int main()
{

    // string str = "Hello Peter";
    // duplicate(str);

    string str1="hello";

    printDups(str1);


    

    return 0;
}