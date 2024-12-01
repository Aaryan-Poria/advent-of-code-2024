#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void calculateTotalDistance(vector<int> col1, vector<int> col2)
{
    ll sum = 0;
    for (int i = 0; i < col1.size(); ++i)
    {
        sum += abs(col1[i] - col2[i]);
    }

    cout << sum << '\n';
}

void calculateSimilarityScore(vector<int> col1, vector<int> col2)
{
    ll sum = 0;
    unordered_map<int, int> mp;
    for (auto e : col2)
        ++mp[e];
    for (auto e : col1)
    {
        if (mp.find(e) != mp.end())
        {
            sum += e * mp[e];
        }
    }

    cout << sum << '\n';
}

void solve()
{
    vector<int> col1, col2;
    int val1, val2;
    while (cin >> val1 >> val2)
    {
        col1.push_back(val1);
        col2.push_back(val2);
    }

    sort(col1.begin(), col1.end());
    sort(col2.begin(), col2.end());

    calculateTotalDistance(col1, col2);
    calculateSimilarityScore(col1, col2);
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