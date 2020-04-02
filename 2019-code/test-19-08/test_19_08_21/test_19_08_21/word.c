#define _CRT_SECURE_NO_WARNINGS 1

class A
{
public:
	void  Func1(void);
	void  Func2(void);
};

class B : public A
{
public:
	void  Func3(void);
	void  Func4(void);
};

main()
{
	B b;
	b.Func1();	// B从A继承了函数Func1 
	b.Func2();	// B从A继承了函数Func2 
	b.Func3();
	b.Func4();
}


			class Human
			{
				…
			};

			class Man : public Human
			{
				…
			};

			class Boy : public Man
			{
				…
			};



			class Bird
			{
			public:

				virtual void Fly(void);
				…
			};

			class Ostrich : public Bird
			{
				…
			};

			// 正确的设计，虽然代码冗长。  
			class Head
			{
			public:
				void Look(void) { m_eye.Look(); }
				void Smell(void) { m_nose.Smell(); }
				void Eat(void){ m_mouth.Eat(); }
				void Listen(void) { m_ear.Listen(); }
			private:
				Eye m_eye;
				Nose m_nose;
				Mouth m_mouth;
				Ear	m_ear;
			};
			class Eye
			{
			public:
				void  Look(void);
			};
			class Nose
			{
			public:
				void  Smell(void);
			};
			class Mouth
			{
			public:
				void  Eat(void);
			};
			class Ear
			{
			public:
				void  Listen(void);
			};
			// 功能正确并且代码简洁，但是设计方法不对。 
			class Head : public Eye, public Nose, public Mouth, public Ear
			{
			};
			}
			}