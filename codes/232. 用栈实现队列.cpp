class MyQueue {
public:
    stack<int> s1,s2;
    stack<int>* pointer1,*pointer2;
    MyQueue() {
         pointer1=&s1,pointer2=&s2;
    }
    
    void push(int x) {
        pointer1->push(x);
    }
    
    int pop() {
        if(pointer2->empty()){
            while(!pointer1->empty()){
                pointer2->push(pointer1->top());
                pointer1->pop();
            }
        }
        int t=pointer2->top();
        pointer2->pop();
        return t;
    }
    
    int peek() {
        if(pointer2->empty()){
            while(!pointer1->empty()){
                pointer2->push(pointer1->top());
                pointer1->pop();
            }
        }
        return pointer2->top();
    }
    
    bool empty() {
        if(pointer1->empty() && pointer2->empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */