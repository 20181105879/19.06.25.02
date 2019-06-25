#include <iostream>
#include <algorithm>
#include <cstring>
#define Student_number 5
#define Teacher_number 7
using namespace std;
long long i,j;
//д�ı��� 
char headline[10000]={"ѧ��-------����---�Ա�-ѧԺ--�༶----����----2-----3------4------5------6------7-----����\n"};
//��Ļ��ʾ�ı��� 
char output_headline[1000]={"ѧ��------����-�Ա�-ѧԺ----�༶---ƽ����--���� "};
//���ı��� 
char show_headline1[10000]={"ѧ��-------����---�Ա�-ѧԺ--�༶----����----2-----3------4------5------6------7-----����---ƽ����\n"};
//{"ѧ��-------����------�Ա�--ѧԺ---�༶-------����2--3--4--5--6--7-����\n"};
char headline1[10000];
//ѧ���ṹ�� ��д�� 
struct Students{
	char id[15];
	char name[10];
	char sex[15];
	char college[15];
	char st_class[15];
	long long phone;
	double sore[Teacher_number];
	double avg;
	double sum;
	
}student[Student_number];

//ѧ���ṹ�壨���� 
struct Students1{
	char id[15];
	char name[10];
	char sex[15];
	char college[15];
	char st_class[15];
	double sore[Teacher_number];
	double avg;
	double sum;
	long long phone;
}student1[Student_number];



//���ṹ������ 
bool cmp( Students1  &p1,Students1 &p2)
{
	if(p1.avg>p2.avg)
	{
		return 1;
	}
	else if(p1.avg==p2.avg)
	{
		if(p1.name-p2.name>0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
		
	} 
	else
	{
		return 0;
	}
}


int main()
{

	
	
	
	
	
	FILE *p=NULL;
	p=fopen("student.txt","w");
		if(!p)
		{
			printf("open fail\n");
			return 0;
		}
//�Լ���дѧ������ 
	Students student[Student_number]=
	{
	

		
		
		
		{"2018110","�񽡾�","��","��е", "��е����",1008611},
		{"2018111","����", "Ů" ,"ҽѧԺ","����ѧ"  ,1008612},
		{"2018112","����", "��" ,"�����","�ɻ�ѧ"  ,1008613},
		{"2018113","��ţ", "����", "��֪��","��°�" ,1008614},
		{"2018114","������","��","�ƿ�Ժ","�������" ,1008615}
			
		  
	};


	
	
	fprintf(p,"%s",headline);
		for( i=0;i<Student_number;i++)
		{
			fprintf(p,"%s  ",student[i].id);
			fprintf(p,"%s  ",student[i].name);
			fprintf(p,"%s    ",student[i].sex);
			fprintf(p,"%s  ",student[i].college);
			fprintf(p,"%s  ",student[i].st_class);
			for(j=0;j<Teacher_number;j++)
			{
			   fprintf(p,"%.2f  ",student[i].sore[j]);
			}
			fprintf(p,"%lld",student[i].phone);
			fprintf(p,"\n");
		}
	fclose(p);
	
	
//��ѧ������	
	FILE *fp=NULL;
	fp=fopen("student.txt","r");
		if(!fp)
		{
			printf("open fail\n");
			return 0;
		}
	fscanf(p,"%s",headline1);

		for(i=0;i<Student_number;i++)
		{
			    
				fscanf(p,"%s",student1[i].id);
		
				fscanf(p,"%s",student1[i].name);
		
				fscanf(p,"%s",student1[i].sex);
		
				fscanf(p,"%s",student1[i].college);
			
				fscanf(p,"%s",student1[i].st_class);
		
				for(int j=0;j<Teacher_number;j++)
				{
				   fscanf(p,"%lf",&student1[i].sore[j]);
				}
	
			 
			
		}
	fclose(p);
	
	sort(student1,student1+Student_number,cmp);


		
		

	
	
	
printf("%s\n",output_headline);
	for(i=0;i<Student_number;i++)
	{
		printf("rank %d:\n",(i+1));
		
		printf("%s  %s  %s  ",student1[i].id,student1[i].name,student1[i].sex);
		
		printf("%s  %s  ",student1[i].college,student1[i].st_class);
		printf("%.2f  %lld\n",student1[i].avg,student1[i].phone);
		printf("\n");
	}

		FILE *pp=NULL;
		pp=fopen("show.txt","w");
		if(!pp)
		{
			printf("open false1\n");
			return 0;
		}
      fprintf(pp,"%s\n",show_headline1);
      for(i=0;i<Student_number;i++)
      {
      	 	fprintf(pp,"%s  ",student1[i].id);
			fprintf(pp,"%s  ",student1[i].name);
			fprintf(pp,"%s    ",student1[i].sex);
			fprintf(pp,"%s  ",student1[i].college);
			fprintf(pp,"%s  ",student1[i].st_class);
			for(int j=0;j<Teacher_number;j++)
			{
			   fprintf(pp,"%.2f  ",student1[i].sore[j]);
			}
			fprintf(pp,"%lld   ",student1[i].phone);
			fprintf(pp,"%.2f",student1[i].avg);
			fprintf(pp,"\n");

	  }
	  fclose(pp);
	
     return 0;
}
