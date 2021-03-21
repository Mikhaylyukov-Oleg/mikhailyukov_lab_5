#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

void print_text_in_uppercase(string text);
void print_text_in_lowercase(string text);
bool check_if_text_has_letters(string text);
void get_text(string* text);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
        
    cout << "Введите текст:" << endl;

    string text;
    get_text(&text);

    cout << endl;
 
    print_text_in_uppercase(text);
    print_text_in_lowercase(text);

    return 0;
}

void get_text(string* text)
{
    bool text_has_letters;
    do {
        getline(cin, *text);
        text_has_letters = check_if_text_has_letters(*text);
        if (text_has_letters != true) {
            cout << "Ошибка: в введённом тексте нет букв\n";
            cout << "Введите текст снова: \n";
        }
    } while (text_has_letters != true);
}

bool check_if_text_has_letters(string text)
{
    const int number_of_characters = text.length();
    int count_of_letters = 0;
    for (int i = 0; i < number_of_characters; i++) {
        if (((text[i] >= -64) && (text[i] <= -1)) ||
            ((text[i] >= 97) && (text[i] <= 122)) ||
            ((text[i] >= 65) && (text[i] <= 90))) {
            count_of_letters++;
        }
    }
    if (count_of_letters != 0) {
        return true;
    } else {
        return false;
    }
}

void print_text_in_uppercase(string text)
{
    cout << "Ваш текст в верхнем регистре:\n";
    const int number_of_characters = text.length();
    for (int i = 0; i < number_of_characters; i++) {
        if (((text[i] >= -32) && (text[i] <= -1)) || ((text[i] >= 97) && (text[i] <= 122))) {
            text[i] -= 32;
        }
        cout << text[i];
    }
    cout << "\n\n";
}

void print_text_in_lowercase(string text)
{
    cout << "Ваш текст в нижнем регистре:\n";
    const int number_of_characters = text.length();
    for (int i = 0; i < number_of_characters; i++) {
        if (((text[i] >= -64) && (text[i] <= -32)) || ((text[i] >= 65) && (text[i] <= 90))) {
            text[i] += 32;
        }
        cout << text[i];
    }
    cout << "\n";
}