#include <iostream> 
#include <algorithm>

// Вар 3


// // Task 1
// int increase (const void * a, const void * b) {
//     return ( *(int*)a - *(int*)b );
// }

// int main() 
// { 

//     const short n = 10;
//     int numbers[n] {1, 554, 2, 9, 4, 1, 8, 9, 76, 86};
//     bool Flag = false;  // don't need sort
    
//     for (int i=0; i < n; i++) {
//         int digit_sum = 0; 
//         int x = numbers[i];
//         while (x > 0) {
//             digit_sum += x % 10;
//             x /= 10;
//         }
//         // std:: cout << digit_sum << std::endl;
//         if (digit_sum == 14) {
//             Flag = true;
//             break;
//         } 
//     }

//     if (Flag) {
//         std::sort(numbers, numbers+n, std::greater<int>());
//         qsort (numbers, n, sizeof(int), increase);
//     }
//     for(int i=0; i<n; i++) {
// 	    std::cout << numbers[i] << " " ;
//     }
//     std::cout << std::endl;

//     return 0; 
// }



// // Task 2
// int main() 
// { 
//     const short n = 10;
//     int numbers[n];
//     short first_digit[n];
//     short max_digit[n];

//     for (int i=0; i<n; i++) {
//         std:: cin >> numbers[i];
//         first_digit[i] = numbers[i];
//         while (first_digit[i] >= 9) {
//             first_digit[i] /= 10;
//         }

//         int x = numbers[i];
//         max_digit[i] = 0;
//         while (x > 0) {
//             if (x % 10 > max_digit[i]) {max_digit[i] = x % 10;}
//             x /= 10;
//         }
//     }

//     // SWAP SORT
//     for (int i=0; i<n-1; i++) {
//         for (int j=i+1; j<n; j++) {
//             if ( (first_digit[i] > first_digit[j]) || 
//             (first_digit[i] == first_digit[j] && max_digit[i] > max_digit[j]) || 
//             (first_digit[i] == first_digit[j] && max_digit[i] == max_digit[j] && numbers[i] > numbers[j])) {
//                 int tmp = numbers[i];
//                 numbers[i] = numbers[j];
//                 numbers[j] = tmp;

//                 tmp = first_digit[i];
//                 first_digit[i] = first_digit[j];
//                 first_digit[j] = tmp;

//                 tmp = max_digit[i];
//                 max_digit[i] = max_digit[j];
//                 max_digit[j] = tmp;
                
//             }
//         }

//     }

//     for(int i=0;i<n;i++)
//         std::cout << numbers[i] << " ";    
//     std::cout << "TEST" << std::endl;

//     return 0; 
// }
// // 1 213 222 3 4 542 547 538 32 12


// // Task 3
// int main()
// {
//     const short n=5;
//     const short m=5;
//     int matrix[n][m] = { {0,-1,5,4,1},
//                          {2,5,3,3,5},
//                          {-19,-20,-1,2,3},
//                          {20,6,2,1,-1},
//                          {13,-7,4,0,2} };

//     int min = matrix[0][0];
//     int min_j = 0;

//     for (int i=0; i<n; i++) {
//         for (int j=0; j<m; j++) {
//             if (matrix[i][j] < min) {
//                 min = matrix[i][j];
//                 min_j = j;
//             }
//         }
//     }

//     for (int i=0; i<n; i++) {
//         if (matrix[i][min_j] < 0) {matrix[i][min_j] = 0;}
//     }

//     for (int i=0; i<n; i++) {
//         for (int j=0; j<m; j++) {
//             std::cout << matrix[i][j] << ' ';
//         }
//         std::cout << std::endl;
//     }

//     return 0;
// }




// Task 4
// Есть пара одинаковых цифр?
bool has_duplicates(int x) {
  while (x >= 9) 
  {
    int a = x % 10;
    int b = x / 10;
    while (b > 0) {
      if (a == b % 10) return true;
      b /= 10;
    }
    x /= 10;
  }
  return false;
}

bool has_five(int x) {
    while (x > 0) {
        if (x % 10 == 5) return true; 
        x /= 10;
    }
    return false;
}

int main() {
    const int N_Max = 20000;
    int mas[N_Max];
    int n;

    std::cin >> n; 
    for (int i = 0; i < n; i++)
        std::cin >> mas[i]; 

    int j = 0; // Индекс для записи оставшихся чисел

    // Удаление 
    for (int i = 0; i < n; i++) {
        if (!has_duplicates(mas[i])) {
            mas[j] = mas[i]; // Сохраняем число без дубликатов
            j++;
        }
    }
    
    n = j; // Обновляем размер массива

    // Дублирование 
    for (int i = 0; i < n; i++) {
        if (has_five(mas[i])) {
            // Сдвигаем элементы вправо, чтобы сделать место для дубликата
            for (int k = n; k > i; k--) {
                mas[k] = mas[k-1]; // Сдвигаем элементы вправо
            }
            //mas[i + 1] = mas[i]; // Дублируем текущее число
            i++; // Пропускаем следующий элемент, так как он уже продублирован
            n++;
        }
    }

    for (int i = 0; i < n; i++)
        std::cout << mas[i] << " ";
    
    return 0;
}
