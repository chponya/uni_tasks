#include <iostream>    


// Вар 3
int main()             
{          
    setlocale(LC_ALL, "Russian");   // установка кодировки   

    // Задача 1.            
    // int A, B, C;
    // scanf("%d %d %d", &A, &B, &C);
    // if (A>B & B>C) {
    //     printf("A-B-C = %d\n", A-B-C);
    // }
    // else if (B>A & (B%C==0)) {
    //     printf("B/C+B-A = %d\n", B/C+B-A);
    // }
    // else {
    //     printf("A+B+C = %d\n", A+B+C);
    // }


    // Задача 2. 
    // int N;
    // int count = scanf("%d", &N);
    // if (count) {
    //     switch(N) {
    //         case 0:
    //             printf("Ноль\n");
    //             break;
    //         case 1:
    //             printf("Единица\n");
    //             break;
    //         case 2:
    //             printf("Два\n");
    //             break;
    //         case 3:
    //             printf("Три\n");
    //             break;
    //         case 4:
    //             printf("Четыре\n");
    //             break;
    //         case 5:
    //             printf("Пять\n");
    //             break;
    //         case 6:
    //             printf("Шесть\n");
    //             break;
    //         case 7:
    //             printf("Семь\n");
    //             break;
    //         case 8:
    //             printf("Восемь\n");
    //             break;
    //         case 9:
    //             printf("Девять\n");
    //             break;
    //         default:
    //             printf("Введите ЦИФРУ (т.е. число от 0 до 9)!!!\n");
    //     }
    // }
    // else printf("Введите ЦИФРУ (т.е. ЧИСЛО)\n");

    // Задача 3. 
    int x;
    scanf("%d", &x);
    std::cout << ((x == 1) ? "Positive number" : "Negative number");

    return 0;          
}