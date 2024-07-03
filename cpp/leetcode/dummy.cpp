#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int find_parent(int node, vector<int> &a) {
        if (a[node] == node)
            return node;
        else
            return a[node] = find_parent(a[node], a);
    }

    void union_find(int node1, int node2, vector<int> &a) {
        int f = find_parent(node1, a);
        int s = find_parent(node2, a);
        a[s] = f;
    }

    bool canTraverseAllPairs(vector<int> &nums) {
        // There are two bases cases we have to check
        if (nums.size() == 1) return true;
        if (find(nums.begin(), nums.end(), 1) != nums.end()) return false;

        int x = *max_element(nums.begin(), nums.end());
        int prime[x + 1];
        iota(prime, prime + x + 1, 0);
        for (int i = 2; i * i <= x; i++) {
            if (prime[i] == i) {
                for (int j = i * i; j <= x; j += i) {
                    prime[j] = i;
                }
            }
        }

        vector<int> nodes(x + 1);
        iota(nodes.begin(), nodes.end(), 0);
        int ans = 0;
        vector<bool> vis(x + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            int x = prime[nums[i]];
            vis[x] = 1;
            int temp = nums[i];
            while (temp != 1) {
                union_find(x, prime[temp], nodes);
                // vis[x]=1;
                vis[prime[temp]] = 1;
                temp /= prime[temp];
            }
        }

        int count = 0;
        for (int i = 0; i <= x; i++) {
            if (vis[i] == 1 && nodes[i] == i) {
                count++;
            }
        }
        return count == 1;
    }
};