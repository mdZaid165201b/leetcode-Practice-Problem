/*
  --------------------QUESTION STATEMENT---------------------
  You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains 
  a single digit. Add the two numbers and return the sum as a linked list.

  You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/







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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int countL1 = 0;
        int countL2 = 0;
        ListNode* head = l1;
        while(head != NULL){
            ++countL1;
            head = head->next;
        }
        head = l2;
        while(head != NULL){
            ++countL2;
            head = head->next;
        }
        // cout<<countL1<<" "<<countL2;

        int arr1[countL1];
        int arr2[countL2];

        head = l1;
        int index = 0;
        while(head && index < countL1){
            arr1[index] = head->val;
            ++index;
            head = head->next;
        }
        index = 0;
        head = l2;
        while(head && index < countL2){
            arr2[index] = head->val;
            ++index;
            head = head->next;
        }
        int firstValue = 0;
        for(int i = countL1 - 1; i > 0; i--){
            firstValue =  firstValue + arr1[i];
            firstValue = firstValue * 10;
            if(i == 1){ firstValue += arr1[0]; }
        }
        int secondValue = 0;
        for(int i = countL2 - 1; i > 0; i--){
            secondValue += arr2[i];
            secondValue *= 10;
            if(i == 1){ secondValue += arr2[0]; }
        }
        int finalValue = firstValue + secondValue;
        

        ListNode *temp;
        head = NULL;
        int testVal = finalValue;
        if(finalValue != 0){
            while(finalValue){
            int rem = finalValue % 10;
            if(head == NULL){
                head = new ListNode(rem);
                temp = head;
            }
            else{
                ListNode *test = new ListNode(rem);
                temp->next = test;
                temp = test;
            }
            finalValue = finalValue / 10;
            }
        }
        else{
            head = new ListNode(finalValue);
        }
        
        return head;
    }
        
    
};
