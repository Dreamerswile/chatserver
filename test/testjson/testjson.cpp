#include "json.hpp"

using json = nlohmann::json;

#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

// json序列化实例1 普通数据序列化
string func1(){
    json js;
    js["msg_type"] = 2;
    js["from"] = "zhang san";
    js["to"] = "li si";
    js["msg"] = "hello, what are you doing now?";

    string sendBuf = js.dump();

    //cout<<sendBuf.c_str()<<endl;
    return sendBuf;
    //cout<<js<<endl;
}
// json序列化实例2 
string func2(){
    json js;
    //添加数组
    js["id"] = {1,2,3,4,5};
    //添加key-value
    js["name"] = "zhang san";
    //添加对象
    js["msg"]["zhang san"] = "hello world";
    js["msg"]["liu shuo"] = "hello china";
    // 上面等同于下面这句一次性添加数组对象
    js["msg"] = {{"zhang san","hello world"},{"liu shuo", "hello china"}};
    //cout<<js<<endl;
    return js.dump();
}
// json序列化实例3 容器序列化
string func3(){
    json js;

    // 直接序列化一个vector容器
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);
    
    js["list"] = vec;

    // 直接序列化一个map容器
    map<int, string> m;
    m.insert({1, "黄山"});
    m.insert({2, "华山"});
    m.insert({5, "泰山"});

    js["path"] = m;

    string sendBuf = js.dump(); // json 数据对象 => 序列化 json字符串
    //cout<<sendBuf<<endl;
    return sendBuf;
    
}
// Json数据反序列化


int main(){
    //func1();
    //func2();
    //func3();

    string recvBuf = func3();
    //数据反序列化  json字符串 => 反序列化 数据对象（看作容器，方便访问）
    json jsbuf = json::parse(recvBuf);

    // cout<<jsbuf["msg_type"] <<endl;
    // cout<<jsbuf["from"] <<endl;
    // cout<<jsbuf["to"] <<endl;
    // cout<<jsbuf["msg"] <<endl;

    // cout<<jsbuf["id"]<<endl;
    // auto arr = jsbuf["id"];
    // cout<<arr[2]<<endl;

    // auto msgjs = jsbuf["msg"];
    // cout<<msgjs["zhang san"]<<endl;
    // cout<<msgjs["liu shuo"]<<endl;

    vector<int> jsvec = jsbuf["list"];
    cout<<jsvec[1]<<endl;
    map<int, string> jsmap = jsbuf["path"];
    for(auto &p :jsmap){
        cout<<p.first<<" "<< p.second<<endl;
    }
    cout<<jsmap[1]<<endl;

    return 0;
}