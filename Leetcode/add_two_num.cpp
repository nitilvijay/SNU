#include <iostream>
#include <cmath>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* l3 = nullptr;
    unsigned long long int length(ListNode* lst) {
        unsigned long long int count = 0;
        while (lst != nullptr) 
        {
            lst = lst->next;
            count++;
        }
        return count;
    }

    void addnode(unsigned long long int val)
    {
        ListNode* node = new ListNode(val);

        if (l3==nullptr)
        {
            l3 = node;
            return;
        }
        ListNode* temp = l3;

        while(temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = node;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

       unsigned long long int digit1 = 0;
       unsigned long long int digit2 = 0;

       unsigned long long int num1 = 1;
       unsigned long long int num2 = 1;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        while (temp1 != nullptr) {
            digit1 += (temp1->val) * num1;
            num1 = num1 * 10;
            temp1 = temp1->next;
        }
        while (temp2 != nullptr) {
            digit2 += (temp2->val) * num2;
            num2 = num2 * 10;
            temp2 = temp2->next;
        }

        unsigned long long sum = digit1 + digit2;
        int rem;

        if (sum==0)
        {
            addnode(0);
            return l3;
        }
        while (sum!=0)
        {
            rem = sum%10;
            sum = sum/10;
            addnode(rem);
        }

        return l3;

    }
};

int main()
{
    
}