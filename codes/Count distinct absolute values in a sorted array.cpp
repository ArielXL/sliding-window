#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

// returns the number of distinct absolute values in the given input
int find_distinct(vector<int> input)
{
	unordered_set<int> set;
	for (int const& i: input)
		set.insert(abs(i));

	return set.size();
}

int main()
{
    int N, a;
	vector<int> input;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> a;
        input.push_back(a);
    }

	cout << find_distinct(input) << endl;
}
