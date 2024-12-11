#include "func.hpp"
#include <iostream>

namespace sb   // мои инициалы
{
    // Заголовок функции (сигнатура)
    // Тип возвр. значения, название, список аргументов

    // Функция чтения
    void ReadMatrix(int mas[100][100], int& n)
    {
            std::cin >> n;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    std::cin >> mas[i][j];
        }    

    // Функции обработки
    // Поиск минимального числа (и его кол-во больше 1?)
    bool MoreThanOneMin(int mas[100][100], int n) 
    {
            int min_x, min_i, min_j, min_count;
            min_x = mas[1][1];
            min_i = min_j = 1;
            min_count = 0;
            for(int i=1;i<=n;i++) {
                for(int j=1;j<=n;j++) {
                    if (mas[i][j] < min_x) {
                        min_x = mas[i][j];
                        min_i = i;
                        min_j = j;
                        min_count = 1;
                    }
                    else if (mas[i][j] == min_x) {
                        min_count++;
                    }
                }
            }
            if (min_count > 1) return true;
            return false;
        }    

    // Проверка на простоту
    bool isPrime(int x)
    {
        x *= (x > 0) - (x < 0);  // модуль числа
        if(x<2)
            return false;
        int sqrtX = static_cast<int>(sqrt(x));
        for(int d=2;d<=sqrtX;d++)
            if(x % d == 0)
                return false;
        return true;
    }

    // Больше 2х простых чисел?
    bool MoreThanOnePrime(int mas[100][100], int n)
    {
            int prime_count = 0;
            for(int i=1;i<=n;i++) {
                for(int j=1;j<=n;j++) {
                    if (isPrime(mas[i][j])) 
                        prime_count++;
                }
            }
            if (prime_count > 1) return true;
            return false;
    }

    // // Произведение элементов функции
    // int* Product_ofElem_inI(int mas[100][100], int n)
    // {
    //     int mas_prods_in_i[100];
    //     int product;
    //     for(int i=1;i<n;i++) {
    //         product = 1;
    //         for (int x : mas[i]) product *= x;
    //         mas_prods_in_i[i] = product;
    //     }
    //     return mas_prods_in_i;
    // }

    void swap(int& a, int& b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    // Сортировка строк по невозрастанию произведений элементов
    void Lines_Sort(int mas[100][100], int n)
    {
        int mas_prods_in_i[100];
        int product;
        for(int i=1;i<=n;i++) {
            product = 1;
            for(int j=1;i<=n;i++) {
                product *= mas[i][j];
            }
            // for (int x : mas[i]) product *= x;
            mas_prods_in_i[i] = product;
        }
        for(int i=1;i<=n;i++) {
            std::cout << mas_prods_in_i[i] << " ";
        }
        std::cout << "\n";

        for(int i=1;i<=n-1;i++)
            for(int j=i+1;j<=n;j++)
                if(mas_prods_in_i[i] > mas_prods_in_i[j])
                {
                    int tmp[100];
                    for (int k=1;k<=n;k++) {  // Копируем элементы массива
                        tmp[k] = mas[i][k];
                        mas[i][k] = mas[j][k];
                        mas[j][k] = tmp[k];
                    }
                    swap(mas_prods_in_i[i], mas_prods_in_i[j]);
                }
    }


    // Функция записи - вывод
    void WriteMatrix(int mas[100][100], int n)
    {
        std::cout << "Answer:" << "\n";
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
            std::cout << mas[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
}