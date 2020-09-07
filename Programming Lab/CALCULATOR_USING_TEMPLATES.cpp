//Program for a basic Calculator using Templates
#include<iostream>
#include<cmath>
using namespace std;
template<class T>
T sum(T a,T b)
{	return(a+b);
}
template<class T>
T sub(T a,T b)
{	return(a-b);
}
template<class T>
T mul(T a,T b)
{	return(a*b);
}
template<class T>
T div(T a,T b)
{	return(a/b);
}
template<class T>
T po(T a,T b)
{	return(pow(a,b));
}
void calc(int x,int y)
{	cout<<"\nEnter a & b:\n";
	try
	{
	switch(x)
	{	case 1:{switch(y)
				{	case 1: {int a,b,c;
							 cin>>a>>b;
							 c=sum<int>(a,b);
							 cout<<"a + b = "<<c;
							}break;
					case 2: {float a,b,c;
							 cin>>a>>b;
							 c=sum<float>(a,b);
							 cout<<"a + b = "<<c;
							}break;
					case 3: {double a,b,c;
							 cin>>a>>b;
							 c=sum<double>(a,b);
							 cout<<"a + b = "<<c;
							}break;
					default:cout<<"\n Wrong Input";
							break;
				}	
			   }break;
		case 2:{switch(y)
				{	case 1: {int a,b,c;
							 cin>>a>>b;
							 c=sub<int>(a,b);
							 cout<<"a - b = "<<c;
							}break;
					case 2: {float a,b,c;
							 cin>>a>>b;
							 c=sub<float>(a,b);
							 cout<<"a - b = "<<c;
							}break;
					case 3: {double a,b,c;
							 cin>>a>>b;
							 c=sub<double>(a,b);
							 cout<<"a - b = "<<c;
							}break;
					default:cout<<"\n Wrong Input";
							break;
				}	
			   }break;
		case 3:{switch(y)
				{	case 1: {int a,b,c;
							 cin>>a>>b;
							 c=mul<int>(a,b);
							 cout<<"a x b = "<<c;
							}break;
					case 2: {float a,b,c;
							 cin>>a>>b;
							 c=mul<float>(a,b);
							 cout<<"a x b = "<<c;
							}break;
					case 3: {double a,b,c;
							 cin>>a>>b;
							 c=mul<double>(a,b);
							 cout<<"a x b = "<<c;
							}break;
					default:cout<<"\n Wrong Input";
							break;
				}	
			   }break; 
		case 4:{switch(y)
				{	
					case 1: {int a,b,c;
							 cin>>a>>b;
							if(b==0)
							 	throw 0;
							 c=div<int>(a,b);
							 cout<<"a / b = "<<c;
							}break;
					case 2: {float a,b,c;
							 cin>>a>>b;
							 if(b==0)
							 	throw 0;
							 c=div<float>(a,b);
							 cout<<"a / b = "<<c;
							}break;
					case 3: {double a,b,c;
							 cin>>a>>b;
							 if(b==0)
							 	throw 0;
							 c=div<double>(a,b);
							 cout<<"a / b = "<<c;
							}break;
					default:cout<<"\n Wrong Input";
							break;
				}	
			   }break;
		case 5:{switch(y)
				{	case 1: {int a,b,c;
							 cin>>a>>b;
							 c=po<int>(a,b);
							 cout<<"a ^ b = "<<c;
							}break;
					case 2: {float a,b,c;
							 cin>>a>>b;
							 c=po<float>(a,b);
							 cout<<"a ^ b = "<<c;
							}break;
					case 3: {double a,b,c;
							 cin>>a>>b;
							 c=po<double>(a,b);
							 cout<<"a ^ b = "<<c;
							}break;
					default:cout<<"\n Wrong Input";
							break;
				}
			   }break;
		default:cout<<"\n Wrong Input";
				break;
		}
	}
	catch(int x)
	{	cout<<"\n'b' cannot be zero!";
	}	
}
int main()
{	int op1,op2;
	cout<<"\nSelect Operation: \n1. a + b (Addition)\n2. a - b (Subtraction)\n3. a x b (Multiplication)\n4. a / b (Divison)\n5. a ^ b (Power)\n";
	cin>>op1;
	cout<<"Select Datatype for a & b: \n1. int\n2. float\n3. double\n";
	cin>>op2;
	calc(op1,op2);
}
