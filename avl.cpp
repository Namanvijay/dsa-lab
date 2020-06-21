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
node *rightrotate(node *z)
{
	node *y=z->left;
	node *t3=y->right;
	y->right=z;
	z->left=t3;
	z->height=max(height(z->left),height(z->right))+1;
	y->height=max(height(y->left),height(y->right))+1;
	return y;

}
node *leftrotate(node *z)
{
	node *y=z->right;
	node *t3=y->left;
	y->left=z;
	z->right=t3;
    z->height=max(height(z->left),height(z->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
	
	return y;

}

int getbalance(node *n)
{
    if(n==NULL)
    	return 0;
    return height(n->left)-height(n->right);
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
	 int bf=getbalance(root);
	 if(bf>1 && x<root->left->data)
	 	return rightrotate(root);
	 else if(bf<-1 && x>root->right->data)
	 	return leftrotate(root);
	 else if(bf>1 && x>root->left->data)
	 	{
	 		root->left=leftrotate(root->left);
	 		return rightrotate(root);
	 	}
	 	else if(bf<-1 && x<root->right->data)
	 	{
	 		root->right=rightrotate(root->right);
	 		return leftrotate(root);
	 	}

	 	return root;
	 	



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

		else+
		{
			root->data=maximum(root->left);
			root->left=deletenode(root->left,root->data);
		}


	}
 
   else if(root->data>x)
   	root->left=deletenode(root->left,x);
   else if(root->data<x)
   	root->right=deletenode(root->right,x);

   
   root->height=max(height(root->left),height(root->right))+1;
	 int bf=getbalance(root);
	 if(bf>1 && x<root->left->data)
	 	return rightrotate(root);
	 else if(bf<-1 && x>root->right->data)
	 	return leftrotate(root);
	 else if(bf>1 && x>root->left->data)
	 	{
	 		root->left=leftrotate(root->left);
	 		return rightrotate(root);
	 	}
	 	else if(bf<-1 && x<root->right->data)
	 	{
	 		root->right=rightrotate(root->right);
	 		return leftrotate(root);
	 	}

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
     int option=1,k,s,p,q;
     while(option)
     {
     	cout<<"What operation u want to perform \n 1.Insert \n 2.Delete\n 3.Print \n 4.Maximum\n 5.Minimum\n 6.search\n 7.Successor\n 8.Predecessor\n9.Exit\n";
     	cin>>option;
     	switch(option)
     	{
     		case 1:
     		cout<<"Enter the key u want to insert\n";
     		cin>>k;
     		root=insert(root,k);
     		break;
     		case 2:
     		cout<<"Enter the valur u want to delete\n";
     		cin>>k;
     		root=deletenode(root,k);
     		break;
     		case 3:
     		preorder(root);
     		break;
     		case 4:
     		p=maximum(root);
     		cout<<p<<endl;
     		break;
     		case 5:
     		s=minimum(root);
     		cout<<s<<endl;
     		break;
     		case 6:
     		cout<<"Enter the element u want to search\n";
     		cin>>k;
     		if(search(root,k))
     			cout<<"Element is present in AVL TREE\n";
     		else
     			cout<<"NOT PRESENT\n";
     		break;
     		case 7:
     		cout<<"Enter the key whose successor needs to be find"<<endl;
   	         cin>>k;
   	              q=succ(root,k);
	           if(q==0)
			  break;
	 			 else
	  {
				  cout<<q<<endl;
		  	break;
	  }
	  case 8:
   	  			cout<<"Enter the key whose Predecessor needs to be find"<<endl;
   	  			cin>>k;
   	  			q=pred(root,k);
         		 if(q==0)
                  break;
         		 else
         		 {
                  cout<<q<<endl;
                  break;
         	 }
          	case 9:
          	
     		option=0;
     	}
     }
     return 0;
} 