//Name: RAVI SAHNI
//Faculty No.: 17 COB 085
//Enrollment No.: GJ 7718
//Serial No.: 024
//Course Code: COC3960 (Advanced Computing Lab)
//Experiment R3: Write a program to find the Convex Hull of a set of points

#include<iostream>
using namespace std;

struct struc_pnt
{
    int x, y;
};

struct node
{
    struc_pnt data;
    node *next;
};

bool check_grt(struc_pnt *one, struc_pnt *two, struc_pnt *three)
{
    return (two->x - one->x) * (three->y - one->y) > (two->y - one->y) * (three->x - one->x);
}

int cmpr(const void *left, const void *right)
{
    struc_pnt ple = *((struc_pnt *)left);
    struc_pnt pre = *((struc_pnt *)right);
    if (ple.x < pre.x)
        return -1;
    if (pre.x < ple.x)
    	return 1;
    return 0;
}

void node_free(node *node_point)
{
    if (node_point == NULL)
	{
        return;
    }
    node_free(node_point->next);
    node_point->next = NULL;
    free(node_point);
}

node* pushb(node *node_point, struc_pnt data)
{
    node *temp = node_point;

    if (node_point == NULL)
	{
        node_point = (node*)malloc(sizeof(node));
        node_point->data = data;
        node_point->next = NULL;
        return node_point;
    }

    while (temp->next != NULL)
	{
        temp = temp->next;
    }

    temp->next = (node*)malloc(sizeof(node));
    temp->next->data = data;
    temp->next->next = NULL;
    return node_point;
}

node* popb(node *node_point)
{
    node *temp = node_point;

    if (node_point == NULL)
	{
        return NULL;
    }
    
    if (node_point->next == NULL)
	{
        free(node_point);
        return NULL;
    }

    while (temp->next->next != NULL)
	{
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    
    return node_point;
}

void prnt_node(node *node_point)
{
    cout<<"[";
    if (node_point != NULL)
	{
        cout<<"("<<node_point->data.x<<","<<node_point->data.y<<")";
        node_point = node_point->next;
    }
    
    while (node_point != NULL)
	{
        cout<<", ("<<node_point->data.x<<","<<node_point->data.y<<")";
        node_point = node_point->next;
    }
    cout<<"]";
}

node* find_convex_hull(struc_pnt p[], int size)
{
    node *h = NULL;
    node *hnode_point = NULL;
    size_t hLen = 0;
    qsort(p, size, sizeof(struc_pnt), cmpr);

    for (int i = 0; i < size; ++i)
	{
        while (hLen >= 2)
		{
            hnode_point = h;
            while (hnode_point->next->next != NULL)
			{
                hnode_point = hnode_point->next;
            }
            if (check_grt(&hnode_point->data, &hnode_point->next->data, &p[i]))
			{
                break;
            }
            h = popb(h);
            hLen--;
        }
        h = pushb(h, p[i]);
        hLen++;
    }

    for (int i = size - 1; i >= 0; i--)
	{
        while (hLen >= 2)
		{
            hnode_point = h;
            while (hnode_point->next->next != NULL)
			{
                hnode_point = hnode_point->next;
            }
            if (check_grt(&hnode_point->data, &hnode_point->next->data, &p[i]))
			{
                break;
            }

            h = popb(h);
            hLen--;
        }

        h = pushb(h, p[i]);
        hLen++;
    }

    popb(h);
    return h;
}

int main()
{

    int n;
    cout<<" Enter the no. of points: ";
    cin>>n;
    struc_pnt pnts[n];
    cout<<"\n Input points {x y}:\n\n";
    for(int i = 0; i < n; i++)
	{
		cout<<" Point "<<i+1<<": ";
		cin>>pnts[i].x>>pnts[i].y;
    }

    node *hull = find_convex_hull(pnts, n);
    cout<<"\n Convex Hull is: ";
    prnt_node(hull);
	cout<<endl;
    node_free(hull);
    hull = NULL;
    return 0;
}
