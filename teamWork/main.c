//#include<stdio.h>
//void fct(unsigned int x, unsigned int y ,int *gys, int *gbs);
//int main (void)
//{
//	unsigned int x, y;
//	int *gys, *gbs;
//	printf("��������������(�м���һ���ո����,�س�������): ");
//	scanf("%u %u",&x,&y);
//	fct(x,y,&gys,&gbs);
//
//	printf("���Լ��Ϊ��%d  \n��С������Ϊ��%d  \n",gys,gbs);
//	return 0;
//}
//
//void fct(unsigned int x,unsigned int y, int *gys, int *gbs)
//{
//	int i,j,k;
//	if(x <= y){
//		j = y;
//		y = x;
//		x = j;
//	}
//	for(i = y; i > 0; i-- ){
//		if(x%i==0 && y%i==0){
//			*gys = i;
//			break;
//		}
//		k = (x/i)+1;
//	}
//	for(i = x;;k++){
//		if(i%x==0 && i%y==0){
//				*gbs = i;
//				break;
//			}
//	i = (*gys * k);
//	}
//}

//#include<stdio.h>
//int main (void)
//{
//	double k ,sum=0;
//	for(k=1;k<=100;k++)
//	{
//		sum += k;
//	}
//	for(k=1;k<=50;k++)
//	{
//		sum += (k*k);
//	}
//	for(k=1;k<=10;k++)
//	{
//		sum += (1/k);
//	}
//	printf("%f",sum);
//
//	return 0;
//}


//����20�������������Сƽ��ֵ
//#include<stdio.h>
//void fct(int *a,int *max,int *min,float *avrg)
//{
//	float sum=0;
//	*max = a[0];
//	*min = a[0];
//	for(int i=0; i<19; i++ )
//	{
//		if(a[i+1]>a[i]) *max = a[i+1];
//		if(a[i+1]<a[i]) *min = a[i+1];
//		if(i<18) sum += a[i];
//		else
//		{
//			sum += (a[i] + a[i+1]);
//			*avrg = sum/20 ;
//		}
//	}
//
//}
//
//int main (void)
//{
//	int max,min;
//	float  avrg;
//	int a[20]={0};
//	for(int i=0 ;i<20;i++)
//		scanf("%d ",&a[i]);
//	fct(a,&max,&min,&avrg);
//	printf("max=%d \n min=%d \n avrg=%.2f \n",max,min,avrg);
//
//
//	return 0;
//}


//����һ����ĸ��Сд��ĸת��Ϊ��д��ĸ�����
//#include<stdio.h>
//int main (void)
//{
//	int i =0;
//	char str[1000];
//	gets(str);
//	while(str[i] != '\0')
//	{
//		if(str[i] > 96) str[i] -= 32;
//		i++;
//	}
//	puts(str);
//
//	return 0;
//}



//#include<stdio.h>
//int main (void)
//{
//    unsigned int x,y,gys,gbs,i,j;
//    scanf("%u %u",&x,&y);
//    if(x>y){
//        j = x;
//        x = y;
//        y = j;
//    }
//    for(i = x;i>0;i--){
//        if(x%i == 0 && y%i == 0){
//            gys = i;
//            break;
//        }
//    }
//    for(i = y;;i++){
//        if(i%x == 0 && i%y == 0){
//            gbs = i;
//            break;
//        }
//    }
//    printf("���Լ��Ϊ��%u ��С������Ϊ��%u ",gys,gbs);
//
//    return 0;
//}

//#include<stdio.h>
//int main (void)
//{
//	unsigned int x,y,i,j;
//	scanf("%u %u",&x,&y);
//	if(x>y){
//		j = x;
//		x = y;
//		y = j;
//	}
//	for(i = y;;i++)
//		if(i%x == 0 && i%y == 0) break;
//        printf("%d",i);
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//int main (void)
//{
//	int x,i;
//	int a[6]={0};
//	srand(time(0));
//	for(i=0; i<10000; i++)
//	{
//		x = rand()%6 +1;
//		switch(x)
//		{
//			case 1: a[x-1] +=1;break;
//			case 2: a[x-1] +=1;break;
//			case 3: a[x-1] +=1;break;
//			case 4: a[x-1] +=1;break;
//			case 5: a[x-1] +=1;break;
//			case 6: a[x-1] +=1;break;
//		}
//	}
//	for(i=0; i<6; i++)
//	{
//		printf("%d��õ���%d��\n",i+1,a[i]);
//	}
//	return 0;
//}
//
//

//#include<stdio.h>
//
//int main(void)
//{
//	int i,j,k;
//	int a[5]={56,55,48,12,23};
//	for(i = 0;i<4;i++){
//		for(j=i+1;j<5;j++){
//			if(a[i]>a[j]){
//				k = a[i];
//				a[i] = a[j];
//				a[j] = k;
//		}
//		}
//
//	}
//	for (i=0; i<5; i++){
//		printf("%d ",a[i]);
//	}
//	return 0;
//}
//
//#include<stdio.h>
//int main (void)
//{
//	int a[4][4] = {{1,9,3,3},{5,8,6,7},{2,9,8,9},{1,9,1,1}};
//	int i,j,k,cnt=0;
//	for(i = 0; i < 4; i++)
//	{
//		for(j = 0; j < 4; j++)
//		{
//			cnt = 0;
//			for(k = 0; k < 4; k++)
//			{
//				if (a[i][j] >= a[i][k]) cnt++;
//			}
//			if(cnt == 4)
//			{
//				cnt =0;
//				for(k = 0; k < 4; k++)
//				{
//					if (a[i][j] <= a[k][j]) cnt++;
//				}
//			}
//			if(cnt == 4)
//			{
//				printf("��%d��,��%d��",i+1,j+1);
//			}
//		}
//	}
//
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
//int main (void)
//{
//	float x1,y1,x2,y2,dst;
//	scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
//	dst = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//	printf("%.3f",dst);
//
//	return 0;
//}

//#include<stdio.h>
//int main (void)
//{
//	struct _student
//	{
//	int num;
//	char name [20];
//	char gender[10] ;
//	float score;
//	}stu [9],stu_t;
//
//	int n,i,j;
//	printf("������Ҫ�����ѧ����Ϣ����: ");
//	scanf("%d",&n);
//	printf("��������ѧ��ѧ�š��������Ա�(male/female)��������");
//	for(i=0; i<n; i++)
//	{
//		scanf("%d %s %s %f",&stu[i].num,stu[i].name,stu[i].gender,&stu[i].score);
//	}
//	printf("\n\n");
//	for(i=0; i<n-1; i++)
//	{
//		for(j=i+1; j<n; j++)
//		{
//			if(stu[i].score <= stu[j].score)
//			{
//				stu_t = stu[i];
//				stu[i] = stu[j];
//				stu[j] = stu_t;
//			}
//		}
//	}
//	for(i=0; i<n; i++)
//	{
//		printf("%d %s %s %.1f\n",stu[i].num,stu[i].name,stu[i].gender,stu[i].score);
//	}
//
//
//
//	return 0;
//}
//
//



//#include<stdio.h>
//#include<string.h>
//int i=0;
//int conut(char str[100])
//{
//	int num=0;
//	while(str[i] != '\0')
//	{
//		if((str[i] >= 'a' && str[i] <= 'z') || (str[i]) >= 'A' && str[i] <= 'Z')
//			num ++;
//		i++;
//
//	}
//	return num;
//}
//
//
//int main(void)
//{
//	int num;
//	char str[100];
//	gets(str);
//	num = conut(str);
//	printf("%d\n",num);
//	for(i=i-1;i>=0;i--)
//	{
//		printf("%c",str[i]);
//	}
//
//
//	return 0;
//}


// ת��
//#include<stdio.h>
//
//void T (int r,int c,int a[r][c])
//{
//	int i,j,k,l,n;
//	r >= c ? (k=r) : (k=c);
//	r <= c ? (l=r) : (l=c);
//	for(i=0; i<k; i++)
//	{
//		for(j=i; j<l; j++)
//		{
//			n = a[i][j];
//			a[i][j] = a[j][i];
//			a[j][i] = n;
//		}
//	}
//
//
//}
//
//void input(int r, int c, int *a[r][c])
//{
//	for(int i=0; i<r; i++)
//	{
//		for(int j=0; j<c; j++)
//		{
//			scanf("%d",&a[i][j]);
//		}
//	}
//	printf("�������������ת�ò����\n");
//}
//
//void print(int r, int c, int a[r][c])
//{
//	for(int i=0; i<r; i++)
//	{
//		for(int j=0; j<c; j++)
//		{
//			printf("%d \t",a[i][j]);
//			if(j==c-1) printf("\n");
//		}
//	}
//}
//int main(void)
//{
//	int r,c,i,j,k;
//	printf("������Ҫת�õľ�����к��У�");
//	scanf("%d %d",&r,&c);
//	int a[r][c] ;
//	printf("������Ҫת�õľ���\n");
//
//	input(r,c,a);
//	T(r,c,a);
//	print(r,c,a);
//	return 0;
//}
//

//#include<stdio.h>
//
//void a(char *str)
//{
//	int i=0;
//	while(str[i] != '\0')
//	{
//		if(str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
//		printf("%c",str[i]);
//		i++;
//	}
//}
//void A(char *str)
//{
//	int i=0;
//	while(str[i] != '\0')
//	{
//		if(str[i] >= 'a' && str[i] <= 'z') str[i] -= 32;
//		printf("%c",str[i]);
//		i++;
//	}
//}
//int main(void)
//{
//	int flag = 0;
//	char *str ;
//	printf("�����ַ�����");
//	gets(str);
//	printf("ѡ��ģʽ��0-���ַ����д�д��ĸת��ΪСд��ĸ���  1-���ַ�����Сд��ĸת��Ϊ��д��ĸ�����\n");
//	scanf("%d",&flag);
//	if(flag) A(str);
//	else a(str);
//
//	return 0;
//}
//
//
//

//#include <stdio.h>
//void hanoi(int n, char A, char B, char C)
//{
//	if(n == 1)
//	{
//		printf("����%d���%c���ƶ���%c��\n", n, A, C);
//	}
//	else
//	{
//		hanoi(n-1, A, C, B);
//		printf("����%d���%c���ƶ���%c��\n", n, A, C);
//		hanoi(n-1, B, A, C);
//	}
//}
//int main()
//{
//	int n;
//	printf("�����뺺ŵ��������");
//	scanf("%d", &n);
//	hanoi(n, 'A', 'B', 'C');
//	return 0;
//
//}


