#include <bits/stdc++.h>
using namespace std;

int is_palindrome(string a)
{
    for (int b = 0; b < ceil(1.0 * a.length() / 2); b++) if (a[b] != a[a.length() - b - 1]) return 0;
    return 1;
}

vector <vector <string> > palindrome_substrings(string a)
{
    if (a.length() == 1) return {{a}};
    vector <vector <string> > res, vec1, vec2;
    for (int b = 1; b <= a.length(); b++)
    {
        if (is_palindrome(a.substr(0, b)))
        {
            if (b == a.length()) res.push_back({a.substr(0, b)});
            else
            {
                vec1 = palindrome_substrings(a.substr(b));
                for (auto c : vec1)
                {
                    c.insert(c.begin(), a.substr(0, b));
                    res.push_back(c);
                }
            }
        }
    }
    return res;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string a = "abbb";
    vector <vector <string> > res = palindrome_substrings(a);
    for (auto b : res)
    {
        for (auto c : b) cout << c << " ";
        cout << endl;
    }
}
