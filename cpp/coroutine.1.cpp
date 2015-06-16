#include <iostream>
#include <boost/asio/yield.hpp>

int foo(boost::asio::coroutine& ct) {
    std::cout << "before reenter" << std::endl;
    reenter(ct) {
        std::cout << "before yield1" << std::endl;
        yield std::cout << "yield1" << std::endl;
        std::cout << "before yield2" << std::endl;
        yield return 1;
    }
    std::cout << "after reenter" << std::endl;
    return 2;
}

int main(int argc, char* argv[])
{
    boost::asio::coroutine ct;
    while (!ct.is_complete()) {
        int ret = foo(ct);
        std::cout << "return:" << ret << std::endl;
    }
    return 0;
}
