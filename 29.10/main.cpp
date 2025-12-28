#include <iostream>
unsigned absoluteValue(int number) {
	return number >= 0 ? number : -number;
}

bool isDigit(char symbol) {
	return symbol >= '0' && symbol <= '9';
}
bool isUpper(char symbol) {
	return symbol >= 'A' && symbol <= 'Z';
}
bool isLower(char symbol) {
	return symbol >= 'a' && symbol <= 'z';
}
char toUpper(char symbol) {
	if (isLower(symbol))
		return symbol - 'a' + 'A';
	
	return symbol;
}
char toLower(char symbol) {
	if (isUpper(symbol))
		return symbol - 'A' + 'a';
	
	return symbol;
}
char toCharacter(int number) {
	if (number < 0 || number>9)
		return '0';
	return '0' + number;
}
int toNumber(char symbol) {
	if (isDigit(symbol))
		return symbol-'0';
	return '0';
}
unsigned getLength(int number) {
	int count=0;
	do {
		count++;
		number /= 10;
	} while (number);
	return count;
}

unsigned getDigitOnPosition(int number, unsigned int position) {
	if (position > getLength(number))
		return 0;
	while (--position) {
		number /= 10;
	}
	return number % 10;
}
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
int lcm(int first, int second) {
	
	if (first > second) {
		swap(first, second);
	}
	int res = second;
	for (; (res%first || res%second) && res < first * second; res += second);
	return res;
}
unsigned concat(unsigned int first, unsigned int second) {
	int res = first,len_first = getLength(first);
	while (len_first--)
		res *= 10;
	return res + second;
}
int sumInInterval(int m, int n) {
	int res = 0;
	while (m <= n) {
		res += m;
		m++;
	}
	return res;
}
bool isSquareRoot(int number) {
	for (int i = 1; i * i <= number; i++) {
		if (i * i == number)
			return true;
	}
	return false;
}
unsigned getDistance(int x1, int y1, int x2, int y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
unsigned getPerimeter(int x1, int y1, int x2, int y2, int x3, int y3) {
	return getDistance(x1, y1, x2, y2) + getDistance(x2, y2, x3, y3) + getDistance(x1, y1, x3, y3);
}
unsigned getArea(int x1, int y1, int x2, int y2, int x3, int y3) {
	int semi_perimeter = getPerimeter(x1, y1, x2, y2, x3, y3)/2;
	int a = getDistance(x1, y1, x2, y2), b = getDistance(x2, y2, x3, y3), c = getDistance(x1, y1, x3, y3);
	return sqrt(semi_perimeter * (semi_perimeter - a) * (semi_perimeter - b) * (semi_perimeter - c));
}
bool isInCircleWithRadius(int x1, int y1, int x2, int y2, int x3, int y3,unsigned radius) {
	return getDistance(0, 0, x1, y1) <= radius && getDistance(0, 0, x2, y2) <= radius&&getDistance(0, 0, x3, y3) <= radius;
}
bool isDivisibleByValue(int number, int divisor) {
	while (number >= divisor) {
		number -= divisor;
	}
	return !number;
}
int getRemainder(int first, int second) {
	first = absoluteValue(first);
	second = absoluteValue(second);
	while (first >= second) {
		first -= second;
	}
	return first;
}
int getDivision(int first, int second) {
	first = absoluteValue(first);
	second = absoluteValue(second);
	int count = 0;
	while (first >= second) {
		first -= second;
		count++;
	}
	return count;
}
unsigned squareRootToLower(int number) {
	if (number < 0)
		return 0;
	int res = 1;
	while ((res + 1) * (res + 1) <= number)res++;
	return res;
}
bool isPerfect(unsigned number) {
	int sum = 1;
	for (int i = 2; i < number; i++) {
		if (number % i == 0)
			sum += i;
	}
	return sum == number;
}
int pow(int x, int n) {
	int res = 1;
	while (n--) {
		res *= x;
	}
	return res;
}
bool isArmstrongNumber(unsigned number) {
	int n = getLength(number);
	int sum = 0;

	for (int num = number; num;num/=10) {
		sum += pow(num % 10,n);
	}
	return sum == number;
}
int getCollatzValue(int n) {
	if (n == 1) {
		return n;
	}
	else if (n % 2==1) {
		return 3*n+1;
	}
	else {
		return n/2;
	}
}
void collatz(int n) {
	int value= n;
	std::cout << value << std::endl;
	for (int i = 1; i < 500 && value != 1; i++) {
		
		value = getCollatzValue(value);
		std::cout << value << std::endl;
	}
}
long long int factoriel(int n) {
	long long int res = 1;
	for (int i = 2; i <= n; res *= i,i++);
	return res;
}
void pascalTriangle(int n) {
	for (int i =0; i <= n+1; i++) {
		for (int s = 0; s <= n-i; s++) {
			std::cout << " ";
		}
		for (int j = 0; j <= i; j++) {
			std::cout << factoriel(i) / (factoriel(j) * factoriel(i - j))<<" ";
		}
		std::cout << std::endl;
	}
}
int main() {
	pascalTriangle(5);
}