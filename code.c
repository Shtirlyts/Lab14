#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
#define N 100

// Прототипы функции
double* full_elements(double* ptr_array, int n);
int put_elements(double* ptr_array, int n);
double* calc_elements(double* ptr_array, int n);
double sum_elements(double* ptr_array, int begin, int end);
int find_min_index(double* ptr_array, int n); // Вариант 1
double average_between(double* ptr_array, int n); // Вариант 17 - Среднее значение элементов

int main() {
	setlocale(LC_ALL, "RUS");
	double array[N];
	int size;
	int begin, end;
	double sum;
	double avg_between;


	printf("Введите размер массива: ");
	scanf("%d", &size);

	if (size <= 0 || size > N) {
		printf("Некорректный размер массива, Массив должен быть от 0 до %d.\n", N);
		return 1;
	}

	// Заполнение массива
	full_elements(array, size);

	// Вывод исходного массива
	printf("\nИсходный массив\n");
	put_elements(array, size);

	// Обработка элементов массива
	calc_elements(array, size);

	// Вывод обработанного массива
	printf("\nМассив после уменьшения значений в 10 раз:\n");
	put_elements(array, size);

	// Вычисление суммы в интервале
	printf("\nВведите начало и конец интервала через пробел для вычисления суммы (0-%d): ", size - 1);
	scanf("%d %d", &begin, &end);

	// Проверка корректности интервала
	if (begin < 0 || end >= size || begin > end) {
		printf("Некорректные интервал\n");
		printf("Интервал должен быть в диапазоне [0, %d] и begin <= end\n", size - 1);
	}
	else {
		sum = sum_elements(array, begin, end);
		printf("Сумма элементов массива с индексами от %d до %d: %.2lf\n", begin, end, sum);
	}

	// Определение индекса минимального элемента в обработанном массиве
	int min_index = find_min_index(array, size);
	printf("\nИндекс минимального элемента в обработанном массиве: %d\n", min_index);
	printf("Значение минимального элемента в обработанном массиве: %.2lf\n", array[min_index]);

	// Среднее значение элементов 
	avg_between = average_between(array, size);
	printf("\nСреднее значение элементов между минимальным и максимальным следующих после него: %.2lf\n", avg_between);

	return 0;


}

// Функция заполнения массива значениями (Я выбрал заполнение квадратами индексов)
double* full_elements(double* ptr_array, int n) {
	for (int i = 0; i < n; i++) {
		ptr_array[i] = (i + 1) * (i + 1);
	}
	return ptr_array;
}

// Функция печати элементов массива
int put_elements(double* ptr_array, int n) {
	for (int i = 0; i < n; i++) {
		printf("array[%d] = %.2lf\n", i, ptr_array[i]);
	}
	return n;
}

// Уменьшить в 10 раз значение каждого элемента массива;
double* calc_elements(double* ptr_array, int n) {
	for (int i = 0; i < n; i++) {
		ptr_array[i] /= 10.0;
	}
	return ptr_array;
}

// Вычисления суммы элементов массива
double sum_elements(double* ptr_array, int begin, int end) {
	double sum = 0.0;

	for (int i = begin; i <= end; i++) {
		sum += ptr_array[i];
	}
	return sum;

}

// Определение  индекса минимального элемента.
int find_min_index(double* ptr_array, int n) {
	int min_index = 0;

	for (int i = 1; i < n; i++) {
		if (ptr_array[i] < ptr_array[min_index]) {
			min_index = i;
		}
	}
	return min_index;
}

// Среднее значение элементов 
double average_between(double* ptr_array, int n) {
	int min_index = find_min_index(ptr_array, n);

	int max_a_min = min_index + 1;
	for (int i = min_index + 2; i < n; i++) {
		if (ptr_array[i] > ptr_array[max_a_min]) {
			max_a_min = i;
		}
	}

	// Вычисляем среднее значение элементов между min_index и max_a_min
	double sum = 0.0;
	int count = 0;

	for (int i = min_index + 1; i < max_a_min; i++) {
		sum += ptr_array[i];
		count++;
	}
	return sum / count;
}