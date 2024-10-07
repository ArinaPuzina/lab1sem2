#pragma once
// ���� ��� �������
template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
struct Queue {
    Node<T>* front; 
    Node<T>* last;  
    // �������������� ������� � ������� �����������
    Queue() : front(nullptr), last(nullptr) {}
};

// ����������
template <typename T>
void enqueue(Queue<T>& queue, T value) {
    Node<T>* newNode = new Node<T>; 
    newNode->data = value;          
    newNode->next = nullptr;        

    if (queue.last) {
        queue.last->next = newNode; //����� ���� � �����
    }
    queue.last = newNode;//��������� ���������� �����
    if (!queue.front) {
        queue.front = newNode;//���� ������� ����� ��������� front
    }
}

//�������� �������
template <typename T>
void dequeue(Queue<T>& queue) {
    if (queue.front == nullptr) {
        cout << "Queue is empty!" << endl;
        return;
    }
    Node<T>* temp = queue.front; //��������� ��������� �� ������ �������
    queue.front = queue.front->next; //�������� front �� ��������� �������
    delete temp;
    if (!queue.front) {
        queue.last = nullptr; //���� ������� �����, ���������� last
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
    newNode->next = top;//������� ����� ����� ����             
    top = newNode;                            
}

template <typename T>
void pop(StackNode<T>*& top) {
    if (top == nullptr) {                     
        cout << "Stack is empty\n";
        return;
    }
    StackNode<T>* temp = top; //��������� �� �������
    top = top->next; //�������� �������
    delete temp;
}

//������(����� �����)
template <typename T>
void printStack(StackNode<T>* stack) {
    StackNode<T>* current = stack;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
