#include "pch.h"

using namespace std;

string ConvertFromTen(int num, int base)
{
    string chars = "0123456789ABCDEFG";
    string result = "";

    bool isNegative = num < 0;

    if (isNegative) 
    {
       num = -num;
    }

    if (num == 0)
    {
        return "0";
    }

    while (num > 0)
    {
        result += chars[num % base];
        num /= base;
    }

    if (isNegative)
    {
        result += '-';
    }

    string reversedResult;

    for (int i = result.length() - 1; i >= 0; --i) 
    {
        reversedResult += result[i];
    }

    return reversedResult;
}

int main()
{
    setlocale(LC_ALL, "ru");

    int number, base;
    char choice;

    while (true)
    {
        cout << "Введите десятичное число: ";
        cin >> number;

        cout << "Введите систему счисления (2-30): ";
        cin >> base;

        if (base < 2 || base > 30)
        {
            cout << "Система счисления должна быть от 2-ой до 30-ой!" << endl;
            continue;
        }

        string result = ConvertFromTen(number, base);

        cout << "Число в " << base << "-ой системе: " << result << endl;

        cout << "Хотите начать сначала? (y/n): ";
        cin >> choice;

        if (choice == 'n')
        {
            system("cls");
            cout << "Завершение программы...";
            break;
        }
        else if (choice == 'y')
        {
            continue;
        }
        else
        {
            cout << "Некорректный ввод! \n" << "Попробуйте еще раз: ";
            cin >> choice;

            if (choice == 'n')
            {
                system("cls");
                cout << "Завершение программы...";
                break;
            }
        }
    }
    return 0;
}

