#include <boost/asio.hpp>
#include <boost/asio/spawn.hpp>
#include <memory>
#include <functional>
#include <iostream>


class session : public std::enable_shared_from_this < session >
{
public:
    explicit session(boost::asio::io_service& io_service)
        : strand_(io_service), socket_(io_service)
    {
    }

    boost::asio::ip::tcp::socket& socket()
    {
        return socket_;
    }

    void go()
    {
        boost::asio::spawn(strand_,
            std::bind(&session::echo,
            shared_from_this(), std::placeholders::_1));
    }

private:
    void echo(boost::asio::yield_context yield)
    {
        char data[128];
        for (;;)
        {
            std::size_t n = socket_.async_read_some(boost::asio::buffer(data), yield);
            boost::asio::async_write(socket_, boost::asio::buffer(data, n), yield);
        }
    }

    boost::asio::io_service::strand strand_;
    boost::asio::ip::tcp::socket socket_;
};

void do_accept(boost::asio::io_service& io_service,
    unsigned short port, boost::asio::yield_context yield)
{
    boost::asio::ip::tcp::acceptor acceptor(
        io_service,
        boost::asio::ip::tcp::endpoint(
        boost::asio::ip::tcp::v4(), port));

    for (;;)
    {
        boost::system::error_code ec;
        std::shared_ptr<session> new_session(std::make_shared<session>(io_service));
        acceptor.async_accept(new_session->socket(), yield[ec]);
        if (!ec)
        {
            new_session->go();
        }
    }
}

int main(int argc, char* argv[])
{
    try
    {
        boost::asio::io_service io_service;

        boost::asio::spawn(io_service,
            std::bind(do_accept,
            std::ref(io_service), 8888, std::placeholders::_1));

        io_service.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
