#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

// function to find the first negative integer in every window of size k
void print_first_negative_integer(int arr[], int n, int k)
{
    deque<int> window;

    int i;
    for(i = 0; i < k; i++)
        if(arr[i] < 0)
            window.push_back(i);

    for( ; i < n; i++)
    {
        if (!window.empty())
            cout << arr[window.front()] << " ";
        else
            cout << 0 << " ";

        while((!window.empty()) && window.front() < (i - k + 1))
            window.pop_front();

        if(arr[i] < 0)
            window.push_back(i);
    }

    if(!window.empty())
        cout << arr[window.front()] << endl;
    else
        cout << 0 << endl;
}

int main()
{
    int N, K, a;
    cin >> N >> K;

    int arr[N];
    for(int i = 0 ; i < N; i++)
    {
        cin >> a;
        arr[i] = a;
    }

    print_first_negative_integer(arr, N, K);
}
