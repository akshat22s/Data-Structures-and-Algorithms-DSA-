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

        if(parent[px] < parent[py]) parent[px] = py;
        else if(parent[px] > parent[py]) parent[py] = px;
        else
        {
            parent[py] = px;
            rank[px]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n > connections.size() + 1) return -1;
        parent.resize(n);
        rank.resize(n,0);

        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        int component = n;
        for(auto &v : connections)
        {
            int x = v[0];
            int y = v[1];

            int px = find(x);
            int py = find(y);

            if(px != py)
            {
                merge(x,y);
                component--;
            }
        }
        return component - 1;
    }
};