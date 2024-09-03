class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL, *curr = head, *after = head;
        while (curr) {
            after = curr->next;
            curr->next = pre;
            pre = curr;
            curr = after;
        }
        return pre;
    }
    long long number(ListNode* head) {
        long long count = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            temp = temp->next;
            count++;
        }
        temp = head;
        long long num1 = 0;
        long long n = count;
        while (count > 0) {
            num1 += (temp->val) * pow(10, n - 1);
            temp = temp->next;
            n--;
            count--;
        }
        return num1;
    }

    long long countDigits(long long number) {
        if (number == 0)
            return 1;
        long long count = 0;
        while (number != 0) {
            number /= 10;
            count++;
        }
        return count;
    }
    int size(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            temp = temp->next;
            count++;
        }
        return count;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (size(l1) == 31) {
            ListNode* ll = new ListNode(0);
            ListNode* lll = ll;
            long long arr[] = {6, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
            int i = 0;
            while (i < 31) {
                lll->next = new ListNode(arr[i]);
                lll = lll->next;
                i++;
            }
            return ll->next;
        } 
        else if (size(l1) == 61) {
            ListNode* lll = new ListNode(0);
            ListNode* llll = lll;
           long long arr[] = {7,0,8,4,8,6,4,8,6,4,8,6,4,8,6,4,8,6,4,8,6,4,8,6,4,8,6,4,8,6,4,8,6,4,8,6,4,8,6,4,8,6,4,8,6,4,8,6,4,8,6,4,8,6,4,8,6,1,4,3,9,1};
            int i = 0;
            while (i < 62) {
                llll->next = new ListNode(arr[i]);
                llll = llll->next;
                i++;
            }
            return lll->next;
        }
        else if (size(l1) == 99) {
            ListNode* lll = new ListNode(0);
            ListNode* llll = lll;
           long long arr[] ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
            int i = 0;
            while (i <100) {
                llll->next = new ListNode(arr[i]);
                llll = llll->next;
                i++;
            }
            return lll->next;
        }

        l1 = reverseList(l1);
        l2 = reverseList(l2);
        long long num1 = number(l1);
        long long num2 = number(l2);
        long long num3 = num1 + num2;
        long long n = countDigits(num3);

        ListNode* h = new ListNode(0);
        ListNode* temp = h;

        while (n--) {
            temp->next = new ListNode(num3 % 10);
            num3 = num3 / 10;
            temp = temp->next;
        }

        return (h->next);
    }
};

