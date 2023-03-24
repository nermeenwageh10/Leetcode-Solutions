class MyLinkedList {
public:
    struct Node{
      int val;
      Node* next;
      Node(int _val, Node* nxt = nullptr)
      {
          val = _val;
          next = nxt;
      }
    };
    int size;
    Node *Head, *Tail; 
    MyLinkedList() {
        size = 0;
        Head = Tail = nullptr; 
    }
    
    int get(int index) {
        if (index >= size) return -1;
        Node* temp = Head; 
        while(index--)
            temp = temp->next; 
        return temp->val; 
    }
    void addAtHead(int val) {
        size++;
        Node* newNode = new Node(val);
        if (Head==nullptr)
        {
            Head = Tail = newNode;
        }else {
            newNode->next = Head;
            Head = newNode;
        }
    }
    
    void addAtTail(int val) {
        size++;
        Node* newNode = new Node(val);
        if (Tail == nullptr){
            Head = Tail = newNode;
        }else {
            Tail->next = newNode;
            Tail = Tail->next;
        }     
    }
    
    void addAtIndex(int index, int val) {
        if (index > size)return;
        if (index == size)
        {
            addAtTail(val);
            return;
        }
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        Node *temp = Head, *prv = nullptr; 
        while(index--)
        {
            prv = temp; 
            temp = temp -> next;
        }
        size++; 
        prv->next = new Node(val, temp); 
    }
    
    void deleteAtIndex(int index) {
        if (index >= size)return; 
        size--;
        if (size == 0){
            Head = Tail = nullptr;
            return;
        }
        if (index == 0){
            Head = Head->next;
            return;
        }
        Node *temp = Head, *prv = nullptr; 
        while(index--)
        {
            prv = temp; 
            temp = temp -> next;
        }
        prv->next = (temp? temp->next: nullptr);
        if (temp->next == nullptr) Tail = prv;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */