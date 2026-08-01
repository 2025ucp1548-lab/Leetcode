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
    int getDecimalValue(ListNode* head) {
        ListNode* temp= head;
        int count =0;
        while(temp!=nullptr){
            temp=temp->next;
            count++;
        }
        ListNode* temp1= head;
        int sum=0;
        while(temp1!=nullptr){
            count--; 
            if (temp1->val == 1) {
                sum += (1 << count); 
            }
            temp1 = temp1->next;
        }
        return sum;
    }
};