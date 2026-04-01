#include <iostream>
#include <vector>
#include <cmath>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n;
    while (true) {
        cout << "Введіть розмір масиву: ";
        cin >> n;
        if (n > 0) break;
        cout << "Розмір масиву не може дорівнювати 0 чи бути від'ємним. Спробуйте ще раз!\n\n";
    }

    vector<int> a(n), b;
    cout << "Введіть елементи масиву: ";
    for (int& x : a) cin >> x;
    int element = a[0], sum = 0;
    bool zero = false;

    for (int i = 0; i < n; ++i) {
        if (abs(a[i]) < abs(element)) element = a[i];
        if (zero) sum += abs(a[i]);
        if (a[i] == 0) zero = true;
        if (i % 2 == 0) b.push_back(a[i]);
    }

    for (int i = 1; i < n; i += 2) b.push_back(a[i]);
    a = b;
    cout << "Найменший елемент (за модулем): " << element << "\n";
    cout << "Сума модулів після першого нуля: " << sum << "\n";
    cout << "Новий масив: ";
    for (int x : a) cout << x << " ";
    cout << "\n";
    return 0;
}