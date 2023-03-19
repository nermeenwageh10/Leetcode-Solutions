class MedianFinder {
public:
    priority_queue<int> left, right;
    // size / 2 + 1,, size / 2 
    int getSize()
    {
        return left.size() + right.size();
    }
    MedianFinder() {
        while(!left.empty()) left.pop();
        while(!right.empty()) right.pop();
    }
    
    void addNum(int num) {
        left.push(num);
        int sz = getSize();
        int lsize = (sz+1)/2, rsize = sz/2;
        while(left.size() > lsize)
        {
            right.push(-left.top());
            left.pop();
        }
        while(right.size() > rsize)
        {
            left.push(-right.top());
            right.pop();
        }
        while(!left.empty() && !right.empty() && left.top() > -right.top())
        {
            int lval = -left.top(); left.pop();
            int rval = -right.top(); right.pop();
            left.push(rval);
            right.push(lval);
        }
    }
    
    double findMedian() {
        if (getSize() % 2)
            return left.top();
        return 1.0 * (left.top() - right.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */