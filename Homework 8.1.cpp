#include <iostream>
#include <Windows.h>

int function(std::string str, int forbidden_length);

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int forbidden_length = 0; std::string str = " ";
    try {
        while (true) {
            std::cout << "Введите запретную длину: ";
            std::cin >> forbidden_length;
            std::cout << "Введите слово: ";
            std::cin >> str;
            forbidden_length = function(str, forbidden_length);
            std::cout << "Длина слова '" << str << "' равна " << forbidden_length << std::endl;
        }
    }
    catch (int i) {
        std::cerr << "Вы ввели слово запретной длины! До свидания" << std::endl;
    }
}

int function(std::string str, int forbidden_length) {
    if (str.length() == forbidden_length) {
        throw -1;
    }
    else {
        return str.length();
    }
}
