#include <iostream>
using namespace std;
// using the recursion
// TC = 2^n;

int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}
// bottom up approach
int fibBU(int n, int *strg)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    if (strg[n] != 0)
    {
        return strg[n];
    }
    int f_1 = fibBU(n - 1, strg);
    int f_2 = fibBU(n - 2, strg);
    int sum = f_1 + f_2;
    strg[n] = sum;
    return sum;
}
// Top Bottom
int fibTB(int n)
{
    int *arr = new int[n + 1];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];
}
// Top Bottom space efficient
int fibTBSE(int n)
{
    int *arr = new int[2];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 1; i < n + 1; i++)
    {
        int sum = arr[0] + arr[1];
        arr[0] = arr[1];
        arr[1] = sum;
    }
    return arr[0];
}
int main()
{

    int n = 100000;
    //  cout << fib(n) << endl;
    // cout << fibBU(n, new int[n + 1])<<endl;
    cout << fibTB(n) << endl;
    cout << fibTBSE(n) << endl;
    return 0;
}
