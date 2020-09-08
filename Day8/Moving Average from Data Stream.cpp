class MovingAverage {
public:
    /** Initialize your data structure here. */
    double Size = 0.0;
    double curSize = 0.0;
    deque<int> res;
    int sum = 0;
    MovingAverage(int size) {
        Size = size;
        
    }
    
    double next(int val) {
        if(res.size()<Size){
            res.push_back(val);
            curSize++;
            sum+=val;
            return sum/curSize;
        }
        else if (res.size()==Size){
            sum = sum - res.front();
            res.pop_front();
            res.push_back(val);
            sum+=val;
            return sum/curSize;
        }
        
        return sum/curSize;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
