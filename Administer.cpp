// 管理员类
#include <iostream>
using std::string;
class Administer {
private:
	string id;
	string password;
public:
	Administer(string id = "", string password = "")
	{
		this->id = id;
		this->password = password;
	}

	// 管理员类只需要检查输入的id和密码是否正确
	bool isValidPassword(string userid, string userpassword)
	{
		if (userid == id && userpassword == password)
			return true;
		return false;
	}

};


