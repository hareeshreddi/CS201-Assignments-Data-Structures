/* 150101044
   SRIKAR PARUCHURU
   1.cpp
*/ 
#include <iostream>
#include <vector>
using namespace std;
//bounded by O(m+nlogn) m is no of makeset n is no of union
//set structure
struct set;
//node structure
struct node
{
	int data;
	node* next;
	//represenrative of group
	set* head;
};
struct set
{
	//stores address of head of list
	node* first;
	//stores address of tail of list
	node* last;
	int length;
};
//makeset func takes O(1) time
void makeset(int x,node* nodeaddress[],vector<set*>& sets)
{
	set* s=new set;
	node* n=new node;
	n->data=x;
	n->next=NULL;
    s->first=n;
    s->last=n;
    s->length=1;
    n->head=s;
    //every node address is stored in an array for faster access
    nodeaddress[x]=n;
    sets.push_back(s);
}

//find set returns set pointer of a node in a list
//takes O(1) time;O(n) memory
set* findset(int x,node* nodeaddress[])
{
	return nodeaddress[x]?nodeaddress[x]->head:0; 
}

//combines two disjoint sets
//takes O(s2.length) time where s2 is the smaller list
//this is the weighted union heuristic
void Union(int x,int y,node* nodeaddress[])
{
	set *s1,*s2,*t;
	s1=findset(x,nodeaddress);
	s2=findset(y,nodeaddress);
	
	//if x,y belong to same set or x,y are not in any set
	//union is invalid
	if(s1==0||s2==0||s1==s2)
	{
		cout<<"Invalid union\n";
		return;
	}
	//s1 is the larger list
	if(s1->length < s2->length)
	{
		t=s1;
		s1=s2;
		s2=t;
	}
    //all elements of s2 have their heads updated to rep of s1
    //s2 list is appended to s1 list
    //s2 length is added to s1
    //s2 is deleted
    node* temp=s1->last;
    temp->next=s2->first;
    s1->last=s2->last;
    temp=s2->first;
    while(temp!=NULL)
    {
    	temp->head=s1;
    	temp=temp->next;
    }
    s1->length+=s2->length;
    delete(s2);
    s2->length=0;
}
//displays the disjoint sets
void display(vector<set*> sets)
{
	int n=sets.size();
	for(int i=0;i<n;i++)
	{
		if(sets[i]->length!=0)
		{
			node* temp=sets[i]->first;
			while(temp!=NULL)
			{
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<"   ";
		}
	}
    cout<<"\n";
}

int main()
{
	int x,y,n;
	char a;
	vector<set*> sets;
	//nodeaaddress array stores the address of all nodes for faster access
	node* nodeaddress[1000]={0};
	set* z;
	cout<<"enter the number of inputs\n";
	cin>>n;
	cout<<"enter "<<n<<" distinct numbers\n";
	for(int i=0;i<n;i++)
	{
		cin>>x;
		makeset(x,nodeaddress,sets);
	}
	cout<<"the initial sets are\n";
	display(sets);
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
	    		    z=findset(x,nodeaddress);
	    			if(z)
	    				cout<<"the element belongs to the set  "<<z->first->data<<endl;
	    			else
	    				cout<<"Invalid input\n";
	    			break;
	    	case 'U':
	    	case 'u':
	    	case '2':  		
	    	  		cout<<"enter two elements of two different sets u want to combine\n";
	    	  		cin>>x>>y;
	    	  		Union(x,y,nodeaddress);
	    			cout<<"The sets formed after the union are\n";
	    			display(sets);
	    			break;
	    	case 'Q':
	    	case 'q':
		    		return 0;
	    }
	}
}