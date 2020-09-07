#include<iostream>
#include<stdlib.h>
using namespace std;
class cm
{   public:
        float data;
        cm()
        {   data=0;
        }
        cm(float val)
        {   data=val;
        }
        cm operator + (cm b);
        cm operator - (cm b);
        cm operator * (cm b);
        cm operator / (cm b);
};
class inch
{
    public:
        float data;
        inch()
        {   data=0;
        }
        inch(float val)
        {   data=val;
        }

        inch operator + (inch b);
        inch operator - (inch b);
        inch operator * (inch b);
        inch operator / (inch b);
        inch operator + (cm b);
        inch operator - (cm b);
        inch operator * (cm b);
        inch operator / (cm b);

};
class feet
{   public:
        float data;
        feet()
        {   data=0;
        }
        feet(float val)
        {   data=val;
        }

        feet operator + (feet b);
        feet operator - (feet b);
        feet operator * (feet b);
        feet operator / (feet b);
        feet operator + (inch b);
        feet operator - (inch b);
        feet operator * (inch b);
        feet operator / (inch b);
        feet operator + (cm b);
        feet operator - (cm b);
        feet operator * (cm b);
        feet operator / (cm b);
};
class m
{   public:
        float data;
        m()
        {   data=0;
        }
        m(float val)
        {   data=val;
        }

        m operator + (m b);
        m operator - (m b);
        m operator * (m b);
        m operator / (m b);
        m operator + (feet b);
        m operator - (feet b);
        m operator * (feet b);
        m operator / (feet b);
        m operator + (inch b);
        m operator - (inch b);
        m operator * (inch b);
        m operator / (inch b);
        m operator + (cm b);
        m operator - (cm b);
        m operator * (cm b);
        m operator / (cm b);
};
class km
{   public:
        float data;
        km()
        {   data=0;
        }
        km(float val)
        {   data=val;
        }
        km operator + (km b);
        km operator - (km b);
        km operator * (km b);
        km operator / (km b);
        km operator + (m b);
        km operator - (m b);
        km operator * (m b);
        km operator / (m b);
        km operator + (feet b);
        km operator - (feet b);
        km operator * (feet b);
        km operator / (feet b);
        km operator + (inch b);
        km operator - (inch b);
        km operator * (inch b);
        km operator / (inch b);
        km operator + (cm b);
        km operator - (cm b);
        km operator * (cm b);
        km operator / (cm b);
};
cm cm :: operator + (cm b)
{   cm temp;
    temp.data = data+b.data;
    return temp;
}
cm cm :: operator - (cm b)
{   cm temp;
    temp.data = data-b.data;
    return temp;
}
cm cm :: operator * (cm b)
{   cm temp;
    temp.data = data*b.data;
    return temp;
}
cm cm :: operator / (cm b)
{   cm temp;
    temp.data = data/b.data;
    return temp;
}
inch inch :: operator + (inch b)
{   inch temp;
    temp.data = data+b.data;
    return temp;
}
inch inch :: operator - (inch b)
{   inch temp;
    temp.data = data-b.data;
    return temp;
}
inch inch :: operator * (inch b)
{   inch temp;
    temp.data = data*b.data;
    return temp;
}
inch inch :: operator / (inch b)
{   inch temp;
    temp.data = data/b.data;
    return temp;
}
inch inch :: operator + (cm b)
{   inch temp;
    temp.data = data+(b.data*0.394);
    return temp;
}
inch inch :: operator - (cm b)
{   inch temp;
    temp.data = data-(b.data*0.394);
    return temp;
}
inch inch :: operator * (cm b)
{   inch temp;
    temp.data = data*(b.data*0.394);
    return temp;
}
inch inch :: operator / (cm b)
{   inch temp;
    temp.data = data/(b.data*0.394);
    return temp;
}
feet feet :: operator + (feet b)
{   feet temp;
    temp.data = data+b.data;
    return temp;
}
feet feet :: operator - (feet b)
{   feet temp;
    temp.data = data-b.data;
    return temp;
}
feet feet :: operator * (feet b)
{   feet temp;
    temp.data = data*b.data;
    return temp;
}
feet feet :: operator / (feet b)
{   feet temp;
    temp.data = data/b.data;
    return temp;
}
feet feet :: operator + (inch b)
{   feet temp;
    temp = data+(0.083333*b.data);
    return temp;
}
feet feet :: operator - (inch b)
{   feet temp;
    temp = data-(0.083333*b.data);
    return temp;
}
feet feet :: operator * (inch b)
{   feet temp;
    temp = data*(0.083333*b.data);
    return temp;
}
feet feet :: operator / (inch b)
{   feet temp;
    temp = data/(0.083333*b.data);
    return temp;
}
feet feet :: operator + (cm b)
{   feet temp;
    temp.data = data+(b.data*0.0328084);
    return temp;
}
feet feet :: operator - (cm b)
{   feet temp;
    temp.data = data-(b.data*0.0328084);
    return temp;
}
feet feet :: operator * (cm b)
{   feet temp;
    temp.data = data*(b.data*0.0328084);
    return temp;
}
feet feet :: operator / (cm b)
{   feet temp;
    temp.data = data/(b.data*0.0328084);
    return temp;
}
m m :: operator + (m b)
{   m temp;
    temp.data = data+b.data;
    return temp;
}
m m :: operator - (m b)
{   m temp;
    temp.data = data-b.data;
    return temp;
}
m m :: operator * (m b)
{   m temp;
    temp.data = data*b.data;
    return temp;
}
m m :: operator / (m b)
{   m temp;
    temp.data = data/b.data;
    return temp;
}
m m :: operator + (feet b)
{   m temp;
    temp.data = data+(0.305*b.data);
    return temp;
}
m m :: operator - (feet b)
{   m temp;
    temp.data = data-(0.305*b.data);
    return temp;
}
m m :: operator * (feet b)
{   m temp;
    temp.data = data*(0.305*b.data);
    return temp;
}
m m :: operator / (feet b)
{   m temp;
    temp.data = data/(0.305*b.data);
    return temp;
}
m m :: operator + (inch b)
{   m temp;
    temp.data = data+(0.0254*b.data);
    return temp;
}
m m :: operator - (inch b)
{   m temp;
    temp.data = data-(0.0254*b.data);
    return temp;
}
m m :: operator * (inch b)
{   m temp;
    temp.data = data*(0.0254*b.data);
    return temp;
}
m m :: operator / (inch b)
{   m temp;
    temp.data = data/(0.0254*b.data);
    return temp;
}
m m :: operator + (cm b)
{   m temp;
    temp.data = data+(0.01*b.data);
    return temp;
}
m m :: operator - (cm b)
{   m temp;
    temp.data = data-(0.01*b.data);
    return temp;
}
m m :: operator * (cm b)
{   m temp;
    temp.data = data*(0.01*b.data);
    return temp;
}
m m :: operator / (cm b)
{   m temp;
    temp.data = data/(0.01*b.data);
    return temp;
}
km km :: operator + (km b)
{   km temp;
    temp.data = data+b.data;
    return temp;
}
km km :: operator - (km b)
{   km temp;
    temp.data = data-b.data;
    return temp;
}
km km :: operator * (km b)
{   km temp;
    temp.data = data*b.data;
    return temp;
}
km km :: operator / (km b)
{   km temp;
    temp.data = data/b.data;
    return temp;
}
km km :: operator + (m b)
{   km temp;
    temp.data = data+(0.001*b.data);
    return temp;
}
km km :: operator - (m b)
{   km temp;
    temp.data = data-(0.001*b.data);
    return temp;
}
km km :: operator * (m b)
{   km temp;
    temp.data = data*(0.001*b.data);
    return temp;
}
km km :: operator / (m b)
{   km temp;
    temp.data = data/(0.001*b.data);
    return temp;
}
km km :: operator + (feet b)
{   km temp;
    temp.data = data+(0.000305*b.data);
    return temp;
}
km km :: operator - (feet b)
{   km temp;
    temp.data = data-(0.000305*b.data);
    return temp;
}
km km :: operator * (feet b)
{   km temp;
    temp.data = data*(0.000305*b.data);
    return temp;
}
km km :: operator / (feet b)
{   km temp;
    temp.data = data/(0.000305*b.data);
    return temp;
}
km km :: operator + (inch b)
{   km temp;
    temp.data = data+(0.0000254*b.data);
    return temp;
}
km km :: operator - (inch b)
{   km temp;
    temp.data = data-(0.0000254*b.data);
    return temp;
}
km km :: operator * (inch b)
{   km temp;
    temp.data = data*(0.0000254*b.data);
    return temp;
}
km km :: operator / (inch b)
{   km temp;
    temp.data = data/(0.0000254*b.data);
    return temp;
}
km km :: operator + (cm b)
{   km temp;
    temp.data = data+(0.00001*b.data);
    return temp;
}
km km :: operator - (cm b)
{   km temp;
    temp.data = data-(0.00001*b.data);
    return temp;
}
km km :: operator * (cm b)
{   km temp;
    temp.data = data*(0.00001*b.data);
    return temp;
}
km km :: operator / (cm b)
{   km temp;
    temp.data = data/(0.00001*b.data);
    return temp;
}
int main()
{   int op,op1,op2;
    float x,y;
    cout<<"\nSELECT OPERATION: \n\n1. a + b (ADDITION)\n2. a - b (SUBSTRACTION)\n3. a x b (MULTIPLICATION)\n4. a / b (DIVISION)\n";
    cin>>op;
    cout<<"\n\nSelect unit for a \n1. cm\n2. in\n3. ft\n4. m\n5. km\n";
    cin>>op1;
    cout<<"\nEnter value for a = ";
    cin>>x;
    cout<<"\n\nSelect unit for b \n1. cm\n2. in\n3. ft\n4. m\n5. km\n";
    cin>>op2;
    cout<<"\nEnter value for b = ";
    cin>>y;
    switch(op)
    {   case 1:
        {   switch(op1)
            {   case 1:
                {   cm a(x);
                    switch(op2)
                    {   case 1: {
                                cm b(y),res;
                                res = a+b;
                                cout<<"\n\na + b = "<<res.data<<" cm\n";
                                break;
                                }
                        case 2: {
                                inch b(y),res;
                                res = b+a;
                                cout<<"\n\na + b = "<<res.data<<" in\n";
                                break;
                                }
                        case 3: {feet b(y),res;
                                res = b+a;
                                cout<<"\n\na + b = "<<res.data<<" ft\n";
                                break;
                                }
                        case 4: {
                                m b(y),res;
                                res = b+a;
                                cout<<"\n\na + b = "<<res.data<<" m\n";
                                break;
                                }
                        case 5: {
                                km b(y),res;
                                res = b+a;
                                cout<<"\n\na + b = "<<res.data<<" km\n";
                                break;
                                }
                        default:cout<<"\nWRONG INPUT!\n";
                                exit(0);
                    }
                }break;
                case 2:
                {   inch a(x);
                    switch(op2)
                    {   case 1: {
                                cm b(y);
                                inch res;
                                res = a+b;
                                cout<<"\n\na + b = "<<res.data<<" in\n";
                                break;
                                }
                        case 2: {
                                inch b(y),res;
                                res = a+b;
                                cout<<"\n\na + b = "<<res.data<<" in\n";
                                break;
                                }
                        case 3: {
                                feet b(y),res;
                                res = b+a;
                                cout<<"\n\na + b = "<<res.data<<" ft\n";
                                break;
                                }
                        case 4: {
                                m b(y),res;
                                res = b+a;
                                cout<<"\n\na + b = "<<res.data<<" m\n";
                                break;
                                }
                        case 5: {
                                km b(y),res;
                                res = b+a;
                                cout<<"\n\na + b = "<<res.data<<" km\n";
                                break;
                                }
                        default:cout<<"\nWRONG INPUT!\n";
                                exit(0);
                    }
                }break;
                case 3:
                {   feet a(x);
                    switch(op2)
                    {   case 1: {
                                cm b(y);
                                feet res;
                                res = a+b;
                                cout<<"\n\na + b = "<<res.data<<" ft\n";
                                break;
                                }
                        case 2: {
                                inch b(y);
                                feet res;
                                res = a+b;
                                cout<<"\n\na + b = "<<res.data<<" ft\n";
                                break;
                                }
                        case 3: {
                                feet b(y),res;
                                res = a+b;
                                cout<<"\n\na + b = "<<res.data<<" ft\n";
                                break;
                                }
                        case 4: {
                                m b(y),res;
                                res = b+a;
                                cout<<"\n\na + b = "<<res.data<<" m\n";
                                break;
                                }
                        case 5: {
                                km b(y),res;
                                res = b+a;
                                cout<<"\n\na + b = "<<res.data<<" km\n";
                                break;
                                }
                        default:cout<<"\nWRONG INPUT!\n";
                                exit(0);
                    }
                }break;
                case 4:
                {   m a(x);
                    switch(op2)
                    {   case 1: {
                                cm b(y);
                                m res;
                                res = a+b;
                                cout<<"\n\na + b = "<<res.data<<" m\n";
                                break;
                                }
                        case 2: {
                                inch b(y);
                                m res;
                                res = a+b;
                                cout<<"\n\na + b = "<<res.data<<" m\n";
                                break;
                                }
                        case 3: {
                                feet b(y);
                                m res;
                                res = a+b;
                                cout<<"\n\na + b = "<<res.data<<" m\n";
                                break;
                                }
                        case 4: {
                                m b(y),res;
                                res = a+b;
                                cout<<"\n\na + b = "<<res.data<<" m\n";
                                break;
                                }
                        case 5: {
                                km b(y),res;
                                res = b+a;
                                cout<<"\n\na + b = "<<res.data<<" km\n";
                                break;
                                }
                        default:cout<<"\nWRONG INPUT!\n";
                                exit(0);
                    }
                }break;
                case 5:
                {   km a(x);
                    switch(op2)
                    {   case 1: {
                                cm b(y);
                                km res;
                                res = a+b;
                                cout<<"\n\na + b = "<<res.data<<" km\n";
                                break;
                                }
                        case 2: {
                                inch b(y);
                                km res;
                                res = a+b;
                                cout<<"\n\na + b = "<<res.data<<" km\n";
                                break;
                                }
                        case 3: {
                                km res;
                                feet b(y);
                                res = a+b;
                                cout<<"\n\na + b = "<<res.data<<" km\n";
                                break;
                                }
                        case 4: {
                                km res;
                                m b(y);
                                res = a+b;
                                cout<<"\n\na + b = "<<res.data<<" km\n";
                                break;
                                }
                        case 5: {
                                km b(y),res;
                                res = a+b;
                                cout<<"\n\na + b = "<<res.data<<" km\n";
                                break;
                                }
                        default:cout<<"\nWRONG INPUT!\n";
                                exit(0);
                    }
                }break;
            }
        }break;
        case 2:
        {   switch(op1)
            {   case 1:
                {   cm a(x);
                    switch(op2)
                    {   case 1: {
                                cm b(y),res;
                                res = a-b;
                                cout<<"\n\na - b = "<<res.data<<" cm\n";
                                break;
                                }
                        case 2: {
                                inch b(y),res;
                                res = b-a;
                                cout<<"\n\na - b = "<<-res.data<<" in\n";
                                break;
                                }
                        case 3: {feet b(y),res;
                                res = b-a;
                                cout<<"\n\na - b = "<<-res.data<<" ft\n";
                                break;
                                }
                        case 4: {
                                m b(y),res;
                                res = b-a;
                                cout<<"\n\na - b = "<<-res.data<<" m\n";
                                break;
                                }
                        case 5: {
                                km b(y),res;
                                res = b-a;
                                cout<<"\n\na - b = "<<-res.data<<" km\n";
                                break;
                                }
                        default:cout<<"\nWRONG INPUT!\n";
                                exit(0);
                    }
                }break;
                case 2:
                {   inch a(x);
                    switch(op2)
                    {   case 1: {
                                cm b(y);
                                inch res;
                                res = a-b;
                                cout<<"\n\na - b = "<<res.data<<" in\n";
                                break;
                                }
                        case 2: {
                                inch b(y),res;
                                res = a-b;
                                cout<<"\n\na - b = "<<res.data<<" in\n";
                                break;
                                }
                        case 3: {
                                feet b(y),res;
                                res = b-a;
                                cout<<"\n\na - b = "<<-res.data<<" ft\n";
                                break;
                                }
                        case 4: {
                                m b(y),res;
                                res = b-a;
                                cout<<"\n\na - b = "<<-res.data<<" m\n";
                                break;
                                }
                        case 5: {
                                km b(y),res;
                                res = b-a;
                                cout<<"\n\na - b = "<<-res.data<<" km\n";
                                break;
                                }
                        default:cout<<"\nWRONG INPUT!\n";
                                exit(0);
                    }
                }break;
                case 3:
                {   feet a(x);
                    switch(op2)
                    {   case 1: {
                                cm b(y);
                                feet res;
                                res = a-b;
                                cout<<"\n\na - b = "<<res.data<<" ft\n";
                                break;
                                }
                        case 2: {
                                inch b(y);
                                feet res;
                                res = a-b;
                                cout<<"\n\na - b = "<<res.data<<" ft\n";
                                break;
                                }
                        case 3: {
                                feet b(y),res;
                                res = a-b;
                                cout<<"\n\na - b = "<<res.data<<" ft\n";
                                break;
                                }
                        case 4: {
                                m b(y),res;
                                res = b-a;
                                cout<<"\n\na - b = "<<-res.data<<" m\n";
                                break;
                                }
                        case 5: {
                                km b(y),res;
                                res = b-a;
                                cout<<"\n\na - b = "<<-res.data<<" km\n";
                                break;
                                }
                        default:cout<<"\nWRONG INPUT!\n";
                                exit(0);
                    }
                }break;
                case 4:
                {   m a(x);
                    switch(op2)
                    {   case 1: {
                                cm b(y);
                                m res;
                                res = a-b;
                                cout<<"\n\na - b = "<<res.data<<" m\n";
                                break;
                                }
                        case 2: {
                                inch b(y);
                                m res;
                                res = a-b;
                                cout<<"\n\na - b = "<<res.data<<" m\n";
                                break;
                                }
                        case 3: {
                                feet b(y);
                                m res;
                                res = a-b;
                                cout<<"\n\na - b = "<<res.data<<" m\n";
                                break;
                                }
                        case 4: {
                                m b(y),res;
                                res = a-b;
                                cout<<"\n\na - b = "<<res.data<<" m\n";
                                break;
                                }
                        case 5: {
                                km b(y),res;
                                res = b-a;
                                cout<<"\n\na - b = "<<-res.data<<" km\n";
                                break;
                                }
                        default:cout<<"\nWRONG INPUT!\n";
                                exit(0);
                    }
                }break;
                case 5:
                {   km a(x);
                    switch(op2)
                    {   case 1: {
                                cm b(y);
                                km res;
                                res = a-b;
                                cout<<"\n\na - b = "<<res.data<<" km\n";
                                break;
                                }
                        case 2: {
                                inch b(y);
                                km res;
                                res = a-b;
                                cout<<"\n\na - b = "<<res.data<<" km\n";
                                break;
                                }
                        case 3: {
                                km res;
                                feet b(y);
                                res = a-b;
                                cout<<"\n\na - b = "<<res.data<<" km\n";
                                break;
                                }
                        case 4: {
                                km res;
                                m b(y);
                                res = a-b;
                                cout<<"\n\na - b = "<<res.data<<" km\n";
                                break;
                                }
                        case 5: {
                                km b(y),res;
                                res = a-b;
                                cout<<"\n\na - b = "<<res.data<<" km\n";
                                break;
                                }
                        default:cout<<"\nWRONG INPUT!\n";
                                exit(0);
                    }
                }break;
            }
        }break;
        case 3:
        {   switch(op1)
            {   case 1:
                {   cm a(x);
                    switch(op2)
                    {   case 1: {
                                cm b(y),res;
                                res = a*b;
                                cout<<"\n\na * b = "<<res.data<<" cm\n";
                                break;
                                }
                        case 2: {
                                inch b(y),res;
                                res = b*a;
                                cout<<"\n\na * b = "<<res.data<<" in\n";
                                break;
                                }
                        case 3: {feet b(y),res;
                                res = b*a;
                                cout<<"\n\na * b = "<<res.data<<" ft\n";
                                break;
                                }
                        case 4: {
                                m b(y),res;
                                res = b*a;
                                cout<<"\n\na * b = "<<res.data<<" m\n";
                                break;
                                }
                        case 5: {
                                km b(y),res;
                                res = b*a;
                                cout<<"\n\na * b = "<<res.data<<" km\n";
                                break;
                                }
                        default:cout<<"\nWRONG INPUT!\n";
                                exit(0);
                    }
                }break;
                case 2:
                {   inch a(x);
                    switch(op2)
                    {   case 1: {
                                cm b(y);
                                inch res;
                                res = a*b;
                                cout<<"\n\na * b = "<<res.data<<" in\n";
                                break;
                                }
                        case 2: {
                                inch b(y),res;
                                res = a*b;
                                cout<<"\n\na * b = "<<res.data<<" in\n";
                                break;
                                }
                        case 3: {
                                feet b(y),res;
                                res = b*a;
                                cout<<"\n\na * b = "<<res.data<<" ft\n";
                                break;
                                }
                        case 4: {
                                m b(y),res;
                                res = b*a;
                                cout<<"\n\na * b = "<<res.data<<" m\n";
                                break;
                                }
                        case 5: {
                                km b(y),res;
                                res = b*a;
                                cout<<"\n\na * b = "<<res.data<<" km\n";
                                break;
                                }
                        default:cout<<"\nWRONG INPUT!\n";
                                exit(0);
                    }
                }break;
                case 3:
                {   feet a(x);
                    switch(op2)
                    {   case 1: {
                                cm b(y);
                                feet res;
                                res = a*b;
                                cout<<"\n\na * b = "<<res.data<<" ft\n";
                                break;
                                }
                        case 2: {
                                inch b(y);
                                feet res;
                                res = a*b;
                                cout<<"\n\na * b = "<<res.data<<" ft\n";
                                break;
                                }
                        case 3: {
                                feet b(y),res;
                                res = a*b;
                                cout<<"\n\na * b = "<<res.data<<" ft\n";
                                break;
                                }
                        case 4: {
                                m b(y),res;
                                res = b*a;
                                cout<<"\n\na * b = "<<res.data<<" m\n";
                                break;
                                }
                        case 5: {
                                km b(y),res;
                                res = b*a;
                                cout<<"\n\na * b = "<<res.data<<" km\n";
                                break;
                                }
                        default:cout<<"\nWRONG INPUT!\n";
                                exit(0);
                    }
                }break;
                case 4:
                {   m a(x);
                    switch(op2)
                    {   case 1: {
                                cm b(y);
                                m res;
                                res = a*b;
                                cout<<"\n\na * b = "<<res.data<<" m\n";
                                break;
                                }
                        case 2: {
                                inch b(y);
                                m res;
                                res = a*b;
                                cout<<"\n\na * b = "<<res.data<<" m\n";
                                break;
                                }
                        case 3: {
                                feet b(y);
                                m res;
                                res = a*b;
                                cout<<"\n\na * b = "<<res.data<<" m\n";
                                break;
                                }
                        case 4: {
                                m b(y),res;
                                res = a*b;
                                cout<<"\n\na * b = "<<res.data<<" m\n";
                                break;
                                }
                        case 5: {
                                km b(y),res;
                                res = b*a;
                                cout<<"\n\na * b = "<<res.data<<" km\n";
                                break;
                                }
                        default:cout<<"\nWRONG INPUT!\n";
                                exit(0);
                    }
                }break;
                case 5:
                {   km a(x);
                    switch(op2)
                    {   case 1: {
                                cm b(y);
                                km res;
                                res = a*b;
                                cout<<"\n\na * b = "<<res.data<<" km\n";
                                break;
                                }
                        case 2: {
                                inch b(y);
                                km res;
                                res = a*b;
                                cout<<"\n\na * b = "<<res.data<<" km\n";
                                break;
                                }
                        case 3: {
                                km res;
                                feet b(y);
                                res = a*b;
                                cout<<"\n\na * b = "<<res.data<<" km\n";
                                break;
                                }
                        case 4: {
                                km res;
                                m b(y);
                                res = a*b;
                                cout<<"\n\na * b = "<<res.data<<" km\n";
                                break;
                                }
                        case 5: {
                                km b(y),res;
                                res = a*b;
                                cout<<"\n\na * b = "<<res.data<<" km\n";
                                break;
                                }
                        default:cout<<"\nWRONG INPUT!\n";
                                exit(0);
                    }
                }break;
            }
        }break;
        case 4:
        {   switch(op1)
            {   case 1:
                {   cm a(x);
                    switch(op2)
                    {   case 1: {
                                cm b(y),res;
                                res = a/b;
                                cout<<"\n\na / b = "<<res.data<<" cm\n";
                                break;
                                }
                        case 2: {
                                inch b(y),res;
                                res = b/a;
                                cout<<"\n\na / b = "<<1/res.data<<" in\n";
                                break;
                                }
                        case 3: {feet b(y),res;
                                res = b/a;
                                cout<<"\n\na / b = "<<1/res.data<<" ft\n";
                                break;
                                }
                        case 4: {
                                m b(y),res;
                                res = b/a;
                                cout<<"\n\na / b = "<<1/res.data<<" m\n";
                                break;
                                }
                        case 5: {
                                km b(y),res;
                                res = b/a;
                                cout<<"\n\na / b = "<<1/res.data<<" km\n";
                                break;
                                }
                        default:cout<<"\nWRONG INPUT!\n";
                                exit(0);
                    }
                }break;
                case 2:
                {   inch a(x);
                    switch(op2)
                    {   case 1: {
                                cm b(y);
                                inch res;
                                res = a/b;
                                cout<<"\n\na / b = "<<res.data<<" in\n";
                                break;
                                }
                        case 2: {
                                inch b(y),res;
                                res = a/b;
                                cout<<"\n\na / b = "<<res.data<<" in\n";
                                break;
                                }
                        case 3: {
                                feet b(y),res;
                                res = b/a;
                                cout<<"\n\na / b = "<<1/res.data<<" ft\n";
                                break;
                                }
                        case 4: {
                                m b(y),res;
                                res = b/a;
                                cout<<"\n\na / b = "<<1/res.data<<" m\n";
                                break;
                                }
                        case 5: {
                                km b(y),res;
                                res = b/a;
                                cout<<"\n\na / b = "<<1/res.data<<" km\n";
                                break;
                                }
                        default:cout<<"\nWRONG INPUT!\n";
                                exit(0);
                    }
                }break;
                case 3:
                {   feet a(x);
                    switch(op2)
                    {   case 1: {
                                cm b(y);
                                feet res;
                                res = a/b;
                                cout<<"\n\na / b = "<<res.data<<" ft\n";
                                break;
                                }
                        case 2: {
                                inch b(y);
                                feet res;
                                res = a/b;
                                cout<<"\n\na / b = "<<res.data<<" ft\n";
                                break;
                                }
                        case 3: {
                                feet b(y),res;
                                res = a/b;
                                cout<<"\n\na / b = "<<res.data<<" ft\n";
                                break;
                                }
                        case 4: {
                                m b(y),res;
                                res = b/a;
                                cout<<"\n\na / b = "<<1/res.data<<" m\n";
                                break;
                                }
                        case 5: {
                                km b(y),res;
                                res = b/a;
                                cout<<"\n\na / b = "<<1/res.data<<" km\n";
                                break;
                                }
                        default:cout<<"\nWRONG INPUT!\n";
                                exit(0);
                    }
                }break;
                case 4:
                {   m a(x);
                    switch(op2)
                    {   case 1: {
                                cm b(y);
                                m res;
                                res = a/b;
                                cout<<"\n\na / b = "<<res.data<<" m\n";
                                break;
                                }
                        case 2: {
                                inch b(y);
                                m res;
                                res = a/b;
                                cout<<"\n\na / b = "<<res.data<<" m\n";
                                break;
                                }
                        case 3: {
                                feet b(y);
                                m res;
                                res = a/b;
                                cout<<"\n\na / b = "<<res.data<<" m\n";
                                break;
                                }
                        case 4: {
                                m b(y),res;
                                res = a/b;
                                cout<<"\n\na / b = "<<res.data<<" m\n";
                                break;
                                }
                        case 5: {
                                km b(y),res;
                                res = b/a;
                                cout<<"\n\na / b = "<<1/res.data<<" km\n";
                                break;
                                }
                        default:cout<<"\nWRONG INPUT!\n";
                                exit(0);
                    }
                }break;
                case 5:
                {   km a(x);
                    switch(op2)
                    {   case 1: {
                                cm b(y);
                                km res;
                                res = a/b;
                                cout<<"\n\na / b = "<<res.data<<" km\n";
                                break;
                                }
                        case 2: {
                                inch b(y);
                                km res;
                                res = a/b;
                                cout<<"\n\na / b = "<<res.data<<" km\n";
                                break;
                                }
                        case 3: {
                                km res;
                                feet b(y);
                                res = a/b;
                                cout<<"\n\na / b = "<<res.data<<" km\n";
                                break;
                                }
                        case 4: {
                                km res;
                                m b(y);
                                res = a/b;
                                cout<<"\n\na / b = "<<res.data<<" km\n";
                                break;
                                }
                        case 5: {
                                km b(y),res;
                                res = a/b;
                                cout<<"\n\na / b = "<<res.data<<" km\n";
                                break;
                                }
                        default:cout<<"\nWRONG INPUT!\n";
                                exit(0);
                    }
                }break;
            }
        }break;
        default:cout<<"\nWRONG INPUT!\n";
                break;
    }
    return 0;
}
