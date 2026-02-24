class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> degree;

        for(auto &it : edges)
        {
            int u = it[0];
            int v = it[1];

            degree[u]++;
            degree[v]++;
        }

        for(auto &it : degree)
        {
            if(it.second == edges.size()) return it.first;
        }
        return -1;
    }
};