// 21. Merge Two Sorted Lists

// less efficient approach

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int>ele;

        while(list1){
            ele.push_back(list1->val);
            list1 = list1->next;
        }
        while(list2){
            ele.push_back(list2->val);
            list2 = list2->next;
        }

        priority_queue<int, vector<int>, greater<int> > pq(ele.begin(),ele.end());

        ListNode*head =  new ListNode(0);
        ListNode*temp = head;

        while(!pq.empty()){
            temp->next = new ListNode(pq.top());
            pq.pop();
            temp = temp->next; 
        }

        return head->next;

    }
};

// Better Approach

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode*head = new ListNode(0);
        ListNode*temp = head;

        while(list1 && list2){

            if(list1->val <= list2->val){
                temp->next = new ListNode(list1->val);
                temp = temp->next;
                list1 = list1->next;

            }

            else if(list2->val < list1->val){
                temp->next = new ListNode(list2->val);
                temp = temp->next;
                list2 = list2->next;

            }

            // temp = temp->next;
        }

        while(list1){
            temp->next = new ListNode(list1->val);
            // temp->next = list1->val;
            temp = temp->next;
            list1 = list1->next;
        }
        while(list2){
            temp->next = new ListNode(list2->val);
            // temp->next = list2->val;
            temp = temp->next;
            list2 = list2->next;
        }

        return head->next;
    }
};
