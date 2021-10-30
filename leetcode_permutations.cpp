#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > permute(vector <int> nums)
{
    if (nums.size() == 1) 
        {
            return {{nums[0]}};
        }
    vector <vector <int> > res;
    for (int i = 0; i < nums.size(); i++)
    {
        int n = nums[i];
        vector<int> nums1;
        nums1.assign(nums.begin(), nums.end());
        nums1.erase(nums1.begin()+i);
        vector <vector <int> > perms = permute(nums1);
        for (auto &perm : perms)
        {
            perm.emplace_back(n);
            res.push_back(perm);
        }
    }
    return res;
}

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    vector <int> nums = {1, 2, 3};
    vector <vector <int> > ret;
    ret = permute(nums);
    cout << "The permutations:" << endl;
    for (auto x: ret)
    {
        for (auto y: x)
        {
            cout << y << ", ";
        }
        cout << endl;
    }
}
