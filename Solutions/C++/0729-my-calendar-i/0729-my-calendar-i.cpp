class MyCalendar {
public:
    set<pair<int, int>> st;
    MyCalendar() {
        st = set<pair<int, int>>();
    }
    
    bool book(int start, int end) {
        if (st.size() == 0){
            st.insert({start, end});
            return 1;
        }
        auto it = st.upper_bound({start, -1});
        if(it != st.begin()){
            auto prv = it;
            prv--;
            if (prv->first < start && prv->second > start)
                return 0;
        }
        while (it != st.end() && it->first < end){
            if (it->second > start)
                return 0;
            it++;
        }
        st.insert({start, end});
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */