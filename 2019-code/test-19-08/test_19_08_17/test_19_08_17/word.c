#define _CRT_SECURE_NO_WARNINGS 1


class A
{
	⋯
	A & operate = (const A &other); // 赋值函数 
};


A a, b, c;	// a, b, c 为A的对象 
⋯
a = b = c;	// 正常的链式赋值 



  public:


	  void  Push(int elem);


	  int
		  Pop(void);


	  int
		  GetCount(void)  const; // const

	  class Stack
	  {
	  public:
		  void Push(int elem);
		  int Pop(void);
		  int GetCount(void)  const; // const成员函数 
	  private:
		  int m_num;
		  int m_data[100];
	  };

	  int Stack::GetCount(void)  const
	  {
		  ++m_num; // 编译错误，企图修改数据成员m_num 
		  Pop();		  // 编译错误，企图调用非const函数 
		  return m_num;
	  }