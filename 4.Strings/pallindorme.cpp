
#include <bits/stdc++.h>
using namespace std;

// Function to check whether string
// is palindrome
string isPalindrome(string S)
{
	for (int i = 0; i < S.length() / 2; i++) {

		
		if (S[i] != S[S.length() - i - 1]) {
			// Return No
			return "No";
		}
	}
	return "Yes";
}

int main()
{
	string S = "ABCDCBA";
	cout << isPalindrome(S);

	return 0;
}
