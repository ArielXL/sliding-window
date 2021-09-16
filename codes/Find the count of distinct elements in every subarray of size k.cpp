#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

// function to find the count of distinct elements in every sub-array
// of size k in the array
void find_distinct_count(int arr[], int n, int k)
{
	// consider every sub-array of size k
	for (int x = 0; x <= n - k; x++)
	{
		// maintains counter for distinct elements in current sub-array
		int distinct = 0;

		// current sub-array is formed by the sub-array [x, x+k)
		for (int i = x; i < x + k; i++)
		{
			// increase distinct count for arr[i] in current sub-array
			distinct++;
			
			// check if arr[i] is present in the sub-array arr[x,i-1] or not
			for (int j = x; j < i; j++)
			{
				// if duplicate element found in current sub-array
				if (arr[i] == arr[j])
				{
					// unmark element arr[i] as distinct - decrease count
					distinct--;
					break;
				}
			}
		}

		cout << "The count of distinct elements in the sub-array [ " << x << " , " << x + k - 1 << " ] is " << distinct << endl;
	}
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

	find_distinct_count(arr, N, K);
}
