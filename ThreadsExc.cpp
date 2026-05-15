#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>
using namespace std;
// using mutex to make each proccess wait for the previous one to finish before it can start
std::mutex mtx;
void foo(int a) {
 sleep(5);
 // making sure each process locks behind himself so no one will bother it
 mtx.lock();
 cout << a << endl;
 mtx.unlock();
}
int main() {
 thread threads[20];
 for (int i = 0; i < 20; i++){
 threads[i] = thread(foo, i);
 }
 for (int i = 0; i < 20; i++){
 threads[i].join();
 }
}
