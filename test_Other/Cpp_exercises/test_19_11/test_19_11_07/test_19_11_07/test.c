#define _CRT_SECURE_NO_WARNINGS 1


#if 0
// ��ָ�������ϵ�����������
#include <stdio.h>
#include <math.h>

int main()
{
	long int c, d, i, j, f = 0;
	int t, n = 0;
	printf("������[c,d]�ϵ�����������\n");
	printf("������ c��d (c>2) :>_ ");
	scanf("%ld%ld", &c, &d);
	if (0 == c % 2)
	{
		c++;			//ȷ�����cΪ����
	}
	for (i = c; i <= d; i += 2)
	{
		for (t = 0, j = 3; j <= sqrt(i); j += 2)		//�����б�����
		{
			if (0 == i%j)
			{
				t = 1;
				break;
			}
		}
		if (0 == t)		//tΪ0����iΪ����
		{
			if (2 == i - f)
			{
				printf(" (%ld,%ld)", f, i);
				n++;
			}
			f = i;			//���� i �洢�� f��Ϊ��һ�б���׼��
		}
	}
	printf("\n[%ld,%ld]�Ϲ� %d ������������\n", c, d, n);
	return 0;
}


#endif


#if 0

#include <stdio.h>
#include <math.h>

int main()
{
	long int c, d, i, j;
	int t, m, n = 0;
	static long a[5000];
	printf("������ c,d (c>2) :>_ ");
	scanf("%ld%ld", &c, &d);
	if (0 == c % 2)
	{
		c++;		//ȷ����� c Ϊ����
	}
	for (m = 0, i = c; i <= d; i += 2)
	{
		for (t = 0, j = 3; j <= sqrt(i); j += 2)	//���̷��б�����
		{
			if (0 == i%j)
			{
				t = 1;
				break;
			}
		}
		if (0 == t)
		{
			a[++m] = i;		// i Ϊ������ a ���鸳ֵ
		}
	}
	for (i = 1; i < m; i++)
	{
		if (a[i + 1] - a[i] == 2)		//�����������Ϊ2�����
		{
			printf(" (%ld,%ld)", a[i], a[i + 1]);
			n++;
		}
	}
	printf("\n[%ld,%ld]�Ϲ� %d ������������\n", c, d, n);
	return 0;
}

#endif


#if 0

//���� n λ����������
#include <stdio.h>
#include <math.h>
int main()
{
	long f, i, j, k, m, r, s, t, p[50000];
	int c, d, g, n;
	printf("������λ�� n (n>1) :>_ ");
	scanf("%d", &n);
	k = s = 0;
	t = 1;
	for (j = 1; j <= n - 1; j++)
	{
		t = t * 10;			//������С�� n λ���� t
	}
	for (m = t + 1; m <= (10 * t - 1); m = m + 2)	//ö�����е�nλ����
	{
		if (0 == m % 5) continue;
		for (g = 0, i = 2; i <= sqrt(m); i++)
		{
			if (0 == m%i)
			{
				g = 1;
				break;
			}
		}
		if (0 == g)
		{
			k++;
			p[k] = m;
		}
	}
	for (j = 1; j <= k - 1; j++)
	{
		f = p[j];
		c = f % 10;
		d = f / t;
		if (c < d) continue;		//�������������ȱ���С�Ĳ�����
		for (r = 0, i = 1; i <= n; i++)
		{
			c = f % 10;
			r = r * 10 + c;
			f = f / 10;		//rΪd��������
		}
		if (r < p[j])
		{
			continue;		//�������������ȱ���С�Ĳ�����
		}
		for (i = j + 1; i <= k; i++)
		{
			if (r == p[i])		//������r�Ǳȱ��������������
			{
				s++;
				printf("(%ld):%ld,%ld ", s, p[j], r);
				if (0 == s % 5)
					printf("\n");
			}
		}
	}
	printf("\n %d λ���������Թ��� %d �ԡ�\n", n, s);
	return 0;
}



#endif


#if 1

#include 

#endif
