#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

int inputInt(const string& message, int min, int max) {
    string input;
    int value;

    while (true) {
        cout << message;
        getline(cin, input);
        try {
            size_t pos;
            value = stoi(input, &pos);

            if (pos != input.length())
                throw invalid_argument("extra");

            if (value < min || value > max) {
                cout << "Помилка! Введіть число в заданому діапазоні.\n";
                continue;
            }

            return value;
        }
        catch (...) {
            cout << "Помилка! Введіть ціле число.\n";
        }
    }
}

struct Product {
    int id;
    int type;
    int year;
    string origin;
    int warranty;
    int payment;
};

string getTypeName(int type) {
    if (type == 1) return "холодильник";
    if (type == 2) return "телевізор";
    return "невідомо";
}

string getPaymentName(int p) {
    if (p == 1) return "частково";
    if (p == 2) return "повністю";
    return "невідомо";
}

class ProductManager {
private:
    vector<Product> arr;

public:
    ProductManager(int size) {
        arr.resize(size);
    }

    void input() {
        for (int i = 0; i < arr.size(); i++) {

            cout << "\n--- Виріб №" << i + 1 << " ---\n";
            arr[i].id = inputInt("Номер (ID): ", 0, 1000000);

            cout << "Назва виробу (1 - холодильник, 2 - телевізор):\n";
            arr[i].type = inputInt("Оберіть: ", 1, 2);

            arr[i].year = inputInt("Рік випуску (від 1900 до 2026): ", 1900, 2026);

            cout << "Походження: (1 - вітчизняний, 2 - імпортний):\n";
            int originChoice = inputInt("Оберіть: ", 1, 2);
            arr[i].origin = (originChoice == 1) ? "вітчизняний" : "імпортний";

            arr[i].warranty = inputInt("Гарантія (від 1 до 5 років): ", 1, 5);

            cout << "Форма оплати: (1 - частково, 2 - повністю):\n";
            arr[i].payment = inputInt("Оберіть: ", 1, 2);
        }
    }

    void print() const {
        cout << "\n[ Усі вироби ]\n";
        for (const auto& p : arr) {
            cout << "ID: " << p.id
                << " | " << getTypeName(p.type)
                << " | Рік: " << p.year
                << " | " << p.origin
                << " | Гарантія: " << p.warranty << " р."
                << " | " << getPaymentName(p.payment)
                << "\n";
        }
    }

    void print(int currentYear) const {
        cout << "\n[ Холодильники з простроченою гарантією (" << currentYear << ") ]\n";
        bool found = false;

        for (const auto& p : arr) {
            int age = currentYear - p.year;

            if (p.type == 1 && age > p.warranty) {
                cout << "- ID: " << p.id
                    << " | Рік: " << p.year
                    << " | Гарантія: " << p.warranty << " р.\n";
                found = true;
            }
        }

        if (!found)
            cout << "Таких холодильників не знайдено.\n";
    }

    void sortProducts() {
        sort(arr.begin(), arr.end(), [](const Product& a, const Product& b) {
            return a.year < b.year;
            });
        cout << "\n[ Вироби відсортовано за роком випуску ]\n";
    }
};

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n = inputInt("Введіть кількість виробів: ", 1, 1000);
    ProductManager manager(n);
    manager.input();
    ProductManager copiedManager = manager;
    copiedManager.sortProducts();
    copiedManager.print();
    int currentYear = 2026;
    copiedManager.print(currentYear);
    return 0;
}