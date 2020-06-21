#include<bits/stdc++.h>
using namespace std;
class node
{
public:
	int data;
	node *left;
	node *right;
	int height;
};
struct node *root=NULL;


node *create(int x)
{
	node *temp=new node();
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	temp->height=1;
	return temp;
}
int height(node *n)
{
	if(n==NULL)
		return 0;
	return n->height;
}
int dia(node *root)
{
	if(root==NULL)
		return 0;
	int lldia=dia(root->left);
	int ridia=dia(root->right);
	int lh=height(root->left);
	int rh=height(root->right);
	return max(lh+rh+1,max(lldia,ridia));
}



node *insert(node *root,int x)
{
	
	if(root==NULL)
		return (create(x));
	else if(root->data>=x)
		root->left=insert(root->left,x);
	else if(root->data<x)
		root->right=insert(root->right,x);
	root->height=max(height(root->left),height(root->right))+1;
	return root;

}
void preorder(node *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" "<<root->height<<endl;
		preorder(root->left);
		preorder(root->right);
	}
}

int main()
{
	int option=1,k,choice;
	while(option)
     {
     	cout<<"What operation u want to perform \n 1.Insert \n 2.EXIT\n ";
     	cin>>choice;
     	switch(choice)
     	{
     		case 1:
     		cout<<"Enter the key u want to insert\n";
     		cin>>k;
     		root=insert(root,k);
     		break;
     		case 2:
     		option=0;
     	}
     }
     preorder(root);
     cout<<dia(root)<<endl;
     return 0;
}

