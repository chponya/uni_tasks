#include "func.hpp"
#include <iostream>

int main()             
{         
    int n;  
    int mas[100][100];
    sb::ReadMatrix(mas, n);
    if (sb::MoreThanOneMin(mas, n) && sb::MoreThanOnePrime(mas, n)) {
        sb::Lines_Sort(mas, n);
    }
    sb::WriteMatrix(mas, n);

    return 0;           
}   