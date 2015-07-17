#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>

using namespace std;

int main() {
    long long counter = 0, N = 100000000;
    mutex m;
    auto start = chrono::system_clock::now();
    auto f = [&counter, &m, N]() {
      while (true) {
        m.lock();
        ++counter;
        m.unlock();
        if (counter >= N) { return; }
        this_thread::yield();
      }
    };
    thread t1(f), t2(f), t3(f), t4(f), t5(f), t6(f), t7(f), t8(f);
    t1.join(); t2.join(), t3.join(); t4.join(); t5.join(); t6.join(); t7.join(); t8.join();

    auto end = chrono::system_clock::now();
    auto x = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    cout << "counter:" << counter << ", elapsed:" << x << ", cost:" << x/(double)counter;
    return 0;
}
