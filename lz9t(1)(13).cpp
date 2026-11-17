#include <iostream>
#include <forward_list>

using namespace std;

int main() {
    forward_list<double> numList;

    // Додавання дійсних чисел до списку (push_front додає елементи на початок)
    numList.push_front(4.2);
    numList.push_front(-1.5);
    numList.push_front(0.0);
    numList.push_front(-7.8);
    numList.push_front(3.5);
    numList.push_front(-2.1);
    
    cout << "Початковий список дійсних чисел: ";
    for (double n : numList) {
        cout << n << " ";
    }
    cout << endl;

    // 1. Пошук першого додатного елемента (> 0)
    double firstPositive = 0.0;
    bool hasPositive = false;

    for (double n : numList) {
        if (n > 0) {
            firstPositive = n;
            hasPositive = true;
            break;
        }
    }

    // 2. Вставка знайденого елемента після кожного від'ємного (< 0)
    if (hasPositive) {
        for (auto it = numList.begin(); it != numList.end(); ++it) {
            if (*it < 0) {
                // insert_after вставляє значення після поточного ітератора 
                // і повертає ітератор на щойно доданий елемент
                it = numList.insert_after(it, firstPositive);
            }
        }
    } 
    cout << "Список після обробки: ";
    for (double n : numList) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}