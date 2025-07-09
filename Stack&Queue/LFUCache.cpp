#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key, value, freq;
    Node* next;
    Node* prev;

    Node(int _key, int _value) {
        key = _key;
        value = _value;
        freq = 1;
        next = nullptr;
        prev = nullptr;
    }
};

struct List {
    int size;
    Node* head;
    Node* tail;

    List() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node* node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    void removeNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        size--;
    }
};

class LFUCache {
    int maxSizeCache;
    int curSize;
    int minFreq;
    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqListMap;

    void updateFreqListMap(Node* node) {
        keyNode.erase(node->key);
        freqListMap[node->freq]->removeNode(node);

        // If this was the only node at minFreq, increase minFreq
        if (node->freq == minFreq && freqListMap[node->freq]->size == 0) {
            minFreq++;
        }

        node->freq += 1;

        if (freqListMap.find(node->freq) == freqListMap.end()) {
            freqListMap[node->freq] = new List();
        }

        freqListMap[node->freq]->addFront(node);
        keyNode[node->key] = node;
    }

public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        curSize = 0;
        minFreq = 0;
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) {
            return -1;
        }
        Node* node = keyNode[key];
        updateFreqListMap(node);
        return node->value;
    }

    void put(int key, int value) {
        if (maxSizeCache == 0) return;

        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        } else {
            if (curSize == maxSizeCache) {
                // Remove LRU from the list with minFreq
                List* list = freqListMap[minFreq];
                Node* nodeToRemove = list->tail->prev;
                keyNode.erase(nodeToRemove->key);
                list->removeNode(nodeToRemove);
                curSize--;
            }

            curSize++;
            minFreq = 1;

            Node* newNode = new Node(key, value);
            if (freqListMap.find(minFreq) == freqListMap.end()) {
                freqListMap[minFreq] = new List();
            }

            freqListMap[minFreq]->addFront(newNode);
            keyNode[key] = newNode;
        }
    }
};

// 🧪 Test in main()
int main() {
    LFUCache cache(2); // Capacity 2

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // returns 1

    cache.put(3, 3);              // evicts key 2 (LFU)
    cout << cache.get(2) << endl; // returns -1 (not found)
    cout << cache.get(3) << endl; // returns 3

    cache.put(4, 4);              // evicts key 1 (LFU)
    cout << cache.get(1) << endl; // returns -1 (not found)
    cout << cache.get(3) << endl; // returns 3
    cout << cache.get(4) << endl; // returns 4

    return 0;
}
