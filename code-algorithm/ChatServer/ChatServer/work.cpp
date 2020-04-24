#define _CRT_SECURE_NO_WARNINGS 1

//�ȱ�д UDP Server ������/UDP Client �ͻ��ˣ���ʹ֮�໥ͨ�ţ�����string��������ɻ���������ͨ�Ź���
//�����¼ע��Э���ʽ

//������������Ǵ�С��
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



