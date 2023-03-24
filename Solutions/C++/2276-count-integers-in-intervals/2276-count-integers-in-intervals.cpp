class CountIntervals {
public:
    static const int mx = 1e9;
    unordered_map<int, int> seg;
    void update(int le, int re, int node = 0, int l = 1, int r = mx)
    {
        if (seg[node] == r - l + 1) return;
        if (le > r || re < l) return;
        if (l >= le && r <= re)
        {
            seg[node] = (r - l + 1);
            return;
        }
        int mid = (l + r) >> 1;
        int n1 = node * 2 + 1;
        int n2 = n1 + 1;
        update(le, re, n1, l, mid);
        update(le, re, n2, mid+1,r);
        seg[node] = seg[n1] + seg[n2];
            
    }
    CountIntervals() {
        
    }
    
    void add(int left, int right) {
        update(left, right);
    }
    
    int count() {
        return seg[0];
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */