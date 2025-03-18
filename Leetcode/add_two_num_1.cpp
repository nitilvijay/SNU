// Using the sum carry method
#include <iostream>
#include <cmath>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:

    ListNode* l3;

    void reverse(ListNode* lst)
    {
        ListNode* prev = nullptr;
        ListNode* curr = lst;
        ListNode* next = nullptr;

        while(curr!=nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

    }

    void addnode(int val)
    {
        ListNode* node = new ListNode(val);
        
        if (l3==nullptr)
        {
            l3 = node;
            return;
        }

        ListNode* temp = l3;
        while(temp->next!=nullptr)
        {
            temp = temp->next;
        }
        temp->next = node;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int sum = 0;
        int car = 0;
        int digit = 0;

        int a,b;

        reverse(l1);
        reverse(l2);

        while (1)
        {
            a = 0;
            b = 0;

            if(l1!=nullptr)
            {
                a = l1->val;
                l1 = l1->next;
            }
            if (l2!=nullptr)
            {
                b = l2->val;
                l2 = l2->next;
            }

            digit = a+b+car;
            sum = digit%10;

            addnode(sum);
            car = digit/10;

        }
        reverse(l3);
        return l3;
    }
};

int main()
{
}