#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


////һά����
//int main()
//{
//	//������ֻ������������±�ʾ���������飬�����������ʾ��Ԫ�ص�ַ��
//	//sizeof(������)��������������Ĵ�С����λ���ֽ�
//	//&��������ȡ��������������ĵ�ַ
//	
//	int a[] = { 1,2,3,4 };
//	printf("%d\n", sizeof(a));//4*4 = 16
//	printf("%d\n", sizeof(a + 0));//��Ԫ�ص�ַ����СΪ4/8
//	printf("%d\n", sizeof(*a));//����ĵ�һ��Ԫ�أ���СΪ4
//	printf("%d\n", sizeof(a + 1));//����ĵڶ���Ԫ�ص�ַ����СΪ4/8
//	printf("%d\n", sizeof(a[1]));//����ĵڶ���Ԫ�أ���СΪ4
//
//	printf("%d\n", sizeof(&a));//��������ĵ�ַ��4/8
//	printf("%d\n", sizeof(*&a));//���������С16
//	printf("%d\n", sizeof(&a + 1));//���������������һ����ַ��4/8
//	printf("%d\n", sizeof(&a[0]));//��Ԫ�صĵ�ַ 4/8
//	printf("%d\n", sizeof(&a[0] + 1));//�ڶ���Ԫ�صĵ�ַ 4/8
//	return 0;
//}


////�ַ�����
//int main()
//{
//	//char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
//	//printf("%d\n", sizeof(arr));//6����������Ĵ�С
//	//printf("%d\n", sizeof(arr + 0));//4/8����Ԫ�ص�ַ��С
//	//printf("%d\n", sizeof(*arr));//1����Ԫ�صĴ�С
//	//printf("%d\n", sizeof(arr[1]));//1����һ��Ԫ�صĴ�С
//	//printf("%d\n", sizeof(&arr));//4/8������Ԫ�صĵ�ַ�Ĵ�С
//	//printf("%d\n", sizeof(&arr + 1));//4/8����������Ԫ�ص���һ����ַ��С
//	//printf("%d\n", sizeof(&arr[0] + 1));//4/8���ڶ���Ԫ�صĵ�ַ��С
//
//	//printf("%d\n", strlen(arr));//���ֵ
//	//printf("%d\n", strlen(arr + 0));//���ֵ
//	//printf("%d\n", strlen(*arr));//err
//	//printf("%d\n", strlen(arr[1]));//err
//	//printf("%d\n", strlen(&arr));//���ֵ
//	//printf("%d\n", strlen(&arr + 1));//���ֵ - 6
//	//printf("%d\n", strlen(&arr[0] + 1));//���ֵ - 1
//
//	char arr[] = "abcdef";
//	//printf("%d\n", sizeof(arr));//7����������Ĵ�С,����'\0'
//	//printf("%d\n", sizeof(arr + 0));//4/8����Ԫ�ص�ַ��С
//	//printf("%d\n", sizeof(*arr));//1����Ԫ�صĴ�С
//	//printf("%d\n", sizeof(arr[1]));//1����һ��Ԫ�صĴ�С
//	//printf("%d\n", sizeof(&arr));//4/8������Ԫ�صĵ�ַ�Ĵ�С
//	//printf("%d\n", sizeof(&arr + 1));//4/8����������Ԫ�ص���һ����ַ��С
//	//printf("%d\n", sizeof(&arr[0] + 1));//4/8���ڶ���Ԫ�صĵ�ַ��С
//
//	//printf("%d\n", strlen(arr));//6
//	//printf("%d\n", strlen(arr + 0));//6
//	//printf("%d\n", strlen(*arr));//err
//	//printf("%d\n", strlen(arr[1]));//err
//	//printf("%d\n", strlen(&arr));//6
//	//printf("%d\n", strlen(&arr + 1));//���ֵ
//	//printf("%d\n", strlen(&arr[0] + 1));//5
//
//	char* p = "abcdef";
//	//printf("%d\n", sizeof(p));//4/8���ַ�����Ԫ�ص�ַ�Ĵ�С
//	//printf("%d\n", sizeof(p + 1));//4/8���ַ����ڶ���Ԫ�ص�ַ�Ĵ�С
//	//printf("%d\n", sizeof(*p));//1���ַ�����Ԫ�صĴ�С
//	//printf("%d\n", sizeof(p[0]));//1���ַ�����Ԫ�صĴ�С
//	//printf("%d\n", sizeof(&p));//4/8������ָ��Ĵ�С
//	//printf("%d\n", sizeof(&p + 1));//4/8������ָ��Ĵ�С
//	//printf("%d\n", sizeof(&p[0] + 1));//4/8���ַ����ڶ���Ԫ�ص�ַ�Ĵ�С
//
//	//printf("%d\n", strlen(p));//6
//	//printf("%d\n", strlen(p + 1));//5
//	//printf("%d\n", strlen(*p));//err
//	//printf("%d\n", strlen(p[0]));//err
//	//printf("%d\n", strlen(&p));//���ֵ
//	//printf("%d\n", strlen(&p + 1));//���ֵ�����ϸ����ֵû�й�ϵ����Ϊ���ǲ�֪�� &p����û��0
//	//printf("%d\n", strlen(&p[0] + 1));//5
//	return 0;
//}

////��ά����
//int main()
//{
//	int a[3][4] = { 0 };
//	printf("%d\n", sizeof(a));//48����������Ĵ�С
//	printf("%d\n", sizeof(a[0][0]));//4����һ�е�һ��Ԫ�صĴ�С
//	printf("%d\n", sizeof(a[0]));//16����һ������Ĵ�С
//	printf("%d\n", sizeof(a[0] + 1));//4����һ�еڶ���Ԫ�صĵ�ַ�Ĵ�С
//	printf("%d\n", sizeof(*(a[0] + 1)));//4����һ�еڶ���Ԫ�أ�int���Ĵ�С
//	printf("%d\n", sizeof(a + 1));//4���ڶ��еĵ�ַ�Ĵ�С
//	printf("%d\n", sizeof(*(a + 1)));//16���ڶ�������Ĵ�С
//	printf("%d\n", sizeof(&a[0] + 1));//4���ڶ��е�ַ�Ĵ�С
//	printf("%d\n", sizeof(*(&a[0] + 1)));//16���ڶ�����������Ĵ�С
//	printf("%d\n", sizeof(*a));//16����һ������Ĵ�С
//	//���ʽ���������ԣ�
//	//	ֵ���ԣ�
//	//	�������ԣ�
//	//sizeof(a[3])ֻ���ݣ����ڲ��������ж��ڴ��С���������㣨���ڲ���ֵ������ʵ�����ǲ������a[3]�ڲ��Ǽ���Ҳ�Ͳ����ڷ���Խ��
//	printf("%d\n", sizeof(a[3])); //16����ά��������֮��4��int�Ĵ�С
//}

//ָ�������
// ������1
//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int* ptr = (int*)(&a + 1);//��ʾ����a֮��ĵ�һ��λ�õĵ�ַ����������Ϊint*
//	printf("%d,%d", *(a + 1), *(ptr - 1));//2, 5
//	return 0;
//}

//������2
////���ڻ�û��ѧϰ�ṹ�壬�����֪�ṹ��Ĵ�СΪ20���ֽ�
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}*p;
////���� p ��ֵΪ0x100000�����±��ʽ��ֵ�ֱ��Ƕ��٣�
////��֪���ṹ��Test���͵ı�����СΪ20���ֽ�
//int main()
//{
//	printf("%p\n", p + 0x1);//0x100014
//	printf("%p\n", (unsigned long)p + 0x1);//0x100001
//	printf("%p\n", (unsigned int*)p + 0x1);//0x100004
//	return 0;
//}


//������3
//int main()
//{
//	int a[4] = { 1,2,3,4 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int)a + 1);//����Ԫ�ص�ַǿ��ת����int������int��ӣ�ʵ��ֵ��1��
//	//���ٴ�ת����int*֮����ʵ�൱�ڽ���Ԫ�ص�ַ����ƶ�һ���ֽ�
//
//	//����С�˴洢����int* ָ���ȡ4���ֽڵ�ԭ������֪��*ptr2�������ڴ����ݷֲ�Ϊ00 00 00 20��
//	//�ٸ���С�˴洢�������ݻ�ԭΪ0x20 00 00 00
//	printf("%x,%x", ptr1[-1], *ptr2);//0x4, 0x20000000
//	return 0;
//}


//������4
//int main()
//{
//	int a[3][2] = { (0, 1), (2,3), (4,5) };//{{1, 3},{5, 0},{0, 0}}
//	int* p;
//	p = a[0];
//	printf("%d\n", p[0]);//1
//	return 0;
//}


//������5
//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	//��ͼ��⣬���Եõ� &p[4][2] - &a[4][2] = -4
//	//���յ�ַ��ӡ�Ͱ������ʹ�ӡ������ǲ�ͬ�ģ�
//	//���յ�ַ��ֱ��ȡ���룬�������ͣ���õ�ԭ��
//	printf("%p, %d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);//0xFFFFFFFC, -4
//	return 0;
//}

//������6
//int main()
//{
//	int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* ptr1 = (int*)(&aa + 1);//ptr1��ʾ��������������һ��λ�õĵ�ַ
//	int* ptr2 = (int*)(*(aa + 1));//ptr2��ʾ��2�е�һ��Ԫ�صĵ�ַ (*(aa + 1)) == aa[1],�ڶ��е��������������ǵڶ�����Ԫ�ص�ַ
//	printf("%d, %d", *(ptr1 - 1), *(ptr2 - 1));//10, 5
//	return 0;
//}


//������7
//int main()
//{
//	char* a[] = { "work", "at", "alibaba" };
//	char** pa = a;//��һ��Ԫ�صĵ�ַ�����ַ���"work"�ĵ�ַ���ַ����������һ���ַ����͵ĵ�ַ�������Ƕ���ָ��
//	pa++;//pa++�൱��a++,��Ϊ�ڶ���Ԫ�صĵ�ַ
//	printf("%s\n", *pa);//at
//	return 0;
//}


////������8
//int main()
//{
//	char* c[] = { "ENTER","NEW", "POINT", "FIRST" };
//	char** cp[] = { c + 3,c + 2, c + 1, c };
//	char*** cpp = cp;
//	//cpp������cp����Ԫ�ص�ַ��Ҳ����c+3�ĵ�ַ��++cpp��ʾc+2�ĵ�ַ
//	printf("%s\n", **++cpp);//POINT
//	printf("%s\n", *-- * ++cpp + 3);//ER
//	printf("%s\n", *cpp[-2] + 3);//ST
//	printf("%s\n", cpp[-1][-1] + 1);//EW
//	return 0;
//}