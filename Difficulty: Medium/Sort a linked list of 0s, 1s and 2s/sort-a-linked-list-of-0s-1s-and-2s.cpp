/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        Node*temp=head;
        Node*dummy=head;
        while(temp!=nullptr)
        {
            if(temp->data == 0)
            {
                swap(dummy->data , temp->data);
                dummy=dummy->next;
            }
            temp=temp->next;
        }
        
        temp=dummy;
        while(temp!=nullptr)
        {
            if(temp->data == 1)
            {
                swap(dummy->data , temp->data);
                dummy=dummy->next;
            }
            temp=temp->next;
        };
        return head; 
        
    }
};
