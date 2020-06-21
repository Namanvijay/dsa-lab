#include<iostream>
using namespace std;
class treeNode
{
	public:
		int data;
		treeNode* left;
		treeNode* right;
		treeNode(int x)
		{
			data=x;
			left=NULL;
			right=NULL;
		}
};
treeNode* insert(treeNode* root, int x)
{
	treeNode* temp=root;
	treeNode* new_node=new treeNode(x);
	if(root==NULL)
	{
		root=new_node;
		return root;
	}
	if(temp->left==NULL&&x<temp->data)
	{
		temp->left=new_node;
		return root;
	}
	if(temp->right==NULL&&x>temp->data)
	{
		temp->right=new_node;
		return root;
	}
	if(x<temp->data)
	{
		temp=insert(temp->left,x);
		return root;
	}
	if(x>temp->data)
	{
		temp=insert(temp->right,x);
		return root;
	}
	return root;
}
void printlist(treeNode* root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	printlist(root->left);
	printlist(root->right);
}
int min(treeNode* root)
{
	treeNode* temp=root;
	if(root==NULL)
		return -1;
	while(temp->left!=NULL)
		temp=temp->left;
	return temp->data;
}
int max(treeNode* root)
{
	treeNode* temp=root;
	if(root==NULL)
		return -1;
	while(temp->right!=NULL)
		temp=temp->right;
	return temp->data;
}
treeNode* search(treeNode* root, int x)
{
	if(root->data==x)
		return root;
	if(x<root->data)
	{
		if(root->left==NULL)
			return NULL;
		return search(root->left,x);
	}
	if(root->right==NULL)
		return NULL;
	return search(root->right,x);
}
int sucsr(treeNode* root,int x)
{
	if(root==NULL)
		return -1;
	treeNode* temp=NULL;
	temp=search(root,x);
	if(temp==NULL)
	{
		cout<<"Given element does not exist!!\n";
		return -1;
	}
	if(temp->data==max(temp))
	{
		cout<<"Given element is maximum!!\n";
		return -1;
	}
	if(temp->right!=NULL)
	{
		int s;
		s=min(temp->right);
		return s;
	}
	treeNode *succ = NULL;  
    	while (root != NULL) 
    	{ 
        	if (temp->data< root->data) 
        	{ 
            		succ = root; 
            		root = root->left; 
        	} 
        	else if (temp->data > root->data) 
            		root = root->right; 
        	else
           		break; 
	} 
  	return succ->data;
}
int prdsr(treeNode* root,int x)
{
	if(root==NULL)
		return -1;
        treeNode* temp=NULL;
        temp=search(root,x);
        if(temp==NULL)
        {
                cout<<"Given element does not exist!!\n";
                return -1;
        }
	if(temp->data==min(temp))
	{
		cout<<"Given element is minimum!!\n";

		return -1;
	}
        if(temp->left!=NULL)
        {
                int s;
                s=max(temp->left);
                return s;
        }
        treeNode *prdcr = NULL;
        while (root != NULL)
        {
                if (temp->data<root->data)
                        root = root->left;
                else if (temp->data > root->data)
		{
			prdcr=root;
                        root = root->right;
		}
                else
                        break;
        }
        return prdcr->data;
}
treeNode* del(treeNode* root,int x)
{
	if(root==NULL)
		return root;
	if(x<root->data)
		root->left=del(root->left,x);
	else if(x>root->data)
		root->right=del(root->right,x);
	else
	{
		if(root->left==NULL)
		{
			treeNode* temp=root->right;
			free(root);
			return temp;
		}
		if(root->right==NULL)
		{
			treeNode* temp=root->left;
			free(root);
			return temp;
		}

		int temp=sucsr(root,x);
		root->data=temp;
		root->right=del(root->right,temp);
	}
	return root;

}

int main()
{
	treeNode* root=NULL;
	int ch;
	do{
	cout<<"MENU\n1.Insert\n2.Minimum\n3.Maximum\n4.Successor\n5.Predecessor\n6.Printlist\n7.Search\n8.Delete\n9.Exit\nChoose your option:";
	cin>>ch;
	switch(ch)
	{
		case 1:cout<<"Enter element:";
		       int x;
		       cin>>x;
		       root=insert(root,x);
		       break;
		case 2:int mini;
		       mini=min(root);
		       if(mini==-1)
			       cout<<"Empty tree\n";
		       else
		       cout<<mini<<endl;
		       break;
		case 3:int maxi;
		       maxi=max(root);
		        if(maxi==-1)
                               cout<<"Empty tree\n";
                       else
		       cout<<maxi<<endl;
		       break;
		case 4:int z,succ;
		       cout<<"Enter data:";
		       cin>>z;
		       succ=sucsr(root,z);
		       if(succ==-1)
			       cout<<"Given element does not exist!!\n";
		       else
			       cout<<succ<<endl;
		       break;
		case 5:int a,pr;
		       cout<<"enter element:";
		       cin>>a;
		       pr=prdsr(root,a);
		       if(pr==-1)
			       cout<<"Given element does not exist!!\n";
		       else
			       cout<<pr<<endl;
		       break;
		case 6:printlist(root);
		       cout<<endl;
		       break;
		case 7:int y;
		       cout<<"enter element you want to search:";
		       cin>>y;
		       treeNode* temp;
		       temp=search(root,y);
		       if(temp==NULL)
			       cout<<"Not found!\n";
		       else
			       cout<<"Found!!\n";
		       break;
		case 8:int u;
		       cout<<"Enter element:";
		       cin>>u;
		       root=del(root,u);
		       cout<<"deleted\n";
		       break;
		case 9:exit(1);
		       break;
		default:cout<<"Wrong input\n";
	}
	}while(ch!=9);
	return 0;
}
