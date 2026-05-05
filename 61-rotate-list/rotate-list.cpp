/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;
        
        int n = 0;
        ListNode *cur = head;
        vector<ListNode*> nodes;
        while (cur != nullptr) {
            ++n;
            nodes.push_back(cur);
            cur = cur->next;
        }

        k %= n;
        if (k == 0) return head;

        // last k elements will come in first
        nodes.back()->next = head;
        nodes[n - k - 1]->next = nullptr;
        return nodes[n - k];
    }
};