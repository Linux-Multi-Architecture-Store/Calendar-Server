#include <iostream>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/io_service.hpp>

#include "boostasio.h"
using namespace std;
using namespace boost;

int testasio()
{
	try
	{
		//简化类型定义
		typedef boost::asio::ip::tcp::acceptor acceptor_type;
		typedef boost::asio::ip::tcp::endpoint endpoint_type;
		typedef boost::asio::ip::tcp::socket   socket_type;

		//io_service对象
		boost::asio::io_service io;

		//创建监听对象
		acceptor_type  acceptor(io, endpoint_type(boost::asio::ip::tcp::v4(), 8899));

		//循环执行服务
		for (;;)
		{
			//创建一个socket对象
			socket_type sock(io);

			//阻塞等待socket连接
			acceptor.accept(sock);

			cout << "client：";
			cout << sock.remote_endpoint().address() << endl;

			//发送数据
			sock.send(boost::asio::buffer("hello asio"));
		}
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
}
