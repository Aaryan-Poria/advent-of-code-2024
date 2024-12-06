#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int padding = 5;

void part1(vector<vector<char>> &paddedGrid, int &rows, int &cols)
{
    vector<pair<int, int>> directions = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1},
        {-1, -1},
        {-1, 1},
        {1, -1},
        {1, 1}};

    auto checkXMAS = [&](int x, int y, int dx, int dy) -> bool
    {
        string target = "XMAS";
        for (int i = 0; i < 4; ++i)
        {
            if (paddedGrid[x + i * dx][y + i * dy] != target[i])
                return false;
        }
        return true;
    };

    int ans = 0;

    int cnt = 0;

    for (int i = padding; i < rows + padding; ++i)
    {
        for (int j = padding; j < cols + padding; ++j)
        {
            if (paddedGrid[i][j] == 'X')
            {
                for (auto [dx, dy] : directions)
                {
                    if (checkXMAS(i, j, dx, dy))
                        ++cnt;
                }
            }
        }
    }

    cout << cnt << '\n';
}

void part2(vector<vector<char>> grid, int rows, int cols)
{
    int cnt = 0;
    vector<pair<int, int>> directions = {
        {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

    for (int i = padding; i < rows + padding; ++i)
    {
        for (int j = padding; j < cols + padding; ++j)
        {
            if (grid[i][j] == 'A')
            {
                string s = "";
                for (auto [dx, dy] : directions)
                {
                    s += grid[i + dx][j + dy];
                }
                if (s == "MMSS" || s == "MSSM" || s == "SSMM" || s == "SMMS")
                    ++cnt;
            }
        }
    }

    cout << cnt << '\n';
}

void solve()
{
    vector<vector<char>> grid;
    string line;
    while (getline(cin, line))
    {
        vector<char> row(line.begin(), line.end());
        grid.push_back(row);
    }

    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<char>> paddedGrid(rows + 2 * padding, vector<char>(cols + 2 * padding, '#'));
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            paddedGrid[i + padding][j + padding] = grid[i][j];
        }
    }

    part1(paddedGrid, rows, cols);
    part2(paddedGrid, rows, cols);
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