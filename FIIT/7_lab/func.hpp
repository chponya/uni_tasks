// заголовочный файл
#pragma once

namespace sb
{
    // Заголовок функции (сигнатура)
    // Тип возвр. значения, название, список аргументов
    void ReadMatrix(int mas[100][100], int& n);
    bool MoreThanOneMin(int mas[100][100], int n);
    bool isPrime(int x);
    bool MoreThanOnePrime(int mas[100][100], int n);
    void swap(int& a, int& b);
    void Lines_Sort(int mas[100][100], int n);
    void WriteMatrix(int mas[100][100], int n);


}