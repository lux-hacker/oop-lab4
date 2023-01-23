#ifndef OOP_LAB4_VECTOR_H
#define OOP_LAB4_VECTOR_H

#include <utility>
#include <stdexcept>

namespace collection{
    template<class T>
    class VectorIterator;

    template<class T>
    class vector{
    private:
        int size;
        T* data;

        static T* realloc(const T* mass, int old_size, int new_size){
            T *arr = new T[new_size];
            for(int i = 0; i < old_size; i++){
                arr[i] = mass[i];
            }
            if(old_size != 0) delete[] mass;
            return arr;
        }
    public:
        vector(): size(0), data(nullptr){};
        vector(int size, T* data) : size(size), data(std::move(data)){};
        vector(const vector<T>& other){
            size = other.size;
            data = realloc(data, 0, size);
            for(int i = 0; i < size; i++){
                data[i] = other.data[i];
            }
        }
        vector(vector<T> &&other) noexcept: size(other.size), data(std::move(other.data)){
            other.size = 0;
            delete[] other.data;
            other.data = nullptr;
        }

        ~vector(){
            delete[] data;
        }

        T &operator[] (int index){
            if(index < 0 || index > size) throw std::invalid_argument("IndexOutOfRange: index can be [0, " + std::to_string(size) + "]");
            if(index == size){
                data = realloc(data, size, size+1);
                size++;
            }
            return data[index];
        }

        T &operator[] (int index) const{
            if(index < 0 || index >= size) throw std::invalid_argument("IndexOutOfRange: index can be [0, " + std::to_string(size) + ")");

            return data[index];
        }

        vector<T> &operator=(const vector<T>& other) {
            //if (*other != this) {
                delete[] data;
                data = realloc(data, size, other.size);
                size = other.size;
                for (int i = 0; i < size; i++)
                    data[i] = other.data[i];
            //}
            return *this;
        }

        vector<T> &operator=(vector&& other) noexcept{
            //if (*other != this) {
                delete[] data;
                data = realloc(data, size, other.size);
                size = other.size;
                for (int i = 0; i < size; i++)
                    data[i] = other.data[i];

                delete[] other.data;
                other.data = nullptr;
                other.size = 0;
            //}
            return *this;
        }

        [[nodiscard]] int getSize() const{
            return size;
        }
        void setSize(int size){
            if(size < 0) throw std::invalid_argument("NegativeSize: size of vector cannot be negative");
            T* mass = new T[size];
            int _size;
            if(size < this->size) _size = size;
            else _size = this->size;

            for(int i = 0; i < _size; i++){
                mass[i] = data[i];
            }

            delete[] data;
            data = mass;
            this->size = _size;
        }

        friend class VectorIterator<T>;
        typedef VectorIterator<T> iterator;

        vector<T>::iterator begin(){
            return iterator(data);
        }

        vector<T>::iterator end(){
            return iterator(data + size);
        }
    };

    template<class T>
    class VectorIterator{
        T* ptr;
    public:
        VectorIterator(): ptr(nullptr){}
        VectorIterator(T* ptr): ptr(ptr){}

        int operator!=(const VectorIterator<T> &other) const{
            return this->ptr != other.ptr;
        }

        int operator==(const VectorIterator<T> &other) const{
            return this->ptr == other.ptr;
        }

        T& operator*(){
            if (this->ptr) return *ptr;
            throw std::invalid_argument("Exception: illegal value for List iterator");
        }

        VectorIterator<T> &operator++(){
            this->ptr++;
            return *this;
        }
        const VectorIterator<T> operator++(int){
            VectorIterator<T> res;
            res.ptr = this->ptr;
            res.ptr++;
            return res;
        }

        friend class vector<T>;
    };
}

#endif //OOP_LAB4_VECTOR_H