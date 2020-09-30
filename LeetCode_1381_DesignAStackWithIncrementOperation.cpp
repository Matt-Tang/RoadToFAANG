class CustomStack {
public:
    vector<int> v;
    int max;
    CustomStack(int maxSize) {
         max = maxSize;
    }
    
    void push(int x) {
        if(v.size() < max){
            v.push_back(x);
        }
    }
    
    int pop() {
        if(v.empty())
            return -1;
        int result = v.back();
        v.pop_back();
        return result;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < min(k, (int)v.size()); i++){
            v[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */