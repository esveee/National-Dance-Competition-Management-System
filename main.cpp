#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

class dancecomp
{
int id;
char name[20];
int nom;
char dstyle[20];
char add[40];
char city[20];
char hname[20];
int hphno;
char hemail[20];

public:
	void getd()
	{
		cout<<"\nEnter Group ID ";
		cin>>id;
		cout<<"\nEnter Group name ";
		gets(name);
		cout<<"\nEnter Dance Style ";
		gets(dstyle);
		cout<<"\nEnter Number of Members in Group ";
		cin>>nom;
		cout<<"\nEnter the Address of Group ";
		gets(add);
		cout<<"\nEnter City name ";
		gets(city);
		cout<<"\nEnter Details of the GROUP HEAD";
		cout<<"\nName: ";
		gets(hname);
		cout<<"\nPhone No.: +91-";
		cin>>hphno;
		cout<<"\nE-Mail: ";
		gets(hemail);
	}

	void showd()
	{
		cout<<"\nGroup ID is ";
		cout<<id;
		cout<<"\nGroup name is ";
		puts(name);
		cout<<"Dance Style is ";
		puts(dstyle);
		cout<<"Number of Members in Group are ";
		cout<<nom;
		cout<<"\nAddress of Group is ";
		puts(add);
		cout<<"City name is ";
		puts(city);
		cout<<"\nDetails of the GROUP HEAD are:-";
		cout<<"\nName: ";
		puts(hname);
		cout<<"Phone No.: +91-";
		cout<<hphno;
		cout<<"\nE-Mail: ";
		cout<<hemail;
	}

	int retid()
	{
		return id;
	}

	int retnom()
	{
		return nom;
	}

	char * retdstyle()
	{
		return dstyle;
	}

	char * retname()
	{
		return name;
	}

	char * retname1()
	{
		return hname;
	}

char * retcity()
	{
		return city;
	}

};

fstream f1,f2;
dancecomp d1,d2;

void create()
{
	char ans;
	f1.open("first.dat",ios::out|ios::binary);
	do
	{
		cout<<"\nEnter Contents\n";
		d1.getd();
		f1.write((char*)&d1,sizeof(d1));
		cout<<"\nWant to add more entries? ";
		cin>>ans;
	}while(ans=='y');

	f1.close();
}

void input()
{
	f1.open("first.dat",ios::in|ios::binary);
	while(f1.read((char*)&d1,sizeof(d1)))
	{
		cout<<"\nThe details are:\n";
		d1.showd();
	}
	f1.close();
}

void count1()
{
	int cnt=0;
	f1.open("first.dat",ios::in|ios::binary);
	while(f1.read((char*)&d1,sizeof(d1)))
	{
		cnt++;
	}
	f1.close();
	cout<<"\nThe number of entries are: "<<cnt;
}

void count2()
{
	int cnt=0, nom;
	cout<<"\nEnter the number of members ";
	cin>>nom;
	f1.open("first.dat",ios::in|ios::binary);
	while(f1.read((char*)&d1,sizeof(d1)))
	{
		if(d1.retnom()>nom)
			cnt++;
	}
	f1.close();
	cout<<"\nThe number of entries having number of members greater than "<<nom<<" are: "<<cnt;
}

void count3()
{
	int cnt=0; char style[20];
	cout<<"\nEnter the Dance Style ";
	gets(style);
	f1.open("first.dat",ios::in|ios::binary);
	while(f1.read((char*)&d1,sizeof(d1)))
	{
		if(strcmpi(d1.retdstyle(),style)==0)
			cnt++;
	}
	f1.close();
	cout<<"\nThe number of entries having Dance Style as "<<style<<" are: "<<cnt;
}

void count4()
{
	int cnt=0; char city[20];
	cout<<"\nEnter the City name ";
	gets(city);
	f1.open("first.dat",ios::in|ios::binary);
	while(f1.read((char*)&d1,sizeof(d1)))
	{
		if(strcmpi(d1.retcity(),city)==0)
			cnt++;
	}
	f1.close();
	cout<<"\nThe number of entries having City name as "<<city<<" are: "<<cnt;
}

void searchid()
{
	int id, f=0;
	cout<<"\nEnter the Group ID to be searched ";
	cin>>id;
	f1.open("first.dat",ios::in|ios::binary);
	while(f1.read((char*)&d1,sizeof(d1)))
	{
		if(id==d1.retid())
		{
			f=1;
			break;
		}
	}
	f1.close();

	if(f==1)
	{
		cout<<"\nThe details are:\n";
		d1.showd();
	}
	else
		cout<<"\nNO MATCH FOUND";
}

void searchcity()
{
	int f=0; char city[20];
	cout<<"\nEnter the City name to be searched ";
	gets(city);
	f1.open("first.dat",ios::in|ios::binary);
	while(f1.read((char*)&d1,sizeof(d1)))
	{
		if(strcmpi(d1.retcity(),city)==0)
		{
			f=1;
			break;
		}
	}
	f1.close();

	if(f==1)
	{
		cout<<"\nThe details are:\n";
		d1.showd();
	}
	else
		cout<<"\nNO MATCH FOUND";
}

void searchhname()
{
	char name[20]; int f=0;
	cout<<"\nEnter the name of the Group Head ";
	gets(name);
	f1.open("first.dat",ios::in|ios::binary);
	while(f1.read((char*)&d1,sizeof(d1)))
	{
		if(strcmpi(d1.retname1(),name)==0)
		{
			f=1;
			d1.showd();
		}
	}
	f1.close();

	if(f==0)
		cout<<"\nNO MATCH FOUND";
}

void editany()
{
	int rec=1,n;
	f1.open("first.dat",ios::in|ios::binary);
	f2.open("second.dat",ios::out|ios::binary);

	cout<<"\nEnter entry number to be edited ";
	cin>>n;
	cout<<"\nEnter new details";
	d2.getd();

	while(f1.read((char*)&d1,sizeof(d1)))
	{
		if(rec!=n)
			f2.write((char*)&d1,sizeof(d1));
		else
			f2.write((char*)&d2,sizeof(d2));
		rec++;
	}
	f1.close();
	f2.close();
	remove("first.dat");
	rename("second.dat","first.dat");
}

void editname()
{
	char nm[20];
	cout<<"\nEnter Group Name ";
	gets(nm);
	f1.open("first.dat",ios::in|ios::binary);
	f2.open("second.dat",ios::out|ios::binary);

	cout<<"\nEnter new details:";
	d2.getd();

	while(f1.read((char*)&d1,sizeof(d1)))
	{
		if(strcmpi(d1.retname(),nm)==0)
			f2.write((char*)&d2,sizeof(d2));
		else
			f2.write((char*)&d1,sizeof(d2));
	}
	f1.close();
	f2.close();
	remove("first.dat");
	rename("second.dat","first.dat");
}

void deleteany()
{
	int rec=1,n;
	cout<<"\nEnter the position where entry has to be deleted ";
	cin>>n;
	f1.open("first.dat",ios::in|ios::binary);
	f2.open("second.dat",ios::out|ios::binary);

	while(f1.read((char*)&d1,sizeof(d1)))
	{
		if(rec!=n)
			f2.write((char*)&d1,sizeof(d1));
		rec++;
	}
	f1.close();
	f2.close();
	remove("first.dat");
	rename("second.dat","first.dat");
}

void insertlast()
{
	f1.open("first.dat",ios::in|ios::binary);
	f2.open("second.dat",ios::out|ios::binary);
	cout<<"\nEnter details to be inserted";
	d2.getd();

	while(f1.read((char*)&d1,sizeof(d1)))
		f2.write((char*)&d1,sizeof(d1));
	f2.write((char*)&d2,sizeof(d2));

	f1.close();
	f2.close();
	remove("first.dat");
	rename("second.dat","first.dat");
}

void main()
{
clrscr();
int ch; char ans='y';

do
{
cout<<"\nENTER YOUR CHOICE:";
cout<<"\n1: Create a file";
cout<<"\n2: Read the file";
cout<<"\n3: Count the number of entries";
cout<<"\n4: Count the entries with no. of members more than user given no. of members";
cout<<"\n5: Count the entries with a given Dance Style";
cout<<"\n6: Count the entries with a given City name";
cout<<"\n7: Search on the basis of Group ID";
cout<<"\n8: Search on the basis of City name";
cout<<"\n9: Search on the basis of Group Head name";
cout<<"\n10: Edit nth entry";
cout<<"\n11: Edit on basis of Group name";
cout<<"\n12: Delete nth entry";
cout<<"\n13: Insert an new entry"<<endl;
cin>>ch;

switch(ch)
{
	case 1: create();
		break;

	case 2: input();
		break;

	case 3: count1();
		break;

	case 4: count2();
		break;

	case 5: count3();
		break;

	case 6: count 4();
		break;

	case 7: searchid();
		break;

	case 8: searchcity();
		break;

	case 9: searchhname();
		break;

	case 10: editany();
		break;

	case 11: editname();
		break;

	case 12: deleteany();
		 break;

	case 13: insertlast();
		 break;

	default: cout<<"\nWRONG CHOICE";

}

cout<<endl;
cout<<"\nDo You Want To Continue? y/n ";
cin>>ans;
}while(ans=='y');

getch();
}
