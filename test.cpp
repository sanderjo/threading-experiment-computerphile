// C++ demonstration of computerphile threading
// Compile: g++ -std=c++17 test.cpp -o test

#include <iostream>
#include <thread>
using namespace std;

int x, y, a, b;

void thread1() {
    x = 1;
    a = y;
}

void thread2() {
    y = 1;
    b = x;
}

int main() {
    size_t count = 0;
    
    do {

        // if count is multiple of 10000, print the count
        if (count % 10000 == 0) {
            cout << "count = " << count << endl;
        }
        ++count;        
        x = y = 0; // important: reset x and y to 0 before each test

        thread first(thread1);
        thread second(thread2);
        first.join();
        second.join();
        if ((a==0) && (b==0)) {
            cout << "Reordering detected!" << endl;
            cout << "count = " << count << ", a = " << a << ", b = " << b << endl;
            break;
        }
        // cout << "count = " << count << ", a = " << a << ", b = " << b << endl;

    } while (count < 1000000);

    //cout << "Final result: count = " << count << ", a = " << a << ", b = " << b << endl;  
    //cout << "count = " << count << ", a = " << a << ", b = " << b << endl;

    return 0;

}
