#include <boost/asio.hpp>


void session(boost::asio::io_service& io_service){
    // construct TCP-socket from io_service
    boost::asio::ip::tcp::socket socket(io_service);

    try{
        for(;;){
            // local data-buffer
            char data[max_length];

            boost::system::error_code ec;

            // read asynchronous data from socket
            // execution context will be suspended until
            // some bytes are read from socket
            std::size_t length=socket.async_read_some(
                    boost::asio::buffer(data),
                    boost::asio::yield[ec]);
            if (ec==boost::asio::error::eof)
                break; //connection closed cleanly by peer
            else if(ec)
                throw boost::system::system_error(ec); //some other error

            // write some bytes asynchronously
            boost::asio::async_write(
                    socket,
                    boost::asio::buffer(data,length),
                    boost::asio::yield[ec]);
            if (ec==boost::asio::error::eof)
                break; //connection closed cleanly by peer
            else if(ec)
                throw boost::system::system_error(ec); //some other error
        }
    } catch(std::exception const& e){
        std::cerr<<"Exception: "<<e.what()<<"\n";
    }
}

int main() {
  boost::asio::io_service io_service;
  session(io_service);
  return 0;
}
