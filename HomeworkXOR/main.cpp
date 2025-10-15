#include <iostream>
using namespace std;

/*---------------- 1. Two unique numbers ----------------*/
void findTwoUniques(int *arr, int n, int &a, int &b) {
    int xr = 0;
    for (int i = 0; i < n; i++) xr ^= arr[i]; // XOR الكل
    int rightmost = xr & -xr; // بت مختلف بين العددين الفريدين
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] & rightmost) x ^= arr[i];
        else y ^= arr[i];
    }
    a = x;
    b = y;
}

/*---------------- 2. Missing number ----------------*/
int missingNumber(int *arr, int n) {
    int xr = 0;
    for (int i = 0; i < n; i++) xr ^= arr[i];
    for (int i = 0; i <= n; i++) xr ^= i;
    return xr;
}

/*---------------- 3. Check power of 2 ----------------*/
bool isPowerOfTwo(unsigned int x) {
    return x && ((x & (x - 1)) == 0);
}

/*---------------- 4. Swap using XOR ----------------*/
void xorSwap(int &a, int &b) {
    if (&a == &b) return;
    a ^= b;
    b ^= a;
    a ^= b;
}

/*---------------- 5. Count 1s in binary (Hamming weight) ----------------*/
int popcount(unsigned int x) {
    int cnt = 0;
    while (x) {
        x &= (x - 1);
        cnt++;
    }
    return cnt;
}

/*---------------- 6. Reverse bits ----------------*/
unsigned int reverseBits(unsigned int x) {
    unsigned int rev = 0;
    for (int i = 0; i < 32; i++) {
        rev = (rev << 1) | (x & 1);
        x >>= 1;
    }
    return rev;
}

/*---------------- 7. Equal XOR split ----------------*/
bool canSplitWithEqualXor(int *arr, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) total ^= arr[i];
    return (n > 1 && total == 0);
}

/*---------------- 8. Multiply by 9 using shifts ----------------*/
int mul9(int x) {
    return (x << 3) + x; // (x*8)+x = x*9
}

/*---------------- Main to test all ----------------*/
int main() {
    // (1)
    int arr1[] = {1, 2, 3, 2, 1, 5};
    int a, b;
    findTwoUniques(arr1, 6, a, b);
    cout << "1) Unique numbers: " << a << " and " << b << endl;

    // (2)
    int arr2[] = {0, 1, 3, 4};
    cout << "2) Missing number: " << missingNumber(arr2, 4) << endl;

    // (3)
    cout << "3) Is 16 power of 2? " << (isPowerOfTwo(16) ? "Yes" : "No") << endl;

    // (4)
    int x = 5, y = 7;
    cout<< "4) Before swap: x=" << x << ", y=" << y << endl;
    xorSwap(x, y);
    cout << " -> After swap: x=" << x << ", y=" << y << endl;

    // (5)
    cout << "5) Hamming weight of 29: " << popcount(29) << endl;

    // (6)
    unsigned int num = 13;
    cout << "6) Reverse bits of 13: " << reverseBits(num) << endl;

    // (7)
    int arr3[] = {1, 2, 3};
    cout << "7) Can split equally by XOR? "
         << (canSplitWithEqualXor(arr3, 3) ? "Yes" : "No") << endl;

    // (8)
    cout << "8) 9 * 7 = " << mul9(7) << endl;

    return 0;
}
