// ����Ա��
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

	// ����Ա��ֻ��Ҫ��������id�������Ƿ���ȷ
	bool isValidPassword(string userid, string userpassword)
	{
		if (userid == id && userpassword == password)
			return true;
		return false;
	}

};


