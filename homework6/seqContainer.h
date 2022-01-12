#pragma once

#include <iostream>

template <typename T>
class seqCont {
    public:
        seqCont(size_t size) : 
            ptr_ {new T[size ? size : 1]}, 
            size_ {0}, 
            capacity_{size} {};
        
        void pushBack(const T& item) {
            if (size_ < capacity_) {
                ptr_[size_++] = item;
            }
            else {
                capacity_ *= 2;
                T *buffer = new T[capacity_];
                for (size_t i = 0; i < size_; i++) {
                    buffer[i]=ptr_[i]; 
                }
                buffer[size_] = item;
                delete[] ptr_; 
                ptr_ = buffer;
                size_++;
            }
        }
        
        size_t size() {return size_;}
        
        T& operator[](const size_t index) {return ptr_[index];}

        const T& operator[](const size_t index) const {return ptr_[index]} ;

        void insert(const T& item, size_t index) {
            if (index < 0 || index > size_) {return;}
            ++size_; // increase on one element
            if (size_ < capacity_) {
                for (size_t i = size_; i > index; i--) {
                    ptr_[i] = ptr_[i-1];
                }
                ptr_[index] = item;
            }
            else {
                T* buffer =new T[size_];
                for (size_t i = 0; i < index; i++) {
                    buffer[i]=ptr_[i]; 
                }
                buffer[index++] = item;
                for (index;  index < size_; index++) {
                    buffer[index] = ptr_[index-1];
                }
                delete[] ptr_;
                ptr_ = buffer;
            }         
        }
        
        void erase(size_t index) {
            if (index < 0 || index > size_) {return;}
            --size_; //decrease on one element
            for (size_t i = index; i < size_; i++) {
                ptr_[i] = ptr_[i+1];
            }
        }

        template <typename T>
        friend std::ostream& operator<<(std::ostream& os, seqCont<T>& cont) {
            for (size_t i = 0; i < cont.size(); ++i) 
                os << cont[i] << " ";
                return os;           
        }

        ~seqCont() {
            delete[] ptr_;
         }

    private:
        T *ptr_ = nullptr;
        size_t size_;
        size_t capacity_;
};

 