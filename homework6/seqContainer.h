#include <iostream>

template <typename T>
class seqCont {
    public:
        seqCont() : 
            ptr_ {new T[1]}, 
            size_ {0}, 
            capacity_{1} {};
        
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
                buffer[size_++] = item;
                //size_++;
                //std::swap(ptr_, buffer);
                delete[] ptr_; 
                ptr_ = buffer;
            }
        }
        
        size_t size() {return size_;}
        
        T& operator[](const size_t index) {return ptr_[index];}

        void insert(const T& item, size_t index) {
            if (index < 0 || index > size_) {return;}
            ++size_; // increase on one element
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
        
        void erase(size_t index) {
            if (index < 0 || index > size_) {return;}
            --size_; //decrease on one element
            T* buffer = new T[size_ > 0 ? size_ : 1];
            size_t i = 0;
            do {
                buffer[i] = ptr_[i];
                ++i;
            } while (i < index);
            while (index < size_) {
                buffer[index] = ptr_[index+1];
                ++index;
            }
            delete[] ptr_;
            ptr_ = buffer;

        }

        template <typename T>
        friend std::ostream& operator<<(std::ostream& os, seqCont<T>& cont) {
            for (size_t i = 0; i < cont.size(); ++i) 
                os << cont[i] << " ";
                return os;           
        }

        // ~seqCont() {
        //     // delete[] ptr_;
        //     ptr_ = nullptr;
        // }
    private:
        T *ptr_ = nullptr;
        size_t size_ ;
        size_t capacity_ ;
};

 //template <typename T>
 //void seqCont<T>::pushBack(const &T item) {

// }
        // int push_back(const T &item) {
        //     if (alloc_size_ > size_) {
        //         ptr_[size_ ++] = item;
        //     }
            
            

        // }

        // int size() {return size_;}

        // T& operator[](size_t index)  {
		// return arr_[index];
        // }

        // const T& operator[](size_t index) const {
		//     return ptr_[index];
        // }

        // template <typename T>
        // std::ostream& operator<<(std::ostream& os, const seqCont<T>& cont) {
        //     for (size_t i = 0; i < cont.size(); ++i) os << cont[i] << " ";
        //         return os;
        // }

        // // template <typename T>