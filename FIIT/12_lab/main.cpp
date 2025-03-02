#include <iostream>    
#include <cstdlib>
#include <ctime>

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

// void QuickSort(int a, int b, int* arr) {
//     if (a >= b)
//         return;
    
//     // Выбор опорного элемента
//     int k = a + rand() % (b - a + 1);    // случайный индекс
//     int m = arr[k];    // Опорный элемент (pivot) — относительно которого происходит разделение.
    
//     // Пресорт
//     int l = a;
//     int r = b;
//     while (l <= r) {
//         while (arr[l] < m) l++;
//         while (arr[r] > m) r--;
//         if (l <= r) {
//             std::swap(arr[l], arr[r]);
//             l++;
//             r--;
//         }
//     }
    
//     QuickSort(a, r, arr);
//     QuickSort(l, b, arr);
// }

// int main() {
//     setlocale(LC_ALL, "Russian");
//     srand(time(0)); // Инициализация генератора случайных чисел

//     const int n = 10; // Размер массива
//     int arr[n] = {2, 3, 1, 6, 6, 9, 7, 8, 7, 0}; // Инициализация массива

//     std::cout << "Исходный массив: ";
//     for (int i = 0; i < n; i++) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;

//     QuickSort(0, n - 1, arr); // Сортировка

//     std::cout << "Отсортированный массив: ";
//     for (int i = 0; i < n; i++) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }


// 3. Обход лабиринта за минимальное количество шагов
#include <fstream> // библиотека для чтения из файлов
// ‘.’ - можно пройти; ‘#’ - нельзя пройти; ‘S’ - старт; ‘E’ - финиш;
// ходить можно и по диагонали
// Лабиринт NxM
#define N 100
#define M 100

int n, m;
char field[N][M];
int steps[N][M];

void Search(int i, int j, int step) {
    if(steps[i][j] <= step)
        return;
    steps[i][j] == step;

    if(field[i][j] == 'E')
        return;

    if(i+1 < N && field[i+1][j] != '#')
        Search(i+1, j, step + 1);
    if(i-1 >= 0 && field[i-1][j] != '#')
        Search(i-1, j, step + 1);
    if(j+1 < M && field[i][j+1] != '#')
        Search(i, j+1, step + 1);
    if(j-1 >= 0 && field[i][j-1] != '#')
        Search(i, j-1, step + 1);
    if(i-1 >= 0 && j-1 >= 0 && field[i-1][j-1] != '#')
        Search(i-1, j-1, step + 1);
    if(i-1 >= 0 && j+1 < M && field[i-1][j+1] != '#')
        Search(i-1, j+1, step + 1);
    if(i+1 < N && j+1 < M && field[i+1][j+1] != '#')
        Search(i+1, j+1, step + 1);
    if(i+1 < N && j-1 >= 0 && field[i+1][j-1] != '#')
        Search(i+1, j-1, step + 1);


}

int main() {
    // Заполним матрицу поля по файлу
    int si, sj, ei, ej;
    char field[N][M];
    int n, m;
    std::ifstream in("input.txt");
    in >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) {
            in >> field[i][j];
            steps[i][j] = INT_MAX;
            if(field[i][j] == 'S') {
                si = i;
                sj = j;
            } else if(field[i][j] == 'E') {
                ei = i;
                ej = j;
            }
        }
    Search(si, sj, 0);
    std::cout << steps[ei][ej];
    
}

