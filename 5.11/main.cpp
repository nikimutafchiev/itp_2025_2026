#include <iostream>
const int SIZE = 6;
void init(int arr[]) {
	for (int i = 0; i < SIZE; i++) {
		std::cin >> arr[i];
	}
}
void print(int arr[]) {
	for (int i = 0; i < SIZE; i++) {
		std::cout << arr[i]<<" ";
	}
	std::cout << std::endl;
}
double average(int arr[]) {
	double sum = 0;
	for (int i = 0; i < SIZE; i++) {
		sum += arr[i];
	}
	return sum / SIZE;
}
int min(int arr[]) {
	if (SIZE == 0)
		return 1 << 30;
	int min = arr[0];
	for (int i = 1; i < SIZE; i++) {
		if (min > arr[i])
			min = arr[i];
	}
	return min;
}
int max(int arr[]) {
	if (SIZE == 0)
		return 1 << 30;
	int max = arr[0];
	for (int i = 1; i < SIZE; i++) {
		if (max < arr[i])
			max = arr[i];
	}
	return max;
}
int second_biggest(int arr[]) {
	if (SIZE == 0)
		return 1 << 30;
	int _max = max(arr), second_max = -1024;
	for (int i = 0; i < SIZE; i++) {
		if (second_max < arr[i] && arr[i] != _max)
			second_max = arr[i];
	}
	return second_max;
}
void remove(int arr[], unsigned index)
{
	if (index >= SIZE)
		return;
	for (int j = index; j < SIZE - 1; j++) {
		arr[j] = arr[j + 1];
	}
	arr[SIZE - 1] = 0;
}
bool is_palindrome(int arr[]) {
	for (int i = 0; i < SIZE / 2; i++) {
		if (arr[i] != arr[SIZE - i-1])
			return false;
	}
	return true;
}
int gcd(int n, int k) {
	if (n < k)
	{
		int temp = n;
		n = k;
		k = temp;
	}

	while (k != 0)
	{
		int mod = n % k;
		n = k;
		k = mod;
	}
	return n;
}
int gcd_array(int arr[]) {
	int gcd_ = arr[0];
	for (int i = 1; i < SIZE; i++) {
		gcd_ = gcd(gcd_, arr[i]);
	}
	return gcd_;
}
bool is_concatenated_palindromes(int arr[]) {
	bool is_palindrome_1, is_palindrome_2;
	for (int i = 0; i < SIZE-1; i++) {
		is_palindrome_1 = is_palindrome_2 = true;
		for (int k = 0; k < i; k++) {
			if (arr[k] != arr[i - k - 1])
				is_palindrome_1 = false;
		}
		if (!is_palindrome_1)
			continue;
		for (int k = i; k < SIZE; k++) {
			if (arr[k] != arr[SIZE - k ])
				is_palindrome_2 = false;
		}
		if (is_palindrome_1 && is_palindrome_2)
			return true;
	}
	return false;
}
bool is_sorted_asc(int arr[])
{
	for (int i = 0; i < SIZE - 1; i++) {
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}
int find(int arr[], int elem) {
	for (int i = 0; i < SIZE; i++) {
		if (arr[i] == elem)
			return i;
	}
	return -1;
}
int rfind(int arr[], int elem) {
	for (int i = SIZE - 1; i >= 0; i--) {
		if (arr[i] == elem)
			return i;
	}
	return -1;
}
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
void selection_sort(int arr[]) {
	for (int i = 0; i < SIZE-1; i++) {
		int min = i;
		for (int j = i + 1; j < SIZE; j++) {
			if (arr[min] > arr[j])
				min = j;
		}
		swap(arr[i], arr[min]);
	}
}
int binary_search(int arr[], int elem) {
	int l = 0, r = SIZE - 1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (elem > arr[mid])
			l = mid;
		else if (elem < arr[mid])
			r = mid;
		else
			return mid;
	}
	return -1;
}
int longestNonDecreasingSubsequence(int arr[],int size) {
	int max = 1,count =1;
	for (int i = 1; i < size; i++)
	{
		if (arr[i] >= arr[i - 1])
			count++;
		else
		{
			if (count > max)
				max = count;
			count = 1;
		}
	}
	return max;
}
int main() {
	int arr[]{ 6,3,6,1,4,4,6,7,-1 };
	std::cout << longestNonDecreasingSubsequence(arr, sizeof(arr) / sizeof(int));
	//std::cout << is_concatenated_palindromes(arr);
	//std::cout << is_palindrome(arr);
	//remove(arr, 3);
	//print(arr);
	//std::cout << second_biggest(arr);
	//init(arr);
	//print(arr);
	//std::cout << average(arr);
}