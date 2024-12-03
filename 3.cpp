#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int getNumber(string s, int &i)
{
    int sum = 0;
    while (isdigit(s[i]))
    {
        sum = sum * 10 + (s[i] - '0');
        ++i;
    }

    if (sum == 0)
        return -1;
    return sum;
}

void solve()
{
    string s;
    char c;
    while (cin.get(c))
        s += c;
    s += "################"; // Add extra characters to avoid overflow
    // cout << s << '\n';
    int answer = 0;
    bool enable = true;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'd' && s[i + 1] == 'o')
        {
            i += 2;
            if (s[i] == '(' && s[i + 1] == ')')
            {
                enable = true;
                i += 2;
            }
            else if (s[i] == 'n' && s[i + 1] == '\'' && s[i + 2] == 't')
            {
                i += 3;
                if (s[i] == '(' && s[i + 1] == ')')
                {
                    enable = false;
                    i += 2;
                }
            }
        }

        if (!enable)
            continue;

        if (s[i] == 'm')
        {
            if (s[i + 1] == 'u' && s[i + 2] == 'l' && s[i + 3] == '(')
            {
                i += 4;
                int x = getNumber(s, i);

                if (s[i] == ',')
                {
                    i += 1;
                    int y = getNumber(s, i);
                    if (s[i] == ')' && x != -1 && y != -1)
                        answer += x * y;
                }
            }
        }
    }

    cout << answer << '\n';
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