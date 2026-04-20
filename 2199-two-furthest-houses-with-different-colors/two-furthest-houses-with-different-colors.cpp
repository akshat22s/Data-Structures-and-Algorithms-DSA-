class Solution {
public:
    int maxDistance(vector<int>& color) {
        int j = color.size();

        for (int i = 0; i < j; i++)
        {
            if ((color[i] ^ color.back()) | (color[j-1-i] ^ color[0])) return j-1-i;
        }
        return 0;
    }
};