#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
class Book {
private:
    string title;
    string author;
    float price;
public:
    Book(string t = "", string a = "", float p = 0)
        : title(t), author(a), price(p) {
    }
    void setTitle() {
        cout << "Введіть назву книги: ";
        getline(cin, title);
    }
    void setAuthor() {
        cout << "Введіть автора: ";
        getline(cin, author);
    }
    void setPrice() {
        cout << "Введіть нову ціну: ";
        while (!(cin >> price)) {
            cout << "Помилка! Введіть числове значення: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cin.ignore(1000, '\n');
    }
    void show() {
        cout << "\nНазва: " << title << endl;
        cout << "Автор: " << author << endl;
        cout << "Ціна: " << price << endl;
    }
};

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    Book b1;
    b1.setTitle();
    b1.setAuthor();
    b1.setPrice();
    b1.show();
    Book b2("Гаррі Поттер і філософський камінь", "Джоан Роулінг", 460);
    b2.show();
    Book b3 = b2;
    b3.show();
    return 0;
}