#include<unordered_map>
class Node{
public:
    Node* next=nullptr;
    Node* pre=nullptr;
    int key=-1;
    int value=-1;
};
class LRUCache {
public:
    unordered_map<int,Node*> map;
    Node* head=new Node();
    Node* rare=head;
    int cap;
    int size=0;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        cout<<key<<endl;
        if(map.find(key)==map.end()){
            return -1;
        }else{
            Node *get=map[key];
            if(get==nullptr){
                cout<<"fsdfs";
            }
            if(get==rare){
                ;
            }else{
                get->next->pre=get->pre;
                get->pre->next=get->next;
                rare->next=get;
                get->pre=rare;
                get->next=nullptr;
                rare=get;
            }
            
            return get->value;
        }
    }
    
    void put(int key, int value) {
        cout<<key<<" "<<value<<endl;
        auto find=map.find(key);
        if(find!=map.end()){
            Node* n=map[key];
            n->value=value;
            if(n==rare){
                ;
            }else{
                n->next->pre=n->pre;
                n->pre->next=n->next;
                rare->next=n;
                n->pre=rare;
                rare=n;
            }
        }
        else if(size!=cap){
            Node* n=new Node;

            n->value=value;
            n->key=key;
            n->pre=rare;
            n->next=nullptr;

            rare->next=n;
            rare=n;

            map[key]=n;
            size++;
        }else{
            Node* n=head->next;
            head->next=head->next->next;
            if(n==rare){
                rare=n->pre;
                rare->next=nullptr;
            }else{
                n->next->pre=n->pre;
                n->pre->next=n->next;
            }

            auto d=map.find(n->key);
            map.erase(d);

            n->key=key;
            n->value=value;
            n->pre=rare;
            n->next=nullptr;

            map[key]=n;
            rare->next=n;
            rare=n;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */