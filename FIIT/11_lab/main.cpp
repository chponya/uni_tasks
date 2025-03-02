#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};

void AddBack(Node* sent, int data) {
    Node* p = new Node;
    p->data = data; // Записываем данные в новый узел
    // Настраиваем связи нового узла:     (...old-old -new-sent- old-old..)
    p->left = sent->left;   // Новый узел ссылается на текущий последний узел
    p->right = sent;        // Новый узел ссылается на стражник
    // Обновляем связи соседних узлов
    sent->left->right = p;  // Текущий последний узел теперь ссылается на новый узел
    sent->left = p;         // Стражник теперь ссылается на новый узел как на последний
}

// вывод элементов, начиная с правого от стражника и до самого стражника
void Print(Node* sent) {
    Node* p = sent->right;
    while(p != sent) {
        std::cout << p->data << std::endl;
        p = p->right;
    }
}

// Функция для очистки списка и удаления всех узлов
void clearList(Node* sent) {
    Node* current = sent->right; // Начинаем с первого реального узла
    while (current != sent) {     // Пока не дошли до стражника
        Node* next = current->right; 
        delete current;             // Удаляем текущий узел
        current = next;              // Переходим к следующему узлу
    }
    sent->left = sent; // Восстанавливаем состояние пустого списка (sentinel)
    sent->right = sent;
}

bool EndsWith2or4(int number) {
    int lastDigit = number % 10;
    return (lastDigit == 2 || lastDigit == 4);
}

bool IsPrime(int number) {
    if (number < 2) return false;
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) return false;
    }
    return true;
}

int GetFirstDigit(int number) {
    while (number >= 10) {
        number /= 10;
    }
    return number;
}

void SortByFirstDigit(Node* sent) {
    if (sent->right == sent) return; // Список пуст

    bool swapped;
    do {
        swapped = false;
        Node* p = sent->right;
        while (p->right != sent) {
            if (GetFirstDigit(p->data) < GetFirstDigit(p->right->data)) {
                // Меняем данные местами
                int temp = p->data;
                p->data = p->right->data;
                p->right->data = temp;
                swapped = true;
            }
            p = p->right;
        }
    } while (swapped);
}

void RemovePrimes(Node* sent) {
    Node* p = sent->right;
    while (p != sent) {
        Node* next = p->right;
        if (IsPrime(p->data)) {
            // Удаляем узел
            p->left->right = p->right;
            p->right->left = p->left;
            delete p;
        }
        p = next;
    }
}

void DuplicateMultiplesOf10(Node* sent) {
    Node* p = sent->right;
    while (p != sent) {
        if (p->data % 10 == 0) {
            // Создаем новый узел с тем же значением
            Node* newNode = new Node;
            newNode->data = p->data;
            newNode->left = p;
            newNode->right = p->right;
            p->right->left = newNode;
            p->right = newNode;
            p = newNode->right; // Пропускаем новый узел, чтобы избежать бесконечного цикла
        } else {
            p = p->right;
        }
    }
}



int main() {
    Node* sent = new Node;
    sent->left = sent;
    sent->right = sent;

// Добавляем элементы в список
    AddBack(sent, 12);
    AddBack(sent, 24);
    AddBack(sent, 33);
    AddBack(sent, 42);
    AddBack(sent, 50);
    AddBack(sent, 7);
    AddBack(sent, 100);

// Проверяем, есть ли >=3 числа, заканчивающихся на 2 или 4
    int count = 0;
    Node* p = sent->right;
    while (p != sent) {
        if (EndsWith2or4(p->data)) {
            count++;
        }
        p = p->right;
    }

    if (count >= 3) {
        // Упорядочиваем по невозрастанию первой цифры
        SortByFirstDigit(sent);
    } else {
        // Удаляем простые числа и дублируем числа, кратные 10
        RemovePrimes(sent);
        DuplicateMultiplesOf10(sent);
    }

    // Выводим результат
    Print(sent);

    clearList(sent); // Очищаем список и удаляем все узлы
    delete sent; // Удаляем фиктивный узел
    return 0;
}

    

/*
Ввод
count(ends with 2 or 4) >= 3 elems ?
   true: sort by the first digit (descending)
   false: (delete common elems) and (dubicate elems multiple of 10)
*/