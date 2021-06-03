// Example02.cpp
//

#include <iostream>
#include <vector>

void interchange(double& a, double& b) {

    double c = a;
    a = b;
    b = c;

    //std::cout << "a = " << a << ", b = " << b << '\n';
}

// Writing a sorting algorithm, putting list of numbers into increasing order
// by successively comparing elements and interchanging them.
void bubblesort(double a[], int N) {

    for (int i = 1; i < N; i++) {

        for (int j = 1; j <= N - i; j++) {

            if (a[j - 1] > a[j])
                interchange(a[j - 1], a[j]);
        }
    }
}

void print(double a[], int N) {

    std::cout << "sorted array: ";
    for (int i = 0; i < N; i++)
        std::cout << a[i] << " ";
}

int main() {

    //double a = 5.0, b = 2.0;
    //interchange(a, b);

    double arr[] = { 64,34,25,12,22,11,90 };
    int N = sizeof(arr) / sizeof(arr[0]);
    bubblesort(arr, N);
    print(arr, N);

    return 0;
}