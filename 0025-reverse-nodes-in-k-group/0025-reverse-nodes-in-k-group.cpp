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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (temp == NULL)
                return head;
            temp = temp->next;
        }
        ListNode* newHead = reverseKGroup(temp, k);
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* nxt = NULL;
        while (current != temp) {
            nxt = current->next;
            current->next = prev;
            prev = current;
            current = nxt;
        }
        head->next = newHead;
        return prev;
    }
};