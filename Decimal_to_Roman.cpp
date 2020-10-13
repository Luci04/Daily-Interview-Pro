#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000

const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;

// Q.Given an integer, convert the integer to a roman numeral.You can assume the input will be between 1 to 3999.

void printRoman(int number)
{
    int num[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string sym[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int i = 12;
    while (number > 0)
    {
        int div = number / num[i];
        number = number % num[i];
        while (div--)
        {
            cout << sym[i];
        }
        i--;
    }
}

int main()
{
    printRoman(3549);
    return 0;
}