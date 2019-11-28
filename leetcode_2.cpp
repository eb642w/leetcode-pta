class Solution {
public:
    bool jinwei = false;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* header = new ListNode(l1->val + l2->val);
        ListNode* p = header;
        p1 = p1->next;
        p2 = p2->next;
        if(header->val >= 10)
            jinwei = true;
        while(p1 != nullptr or p2 != nullptr)
        {
            ListNode* q = new ListNode(0);
            if(p1!= nullptr)
            {
                q->val += p1->val;
                p1= p1->next;
            }
            if(p2!= nullptr)
            {
                q->val += p2->val;
                p2 = p2->next;
            }
            if(jinwei)
            {
                p->val %= 10;
                q->val++;
                jinwei = false;
            }
            if(q->val >= 10)
            {
                //q->val = q->val%10;
                jinwei = true;

            }
            p->next = q;
            p = p->next;

        }
        if(jinwei)
        {
            p->next = new ListNode(1);
            p->val %= 10;
        }
        return header;
    }
};
