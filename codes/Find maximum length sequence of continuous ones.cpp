#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

// find index of 0 to replaced with 1 to get maximum sequence of
// continuous 1's using sliding window technique
int find_index_of_zero(int arr[], int n)
{
	int left = 0;
	int count = 0;
	int max_count = 0;
	int max_index = -1;
	int prev_zero_index;

	for(int i = 0; i < n; i++)
	{
		if(arr[i] == 0)
		{
			prev_zero_index = i;
			count++;
		}
		if(count == 2)
		{
			while(arr[left])
				left++;
			left++;
			count = 1;
		}
		if((i - left + 1) > max_count)
		{
			max_count = i - left + 1;
			max_index = prev_zero_index;
		}
	}

	return max_index;
}

int main()
{
	int N, a;
	cin >> N;

	int arr[N];
	for(int i = 0; i < N; i++)
	{
		cin >> a;
		arr[i] = a;
	}

	int index = find_index_of_zero(arr, N);
	cout << index << endl;
}
