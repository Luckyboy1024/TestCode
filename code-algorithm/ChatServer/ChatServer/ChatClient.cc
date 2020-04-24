#define _CRT_SECURE_NO_WARNINGS 1

int main()
{
	int Login(id_type id_, std::string passwd_, struct sockaddr_in &client_, socklen_t &len_)
	{
		int status;
		std::unordered_map<id_type, User>::iterator it;
		LockManager();
		it = register_user.find(id_);
		if (it != register_user.end()){
			if ((it->second).passwd == passwd_){
				LOG(INFO, "user Login success, add to Logined user!");
				(it->second).status = USER_LOGINED;
				//(it->second).status = USER_ONLINE;
				//online_user.push_back(it->second);
				logined_count++;
				status = 0;
			}
			else{
				status = -1;
			}
		}
		else{
			status = -1;
		}
		UnLockManager();
		return status;
	}
	int Logout(id_type id_)
	{
		//自己完成
	}
	id_type Register(std::string nick_name_, std::string school_, std::string passwd_)
	{
		id_type id_;
		LockManager();
		GetId(id_);
		User u(nick_name_, school_, id_, passwd_);
		register_user.insert(std::make_pair(id_, u));
		UnLockManager();
		return id_;
	}
}
