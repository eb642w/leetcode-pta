struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    long long micheng(int n)
    {
        long long a = 1;
        if(n == 0)
            return 1;
        for(int i = 0;i < n;++i)
        {
            a *= 10;
        }
        return a;
    }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        long long a = 0, b = 0;
        int i = 0;
        while(p!=nullptr)
        {
            a = a + p->val * micheng(i);
            i++;
            p = p->next;
        }
        i = 0;
        p = l2;
        while(p!=nullptr)
        {
            b = b + p->val * micheng(i);
            i++;
            p = p->next;
        }
        long long sum = a + b;
        string summ = to_string(sum);
        p = new ListNode(summ[summ.size()-1]-'0');
        ListNode* header = p;
        for(i = (int)summ.size() - 2;i >= 0;i--)
        {
            auto q = new ListNode(summ[i]-'0');
            p->next = q;
            p = q;
        }
        return header;

    }
};
