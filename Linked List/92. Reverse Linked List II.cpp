// 92. Reverse Linked List II

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(left == right){
            return head;
        }

        int count = 1;
        int size = 0;
        ListNode*temp = head,*left_curr, *right_curr, *lp,*rn;

        while(temp){

            if(count == left-1){
                lp = temp;
            }
            if(count == left){
                left_curr = temp;
            }
            if(count == left-1){
                lp = temp;
                left_curr = temp->next;
            }

            if(count == right){
                right_curr = temp;
            }

            size++;
            count++;
            temp = temp->next;
        }

        cout<<"Count: "<<count<<endl;
        cout<<"Size: "<<size<<endl;

        if(left == 1 && right-left == 1){
            left_curr->next = right_curr->next;
            right_curr->next = left_curr;
            return right_curr;
        }

        if(left == 1){
            ListNode*prev = right_curr->next;
            ListNode*curr = left_curr;
            ListNode*temp = left_curr;

            while(prev != right_curr){
                curr = curr->next;
                temp->next = prev;
                prev = temp;
                temp = curr;
            }

            return right_curr;

        }
        lp->next = right_curr;

        rn = right_curr->next;


        cout<<left_curr->val<<endl;
        cout<<right_curr->val<<endl;

        ListNode*prev = right_curr->next;
        ListNode*curr = left_curr;
        ListNode*temp1 = curr;

        while(prev != right_curr){
            curr = curr->next;

            temp1->next = prev;
            prev = temp1;
            temp1 = curr;
        }

        while(prev){
            cout<<prev->val<<" ";
            prev=prev->next;
        }


        return head;
    }
};
