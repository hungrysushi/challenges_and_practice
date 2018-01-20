#pragma once

#include <cstdint>

template <class T>
class Vector {
public:

        typedef T* iterator;

        Vector();
        ~Vector();
        Vector<T>& operator=(const Vector<T>& rhs);

        unsigned int size();
        unsigned int capacity();
        bool empty();
        void reserve(const unsigned int capacity);

        T& operator[](const unsigned int index);
        T& at(const unsigned int index);
        T& front();
        T& back();
        T* data();

        void push_back(const T& val);
        void pop_back();
        
private:
        uint8_t* data_buffer_ = nullptr;

        unsigned int size_;
        unsigned int capacity_;
};

template <typename T>
Vector<T>::Vector() 
        : capacity_(0),
          size_(0),
          data_buffer_(new uint8_t[capacity_ * sizeof(T)])
{
        // nothing else to do here, for now
}

template <typename T>
Vector<T>::~Vector() {
        delete[] data_buffer_;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs) {
        // TODO
}

template <typename T>
unsigned int Vector<T>::size() {
        return size_;
}

template <typename T>
unsigned int Vector<T>::capacity() {
        return capacity_;
}

template <typename T>
bool Vector<T>::empty() {
        return size_ == 0;
}

template <typename T>
void Vector<T>::reserve(const unsigned int capacity) {
        uint8_t* reserved = new uint8_t[capacity * sizeof(T)];

        for (int i = 0; i < size_ * sizeof(T); i++) {
                reserved[i] = data_buffer_[i];
        }
        
        delete[] data_buffer_;
        data_buffer_ = reserved;

        capacity_ = capacity;
}

template <typename T>
T& Vector<T>::operator[](const unsigned int index) {
        // it's undefined behaviour when accessing element outside of vector
        // size, so no need to check here
        return (T&) data_buffer_[sizeof(T) * index];
}

template <typename T>
T& Vector<T>::at(const unsigned int index) {
        return data_buffer_[index];
}

template <typename T>
T& Vector<T>::front() {
        return data_buffer_[0];
}

template <typename T>
T& Vector<T>::back() {
        return data_buffer_[size_ - 1];
}

template <typename T>
T* Vector<T>::data() {
        return (T*) data_buffer_;
}

template <typename T>
void Vector<T>::push_back(const T& val) {
        if (size_ >= capacity_) {
                reserve(capacity_ * 2);
        }

        data_buffer_[size_] = val;
        size_++;
}

template <typename T>
void Vector<T>::pop_back() {
        (T*) (data_buffer_ + (size_ - 1) * sizeof(T)) = new T();
        size_--;
}
