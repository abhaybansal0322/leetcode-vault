class MedianFinder {

    priority_queue<int> leftMaxHeap;
    priority_queue<int,vector<int>,greater<int>> rightMinHeap;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(leftMaxHeap.empty() || num < leftMaxHeap.top())  leftMaxHeap.push(num);

        else rightMinHeap.push(num);

        if((int)leftMaxHeap.size() - (int)rightMinHeap.size() > 1) {

            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        }

        else if((int)rightMinHeap.size() > (int)leftMaxHeap.size()) {

            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }

    }
    
    double findMedian() {

        if((int)leftMaxHeap.size() == (int)rightMinHeap.size()) return (double) (leftMaxHeap.top()+rightMinHeap.top())/2;

        return (double)leftMaxHeap.top();
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */