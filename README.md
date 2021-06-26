# chatserver
可以工作在nginx tcp负载均衡环境中的集群聊天服务器和客户端源码 使用mysql作为数据存储 基于muduo网络库实现 利用redis作为中间件消息队列，使用分布式服务器之间的通信 

编译方式
cd build
rm -rf *
cd ..
cmake ..
make

需要启动nginx，reids服务器
