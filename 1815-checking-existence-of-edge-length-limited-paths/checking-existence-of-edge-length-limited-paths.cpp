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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        parent.resize(n);
        rank.resize(n,0);

        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        // queries ma index push kar diya
        for(int i = 0; i < queries.size(); i++)
        {
            queries[i].push_back(i);
        }
        auto lambda = [&](vector<int> &v1, vector<int> &v2)
        {
            return v1[2] < v2[2];
        };
        sort(edgeList.begin(), edgeList.end(), lambda);
        sort(queries.begin(),  queries.end(),  lambda);

        vector<bool> ans(queries.size());

        int j = 0;

        for(int i = 0; i < queries.size(); i++)
        {
            vector<int> query = queries[i];
            int u   = query[0];
            int v   = query[1];
            int t   = query[2];
            int idx = query[3];

            while(j < edgeList.size() && edgeList[j][2] < t)
            {
                merge(edgeList[j][0],edgeList[j][1]);
                j++;
            }

            if(find(u) == find(v)) ans[idx] = true;
            else ans[idx] = false;
        }
        return ans;
    }
};