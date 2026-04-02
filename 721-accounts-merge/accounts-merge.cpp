class Solution {
public:
    string find(string x, unordered_map<string,string> &parent)
    {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x], parent);
    }

    void merge(string x, string y, unordered_map<string,string> &parent)
    {
        string px = find(x, parent);
        string py = find(y, parent);

        if(px == py) return;
        parent[py] = px;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        unordered_map<string,string> parent;
        unordered_map<string,string> emailName;

        // Step 1: Initialize
        for(int i = 0; i < n; i++)
        {
            string name = accounts[i][0];

            for(int j = 1; j < accounts[i].size(); j++)
            {
                parent[accounts[i][j]] = accounts[i][j];
                emailName[accounts[i][j]] = name;
            }
        }

        // Step 2: Union
        for(int i = 0; i < n; i++)
        {
            for(int j = 2; j < accounts[i].size(); j++)
            {
                merge(accounts[i][1], accounts[i][j], parent);
            }
        }

        // Step 3: Group emails
        unordered_map<string, set<string>> mp;

        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j < accounts[i].size(); j++)
            {
                string root = find(accounts[i][j], parent);
                mp[root].insert(accounts[i][j]);
            }
        }

        // Step 4: Build answer
        vector<vector<string>> ans;

        for(auto &it : mp)
        {
            vector<string> temp;
            string root = it.first;

            temp.push_back(emailName[root]);

            for(auto &email : it.second)
                temp.push_back(email);

            ans.push_back(temp);
        }

        return ans;
    }
};