#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class Foo{
public:
    int a, b;
    Foo(){}
    Foo(int a_, int b_){
        a = a_;
        b = b_;
    }
};


int main(){
    std::vector<int> v(1, 2);
    for (auto x : v) { cout << x << endl; }

    std::map<std::string, Foo> myMap = { {"1", Foo(10,5)}, {"2", Foo(5,10)} };
    int b  = myMap["1"].b;    // it tries to call private constructor of Foo.
    cout << b << endl;
    return 0;
}

//int fun(const vector<string>& x) {
//  return x.size();
//}
//int main() {
//  cout << fun({"1", "2"}) << endl;
//  return 0;
//}
