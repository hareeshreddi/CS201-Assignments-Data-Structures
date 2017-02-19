/* SRIKAR PARUCHURU
	150101044
	2.cpp
*/
#include <iostream>
#include <vector>
using namespace std;
//disjoint set with union rank and compressed path heuristics
//typical node
struct node
{
	int data;
	int rank;
	node* parent;
    vector<int> children;
    bool status;
};
//list of nodes
//make set takes O(1) time
void makeset(int x,node* nodeaddress[],vector<node*>* list)
{
	node* n=new node;
	n->data=x;
	n->rank=0;
	n->parent=n;
	//chldren consists of children of n
	n->children.push_back(x);
	//status true implies n is a parent
	n->status=true;
	nodeaddress[x]=n;
    list->push_back(n);
}

//takes O(rank) time
//returns the address of root and also connects n to root
//it's a two pass algo
node* findset(node* n)
{
	if(n->parent!=n)
		n->parent=findset(n->parent);
	else
		return n;
}

//the smaller tree root is linked to larger tree root
void Union(int x,int y,node* nodeaddress[])
{
	node *n1,*n2;
	int s;
	n1=findset(nodeaddress[x]);
	n2=findset(nodeaddress[y]);
    if(n1==n2)
    {
    	cout<<"Invalid union\n";
    	return;
    }
    if(n1->rank > n2->rank)
    {
    	n2->parent=n1;
    	//n2 is no longer a parent hence the status is false
    	n2->status=false;
    	s=n2->children.size();
    	for(int i=0;i<s;i++)
    	{
    		n1->children.push_back(n2->children[i]);
    	}
    }
    else
    {
    	n1->parent=n2;
    	n1->status=false;
    	s=n1->children.size();
    	for(int i=0;i<s;i++)
    	{
    		n2->children.push_back(n1->children[i]);
    	}
        if(n1->rank==n2->rank)
        	n2->rank+=1;
    }
}

//displays data
void display(vector<node*> list)
{
	int n=list.size();
	for(int i=0;i<n;i++)
	{
		if(list[i]->status==true)
		{
			int n1=list[i]->children.size();
			for(int j=0;j<n1;j++)
				cout<<list[i]->children[j]<<" ";
			cout<<"   ";
		}
	}
	cout<<endl;
}

int main()
{
	char a;
	int x,y,n;
	node* z;
	vector<node*> list;
	//stores address of nodes
	node* nodeaddress[1000]={0};
	cout<<"enter the number of inputs\n";
	cin>>n;
	cout<<"enter "<<n<<" distinct numbers\n";
	for(int i=0;i<n;i++)
	{
		cin>>x;
		makeset(x,nodeaddress,&list);
	}
	cout<<"the initial sets are \n";
	display(list);
	cout<<"************************************\n";
	cout<<"MENU:\n";
	cout<<"f/F/1  :  FINDSET\n";
	cout<<"u/U/2  :  UNION\n";
	cout<<"q/Q  :  Exit\n";
	cout<<"************************************\n";
	while(1)
	{
		cout<<"enter ur choice\n";
		cin>>a;
	    switch(a)
	    {
	    	case 'F':
	    	case 'f':
	    	case '1':		
	    			cout<<"enter element whose set rep is required\n";
	    			cin>>x;
	    		    if(nodeaddress[x])
	    				cout<<"the element belongs to the set  "<<findset(nodeaddress[x])->data<<endl;
	    			else
	    				cout<<"Invalid input\n";
	    			break;
	    	case 'U':
	    	case 'u':
	    	case '2':  		
	    	  		cout<<"enter two elements of two different sets u want to combine\n";
	    	  		cin>>x>>y;
	    	  		if(nodeaddress[x]!=0&&nodeaddress[y]!=0)
	    	  			Union(x,y,nodeaddress);
	    			else
	    				cout<<"invalid union\n";
	    			cout<<"The sets formed after the union are\n";
	    			display(list);
	    			break;
	    	case 'Q':
	    	case 'q':
		    		return 0;
	    }
	}
}
