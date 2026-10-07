class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        // Dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != NULL) {

            // Duplicate check
            if (curr ->next  != NULL && curr -> val == curr -> next-> val) {

                int duplicate = curr ->val;

                // Duplicate ki saari nodes skip karo
                while (curr != NULL && curr -> val == duplicate) {
                    curr = curr -> next;
                }

                prev->next = curr;

            } else {

                prev = curr;
                curr = curr ->next;
            }
        }

        return dummy->next;
    }
};