#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void print_deque(deque<int> wind, int arr[])
{
    while(!wind.empty())
    {
        int a = wind.front();
        cout << arr[a] << endl;
        wind.pop_front();
    }
}

// function to print sub-array having given sum using
// sliding window technique
deque<int> find_subarray(int arr[], int n, int sum)
{
	// maintain sum of current window
	int window_sum = 0;
	deque<int> window;

	// maintain a window [low, high-1]
	int low = 0, high = 0;

	// consider every sub-array starting from low index
	for(low = 0; low < n; low++)
	{
		// if current window's sum is less than the given sum,
		// then add elements to current window from right
		while(window_sum < sum && high < n)
		{
			window_sum += arr[high];
			window.push_back(high);
			high++;
		}

		// if current window's sum is equal to the given sum
		if(window_sum == sum)
		{
			cout << "Subarray found [ " << low << " - " << high - 1 << " ]" << endl;
			return window;
		}

		// at this point the current window's sum is more than the given sum
		// remove current element (leftmost element) from the window
		window_sum -= arr[low];
		window.pop_front();
	}
}

int main()
{
    int N, SUM, a;
    cin >> N >> SUM;

    int arr[N];
    for(int i = 0; i < N; i++)
    {
        cin >> a;
        arr[i] = a;
    }

	deque<int> window = find_subarray(arr, N, SUM);
	print_deque(window, arr);
}
