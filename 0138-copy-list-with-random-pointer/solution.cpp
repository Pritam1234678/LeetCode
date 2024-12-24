/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(0);
        Node* temp = head;
        Node* tempc = dummy;
        while (temp) {
            Node* a = new Node(temp->val);
            tempc->next=a;
            tempc = tempc->next;
            temp = temp->next;
        }
        Node* b = dummy->next; // copy LL
        Node* a = head;        // real LL
        unordered_map<Node*, Node*> m;
        // step2: Make a map of <original,duplicate>
        Node* tempa = a;
        Node* tempb = b;
        while (tempa) {
            m[tempa] = tempb;
            tempa = tempa->next;
            tempb = tempb->next;
        } //connecting random 
        for (auto x : m) {
            Node* o = x.first;
            Node* d = x.second;
            if (o->random != NULL) {
                Node* p = o->random;
                Node* q = m[o->random];
                d->random = q;
            }
        }
        return b;
    }
};
