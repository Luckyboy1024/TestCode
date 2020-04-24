#define _CRT_SECURE_NO_WARNINGS 1

//先编写 UDP Server 服务器/UDP Client 客户端，并使之相互通信，基于string，优先完成基本的网络通信功能
//定义登录注册协议格式

//简单起见，不考虑大小端
struct RegisterInfo
{
	char nick_name[32];
	char school[64];
	char passwd[32];
};
struct LoginInfo
{
	id_type id;
	char passwd[32];
};

struct Reply
{
	int status;
	id_type id;
};


class Message{
private:
	std::string nick_name;
	std::string school;
	std::string msg;
	id_type id;
public:
	Message()
	{}
	-Message()
	{}
	const std::string& GetNickName(){ return this->nick_name; }
	const std::string& GetSchool(){ return this->school; }
	const std::string& GetMsg(){ return this->id; }
	void SetNickName(const std::string &n_)
	{
		this->nick_name = n_;
	}
	void SetSchool(const std::string &s_)
	{
		this->school = s_;
	}
	void SetMsg(const std::string &m_)
	{
		this->msg = m_;
	}
	void SetId(const id_type &i_)
	{
		this->id = i_;
	}
	void Serialize(std::string &message_)
	{
		Json::Value value_;
		value_["nick_name"] = nick_name;
		value_["school"] = school;
		value_["msg"] = msg;
		value_["id"] = id;
		Util::ValueToMessage(value_, message_);
	}
	void Deserialize(std::string &message_)
	{
		Json::Value value_;
		Util::MessageToValue(message_, value_);

		nick_name = value_["nick_name"].asString();
		school = value_["school"].asString();
		msg = value_["msg"].asString();
		id = value_["id"].asInt();
	}
};



