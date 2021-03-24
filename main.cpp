#include <iostream>

using namespace std;

struct element
{
    int data;
    element *next;
};


void addToList(element **head, element **tail, int value)
{
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

    return 0;
}
