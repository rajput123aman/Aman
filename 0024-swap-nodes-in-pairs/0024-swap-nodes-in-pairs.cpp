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
    ListNode* swapPairs(ListNode* head) {

        // 0 ya 1 node ke liye
        if (head == NULL || head->next == NULL)
            return head;

        // First aur second node
        ListNode* first = head;
        ListNode* second = head->next;

        // Remaining list ko swap karo
        first->next =swapPairs(second->next);

        // Second ko first ke aage lagao
        second->next=first;


        // New head
        return second;
    }
};