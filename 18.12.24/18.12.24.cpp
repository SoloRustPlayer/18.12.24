#include <iostream>

template <typename T>
class Array {
private:
    T* data;
    size_t size;
    size_t capacity;

    void Resize(size_t newCapacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    Array(size_t initialCapacity = 10)
        : size(0), capacity(initialCapacity) {
        data = new T[capacity];
    }

    Array(const Array& other)
        : size(other.size), capacity(other.capacity) {
        data = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    ~Array() {
        delete[] data;
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    void Add(const T& element) {
        if (size >= capacity) {
            Resize(capacity * 2);
        }
        data[size++] = element;
    }

    void Append(const T& value) {
        Add(value);
    }

    void Remove(size_t index) {
        if (index >= size) {
            exit(1);
        }
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }

    size_t GetSize() const {
        return size;
    }

    T& operator[](size_t index) {
        if (index >= size) {
            exit(1);
        }
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size) {
            exit(1);
        }
        return data[index];
    }
};

int main() {
    Array<int> arr;

    arr.Append(10);
    arr.Append(20);
    arr.Append(30);

    std::cout << "After Append: ";
    for (size_t i = 0; i < arr.GetSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    arr.Remove(1);

    std::cout << "After Remove(1): ";
    for (size_t i = 0; i < arr.GetSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;

}
  
