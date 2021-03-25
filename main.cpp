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

element * findNode(element * head, int x)
{
    // покажчик на перший елемент списку
    element * node = head;
    while(node != nullptr) {    // або while(node)
        //якщо заданий елемент знайдено
        if (node->data == x)
            //закінчення пошуку і повернення покажчика на цей елемент
            return node;
            // у іншому випадку
        else
            // перехід на наступний елемент списку
            node = node->next;
    }
    // якщо список вичерпано, то шуканий елемент не знайдено,
    // тому повертаємо «порожнє» значення
    return nullptr;
}

void addNodeAfter(element ** pk, int value)
{
    //створення нового динамічного об'єкта
    element * p = new element;
    //запис інформаційної частини
    p->data = value;
    //заповнення покажчика на наступний елемент
    p->next = (*pk)->next;
    //додавання нового елемента в список
    (*pk)->next = p;
}

int deleteFirst(element ** head)
{
    //зберігаємо адресу елемента, який потрібно видалити
    element * p = *head;
    //отримуємо з нього інформацію
    int value = p->data;
    //встановлюємо голову списку на наступний елемент
    *head = p->next;
    //видаляємо перший елемент
    delete p;
    // повертаємо значення видаленого елемента
    return value;
}

int deleteLast(element * head)
{
    //знаходження передостаннього елемента списку
    element * p = head;
    while (p->next->next != nullptr) p = p->next;
    //збереження адреси останнього елемента
    element * temp = p->next; // tail
    //вибирання з нього інформації
    int value = p->next->data; // або value = temp->data;
    //видалення останнього елемента
    delete temp;
    //збереження ознаки кінця списку
    p->next = nullptr;
    return value;
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
    cout << endl;

    element * pk = findNode(head, 4);
    addNodeAfter(&pk, 45);

    printListRec(head);
    cout << endl;

    int v = deleteFirst(&head);
    cout << "v = " << v << endl;

    printListRec(head);
    cout << endl;

    v = deleteLast(head);
    cout << "v = " << v << endl;

    printListRec(head);

    return 0;
}
