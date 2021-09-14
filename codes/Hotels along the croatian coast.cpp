#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void print_deque(deque<int> wind, int arr[])
{
    while(!wind.empty())
    {
        int a = wind.front();
        cout << arr[a] << " ";
        wind.pop_front();
    }
    cout << endl;
}

int find_subarray(int arr[], int n, int m)
{
    int sol = INT_MIN;
	int window_sum = 0;
	deque<int> window;

	int low = 0, high = 0;

	for(low = 0; low < n; low++)
	{
		while(window_sum < m && high < n)
		{
            sol = max(sol, window_sum);
			window_sum += arr[high];
			window.push_back(high);
			high++;
		}

		if(window_sum == m)
		{
            sol = m;
			break;
        }

		window_sum -= arr[low];
		window.pop_front();
	}

	return sol;
}

int main()
{
    int N, M, a;
    cin >> N >> M;

    int arr[N];
    for(int i = 0; i < N; i++)
    {
        cin >> a;
        arr[i] = a;
    }

	int sol = find_subarray(arr, N, M);
	cout << sol << endl;
}
