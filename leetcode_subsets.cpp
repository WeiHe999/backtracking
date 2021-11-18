#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << endl;
}

vector <string> split (string str1)
{
    vector <string> vv;
    string word;
    istringstream ss (str1);
    while (getline (ss, word, ' ')) vv.emplace_back(word);
    return vv;
}

set <vector <int> > subsets(vector <int> nums)
{
    if (nums.size() == 1) return {{nums[0]}};
    set <vector <int> > res, perms;
    for (int x = 0; x < nums.size(); x++)
    {
        vector <int> nums1(nums.begin(), nums.end());
        nums1.erase(nums1.begin() + x);
        perms = subsets(nums1);
        for (auto a : perms) res.insert(a);
    }
    res.insert(nums);
    return res;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    vector <int> nums = {1, 2, 3};
    set <vector <int> > res = subsets(nums);
    res.insert({{}});
    for (auto a : res) print(a);
}
