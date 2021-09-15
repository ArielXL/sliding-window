#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

// function to find all substrings of string X that are permutations of string Y
void find_all_anagrams(string X, string Y)
{

    // m and n stores size of string Y and X respectively
	int m = Y.length(), n = X.length();

	// invalid input
	if (m > n)
		return;

	// maintain count of characters in current window
	multiset<char> window;
	// maintain count of characters in second string
	multiset<char> set;

	// insert all characters of string Y into set
	for (int i = 0; i < m; i++)
	{
		set.insert(Y[i]);
    }
	// note that multiset can maintain duplicate elements unlike set

	// maintain a sliding window of size m with adjacent characters of string X
	for (int i = 0; i < n; i++)
	{
		// add first m characters of string X into current window
		if (i < m)
			window.insert(X[i]);
		else
		{
			// if all characters in current window matches that of string Y, we found an anagram
			if (window == set)
				cout << "Anagram " << X.substr(i - m, m) << " present at index " << i - m << endl;

			// consider next substring of X by removing leftmost element of the sliding
			// window and add next character of string X to it

			// delete only "one" occurrence of leftmost element of current window
			auto iter = window.find(X[i - m]);
			if (iter != window.end())
				window.erase(iter);

			// insert next character of string X in current window
			window.insert(X[i]);
		}
	}

	// if last m characters of string X matches that of string Y, we found an anagram
	if (window == set)
		cout << "Anagram " << X.substr(n - m, m) << " present at index " << n - m << endl;
}

int main()
{
	string X, Y;
	cin >> X >> Y;

	find_all_anagrams(X, Y);
}

