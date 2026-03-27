class Solution {
public:
    class DSU{
    public:
        vector<int> parent;
        vector<int> size;
        DSU(int n)
        {
            parent.resize(n);
            size.resize(n);
            for(int i = 0; i < n; i++)
            {
                parent[i] = i;
                size[i] = 1;
            }
        }

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

            if(size[px] < size[py])
            {
                parent[px] = py;
                size[py] += size[px];
            }
            else if(size[px] > size[py]) 
            {
                parent[py] = px;
                size[px] += size[py];
            }
            else
            {
                parent[py] = px;
                size[px] += size[py];
            }
        }

    };
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        unordered_map<int, int> mp;
        for(auto &e : edges)
        {
            int u = e[0];
            int v = e[1];

            dsu.merge(u,v);
        }

        // count the edges
        for(auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int root = dsu.find(u);
            mp[root]++;
        }

        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(dsu.find(i) == i)
            {
                int v = dsu.size[i];
                int e = mp[i];

                if((v * (v-1)/ 2) == e) ans++;
            }
        }
        return ans;
    }
};