#include <iostream>
#include <cmath>

class Cuboid {

    double length;  
    double width;   
    double height; 

public:
    // Конструктор для инициализации длины, ширины и высоты
    Cuboid(double l, double w, double h) : length(l), width(w), height(h) {}

// Методы
    // Расчёт площади поверхности
    double calculateSurfaceArea() const {
        return 2 * (length * width + length * height + width * height);
    }

    // Расчёт объема
    double calculateVolume() const {
        return length * width * height;
    }

    // Расчёт длины диагонали
    double calculateDiagonal() const {
        return std::sqrt(length * length + width * width + height * height);
    }

    // Вывод информации о параллелепипеде
    void printInfo() const {
        std::cout << "Прямоугольный параллелепипед с размерами: " << length << " x " << width << " x " << height << std::endl;
        std::cout << "Площадь поверхности: " << calculateSurfaceArea() << std::endl;
        std::cout << "Объем: " << calculateVolume() << std::endl;
        std::cout << "Длина диагонали: " << calculateDiagonal() << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");   // установка кодировки
    // Создаем объект класса Cuboid
    Cuboid parallelepiped(3.0, 4.0, 5.0);

    // Выводим информацию о параллелепипеде
    parallelepiped.printInfo();

    return 0;
}