#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

// find minimum sum sub-array of given size k
void find_subarray(int arr[], int n, int k)
{
	int window_sum = 0;
	int min_window = INT_MAX;
	int last = 0;

	for(int i = 0; i < n; i++)
	{
		window_sum += arr[i];

		if(i + 1 >= k)
		{
			if(min_window > window_sum)
			{
				min_window = window_sum;
				last = i;
			}

			window_sum -= arr[i + 1 - k];
		}
	}

	cout << "Minimum sum sub-array is ( " << last - k + 1 << " , " << last << " )" << endl;
}

int main()
{
    int N, K, a;
    cin >> N >> K;

	int arr[N];
    for(int i = 0; i < N; i++)
    {
        cin >> a;
        arr[i] = a;
    }

	find_subarray(arr, N, K);
}
