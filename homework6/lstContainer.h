#pragma once

#include <iostream>

template <typename T>
struct Node {
    Node* pPrev = nullptr;
    Node* pNext = nullptr;
    T data;
};

template <typename T>
class listContainer {
public:
    listContainer() {}; 

    void insert(const T& item, size_t index) {
        if (index > cnt) {return;}
        Node<T>* n = new Node<T>{};
        Node<T>* idx = pLast_;
        if (index == 0) {
            if (pLast_ != nullptr) {
                while (idx->pPrev != nullptr) idx = idx->pPrev;
                n->pNext = idx;
                n->pNext->pPrev = n;
            }
            else {
                pLast_ = n;
            }
        }
        else if (index == cnt) {
            pLast_->pNext = n;
            n->pPrev = pLast_;
            pLast_ = n;
        }
        else {
            for (size_t i = 0; i < index; ++i) { idx = idx->pPrev; }
                n->pNext = idx->pNext;
                n->pNext->pPrev = n;
                idx->pNext = n;
                n->pPrev = idx;
        }
        n->data = item;
        ++cnt;
    }

    void erase(size_t index) {
        if (index > cnt) {return;}
        Node<T>* pNode = pLast_;
        size_t i = cnt;
        while (--i > index) {
            pNode = pNode->pPrev; 
            }
        pNode->pNext->pPrev = pNode->pPrev;
        pNode->pPrev->pNext = pNode->pNext;
        --cnt;

    }

    void pushBack(const T& item) {
        if (cnt == 0) {
            insert(item, 0);
        }
        else {
            insert(item, cnt);
        }
    }

    template <typename T>
    friend std::ostream& operator<<(std::ostream& os, listContainer<T>& cont) {
         for (size_t i = 0; i < cont.size(); ++i) 
                os << cont[i] << " ";
                return os;    
        }

    size_t size() {return cnt;}

    T& operator[](const size_t index) {
        Node<T>* pNode = pLast_;
        size_t i = cnt;
        while (--i > index) {
            pNode = pNode->pPrev; 
            }
        return pNode->data;
        }

private:
    Node<T>* pLast_ = nullptr;
    size_t cnt = 0;
};

