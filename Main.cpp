#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>

unsigned int gcd(unsigned int a, unsigned int b) {	// Euclidean algorithm using subtraction: gcd(a, b) = gcd(a - b, b)
	if (a % b == 0)
		return b;
	if (b % a == 0)
		return a;
	while (a != b)
		a > b ? a -= b: b -= a;
	return a;
}

unsigned int gcd2(unsigned int a, unsigned int b) {		// Euclidean algorithm using division with remainder: gcd(a, b) = gcd(a % b, b)
	if (a % b == 0)										// (variant via recursion)
		return b;
	if (b % a == 0)
		return a;
	return a > b ? gcd2(a % b, b) : gcd2(a, b % a);
}

int mirror_number(int num) {	// Variant via cycle
	int mir_num = 0;
	while (num)	{
		mir_num = mir_num * 10 + num % 10;
		num /= 10;
	}
	return mir_num;
}

int mirror_number2(int num){	// Variant via recursion
	return num ? num % 10 * pow(10, (int)log10(num)) + mirror_number2(num / 10) : 0;
}

void fill_arr(int arr[], const int length, int A, int B) {
	srand(time(NULL));
	for (int i = 0; i < length; i++) 
		arr[i] = rand() % (B - A + 1) + A;	// [A..B]
}

template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << '[';
	for (int i = 0; i < length; i++) 
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}

template <typename T>
int searh_index_and_sort_arr(T arr[], const int length, T n) {
	int index = -1;
	for (int i = 0; i < length; i++)
		if (arr[i] == n) {
			index = i;
			break;
		}
	std::sort(arr + index + 1, arr + length);
	return index;
}

int main() {
	int n;

	// 19.1 Greatest common divisor (GCD)
	std::cout << "\t19.1 Greatest common divisor (GCD)\n";
	unsigned int a, b;
	std::cout << "Enter 2 integers -> ";
	std::cin >> a >> b;
	std::cout << "gcd(" << a << ", " << b << ") = " << gcd2(a, b) << "\n\n";

	// 19.2 Mirror number
	std::cout << "\t19.2 Mirror number\n";
	std::cout << "Enter number -> ";
	std::cin >> n;
	std::cout << "Mirror number:  " << mirror_number(n) << "\n\n";

	// 19.3 Linear search and sort array
	std::cout << "\t19.3 Linear search and sort array\n";
	const int size3 = 10;
	int arr3[size3];
	int index;
	fill_arr(arr3, size3, 0, 10);	// [0..10]
	std::cout << "Initial array: ";
	print_arr(arr3, size3);
	std::cout << "Enter value to search -> ";
	std::cin >> n;
	index = searh_index_and_sort_arr(arr3, size3, n);
	if (index == -1)
		std::cout << "No match found!\n";
	else {
		std::cout << "Index of the first matching element: " << index << '\n';
		std::cout << "Result array: ";
		print_arr(arr3, size3);
	}
	std::cout << '\n';

	// 19.4 Random fill array
	std::cout << "\t19.4 Random fill array\n";
	const int size4 = 20;
	int arr4[size4];
	int A, B;
	std::cout << "Enter range boundaries -> ";
	std::cin >> A >> B;
	fill_arr(arr4, size4, A, B);
	std::cout << "An array filled with random numbers " << '[' << A << ".." << B << "]:\n";
	print_arr(arr4, size4);

	return 0;
}