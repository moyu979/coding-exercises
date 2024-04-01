class MyStack {
public:
    queue<int> q1,q2;
    queue<int>* pointer1,*pointer2;
    MyStack() {
        pointer1=&q1;
        pointer2=&q2;
    }
    
    void push(int x) {
        pointer1->push(x);
    }
    
    int pop() {
        int t;
        t=pointer1->front();
        pointer1->pop();
        while(!pointer1->empty()){
            pointer2->push(t);
            t=pointer1->front();
            pointer1->pop();
        }
        queue<int> *tp=pointer1;
        pointer1=pointer2;
        pointer2=tp;
        return t;
    }
    
    int top() {
        int t;
        while(!pointer1->empty()){
            t=pointer1->front();
            pointer2->push(t);
            pointer1->pop();

        }
        queue<int>* tp=pointer1;
        pointer1=pointer2;
        pointer2=tp;
        return t;
    }
    
    bool empty() {
        if(pointer1->empty()){
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */