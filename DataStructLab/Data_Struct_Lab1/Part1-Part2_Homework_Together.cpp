#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;
/*
int main() {

    // QUESTION 1: ONE-DIMENSIONAL ARRAY
    // Time Complexity: O(m)

    int arr[200];

    for (int test = 1; test <= 2; test++) {
        int m = (test == 1) ? 100 : 200;

        auto start = high_resolution_clock::now();

        for (int i = 0; i < m; i++)
            arr[i] = i + 1;

        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";

        auto end = high_resolution_clock::now();

        cout << "\nm = " << m;
        cout << "\nTime Complexity: O(m)";
        cout << "\nElapsed Time: "
             << duration_cast<nanoseconds>(end - start).count()
             << " ns\n\n";
    }

    // QUESTION 2: TWO-DIMENSIONAL ARRAY
    // Time Complexity: O(m^2)

    int arr2[20][20];

    for (int test = 1; test <= 2; test++) {
        int m = (test == 1) ? 10 : 20;

        auto start = high_resolution_clock::now();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++)
                arr2[i][j] = i * m + j + 1;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++)
                cout << arr2[i][j] << "\t";
            cout << endl;
        }

        auto end = high_resolution_clock::now();

        cout << "m = " << m;
        cout << "\nNumber of elements: " << m * m;
        cout << "\nTime Complexity: O(m^2)";
        cout << "\nElapsed Time: "
             << duration_cast<nanoseconds>(end - start).count()
             << " ns\n\n";
    }

    // QUESTION 3: THREE-DIMENSIONAL ARRAY
    // Time Complexity: O(m^3)

    int arr3[10][10][10];

    for (int test = 1; test <= 2; test++) {
        int m = (test == 1) ? 5 : 10;

        auto start = high_resolution_clock::now();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < m; k++)
                    arr3[i][j][k] = i * m * m + j * m + k + 1;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < m; k++)
                    cout << arr3[i][j][k] << " ";
                cout << endl;
            }
            cout << endl;
        }

        auto end = high_resolution_clock::now();

        cout << "m = " << m;
        cout << "\nNumber of elements: " << m * m * m;
        cout << "\nTime Complexity: O(m^3)";
        cout << "\nElapsed Time: "
             << duration_cast<nanoseconds>(end - start).count()
             << " ns\n\n";
    }

    return 0;
}
*/








//Sonraki Ödev NEXT HOMEWORK//








// Question 1.A
// Countdown using for loop
// Time Complexity: O(n)

void countdown(int n) {
    for (int i = n; i >= 0; i--)
        cout << i << " ";

    cout << endl;
}

// Question 1.B
// Sum of first n positive integers using while loop
// Time Complexity: O(n)

void sumWhile(int n) {
    int sum = 0, i = 1;

    while (i <= n) {
        sum += i;
        i++;
    }

    cout << "The sum is: " << sum << endl;
}

// Question 1.C
// Sum of first n positive integers using do-while loop
// Time Complexity: O(n)

void sumDoWhile(int n) {
    int sum = 0, i = 1;

    if (n <= 0) {
        cout << "The sum is: 0" << endl;
        return;
    }

    do {
        sum += i;
        i++;
    } while (i <= n);

    cout << "The sum is: " << sum << endl;
}

// Question 2.A
// Print first 50 natural numbers using recursion
// Time Complexity: O(n)

void naturalNumbers(int n) {
    if (n > 50)
        return;

    cout << n << " ";
    naturalNumbers(n + 1);
}

// Question 2.B
// Sum of numbers from 1 to n using recursion
// Time Complexity: O(n)

int recursiveSum(int n) {
    if (n <= 0)
        return 0;

    return n + recursiveSum(n - 1);
}

// Question 3
// Factorial using recursion
// Time Complexity: O(n)

int factorial(int n) {
    if (n <= 1)
        return 1;

    return n * factorial(n - 1);
}

// Question 4
// Fibonacci series using recursion
// Time Complexity: O(n^2) for the naive recursive algorithm

int fibonacci(int n) {
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

void fibonacciSeries(int n) {
    for (int i = 0; i < n; i++)
        cout << fibonacci(i) << " ";

    cout << endl;
}

int main() {
    int n;

    // Question 1.A
    cout << "Enter the n: ";
    cin >> n;
    countdown(n);

    // Question 1.B
    cout << "\nEnter the number of consecutive positive integers (starting from 1): ";
    cin >> n;
    sumWhile(n);

    // Question 1.C
    cout << "\nEnter the number of consecutive positive integers (starting from 1): ";
    cin >> n;
    sumDoWhile(n);

    // Question 2.A
    cout << "\nThe natural numbers are: ";
    naturalNumbers(1);
    cout << endl;

    // Question 2.B
    cout << "\nEnter n to calculate the sum from 1 to n: ";
    cin >> n;
    cout << "The sum of numbers from 1 to " << n
         << ": " << recursiveSum(n) << endl;

    // Question 3
    cout << "\nInput a number: ";
    cin >> n;
    cout << "The Factorial of " << n
         << " is: " << factorial(n) << endl;

    // Question 4
    cout << "\nEnter the number of terms of series: ";
    cin >> n;
    cout << "Fibonacci Series: ";
    fibonacciSeries(n);

    return 0;
}
























