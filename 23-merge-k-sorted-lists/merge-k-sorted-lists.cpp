class Solution {
public:
    typedef pair<int, ListNode*> pi;
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        int n = arr.size();
        for(int i = 0; i < n; i++)
        {
            if(arr[i] != NULL) pq.push({arr[i]->val, arr[i]});
        }
        // for(auto node : arr)
        // {
        //     if(node != NULL) pq.push({node->val, node});
        // }
        ListNode* result = new ListNode(100);
        ListNode* temp = result;
        while(pq.size() != 0)
        {
            auto curr = pq.top();
            pq.pop();
            temp->next = curr.second;
            temp = temp->next;
            if(curr.second->next != NULL)
            {
                pq.push({curr.second->next->val,curr.second->next});
            }
        }
        return result->next;
    }
};