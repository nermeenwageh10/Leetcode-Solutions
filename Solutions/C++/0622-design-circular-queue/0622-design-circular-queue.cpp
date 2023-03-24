class MyCircularQueue {
public:
    vector<int> v;
    int front, back, size, cnt;
    MyCircularQueue(int k) {
        v = vector<int>(k);
        front = cnt = back = 0;
        size = k;
    }
    
    bool enQueue(int value) {
        if (!isFull()){
            v[front] = value;
            cnt++;
            front = (front + 1) % size;
            return 1;
        }else {
            return 0;
        }
    }
    
    bool deQueue() {
        if (!isEmpty()){
            back = (back + 1) % size;
            cnt--;
            return 1;
        }
        return 0;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return v[back];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return v[(front-1+size)%size];
    }
    
    bool isEmpty() {
        return cnt == 0;
    }
    
    bool isFull() {
        return cnt == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */