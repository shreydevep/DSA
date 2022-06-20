class LRUCache {
public:
    struct Node{
        int key= -1;
        int val = -1;
        Node* prev = NULL;
        Node* next = NULL;
    };
    class DLL{
        public:
        Node* root;
        Node* tail;
        DLL(){
             root = new Node();
             tail = new Node();
            root->next = tail;
            tail->prev = root;
        }
        
        Node* addNode(int keyy,int value,Node* node){
            auto temp = root->next;
            root->next = node;
            node->prev = root;
            node->next = temp;
            temp->prev = node;
            node->val = value;
            node->key = keyy;
            return node;
        }
        void removeNode(Node* node){
            (node->prev)->next = (node->next);
            (node->next)->prev = (node->prev);
            delete node;
        }
        void removeLRU(){
            auto temp = tail->prev;
            tail->prev = temp->prev;
            (temp->prev)->next = tail;
            delete temp;
        }
        
    };
    unordered_map<int,Node*> hashmap;
    int sz;
    int maxSize;
    DLL *dll;
    LRUCache(int capacity) {
        sz = 0;
        maxSize = capacity;
        dll = new DLL();
    }
    
    int get(int key) {
        
        if(!hashmap[key]) return -1;
        auto temp = hashmap[key];
        int v = temp->val;
        int k = temp->key;
        dll->removeNode(temp);
        hashmap[key] = dll->addNode(k,v,new Node());
        return (hashmap[key]->val);
    }
    
    void put(int key, int value) {
        if(hashmap[key]){
            hashmap[key]->val = value;
            get(key);
            return;
        }
        if(sz == maxSize){
            auto temp = dll->tail->prev;
            hashmap.erase(temp->key);
            dll->removeNode(temp);
            sz--;
        }
         
        hashmap[key] = dll->addNode(key,value,new Node());
        sz++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */