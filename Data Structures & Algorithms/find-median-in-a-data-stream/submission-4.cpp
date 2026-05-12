class MedianFinder {
public:
    priority_queue<int> _small; //maxHeap
    priority_queue<int, vector<int>, greater<int>> _large; //minHeap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        _small.push(num);
        if(!_large.empty() && _small.top()>_large.top()){
            _large.push(_small.top());
            _small.pop();
        }

        if(_small.size() > _large.size()+1){
            _large.push(_small.top());
            _small.pop();
        }

        if(_large.size() > _small.size()+1){
            _small.push(_large.top());
            _large.pop();
        }
    }
    
    double findMedian() {
        if(_small.size() == _large.size()){
            return (_large.top() + _small.top())/2.0;
        } else if(_small.size()>_large.size()){
            return _small.top();
        }

        return _large.top();
    }
};
