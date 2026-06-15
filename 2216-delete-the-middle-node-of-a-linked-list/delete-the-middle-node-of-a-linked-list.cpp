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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        ListNode *cur = head;
        while (cur != nullptr) ++n, cur = cur->next;

        if (n == 1) return nullptr;

        cur = head;
        int i = 0;
        while (cur != nullptr) {
            ++i;
            if (i == n / 2) {
                cur->next = cur->next->next;
            }
            cur = cur->next;
        }
        return head;
    }
};