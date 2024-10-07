#pragma once
// Узел для очереди
template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
struct Queue {
    Node<T>* front; 
    Node<T>* last;  
    // Инициализируем очередь с пустыми указателями
    Queue() : front(nullptr), last(nullptr) {}
};

// добавление
template <typename T>
void enqueue(Queue<T>& queue, T value) {
    Node<T>* newNode = new Node<T>; 
    newNode->data = value;          
    newNode->next = nullptr;        

    if (queue.last) {
        queue.last->next = newNode; //новый узел в конец
    }
    queue.last = newNode;//последнйи становится новым
    if (!queue.front) {
        queue.front = newNode;//если очередь пуста обновляем front
    }
}

//удаление элемент
template <typename T>
void dequeue(Queue<T>& queue) {
    if (queue.front == nullptr) {
        cout << "Queue is empty!" << endl;
        return;
    }
    Node<T>* temp = queue.front; //мохраняем указатель на первый элемент
    queue.front = queue.front->next; //сдвигаем front на следующий элемент
    delete temp;
    if (!queue.front) {
        queue.last = nullptr; //если очередь пуста, сбрасываем last
    }
}

template <typename T>
void printQueue(const Queue<T>& queue) {
    Node<T>* current = queue.front;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
//STACK****************************************************************************************************
template <typename T>
struct StackNode {
    T data;            
    StackNode* next;  
};

template <typename T>
void push(StackNode<T>*& top, T value) {
    StackNode<T>* newNode = new StackNode<T>; 
    newNode->data = value;                    
    newNode->next = top;//вершина стека новый узел             
    top = newNode;                            
}

template <typename T>
void pop(StackNode<T>*& top) {
    if (top == nullptr) {                     
        cout << "Stack is empty\n";
        return;
    }
    StackNode<T>* temp = top; //указатель на вершину
    top = top->next; //бновляем вершину
    delete temp;
}

//Чтение(вывод стека)
template <typename T>
void printStack(StackNode<T>* stack) {
    StackNode<T>* current = stack;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
