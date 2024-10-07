#pragma once
#include <iostream>
using namespace std;

// Односвязный список
template <typename T>
struct NodeSingly {
    T info;
    NodeSingly* next;
};

template <typename T>
void AddHeadS(NodeSingly<T>*& listic, T inf) {
    NodeSingly<T>* NewHead = new NodeSingly<T>;
    NewHead->info = inf;
    NewHead->next = listic;
    listic = NewHead;
}

template <typename T>
void AddTailS(NodeSingly<T>*& listic, T inf) {
    NodeSingly<T>* NewTail = new NodeSingly<T>;
    NewTail->info = inf;
    NewTail->next = nullptr;

    if (listic != nullptr) {
        NodeSingly<T>* lastNode = listic;
        while (lastNode->next != nullptr) {
            lastNode = lastNode->next;
        }
        lastNode->next = NewTail;
    }
    else {
        listic = NewTail;
    }
}

template <typename T>
void RemoveHeadS(NodeSingly<T>*& listic) {
    if (listic != nullptr) {
        NodeSingly<T>* temp = listic;
        listic = listic->next;
        delete temp;
    }
}

template <typename T>
void RemoveTailS(NodeSingly<T>*& listic) {
    if (listic == nullptr) return;
    if (listic->next == nullptr) {
        delete listic;
        listic = nullptr;
        return;
    }

    NodeSingly<T>* temp = listic;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

template <typename T>
void RemoveByValueS(NodeSingly<T>*& listic, T value) {
    if (listic == nullptr) return;
    if (listic->info == value) {
        RemoveHeadS(listic);
        return;
    }

    NodeSingly<T>* temp = listic;
    while (temp->next != nullptr && temp->next->info != value) {
        temp = temp->next;
    }

    if (temp->next != nullptr) {
        NodeSingly<T>* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}

template <typename T>
NodeSingly<T>* FindS(NodeSingly<T>* listic, T value) {
    NodeSingly<T>* temp = listic;
    while (temp != nullptr) {
        if (temp->info == value) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

template <typename T>
void PrintListS(NodeSingly<T>* List) {
    while (List != nullptr) {
        cout << List->info << " ";
        List = List->next;
    }
    cout << endl;
}
// Двусвязный список
template <typename T>
struct NodeDoubLin {
    T info;
    NodeDoubLin* previous;
    NodeDoubLin* next;
};
// Реализация для двусвязного списка
template <typename T>
void AddHeadD(NodeDoubLin<T>*& listic, T inf) {
    NodeDoubLin<T>* NewHead = new NodeDoubLin<T>;
    NewHead->previous = nullptr;
    NewHead->next = listic;
    NewHead->info = inf;
    if (listic != nullptr) {
        listic->previous = NewHead;
    }
    listic = NewHead;
}

template <typename T>
void AddTailD(NodeDoubLin<T>*& listic, T inf) {
    NodeDoubLin<T>* NewTail = new NodeDoubLin<T>;
    NewTail->next = nullptr;
    NewTail->info = inf;

    if (listic != nullptr) {
        NodeDoubLin<T>* lastNodeDoub = listic;
        while (lastNodeDoub->next != nullptr) {
            lastNodeDoub = lastNodeDoub->next;
        }
        NewTail->previous = lastNodeDoub;
        lastNodeDoub->next = NewTail;
    }
    else {
        NewTail->previous = nullptr;
        listic = NewTail;
    }
}

template <typename T>
void RemoveHeadD(NodeDoubLin<T>*& listic) {
    if (listic != nullptr) {
        NodeDoubLin<T>* temp = listic;
        listic = listic->next;
        if (listic != nullptr) { //если второй узел существует
            listic->previous = nullptr;
        }
        delete temp;//удаляем первый
    }
}

template <typename T>
void RemoveTailD(NodeDoubLin<T>*& listic) {
    if (listic == nullptr) return;//если двухсвязного списка нет
    if (listic->next == nullptr) {//если один элемент то сносим голову
        delete listic;
        listic = nullptr;
        return;
    }

    NodeDoubLin<T>* temp = listic;
    while (temp->next != nullptr) {
        temp = temp->next;//находим последний
    }
    temp->previous->next = nullptr;//предпоследний становится последним
    delete temp;
}

template <typename T>
void RemoveByValueD(NodeDoubLin<T>*& listic, T value) {
    if (listic == nullptr) return;

    if (listic->info == value) {
        RemoveHeadD(listic);
        return;
    }

    NodeDoubLin<T>* temp = listic;
    while (temp != nullptr && temp->info != value) {
        temp = temp->next;
    }

    if (temp != nullptr) {
        temp->previous->next = temp->next;//меняем связь на через один
        if (temp->next != nullptr) {//если есть последующий после удаляемого
            temp->next->previous = temp->previous;//меняем связь
        }
        delete temp;
    }
}

template <typename T>
NodeDoubLin<T>* FindD(NodeDoubLin<T>* listic, T value) {
    NodeDoubLin<T>* temp = listic;
    while (temp != nullptr) {
        if (temp->info == value) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

template <typename T>
void PrintListD(NodeDoubLin<T>* List) {
    while (List != nullptr) {
        cout << List->info << " ";
        List = List->next;
    }
    cout << endl;
}