#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
    {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> indeg, outdeg;
        vector<int> eulerPath;
        vector<vector<int>> ans;
        int n = pairs.size();

        for (auto &i : pairs)
        {
            int u = i[0], v = i[1];
            graph[u].push_back(v);
            indeg[v]++;
            outdeg[u]++;
        }
        int node = pairs[0][0];
        for (auto &i : outdeg)
            if (i.second - indeg[i.first] == 1)
            {
                node = i.first;
                break;
            }

        stack<int> st;
        st.push(node);

        while (st.empty() == false)
        {
            int u = st.top();
            if (graph[u].size())
            {
                int v = graph[u].back();
                graph[u].pop_back();
                st.push(v);
            }
            else
            {
                eulerPath.push_back(u);
                st.pop();
            }
        }
        reverse(eulerPath.begin(), eulerPath.end());
        for (int i = 1; i < n + 1; i++)
            ans.push_back({eulerPath[i - 1], eulerPath[i]});

        return ans;
    }
};
