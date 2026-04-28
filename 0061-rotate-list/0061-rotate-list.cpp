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
        if (k == 0)
            return head;

        if (head == nullptr)
            return nullptr;

        int length = 1;

        ListNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
            length++;
        }
        ListNode* tail = current;
        if (tail == nullptr)
            return nullptr;
        k %= length;
        tail->next = head;
        current = head;
        for (int i = 0; i < length - k - 1; i++) {
            current = current->next;
        }
        head = current->next;
        current->next = nullptr;
        return head;
    }
};