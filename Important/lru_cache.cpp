class LRUCache
{
    private:

    public:
    class node{
        public:
        int key;
        int val;
        node*prev;
        node*next;
        node(int k,int v){
            key=k;
            val=v;
        }
    };
    node*head=new node(-1,-1);
    node *tail=new node(-1,-1);
    
    int cap;
    unordered_map<int,node*>m;
    
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        this->cap=cap;
        head->next=tail;
        tail->prev=head;
    }
    void addnode(node *newnode){
        node*temp=head->next;
        head->next=newnode;
        newnode->next=temp;
        newnode->prev=head;
        temp->prev=newnode;
    }
    void deletenode(node *delnode){
        delnode->prev->next=delnode->next;
        delnode->next->prev=delnode->prev;
    }
    //Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        if(m.find(key)!=m.end()){
            node*resnode=m[key];
            int res=resnode->val;
            m.erase(key);
            deletenode(resnode);
            addnode(resnode);
            
            m[key]=head->next;
            
            return res;  
        }
        
        return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here   
        if(m.find(key)!=m.end()){
            node*existnode=m[key];
            m.erase(key);
            deletenode(existnode);
        }
        
        if(m.size()==cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        
        addnode(new node(key,value));
        m[key]=head->next;
    }
};
