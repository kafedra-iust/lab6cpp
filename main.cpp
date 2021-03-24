#include <iostream>

using namespace std;

struct element
{
    int data;
    element *next;
};

void printList(element *head) {
    element *p = head;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
}

void printListRec(element *head) {
    if (head != nullptr) {
        cout << head->data << " ";
        printListRec(head->next);
    }
}

void addInHead(element **head, int value)
{
    //виділення пам'яті під новий елемент списку
    element *p = new element;
    //заповнення інформаційної частини
    p->data = value;
    if (*head != nullptr) //якщо список не порожній
        //встановлення зв'язку між першим елементом списку й новим
        p->next = *head;
    //Переміщення вказівника на голову на новий елемент
    *head = p;
}

void addToList(element **head, element **tail, int value) {
    //виділення пам'яті під новий елемент списку
    element *p = new element;
    //заповнення інформаційної частини
    p->data = value;
    //встановлення посилання останнього елемента
    p->next = nullptr;
    //якщо список порожній
    if (*head == nullptr) // або if (!(*head))
        //встановлення покажчика head на перший елемент
        *head = p;
        //інакше встановлення зв'язку між останнім елементом списку й новим
    else (*tail)->next = p;
    //встановлення покажчика кінця списку на новий елемент
    *tail = p;
}

int main() {
    element *head = nullptr, *tail = nullptr;
    addToList(&head, &tail, 1);
    addToList(&head, &tail, 2);
    addToList(&head, &tail, 3);
    addToList(&head, &tail, 4);
    addToList(&head, &tail, 5);
    addToList(&head, &tail, 6);
    addToList(&head, &tail, 7);

    printListRec(head);

    return 0;
}
