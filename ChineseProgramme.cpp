#include<stdio.h>
#include<string.h>
#include<math.h>
char s1[2][5]={"����","С��"}; //���޿���
char s2[5];//����
char s3[3][5]={"����","С��","����"};
char s4[11][3]={"��","һ","��","��","��","��","��","��","��","��","ʮ"};
char s5[2][5]={"����","���"};
char s6[2][5]={"����","����"};
char s7[3][3]={"��","ǧ","��"};
char s8[3]="��";
char s9[3][3]={"\"","��","��"};

char a1[10],a2[10],a3[10],a4[10],a5[20];
char op[10],n[10];
char c1[20],c2[20],c3[20],c4[20],c5[20],c6[20],c7[20],c8[20],c9[20];
int sum=0,num,num2=0;
char type[10],name[10],same[10];

int change1(char n[]);
int change2(char n[]);
int change3(int sum);
int change4(int sum);
int change(int sum);
int cal(char op[],int num,int sum);
void judge1(char a[]);
void judge2(char b[],char c1[],char c2[],int sum,int num,char c[]);

int main()
{

    int a[20]={0};
    char b[10][10]={"\0"};
    int i=0,flag1=0,j=0,flag2=0;
    printf("������Ҫ��\n");
	while(scanf("%s",a1)!=EOF)
    {
        if(strcmp(a1,s1[0])==0)//�ж��Ƿ�Ϊ����
        {
            scanf("%s %s %s",b[i],same,n);
            a[i]=change2(n);
            i++;
        }
        else if(strcmp(a1,s5[0])==0) //����
        {
            scanf("%s",a5);
            for(j=0;j<i;j++)
            {
                if(strcmp(a5,b[j])==0)
                {
                    change4(a[j]);
                    printf("\n");
                    flag2=1;
                    break;
                }
            }
            if(flag2==0)
                judge1(a5);
        }   
        else if(strcmp(a1,s5[1])==0) //���
        {
            scanf("%s %s %s %s %s %s %s %s %s",c1,c2,c3,c4,c5,c6,c7,c8,c9);
            if(strcmp(c5,s5[0])==0 && strcmp(c8,s5[0])==0)
            {
                num=change2(c3);
                for(j=0;j<i;j++)
                    if(strcmp(c1,b[j])==0)
                    {
                        judge2(c2,c6,c9,a[j],num,b[j]);
                        break;
                    }
            }
            else
            {
                for(j=0;j<i;j++)
                    if(strcmp(c1,b[j])==0)
                    {   
                        num=change2(c3);
                        num2=change2(c7);
                        if(strcmp(c2,s3[0])==0)
                        {
                            if(a[j]>num)
                            {
                                for(int k=0;k<i;k++)
                                    if(strcmp(c5,b[k])==0)
                                        a[k]=cal(c6,num2,a[k]);
                            }
                            else
                                break;
                        }
                        else if(strcmp(c2,s3[1])==0)
                        {
                            if(a[j]<num)
                            {
                                for(int k=0;k<i;k++)
                                    if(strcmp(c5,b[k])==0)
                                        a[k]=cal(c6,num2,a[k]);
                            }
                            else
                                break;
                        }
                        else
                        {
                            if(a[j]==num)
                            {
                                for(int k=0;k<i;k++)
                                    if(strcmp(c5,b[k])==0)
                                        a[k]=cal(c6,num2,a[k]);
                            }
                            else
                                break;
                        }
                    }
            }
        }
        else  //�Ӽ�
        {   
            scanf("%s %s",a3,a4);
            for(j=0;j<i;j++)
                if(strcmp(a1,b[j])==0)
                {
                    num=change2(a4);
                    a[j]=cal(a3,num,a[j]);
                    break;
                }
        }
    }
    return 0;
}


//����ת����
int change1(char n[]) //n����
{   
    char m1[10]="\0",m2[10]="\0",m3[10]="\0";
    int num=0;
    int i=0,j=0;
    if(strlen(n)==2) //0-10
    {
        for(i=0;i<11;i++)
            if(strcmp(n,s4[i])==0)
                num=num+i;
    }
    else if(strlen(n)==4)
    {   
        strncpy(m1,n,2); //��һλ
        strncpy(m2,n+2,2);  //�ڶ�λ
        if(strcmp(m1,s4[10])==0) //��һλΪʮ
        {
            num=10+num;
            for(i=0;i<10;i++)
                if(strcmp(m2,s4[i])==0)
                    num=i+num;
        }
        else if(strcmp(m2,s4[10])==0) //�ڶ�λ��ʮ����ʮ����
        {
            for(i=0;i<10;i++)
                if(strcmp(m1,s4[i])==0)
                    num=num+i*10;
        }
        else if(strcmp(m2,s7[0])==0) //�ڶ�λ�ǰ�
        {
            for(i=0;i<10;i++)
                if(strcmp(m1,s4[i])==0)
                    num=num+i*100;
        }
        if(strcmp(m1,s4[1])==0) //��һλΪһ   һ�� һǧ һ��
        {
            if(strcmp(m2,s7[0])==0)
                num=100;
            else if(strcmp(m2,s7[1])==0)
                num=1000;
            else if(strcmp(m2,s7[2])==0)
                num=10000;
            else
                printf("������ֵ�����ݲ�����ת��");
        }
    }
    else if(strlen(n)==6) //21-99
    {
        strncpy(m1,n,2);
        strncpy(m3,n+4,2);
        for(i=0;i<10;i++)
        {
            if(strcmp(m1,s4[i])==0)
                num=num+i*10;
            if(strcmp(m3,s4[i])==0)
                num=num+i;
        }
    }
    else if(strlen(n)==8)  //100����
    {
        strncpy(m1,n,2);
        strncpy(m2,n+4,2);
        strncpy(m3,n+6,2);
        for(i=0;i<10;i++)
            if(strcmp(m1,s4[i])==0)//��λ
            {
                num=num+i*100;
                if(strcmp(m2,s4[0])==0) //ʮλΪ��
                {
                    for(j=0;j<10;j++)
                        if(strcmp(m3,s4[j])==0)
                            num=num+j;
                }
                else
                {
                    for(j=0;j<10;j++)
                        if(strcmp(m2,s4[j])==0)
                            num=num+j*10;
                }
            }
    }
    else if(strlen(n)==10)
    {
        strncpy(m1,n,2);
        strncpy(m2,n+4,2);
        strncpy(m3,n+8,2);
        for(i=0;i<10;i++)
        {
            if(strcmp(m1,s4[i])==0)
            {
                num=num+i*100;
                for(j=0;j<10;j++)
                {
                    if(strcmp(m2,s4[j])==0)
                        num=num+j*10;
                    if(strcmp(m3,s4[j])==0)
                            num=num+j;
                }
            }
        }
    }
    return num;
}
int change2(char n[]) //�жϸ���
{
    char m[10]="\0";
    char k[10]="\0";
    int num=0;
    strncpy(m,n,2);
    if(strcmp(m,s8)==0)
    {
        strncpy(k,n+2,strlen(n));
        num=num-change1(k);
    }
    else
        num=change1(n);
    return num;
}

//����ת����
int change3(int sum)
{
    int d[10],i=0,flag1=0,flag2=0;
    if(sum==0)
        printf("��");
    else if(sum==100)
        printf("һ��");
    else if(sum>100) //1000>sum>100
    {   
        if((sum/10%10)==0)
            flag1=1;
        if((sum%100)==0)
            flag2=1;
        while(sum!=0)
        {
            d[i]=sum%100;
            sum=sum/100;
            i++;
        }
        printf("%s��",s4[d[1]]);
        if(flag1==1)
            if(flag2==1);
            else
                printf("��");
        change(d[0]);
    }
    else
        change(sum);
    return 0;
}

int change(int sum)  //99����
{
    int d[10],i=0,count=0,j=0;
    while(sum!=0)
    {
        d[i]=sum%10;
        sum=sum/10;
        i++;count++;
    }
    for(i=count-1;i>=0;i--)
    {
        if(j==1)
        {
            printf("ʮ");
            j++;
        }
        if(j==0)
        {   
            if(d[i]==0);
			else if(d[i]==1)
				if(i==0)
					printf("%s",s4[d[i]]);
				else
					;
            else 
                printf("%s",s4[d[i]]);
            j++;
        }
        else if(j==2)
        {
            if(d[i]==0);
            else
                printf("%s",s4[d[i]]);
            j++;
        }
    }
    return 0;
}

int change4(int sum) //�жϸ���
{
    if(sum<0)
    {
        printf("��");
        sum=abs(sum);
        change3(sum);
    }
    else
        change3(sum);
    return 0;
}

//����
int cal(char op[],int num,int sum)
{
    if(strcmp(op,s6[0])!=0)
        sum-=num;
    else
        sum+=num;
    return sum;
}

//����

void judge1(char a[])//���� ���ַ�����
{
    char m[20]={"\0"};
    char n[20]={"\0"};
    if(strcmp(strncpy(n,a,1),s9[0])==0)
        strncpy(m,a+1,strlen(a)-2);
    else if(strcmp(strncpy(n,a,2),s9[1])==0)
        strncpy(m,a+2,strlen(a)-4);
    else
        strcpy(m,a);
    printf("%s\n",m);
}

//���
void judge2(char b[],char c1[],char c2[],int sum,int num,char c[])  
{
    if(strcmp(b,s3[0])==0) //����
    {
        if(sum>num)
            judge1(c1);
        else
            judge1(c2);
    }       
    else if(strcmp(b,s3[1])==0)  //С��
    {
        if(sum<num)
            judge1(c1);
        else
            judge1(c2);
    }
    else if(strcmp(b,s3[2])==0)  //����
    {
        if(sum=num)
            judge1(c1);
        else
            judge1(c2);
    }
}