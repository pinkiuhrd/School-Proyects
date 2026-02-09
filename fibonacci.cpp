// Created by otam6 on 08/02/2026.

#include <iostream>
using namespace std;

int main() {
    int f1 = 0, f2 = 1, nextt = 0, n;

    cout << "---Welcome to: Fibonacci serie wuuu---\n " << endl;
    cout << "Please enter an entire number and see the fibonacci serie work :D. [ain't try be funny you'll destroy your interface]\n ";
    cin >> n;

    cout << "Fibonacci Series: " << f1 << ", " << f2 << ", ";

    nextt = f1 + f2;

    while(nextt <= n) {
        cout << nextt << ", ";
        f1 = f2;
        f2 = nextt;
        nextt = f1 + f2;
    }//while
    return 0;
}//int
