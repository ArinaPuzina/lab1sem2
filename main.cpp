#include "lists.hpp"
#include "queue&stack.hpp"

int main() {
    NodeSingly<int>* ListS = nullptr;
    AddHeadS(ListS, 1);
    AddHeadS(ListS, 2);
    PrintListS(ListS);
    RemoveTailS(ListS);
    PrintListS(ListS);
    NodeDoubLin<int>* ListD = nullptr;
    AddTailD(ListD, 3);
    AddTailD(ListD, 4);
    PrintListD(ListD);
    RemoveByValueD(ListD, 3);
    PrintListD(ListD);

    // Очистка памяти
    while (ListS != nullptr) {
        RemoveHeadS(ListS);
    }
    while (ListD != nullptr) {
        RemoveHeadD(ListD);
    }
    Queue<int> myQueue;
    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);
    cout << "Current queue: ";
    printQueue(myQueue);
    dequeue(myQueue);
    cout << "After dequeue: ";
    printQueue(myQueue);
    dequeue(myQueue);
    dequeue(myQueue);
    dequeue(myQueue);
    StackNode<int>* stack = nullptr;
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    printStack(stack);
    return 0;
}