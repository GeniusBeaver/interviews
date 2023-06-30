#include <iostream>
#include "TestStation.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    {
        int T;
        std::cout << "Введите температуру окружающей среды: ";
        std::cin >> T;
        TestStation station1(T);
        std::cout << "Время в секундах, которое проработал генератор до перегрева: " << station1.StartTest1() << std::endl;
    }

    {
        TestStation station2;
        const auto result = station2.StartTest2();
        std::cout << "Максимальная мощность: " << result.first << std::endl;
        std::cout << "При скорости коленвала: " << result.second << std::endl;
    }
}


