#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
class person
{		string name,dept,add;
	public:
		person()
		{	name="EMPTY";
			dept="EMPTY";
			add="EMPTY";
		}
		void setname(string name)
		{	this->name=name;
		}
		string getname()
		{	return name;
		}
		void setdept(string dept)
		{	this->dept=dept;
		}
		string getdept()
		{	return dept;
		}
		void setadd(string add)
		{	this->add=add;
		}
		string getadd()
		{	return add;
		}
		virtual void get_class() = 0;
		virtual void set_class() = 0;		
};
class employ : public person
{		string desig,empid;
		int leaves;
	public:
		employ()
		{	desig="EMPTY";
			empid="EMPTY";
			leaves=0;
		}
		void setdesig(string desig)
		{	this->desig=desig;
		}
		string getdesig()
		{	return desig;
		}
		void setempid(string empid)
		{	this->empid=empid;
		}
		string getempid()
		{	return empid;
		}
		void setleaves(int leaves)
		{	this->leaves=leaves;
		}
		int getleaves()
		{	return leaves;
		}
};
class student : public person
{		int year;
		string enroll,fac_no;
		float CPI;
	public:
		student()
		{	year=0000;
			enroll="EMPTY";
			fac_no="EMPTY";
			CPI=00.00;
		}
		void setenroll(string enroll)
		{	this->enroll=enroll;
		}
		string getenroll()
		{	return enroll;
		}
		void setfac_no(string fac_no)
		{	this->fac_no=fac_no;
		}
		string getfac_no()
		{	return fac_no;
		}
		void setyear(int year)
		{	this->year=year;
		}
		int getyear()
		{	return year;
		}
		void setCPI(float CPI)
		{	this->CPI=CPI;
		}
		float getCPI()
		{	return CPI;
		}	
};
class alumni : public person
{		int pass_year;
		string enroll,curr_emp;
	public:
		alumni()
		{	pass_year=0;
			enroll="EMPTY";
			curr_emp="EMPTY";
		}
		void setpass_year(int pass_year)
		{	this->pass_year=pass_year;
		}
		int getpass_year()
		{	return pass_year;
		}
		void setenroll(string enroll)
		{	this->enroll=enroll;
		}
		string getenroll()
		{	return enroll;
		}
		void setcurr_emp(string curr_emp)
		{	this->curr_emp=curr_emp;
		}
		string getcurr_emp()
		{	return curr_emp;
		}
		void get_class();
		void set_class();
};
class faculty : public employ
{		string spec;
	public:
		faculty()
		{	spec="EMPTY";
		}
		void setspec(string spec)
		{	this->spec=spec;
		}
		string getspec()
		{	return spec;
		}
		void get_class();
		void set_class();		
};
class staff : public employ
{	public:
		void get_class();
		void set_class();
};
class UG : public student
{	public:
		void get_class();
		void set_class();	
};
class PG : public student
{		string spec;
	public:
		PG()
		{	spec="EMPTY";
		}
		void setspec(string spec)
		{	this->spec=spec;
		}
		string getspec()
		{	return spec;
		}
		void get_class();
		void set_class();	
};
class RS : public student
{		string spec;
		int pub;
	public:
		RS()
		{	spec="EMPTY";
			pub=0;
		}
		void setspec(string spec)
		{	this->spec=spec;
		}
		string getspec()
		{	return spec;
		}
		void setpub(int pub)
		{	this->pub=pub;
		}
		int getpub()
		{	return pub;
		}
		void get_class();
		void set_class();	
};
/*FUNCTION DEFINATIONS*/
void alumni::set_class()
{	string tempname,tempdept,tempadd,tempenroll,tempcurr_emp;
	int temppass_year;
	cout<<"\n Enter Alumni Name: ";
	getline(cin,tempname);
	setname(tempname);
	cout<<"\n Enter Alumni's Department of Passing: ";
	getline(cin,tempdept);
	setdept(tempdept);
	cout<<"\n Enter Alumni's Address: ";
	getline(cin,tempadd);
	setadd(tempadd);
	cout<<"\n Enter Alumni's Enrollment No.: ";
	getline(cin,tempenroll);
	setenroll(tempenroll);
	cout<<"\n Enter Alumni's Current Employer: ";
	getline(cin,tempcurr_emp);
	setcurr_emp(tempcurr_emp);
	cout<<"\n Enter Alumni's Year of Passing: ";
	cin>>temppass_year;
	setpass_year(temppass_year);
}
void alumni::get_class()
{	cout<<"\n\n Alumni Name: ";
	cout<<getname();
	cout<<"\n\n \t Department of Passing: ";
	cout<<getdept();
	cout<<"\n\n \t Address: ";
	cout<<getadd();
	cout<<"\n\n \t Enrollment No.: ";
	cout<<getenroll();
	cout<<"\n\n \t Current Employer: ";
	cout<<getcurr_emp();
	cout<<"\n\n \t Year of Passing: ";
	cout<<getpass_year();
}
void faculty::set_class()
{	string tempname,tempdept,tempadd,tempdesig,tempempid,tempspec;
	int templeaves;
	cout<<"\n Enter Faculty Name: ";
	getline(cin,tempname);
	setname(tempname);
	cout<<"\n Enter Faculty's Department: ";
	getline(cin,tempdept);
	setdept(tempdept);
	cout<<"\n Enter Faculty's Address: ";
	getline(cin,tempadd);
	setadd(tempadd);
	cout<<"\n Enter Faculty's Designation: ";
	getline(cin,tempdesig);
	setdesig(tempdesig);
	cout<<"\n Enter Faculty's Employee ID: ";
	getline(cin,tempempid);
	setempid(tempempid);
	cout<<"\n Enter Faculty's Specilization: ";
	getline(cin,tempspec);
	setspec(tempspec);
	cout<<"\n Enter Faculty's no. of Leaves': ";
	cin>>templeaves;
	setleaves(templeaves);
}
void faculty::get_class()
{	cout<<"\n\n Faculty Name: ";
	cout<<getname();
	cout<<"\n\n \t Department: ";
	cout<<getdept();
	cout<<"\n\n \t Address: ";
	cout<<getadd();
	cout<<"\n\n \t Designation: ";
	cout<<getdesig();
	cout<<"\n\n \t Employee ID: ";
	cout<<getempid();
	cout<<"\n\n \t Specilization: ";
	cout<<getspec();
	cout<<"\n\n \t No. of Leaves: ";
	cout<<getleaves();
}
void staff::set_class()
{	string tempname,tempdept,tempadd,tempdesig,tempempid;
	int templeaves;
	cout<<"\n Enter Staff Name: ";
	getline(cin,tempname);
	setname(tempname);
	cout<<"\n Enter Staff's Department: ";
	getline(cin,tempdept);
	setdept(tempdept);
	cout<<"\n Enter Staff's Address: ";
	getline(cin,tempadd);
	setadd(tempadd);
	cout<<"\n Enter Staff's Designation: ";
	getline(cin,tempdesig);
	setdesig(tempdesig);
	cout<<"\n Enter Staff's Employee ID: ";
	getline(cin,tempempid);
	setempid(tempempid);
	cout<<"\n Enter Staff's no. of Leaves': ";
	cin>>templeaves;
	setleaves(templeaves);
}
void staff::get_class()
{	cout<<"\n\n Staff Name: ";
	cout<<getname();
	cout<<"\n\n \t Department: ";
	cout<<getdept();
	cout<<"\n\n \t Address: ";
	cout<<getadd();
	cout<<"\n\n \t Designation: ";
	cout<<getdesig();
	cout<<"\n\n \t Employee ID: ";
	cout<<getempid();
	cout<<"\n\n \t No. of Leaves: ";
	cout<<getleaves();
}
void UG::set_class()
{	string tempname,tempdept,tempadd,tempenroll,tempfac_no;
	float tempCPI;
	int tempyear;
	cout<<"\n Enter Student (UG) Name: ";
	getline(cin,tempname);
	setname(tempname);
	cout<<"\n Enter Student's Department: ";
	getline(cin,tempdept);
	setdept(tempdept);
	cout<<"\n Enter Student's Address: ";
	getline(cin,tempadd);
	setadd(tempadd);
	cout<<"\n Enter Student's Enrollment No.: ";
	getline(cin,tempenroll);
	setenroll(tempenroll);
	cout<<"\n Enter Student's Faculty No.: ";
	getline(cin,tempfac_no);
	setfac_no(tempfac_no);
	cout<<"\n Enter Student's Course Year: ";
	cin>>tempyear;
	setyear(tempyear);
	cout<<"\n Enter Student's CPI: ";
	cin>>tempCPI;
	setCPI(tempCPI);
}
void UG::get_class()
{	cout<<"\n\n Student(UG) Name: ";
	cout<<getname();
	cout<<"\n\n \t Department: ";
	cout<<getdept();
	cout<<"\n\n \t Address: ";
	cout<<getadd();
	cout<<"\n\n \t Enrollment No.: ";
	cout<<getenroll();
	cout<<"\n\n \t Faculty No.: ";
	cout<<getfac_no();
	cout<<"\n\n \t Course Year: ";
	cout<<getyear();
	cout<<"\n\n \t CPI: ";
	cout<<getCPI();
}
void PG::set_class()
{	string tempname,tempdept,tempadd,tempenroll,tempfac_no,tempspec;
	float tempCPI;
	int tempyear;
	cout<<"\n Enter Student (PG) Name: ";
	getline(cin,tempname);
	setname(tempname);
	cout<<"\n Enter Student's Department: ";
	getline(cin,tempdept);
	setdept(tempdept);
	cout<<"\n Enter Student's Address: ";
	getline(cin,tempadd);
	setadd(tempadd);
	cout<<"\n Enter Student's Enrollment No.: ";
	getline(cin,tempenroll);
	setenroll(tempenroll);
	cout<<"\n Enter Student's Faculty No.: ";
	getline(cin,tempfac_no);
	setfac_no(tempfac_no);
	cout<<"\n Enter Student's Area of Specilization: ";
	getline(cin,tempspec);
	setspec(tempspec);
	cout<<"\n Enter Student's Course Year: ";
	cin>>tempyear;
	setyear(tempyear);
	cout<<"\n Enter Student's CPI: ";
	cin>>tempCPI;
	setCPI(tempCPI);
}
void PG::get_class()
{	cout<<"\n\n Student(PG) Name: ";
	cout<<getname();
	cout<<"\n\n \t Department: ";
	cout<<getdept();
	cout<<"\n\n \t Address: ";
	cout<<getadd();
	cout<<"\n\n \t Enrollment No.: ";
	cout<<getenroll();
	cout<<"\n\n \t Faculty No.: ";
	cout<<getfac_no();
	cout<<"\n\n \t Area of Specilization: ";
	cout<<getspec();
	cout<<"\n\n \t Course Year: ";
	cout<<getyear();
	cout<<"\n\n \t CPI: ";
	cout<<getCPI();
}
void RS::set_class()
{	string tempname,tempdept,tempadd,tempenroll,tempfac_no,tempspec;
	float tempCPI;
	int tempyear,temppub;
	cout<<"\n Enter Student (PG) Name: ";
	getline(cin,tempname);
	setname(tempname);
	cout<<"\n Enter Student's Department: ";
	getline(cin,tempdept);
	setdept(tempdept);
	cout<<"\n Enter Student's Address: ";
	getline(cin,tempadd);
	setadd(tempadd);
	cout<<"\n Enter Student's Enrollment No.: ";
	getline(cin,tempenroll);
	setenroll(tempenroll);
	cout<<"\n Enter Student's Faculty No.: ";
	getline(cin,tempfac_no);
	setfac_no(tempfac_no);
	cout<<"\n Enter Student's Area of Specilization: ";
	getline(cin,tempspec);
	setspec(tempspec);
	cout<<"\n Enter Student's Course Year: ";
	cin>>tempyear;
	setyear(tempyear);
	cout<<"\n Enter Student's CPI: ";
	cin>>tempCPI;
	setCPI(tempCPI);
	cout<<"\n Enter Student's No. of Publications: ";
	cin>>temppub;
	setpub(temppub);
}
void RS::get_class()
{	cout<<"\n\n Student(PG) Name: ";
	cout<<getname();
	cout<<"\n\n \t Department: ";
	cout<<getdept();
	cout<<"\n\n \t Address: ";
	cout<<getadd();
	cout<<"\n\n \t Enrollment No.: ";
	cout<<getenroll();
	cout<<"\n\n \t Faculty No.: ";
	cout<<getfac_no();
	cout<<"\n\n \t Area of Specilization: ";
	cout<<getspec();
	cout<<"\n\n \t Course Year: ";
	cout<<getyear();
	cout<<"\n\n \t CPI: ";
	cout<<getCPI();
	cout<<"\n\n \t No. of Publications: ";
	cout<<getpub();
}
void facl();
void stff();
void employee()
{	int op;
	emenu:
	cout<<"\n SELECT CATEGORY\n 1. FACULTY \n 2. STAFF \n 3. EXIT\n";		
	cin>>op;
	switch(op)
	{	case 1: system("cls");
				facl();
			   	break;
		case 2: system("cls");
				stff();
				break;
		case 3: exit(0);
				break;
		default:system("cls");
				cout<<"\n Wrong INPUT\n TRY AGAIN !\n";
				goto emenu;	
	}
}
void facl()
{	int op,n,n1,i,check=0;
	faculty f[100];
	fmenu:
	cout<<"\n SELECT OPERATION\n 1. ENTER RECORDS \n 2. DISPLAY RECORD \n 3. EXIT\n";
	cin>>op;
	switch(op)
	{	case 1: system("cls");
				check=1;
				cout<<"\n Enter No. of records to input (max 100):\n";
				i=0;
				cin>>n;
				n1=n;
				while(n>0)
				{	system("cls");
					cout<<"\nEnter record "<<i+1<<" :";
					cin.ignore();
					f[i].set_class();
					i++;n--;
				}
				system("cls");
				cout<<"\n INPUT DONE!\n";
				goto fmenu;
				break;
		case 2: system("cls");
				if(check==0)
					cout<<"\n No DATA\n";
				else
				{	for(i=0;i<n1;i++)
					{	f[i].get_class();
						cout<<"\n**************************************************************\n";			  
					}
				}
				goto fmenu;
		case 3: exit(0);
				break;
		default:system("cls");
				cout<<"\n Wrong INPUT\n TRY AGAIN !\n";
				goto fmenu;
				
	}
		
}
void stff()
{	int op,n,n1,i,check=0;
	staff s[100];
	smenu:
	cout<<"\n SELECT OPERATION\n 1. ENTER RECORDS \n 2. DISPLAY RECORD \n 3. EXIT\n";
	cin>>op;
	switch(op)
	{	case 1: system("cls");
				check=1;
				cout<<"\n Enter No. of records to input (max 100):\n";
				i=0;
				cin>>n;
				n1=n;
				while(n>0)
				{	system("cls");
					cout<<"\nEnter record "<<i+1<<" :";
					cin.ignore();
					s[i].set_class();
					i++;n--;
				}
				system("cls");
				cout<<"\n INPUT DONE!\n";
				goto smenu;
				break;
		case 2: system("cls");
				if(check==0)
					cout<<"\n No DATA\n";
				else
				{	for(i=0;i<n1;i++)
					{	s[i].get_class();
						cout<<"\n**************************************************************\n";			  
					}
				}
				goto smenu;
		case 3: exit(0);
				break;
		default:system("cls");
				cout<<"\n Wrong INPUT\n TRY AGAIN !\n";
				goto smenu;
	}
}
void ug();
void pg();
void rs();
void studnt()
{	int op;
	stmenu:
	cout<<"\n SELECT CATEGORY\n 1. UG \n 2. PG \n 3. RS \n 4. Exit\n";		
	cin>>op;
	switch(op)
	{	case 1: system("cls");
				ug();
			   	break;
		case 2: system("cls");
				pg();
				break;
		case 3: system("cls");
				rs();
				break;
		case 4: exit(0);
				break;
		default:system("cls");
				cout<<"\n Wrong INPUT\n TRY AGAIN !\n";
				goto stmenu;	
	}
}
void ug()
{	int op,n,n1,i,check=0;
	UG u[100];
	umenu:
	cout<<"\n SELECT OPERATION\n 1. ENTER RECORDS \n 2. DISPLAY RECORD \n 3. EXIT\n";
	cin>>op;
	switch(op)
	{	case 1: system("cls");
				check=1;
				cout<<"\n Enter No. of records to input (max 100):\n";
				i=0;
				cin>>n;
				n1=n;
				while(n>0)
				{	system("cls");
					cout<<"\nEnter record "<<i+1<<" :";
					cin.ignore();
					u[i].set_class();
					i++;n--;
				}
				system("cls");
				cout<<"\n INPUT DONE!\n";
				goto umenu;
				break;
		case 2: system("cls");
				if(check==0)
					cout<<"\n No DATA\n";
				else
				{	for(i=0;i<n1;i++)
					{	u[i].get_class();
						cout<<"\n**************************************************************\n";			  
					}
				}
				goto umenu;
		case 3: exit(0);
				break;
		default:system("cls");
				cout<<"\n Wrong INPUT\n TRY AGAIN !\n";
				goto umenu;
	}
}
void pg()
{	int op,n,n1,i,check=0;
	PG p[100];
	pmenu:
	cout<<"\n SELECT OPERATION\n 1. ENTER RECORDS \n 2. DISPLAY RECORD \n 3. EXIT\n";
	cin>>op;
	switch(op)
	{	case 1: system("cls");
				check=1;
				cout<<"\n Enter No. of records to input (max 100):\n";
				i=0;
				cin>>n;
				n1=n;
				while(n>0)
				{	system("cls");
					cout<<"\nEnter record "<<i+1<<" :";
					cin.ignore();
					p[i].set_class();
					i++;n--;
				}
				system("cls");
				cout<<"\n INPUT DONE!\n";
				goto pmenu;
				break;
		case 2: system("cls");
				if(check==0)
					cout<<"\n No DATA\n";
				else
				{	for(i=0;i<n1;i++)
					{	p[i].get_class();
						cout<<"\n**************************************************************\n";			  
					}
				}
				goto pmenu;
		case 3: exit(0);
				break;
		default:system("cls");
				cout<<"\n Wrong INPUT\n TRY AGAIN !\n";
				goto pmenu;
	}
}
void rs()
{	int op,n,n1,i,check=0;
	RS r[100];
	rmenu:
	cout<<"\n SELECT OPERATION\n 1. ENTER RECORDS \n 2. DISPLAY RECORD \n 3. EXIT\n";
	cin>>op;
	switch(op)
	{	case 1: system("cls");
				check=1;
				cout<<"\n Enter No. of records to input (max 100):\n";
				i=0;
				cin>>n;
				n1=n;
				while(n>0)
				{	system("cls");
					cout<<"\nEnter record "<<i+1<<" :";
					cin.ignore();
					r[i].set_class();
					i++;n--;
				}
				system("cls");
				cout<<"\n INPUT DONE!\n";
				goto rmenu;
				break;
		case 2: system("cls");
				if(check==0)
					cout<<"\n No DATA\n";
				else
				{	for(i=0;i<n1;i++)
					{	r[i].get_class();
						cout<<"\n**************************************************************\n";			  
					}
				}
				goto rmenu;
		case 3: exit(0);
				break;
		default:system("cls");
				cout<<"\n Wrong INPUT\n TRY AGAIN !\n";
				goto rmenu;
	}
}
void almni()
{	int op,n,n1,i,check=0;
	alumni a[100];
	almenu:
	cout<<"\n SELECT OPERATION\n 1. ENTER RECORDS \n 2. DISPLAY RECORD \n 3. EXIT\n";
	cin>>op;
	switch(op)
	{	case 1: system("cls");
				check=1;
				cout<<"\n Enter No. of records to input (max 100):\n";
				i=0;
				cin>>n;
				n1=n;
				while(n>0)
				{	system("cls");
					cout<<"\nEnter record "<<i+1<<" :";
					cin.ignore();
					a[i].set_class();
					i++;n--;
				}
				system("cls");
				cout<<"\n INPUT DONE!\n";
				goto almenu;
				break;
		case 2: system("cls");
				if(check==0)
					cout<<"\n No DATA\n";
				else
				{	for(i=0;i<n1;i++)
					{	a[i].get_class();
						cout<<"\n**************************************************************\n";			  
					}
				}
				goto almenu;
		case 3: exit(0);
				break;
		default:system("cls");
				cout<<"\n Wrong INPUT\n TRY AGAIN !\n";
				goto almenu;
	}
}
int main()
{	int op;
	menu:
	cout<<"\n SELECT CATEGORY\n 1. EMPLOYEE \n 2. STUDENT \n 3. ALUMNI \n 4. EXIT\n";		
	cin>>op;
	switch(op)
	{	case 1: system("cls");
				employee();
			   	break;
		case 2: system("cls");
				studnt();
				break;
		case 3: system("cls");
				almni();
				break;
		case 4: exit(0);
				break;
		default:system("cls");
				cout<<"\n Wrong INPUT\n TRY AGAIN !\n";
				goto menu;	
	}
}
