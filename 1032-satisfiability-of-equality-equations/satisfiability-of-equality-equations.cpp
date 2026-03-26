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
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26, 0);

        for(int i = 0; i < 26; i++)
        {
            parent[i] = i;
        }
        
        // equal wala cases
        for(auto &s : equations)
        {
            if(s[1] == '=')
            {
                merge(s[0]-'a',s[3]-'a');
            }
        }
        
        // not equal wala cases
        for(auto &s : equations)
        {
            if(s[1] == '!')
            {
                char x = s[0];
                char y = s[3];

                int px = find(x-'a');
                int py = find(y-'a');

                if(px == py) return false;
            }
        }
        return true;
    }
};