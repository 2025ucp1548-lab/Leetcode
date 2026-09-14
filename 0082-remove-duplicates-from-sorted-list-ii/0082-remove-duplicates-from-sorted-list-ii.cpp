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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        std::unordered_map<int, int> counts;
        ListNode* curr = head;
        while (curr) {
            counts[curr->val]++;
            curr = curr->next;
        }
        ListNode* dummy = new ListNode(0, head);
        ListNode* temp = dummy; 
        while (temp->next) {
            if (counts[temp->next->val] > 1) {
                ListNode* toDelete = temp->next;
                temp->next = temp->next->next; 
                delete toDelete;               
            } else {
                temp = temp->next;             
            }
        }
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};