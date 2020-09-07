#include<iostream>
using namespace std;
struct node
{
    char val;
    node* right;
    node* left;
};
class stptr
{
    node** sn = new node*[40];
    int top;
    public:
        stptr()
		{	
			top = -1;
		}
        void push(node* temp)
		{
            if(top >= 40)
                cout<<"\nERROR! OVERFLOW.";
            else
            {
            	top+=1;
            	sn[top]= temp;
        	}
        }
        node* pop()
		{
            if(top==-1)
			{
                return NULL;
            }
            node* temp=sn[top];
            top-=1;
            return temp;
        }
        int isempty()
		{
            if(top==-1)
                return -1;
            return 1;
        }
};
class tree
{
    	node* root;
    	node* cp;
    public:
        tree()
		{
			root=NULL;
		}
        
        void start_tree(char x)
		{
            root = new node;
            root->val=x;
            root->left=NULL;
            root->right=NULL;
            cp=root;
        }
        void add_node(char value,char pos)
		{
            node* ptr=new node;
            ptr->left=NULL;
            ptr->right=NULL;
            ptr->val=value;
            if(pos=='L')
                cp->left=ptr;
            if(pos=='R')
                cp->right=ptr;
            cp=ptr;
        }
        void inorder(node *tr)
		{
            if((tr->left==NULL && tr->right==NULL)==0)
                cout<<"(";
            if(tr->left!=NULL)
                inorder(tr->left);
            cout<<tr->val;
            if(tr->right!=NULL)
                inorder(tr->right);
            if((tr->left==NULL && tr->right==NULL)==0)
            cout<<")";
        }
        node* return_root()
		{
            return root;
        }
        node* return_cp()
		{
            return cp;
        }
        void set_cp(node* temp)
		{
            cp=temp;
        }
};

int main()
{
    stptr ptrstck;
    tree exp;
    char ch,ch2;
    cout<<"Enter the Value/Operator at Root: ";
    cin>>ch2;
    exp.start_tree(ch2);
    ptrstck.push(exp.return_cp());
    cout<<"Select L/R/(N for Return): ";
    while(1)
	{
        cin>>ch;
        if(ch=='L')
		{
            if(exp.return_cp()->left==NULL)
			{
                ptrstck.push(exp.return_cp());
                cout<<"Enter the Value/Operator: ";
                cin>>ch2;
                exp.add_node(ch2,'L');
                cout<<"Current Sub-tree Root: "<<exp.return_cp()->val<<endl;
            }
            else
			{
                if(ch=='L')
				{
                    cout<<"Selected Node is Filled!\nSelect (Right(R)/Return(N)): ";
                    cin>>ch;
                }
            }
        }
        if(ch=='R')
		{
            if(exp.return_cp()->right==NULL)
			{
                ptrstck.push(exp.return_cp());
                cout<<"Enter the Value/Operator: ";
                cin>>ch2;
                exp.add_node(ch2,'R');
                cout<<"Current Sub-tree Root:  "<<exp.return_cp()->val<<endl;
            }
            else
			{
                while(ch=='R')
				{
                    if(exp.return_cp()->left==NULL)
                        cout<<"Selected Node is Filled!\nSelect (Left(L)/Return(N)): ";
                    else cout<<"Selected Node is Filled!\nSelect (Return(N)): ";
                    cin>>ch;
                    if(ch=='L')
					{
                            if(exp.return_cp()->left==NULL)
							{
                            	ptrstck.push(exp.return_cp());
                            	cout<<"Enter the Value/Operator: ";
                            	cin>>ch2;
                            	exp.add_node(ch2,'L');
                            	cout<<"Current Sub-tree Root:"<<exp.return_cp()->val<<endl;
                        	}
                    }
                }
            }
        }
        char x = exp.return_cp()->val;
        if(ch=='N')
		{
            exp.set_cp(ptrstck.pop());
            cout<<"Current Sub-tree Root:  "<<exp.return_cp()->val<<endl;
        }
        if(ptrstck.isempty()==-1)
           break;
        cout<<"Select L/R/(N for Return): ";
    }
    exp.inorder(exp.return_root());
}
