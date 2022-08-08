
#include <iostream>
#include <Windows.h>    //Для ввода русских букв с консоли (SetConsoleCP(1251))


int function(std::string str, int forbidden_length)
{
    if (str.length() != forbidden_length) return str.length();
    else
    {
        throw std::length_error{"Вы ввели слово запретной длины! До свидания"};
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);             // установка кодовой страницы win-cp 1251 в поток ввода
    int forb_length = 0;
    std::cout << "Введите запретную длину: ";
    std::cin >> forb_length;
    std::string user_input;
    while (true)
    {
        std::cout << "Введите слово : ";
        std::cin >> user_input;
        try
        {
            std::cout << "Длина слова \"" << user_input << "\" равна " << function(user_input, forb_length) << std::endl;
        }
        catch (std::length_error& e)
        {
            std::cout << e.what();
            return 0;
        }
    }
}

