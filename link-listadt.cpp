#include<bits/stdc++.h>
using namespace std;
class node
{
public:
	int data;
	node *left;
	node *right;
};struct node* root=NULL;

node* createnode(int x)
{
	node *temp=new node();
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

node *insertnode(node *root,int x)
{
	if(root==NULL)
	{
		return createnode(x);
	}
	else if(root->data<x)
	root->right=insertnode(root->right,x);
	else if(root->data>=x)
	root->left=insertnode(root->left,x);
	
	return root;	

}

bool search(node *root,int x)
{
	if(root==NULL)
		return false;
	if(root->data==x)
		return true;
	if(root->data>x)
		return search(root->left,x);
	else
		return search(root->right,x);
}

int maximum(node *root)
{
	if(root->right==NULL)
		return root->data;
	else
		return maximum(root->right);

}
int minimum(node *root)
{
	if(root->left==NULL)
		return root->data;
	else
		return minimum(root->left);
}

void preorder(node *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
		
	}
}
node *deletenode(node *root,int x)
{
	if(root==NULL)
		return NULL;
	if(root->data==x)
	{
		if(root->left==NULL && root->right==NULL)
			return NULL;
		else if(root->left==NULL)
			return root->right;
		else if(root->right==NULL)
			return root->left;

		else
		{
			root->data=maximum(root->left);
			root->left=deletenode(root->left,root->data);
		}


	}
 
   else if(root->data>x)
   	root->left=deletenode(root->left,x);
   else if(root->data<x)
   	root->right=deletenode(root->right,x);

   return root;

}
node *find(node *root,int x)
{
	if(root==NULL)
		return NULL;
	if(root->data==x)
		return root;
	else if(root->data<x)
		return find(root->right,x);
	else if(root->data>x)
		return find(root->left,x);
}

int succ(node *root,int x)
{
	node * current=find(root,x);
	if(current->right!=NULL)
		return minimum(current->right);
	else
	{
		node * successor=NULL;
		node *ancestor=root;
		int p=maximum(root);
		while(ancestor->data!=current->data)
		{
			if(current->data<ancestor->data)
			{
				successor=ancestor;
				ancestor=ancestor->left;
			}
			else 
				ancestor=ancestor->right;
		}
		if((current->data)==p)
		{
		  	cout<<"Successor do not exist"<<endl;
                return 0;
		}
		else 
			return successor->data;

	}
	
}
int pred(node *root,int x)
{
	node *current=find(root,x);
	if(current->left!=NULL)
		return maximum(current->left);
	else
	{
		int p=minimum(root);
		node *pred=NULL;
		node *ancestor=root;
		if((current->data)==p)
		{
			cout<<"Predecessor do not exist"<<endl;
		   return 0; 

		}
			
		else
		{
                  while(ancestor->right!=current)
                  {
                  	if(current->data<ancestor->data)
                  	{
                             ancestor=ancestor->left;
                  	}
                  	else
                  		ancestor=ancestor->right;
                  }

                  pred=ancestor;
                  return pred->data;
		}
	}

}



int main()
{
	int n,val,ma,mi,a,q;

	do
	{
		cout<<"Enter the operation u want to perform \n 1.Insert \n 2. Search \n 3. Print \n 4.Maximum \n 5.Minimum \n 6.Delete \n 7.Successor\n 8.Predecessor\n 9.Exit"<<endl;
        cin>>n;

   switch(n)
   {
   	  case 1:
   	  cout<<"Enter the value u want to insert"<<endl;
   	  cin>>val;
   	  root=insertnode(root,val);
   	  break;
   	  case 2:
   	  cout<<"Enter the element to be searched"<<endl;
   	  cin>>val;
   	  if(search(root,val))
   	  	cout<<"Element is present"<<endl;
   	  else
   	  	cout<<"Element not found "<<endl;
   	  break;
   	  case 3:
   	  preorder(root);
   	  break;
   	  case 4:
   	   ma=maximum(root);
   	  cout<<"Maximum element is "<<ma<<endl;
   	  break;
   	  case 5:
   	   mi=minimum(root);
   	  cout<<"Minimum element is "<<mi<<endl;
   	  break;
   	  case 6:
   	  cout<<"Enter the element u want to Delete"<<endl;
   	  cin>>val;
   	  root=deletenode(root,val);
   	  break;
   	  case 7:
   	  cout<<"Enter the key whose successor needs to be find"<<endl;
   	  cin>>val;
   	   q=succ(root,val);
	  if(q==0)
		  break;
	  else
	  {
		  cout<<q<<endl;
		  break;
	  }
   	  case 8:
   	  cout<<"Enter the key whose Predecessor needs to be find"<<endl;
   	  cin>>val;
   	  a=pred(root,val);
          if(a==0)
                  break;
          else
          {
                  cout<<a<<endl;
                  break;
          }
   	  case 9:
   	  exit(0);
   }

	}while(1);
	return 0;

}



