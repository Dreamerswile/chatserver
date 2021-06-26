#ifndef FRIENDMODEL_H
#define FRIENDMODEL_H

#include<vector>

#include "user.hpp"
using namespace std;
// 维护好友信息的操作接口方法
class FriendModel
{
public:
    //添加好友关系
    void insert(int userid, int friended);

    // 返回好友列表
    vector<User> query(int userid);
};

#endif