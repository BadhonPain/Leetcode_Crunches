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
    ListNode* removeElements(ListNode* head, int val) {
        while (head!= NULL && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        ListNode* current = head;
        ListNode* prev = NULL;
        while (current != NULL) {
            if (current->val == val) {
                ListNode* temp = current;
                prev->next = temp->next;
                current = current->next;
                delete temp;
            } else {
                prev = current;
                current = current->next;
            }
        }
        return head;
    }
};