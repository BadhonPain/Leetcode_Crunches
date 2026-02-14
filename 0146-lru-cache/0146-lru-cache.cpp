class LRUCache {
public:
    class Node {
    public:
        Node* prev;
        Node* next;
        int key;
        int value;

        Node(int key, int value) {
            this->key = key;
            this->value = value;
            prev = next = NULL;
        }
    };

    Node* head;
    Node* tail;
    int cp;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        cp = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* temp = mp[key];
        deleteNode(temp);
        addNode(temp);

        return temp->value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* temp = mp[key];
            deleteNode(temp);
            delete temp;
            mp.erase(key);
        }

        if (mp.size() == cp) {
            Node* temp = tail->prev;
            mp.erase(temp->key);
            deleteNode(temp);
            delete temp;
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */