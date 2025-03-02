#include <iostream>
#include <cstdint>

int main() {
    setlocale(LC_ALL, "Russian"); 
    int16_t num = 0x1234; // пример числа

    // Используем указатель на unsigned char для доступа к байтам
    unsigned char* ptr = reinterpret_cast<unsigned char*>(&num);
    std::cout << "Указатель типа unsigned char: " << std::hex << ptr << std::dec << std::endl;
    std::cout << "Размер указателя типа unsigned char: " << sizeof(ptr) << std::endl;
    std::cout << "Число: 0x" << std::hex << num << std::dec << std::endl;
    // std::cout << std::hex  << ptr << std::dec  << std::endl;
    std::cout << "Байты (без учёта порядка байтов):" << std::endl;
    std::cout << "Байт 1: 0x" << std::hex << static_cast<int>(ptr[0]) << std::dec << std::endl;
//  std::cout << "Байт 1: 0x" << std::hex << ptr[0] << std::dec << std::endl;   // Байт 1: 0x4 - Если это значение больше 127, то при неявном преобразовании в int может произойти расширение знака (sign extension), приводящее к неверному результату. 
    std::cout << "Байт 2: 0x" << std::hex << static_cast<int>(ptr[1]) << std::dec << std::endl;


    short* numu = &num;
    std::cout << "Указатель типа short: " << std::hex << numu << std::dec << std::endl;
    std::cout << "Размер указателя типа short: " << std::hex << sizeof(numu) << std::dec << std::endl;
    std::cout << "Байт 1: 0x" << std::hex << numu[0] << std::dec << std::endl;
    std::cout << "Байт 2: 0x" << std::hex << numu[1] << std::dec << std::endl;
    return 0;
}

// Результат выполнения программы зависит от порядка байтов (endianness) на системе:
// • Little-endian: младший байт находится по меньшему адресу. (мой случай)
// • Big-endian: старший байт находится по меньшему адресу.









/*
Тип short определён в C++ как имеющий как минимум 16 бит, но  его фактический размер может варьироваться в зависимости от компилятора и архитектуры целевой системы.
Тип int16_t из заголовочного файла <cstdint>  всегда имеет ровно 16 бит, обеспечивая переносимость кода.
*/