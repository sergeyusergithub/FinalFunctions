#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

void type_of(int num) {	std::cout << "INT\n";}
//void type_of(long long num) { std::cout << "LONG LONG\n"; }
void type_of(double num) { std::cout << "DOUBLE\n"; }
void type_of(char sym) { std::cout << "CHAR\n"; }

int sum_AB(int a, int b); // прототип функции sum_AB

// Заполнение массива случайными числами
template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;

}

// Вывод массива в консоль
template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}

// Функция сортировки середины массива
template <typename T>
void middle_sort(T arr[], const int length);

// Функция сдвига вправо по кругу
template <typename T>
void move_arr(T arr[], const int length, int steps);


int main() {
	setlocale(LC_ALL, "Russian");
	int m, n;

	// Задача 1. Функция принимает любое число и выводит его тип данных

	//std::cout << "Задача 1.\n";
	//std::cout << "77 - "; type_of(77);
	////std::cout << "7757098547023479 - "; type_of(7757098547023479);
	//std::cout << "5.1 - "; type_of(5.1);
	//std::cout << "'A' - "; type_of('A');
	//std::cout << std::endl;


	// Задача 2. Рекурсивная функция вычисляющая сумму чисел от A До B

	/*std::cout << "Задача 2.\nВведите два числа -> ";
	std::cin >> n >> m;
	std::cout << "Сумма чисел от " << n << " до " << m << " = " << sum_AB(n, m) << "\n\n";*/

	// Задача 3. сортировка середины

	/*std::cout << "Задача 3.\nИзначальный массив:\n";
	const int size3 = 10;
	int arr3[size3];
	fill_arr(arr3, size3, -10, 11);
	print_arr(arr3, size3);
	middle_sort(arr3, size3);
	std::cout << "Итоговый массив:\n";
	print_arr(arr3, size3);*/


	// Задача 4. Функция Сдвига массива вправо по кругу

	std::cout << "Задача 4.\nИзначальный массив:\n";
	const int size4 = 10;
	int arr4[size4]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	print_arr(arr4, size4);
	std::cout << "Введите число - > ";
	std::cin >> n;
	move_arr(arr4, size4, n);
	print_arr(arr4, size4);



	return 0;
}

// реализация фукнции sum_AB
int sum_AB(int a, int b) {
	if (a == b)
		return a;
	
	return sum_AB(a, b - 1) + b;

}

template<typename T>
void middle_sort(T arr[], const int length) {
	int first_index = 0, last_index = 0;
	// Индекс первого отрицательного элемента
	for (int i = 0; i < length; i++)
		if (arr[i] < 0) {
			first_index = i;
			break;
		}
	// Индекс последнего отрицательного элемента
	for (int i = length - 1; i >= first_index; i--)
		if (arr[i] < 0) {
			last_index = i;
			break;
		}
	// Пузырьковая сортировка
	/*for (int i = last_index - 1; i > first_index + 1; i--)
		for (int j = first_index + 1; j < i; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);*/

	//Быстрая сортировка
	std::sort(arr + first_index + 1, arr + last_index);
}

template<typename T>
void move_arr(T arr[], const int length, int steps) {
	T tmp;
	if (steps >= 0) {
		while (steps != 0) {
			tmp = arr[length - 1];
			for (int i = length - 1; i >= 1; i--)
				arr[i] = arr[i - 1];
			arr[0] = tmp;
			steps--;
		}
	}
	else {
		for (int i = 0; i < -steps; i++) {
			for (int i = 0; i < length - 1; i++)
				std::swap(arr[i], arr[i + 1]);
		}
	}	
}
