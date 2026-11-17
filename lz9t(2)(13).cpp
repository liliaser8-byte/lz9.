#include <iostream>
#include <forward_list>
#include <iomanip>

using namespace std;

int main() {
    forward_list<double> prices;

    // Додаємо вартості покупок до списку
    prices.push_front(15.50);
    prices.push_front(8.20);
    prices.push_front(24.00);
    prices.push_front(5.99);
    prices.push_front(10.00);
    prices.push_front(42.75);

    cout << "Початковий список вартостей покупок: ";
    for (double price : prices) {
        cout << setprecision(2) << fixed << price << " ";
    }
    cout << endl;

    // Формуємо новий список без значень, менших за 10
    forward_list<double> result;
    for (double price : prices) {
        if (price >= 10.0) {
            result.push_front(price);
        }
    }

    cout << "Список після видалення значень < 10: ";
    for (double price : result) {
        cout << setprecision(2) << fixed << price << " ";
    }
    cout << endl;

    return 0;
}