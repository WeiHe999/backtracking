#include <bits/stdc++.h>
using namespace std;

template < typename T > void
print (T t)
{
 for (const auto & e:t) cout << e << " ";
  cout << endl;
}

unordered_map<int, int> get_count(vector<int> nums)
{
   unordered_map<int, int> m;
   for(auto x: nums)
   {
       m[x]++;
   }
   return m;
}

vector <vector <int> > permute(vector<int> nums)
{
    // base case
    if (nums.size() == 1) 
        {
            return {{nums[0]}};
        }
        
    // recursive case
    unordered_map<int, int> m2 = get_count(nums);
    vector <vector <int> > res, perms;
    for (auto x: m2)
    {
        if(x.second>0)
        {
            // copy vector and then pop the element from the vector
            vector<int> num1;
            num1.assign(nums.begin(), nums.end());
            num1.erase(find(num1.begin(), num1.end(), x.first));
            perms = permute(num1);
            // add back the popped element
            for (auto &p: perms)
            {
                p.push_back(x.first);
                res.push_back(p);
            }
            
        }
    }
    return res;
}

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    vector <int> nums = {1, 1, 2, 2};
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
