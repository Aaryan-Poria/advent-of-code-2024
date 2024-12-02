#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isSafe(vector<int> &arr)
{
    if (arr.size() <= 1)
        return true;

    bool increasing = arr[1] > arr[0];
    for (int i = 1; i < arr.size(); ++i)
    {
        int diff = arr[i] - arr[i - 1];
        if ((diff > 0) != increasing || abs(diff) < 1 || abs(diff) > 3)
        {
            return false;
        }
    }
    return true;
}

bool calculateNormalCnt(vector<int> &arr, int &cnt)
{
    if (isSafe(arr))
    {
        ++cnt;
        return true;
    }

    // For Part-1, only checkig if the arr is safe is sufficient

    for (int i = 0; i < arr.size(); ++i)
    {
        vector<int> copy = arr;
        copy.erase(copy.begin() + i);
        if (isSafe(copy))
        {
            ++cnt;
            return true;
        }
    }
    return false;
}

void solve()
{
    vector<int> arr;
    string line;
    int simpleCnt = 0;

    while (getline(cin, line))
    {
        stringstream ss(line);
        int val;
        while (ss >> val)
            arr.push_back(val);

        calculateNormalCnt(arr, simpleCnt);
        arr.clear();
    }

    cout << simpleCnt << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();

    return 0;
}
