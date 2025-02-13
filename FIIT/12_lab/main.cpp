#include <iostream>    
using namespace std; 


// // 1. Рассчёт длины строки при помощи рекурсии
// int calculateLength(const char* str) {    // char* str - хранит адрес первого символа в массиве str.
//     if (*str == '\0') {
//         return 0;
//     } else {
//         return 1 + calculateLength(str + 1);
//     }
// }

// int main() {
//     char str[101]; // Максимальная длина строки — 100 символов + нуль-терминатор
//     std::cout << "Enter a line: ";
//     std::cin.getline(str, 100); // Считываем строку с клавиатуры
//     std::cout << "Line length: " << calculateLength(str) << std::endl;
//     return 0;
// }                  


// 2. Реализуйте быструю сортировку. Сравните скорость работы с сортировкой обменами.
// Quick_sort VS Bubble_sort  ---  O(n*log_n) VS O(n^2)

void QuickSort(int a, int b, int* arr) {
    if(a>=b)
        return;
    // Выбор опорного элемента
    int k = (rand()*rand()) % (b-a+1) + a;
    int m = arr[k];
    // Пресорт
    int l = a - 1;
    int r = b + 1;
    while(true) {
        do l++; while(arr[l] < m);
        do r--; while(arr[r] > m);
        if(l >= r) 
            break;
        std::swap(arr[l], arr[r]);
    }
    l = r;
    r++;
    QuickSort(a, l, arr);
    QuickSort(r, b, arr);
}

int main() {

    // srand(time(0));
    const int n = 1'000'000;
    int arr[n] = {2, 3, 1, 6, 4};
    QuickSort(0, n-1, arr);
    std::cout << "===" << std::endl;
    for(int i=n-10;i<n;i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    return 0;
}