#pragma once
#include <string>
template <typename T>
struct DynamicArray {
    T* data;         //��������� �� ������������ ������
    size_t size;     //������� ������ �������
    size_t capacity; //����������� �������
};

//���������� �������� � ����� �������
template <typename T>
void append(DynamicArray<T>& arr, T value) {
    if (arr.size == arr.capacity) {
        //����������� ������ �������
        arr.capacity *= 2;
        T* newArr = new T[arr.capacity];
        for (size_t i = 0; i < arr.size; i++) {
            newArr[i] = arr.data[i];
        }
        delete[] arr.data;
        arr.data = newArr;
    }
    arr.data[arr.size] = value;
    arr.size++;
}

//��������� �������� �� �������
template <typename T>
T get(const DynamicArray<T>& arr, size_t index) {
    if (index < arr.size) {
        return arr.data[index];
    }
    throw out_of_range("Index out of range");
}

//�������� �������� �� �������
template <typename T>
void removeAt(DynamicArray<T>& arr, size_t index) {
    if (index < arr.size) {
        for (size_t i = index; i < arr.size - 1; i++) {
            arr.data[i] = arr.data[i + 1];
        }
        arr.size--;
    }
}

//������ �������� �� �������
template <typename T>
void replaceAt(DynamicArray<T>& arr, size_t index, T value) {
    if (index < arr.size) {
        arr.data[index] = value;
    }
}

//�����
template <typename T>
size_t length(const DynamicArray<T>& arr) {
    return arr.size;
}

//������
template <typename T>
void printArray(const DynamicArray<T>& arr) {
    for (size_t i = 0; i < arr.size; i++) {
        cout << arr.data[i] << " ";
    }
    cout << endl;
}

//����������� ������ 
template <typename T>
void freeArray(DynamicArray<T>& arr) {
    delete[] arr.data;
}