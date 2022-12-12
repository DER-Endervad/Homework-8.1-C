#include <iostream>
#include <Windows.h>

int function(std::string str, int forbidden_length);

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int forbidden_length = 0, length = 0; std::string str = " ";
    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden_length;
    try {
        while (true) {
            std::cout << "Введите слово: ";
            std::cin >> str;
            length = function(str, forbidden_length);
            std::cout << "Длина слова '" << str << "' равна " << length << std::endl;
        }
    }
    catch (std::domain_error& с) {
        std::cerr << с.what() << std::endl;
    }
}

int function(std::string str, int forbidden_length) {
    if (str.length() == forbidden_length) {
        throw std::domain_error("Вы ввели слово запретной длины! До свидания");
    }
    else {
        return str.length();
    }
}
