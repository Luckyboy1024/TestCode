#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//���������ָ������������ж��ٸ���������
#include <stdio.h>
#include <math.h>
int main()
{
	long c, d, i, j, f, t, f1, i1, max;
	printf("������ c,d (2<c<d) :>_ ");
	scanf("%ld%ld", &c, &d);
	f = c;
	max = 0;
	if (0 != c % 2)
	{
		for (t = 0, j = 3; j <= sqrt(c); j += 2)		//�����б�����c�Ƿ�Ϊ����
		{
			if (0 == c%j)
			{
				t = 1;
				break;
			}
		}
	}
	if (0 == c % 2 || 1 == t)
		f = c - 1;				//��c-1Ϊ��������ֵ��f
	if (0 == c % 2)
		c++;
	for (i = c; i <= d; i += 2)
	{
		t = 0;
		for (j = 3; j <= sqrt(i); j += 2)		//�����б�����
		{
			if (0 == i%j)
			{
				t = 1;
				break;
			}
		}
		if (d - i < 2 && t == 1)
		{
			t = 0;
			i = d + 1;			//��d+1Ϊ��������ֵ�� i
		}
		if (0 == t)
		{
			if (i - f >max)
			{
				max = i - f;
				f1 = f + 1;
				i1 = i - 1;
			}
			f = i;			//f Ϊ i ��ǰһ������
		}
	}
	printf("������������ĸ���Ϊ :>_ %ld\n", max - 1);
	printf("������������Ϊ :>_ [%ld,%ld]\n", f1, i1);
	return 0;
}

#endif


#if 0
//ɸ����ָ������������ж��ٸ���������
#include <stdio.h>
#include <math.h>

int main()
{
	long c, d, cs, ds,ct, dt, f, g, i, j, k, m, max, a[11000];
	int e, u, x, y;
	printf("������ c,d (2<c<d) :>_ ");
	scanf("%ld%ld", &c, &d);
	if (d - c <= 20000)
	{
		cs = c;
		ds = d;
		x = 0;
	}
	else
	{
		x = (d - c) / 20000;
		cs = c;
		ds = d - 20000 * x;
	}
	f = cs;
	max = 0;
	for (y = 1; y <= x + 1; y++)		//�� [c,d] ��x+1��������ɸѡ����
	{
		if (0 == cs % 2)
			cs++;
		for (i = 0; i <= 10999; i++)
			a[i] = 0;
		e = (ds - cs) / 2;
		i = 1;
		while (i <= sqrt(ds))
		{
			i = i + 2;
			g = 2 * sqrt(cs / (2 * i)) + 1;
			if (g * i > ds)
				continue;
			if (1 == g)
				g = 3;
			j = i *g;
			while (j <= ds)
			{
				if (j >= cs)
					a[(j - cs) / 2] = -1;		//��ֵɸȥ���-1
				j = j + 2 * i;
			}
		}
		for (u = 1, k = 0; k <= e; k++)
		{
			if (a[k] != -1)
			{
				m = cs + 2 * k;		//m��ɸѡ��������
				if (m - f > max)		//Ѱ�������������������ֵ
				{
					max = m - f;
					ct = f + 1;
					dt = cs + 2 * k - 1;
				}
				f = m;
			}
		}
		cs = ds + 1;
		ds = ds + 20000;		//cs��ds���������̽��
	}
	printf("������������ĸ���Ϊ :>_ %ld\n", max - 1);
	printf("������������Ϊ :>_ [%ld,%ld]\n", ct, dt);
	return 0;
}

#endif


#if 0
//����С������ n ������
#include <stdio.h>
#include <math.h>

int main()
{
	long c, d, f, m, j;
	int t, n;
	printf("����С�� n ������������\n");
	printf("������ n (n<200) :>_ ");
	scanf("%d", &n);
	c = 3;
	d = c + 10000;
	f = 3;
	while (1)
	{
		for (m = c; m <= d; m += 2)
		{
			for (t = 0, j = 3; j <= sqrt(m); j += 2)
			{
				if (0 == m % j)		//ʵʩ����
				{
					t = 1;
					break;
				}
			}
			if (t == 0 && m - f > n)		//���������������
			{
				printf("��С�� %d ��������������Ϊ :>_ ", n);
				printf("[%ld,%ld]��\n", f + 1, f + n);
				return;
			}
			if (0 == t)
				f = m;				//ÿ���һ������ m ��ֵ�� f
		}
		if (m > d)
		{
			c = d + 2;
			d = c + 10000;			//ÿһ�����̺�ı�c��dת��һ��
		}
	}
	return 0;
}

#endif

#if 0
//̽��� n ����������
#include <stdio.h>
#include <math.h>
int main()
{
	long a, b, k;
	int m, n, s, x;
	printf("̽��� n ���������ͣ������� n :>_ ");
	scanf("%d", &n);
	a = 1;
	m = 0;
	while (1)
	{
		a++;
		s = 0;			//���� a ����
		for (b = a * 100 - 99; b <= a * 100 - 1; b += 2)	//ö��a�����������b
		{
			x = 0;
			for (k = 3; k <= sqrt(b); k += 2)
			{
				if (0 == b%k)
				{
					x = 1;
					break;
				}
			}
			if (0 == x) break;	//����ѭ�����������͵�̽��
			s = s + x;			//���bΪ����ʱ��x=1,s��1
		}
		if (50 == s) m++;
		if (n == m) break;
	}
	printf("�� %d ����������Ϊ %ld ���ͣ�\n", n, a);
	printf("�����͵���� %ld -- %ld ȫΪ����\n", a * 100 - 99, a * 100);
	return 0;
}

#endif

#if 0
//�������ֽ�˻���ʽ
#include <stdio.h>
#include <math.h>
int main()
{
	long int b, i, k, m, n;
	printf("������ m,n :>_ ");
	scanf("%ld%ld", &m, &n);
	for (i = m; i <= n; i++)		// i Ϊ���ֽ������
	{
		printf("  %ld = ", i);
		b = i;
		k = 2;					//kΪ��������
		while (k <= sqrt(i))
		{
			if (0 == b%k)
			{
				b = b / k;
				if (b > 1)
				{
					printf("%ld * ", k);
					continue;		//kΪ����������������
				}
				if (1 == b)
				{
					printf("ld\n", k);
				}
			}
			k++;
		}
		if (b > 1 && b < i)
		{
			printf("%ld\n", b);		//�б�������� i ƽ����������
		}
		if (b == i)				//b=i����ʾi��������
		{
			printf("(����!)\n");
		}
	}
	return 0;
}
#endif

#if 0
// ˫�����������ֽ�ָ����ʽ
#include <stdio.h>
#include <math.h>

int main()
{
	double b, i, k, m, n;
	int j;
	printf("������ m,n :>_ ");
	scanf("%lf%lf", &m, &n);
	for (i = m; i <= n; i++)
	{
		printf(" %.0f = ", i);
		b = i;
		k = 2;
		j = 0;
		while (k <= pow(i, 0.5))	//kΪ��������
		{
			if (0 == fmod(b, k))	//kΪ����������������
			{
				b = floor(b / k);
				j++;
				continue;
			}
			if (j >= 1)
			{
				printf("%.0f", k);
				if (j > 1)
				{
					printf(" %d", j);		//��ӡָ����ʽ
				}
				if (b > 1)
				{
					printf(" * ");
				}
			}
			k++;
			j = 0;
		}
		if (b > 1 && b < i)
		{
			printf("%.0f", b);		//�������iƽ����������
		}
		if (i == b)
		{
			printf("(����!)");		//b=i����ʾi��������
		}
		printf("\n");
	}
	return 0;
}

#endif