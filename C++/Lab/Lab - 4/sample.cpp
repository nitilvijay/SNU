class Solution
{
public:
    int length(ListNode *head)
    {
        if (head == nullptr)
        {
            return 0;
        }
        ListNode *temp = head;
        int count;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        int len = length(head);
        int count = 1;
        ListNode *temp = head;
        ListNode *temp1;

        if (len < n || n == 0)
        {
            cout << "Invalid" << endl;
            return head;
        }
        else if (len == n) // delete at beginning
        {
            head = head->next;
            return head;
        }
        else if (n == 1)
        {
            ListNode *temp = head;
            int count;
            while (temp != nullptr)
            {
                count++;
                temp = temp->next;
            }
        }
        else
        {
            while (count == (len - n))
            {
                temp = temp->next;
                count++;
            }

            temp1 = temp->next;
            temp->next = temp->next->next;
            delete temp1;

            return head;
        }
    }
};