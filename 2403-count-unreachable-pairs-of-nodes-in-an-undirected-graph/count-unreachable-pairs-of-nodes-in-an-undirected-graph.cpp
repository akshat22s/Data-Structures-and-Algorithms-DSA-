class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x)
    {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void merge(int x, int y)
    {
        int px = find(x);
        int py = find(y);

        if(px == py) return;

        if(parent[px] < parent[py]) parent[px] = py;
        else if(parent[px] > parent[py]) parent[py] = px;
        else
        {
            parent[py] = px;
            rank[px]++;
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);

        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        for(auto &e : edges)
        {
            int x = e[0];
            int y = e[1];

            int px = find(x);
            int py = find(y);

            if(px != py)
            {
                merge(x,y);
            }
        }
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++)
        {
            int x = find(i);
            mp[x]++;
        }

        int rem = n;
        long long  ans = 0;
        for(auto & i : mp)
        {
            ans = ans + ((long long)(i.second) * (long long)((rem - i.second)));
            rem = rem - i.second;
        }
        return ans;
    }
};