//CH.SC.U4CSE24140 - Rohith S
#include<stdio.h>
#include<stdlib.h>

#define RED 1
#define BLACK 0

struct Node{
	int data;
	int color;
	struct Node*left;
	struct Node*right;
	struct Node*parent;
};

struct Node*root=NULL;

struct Node*newNode(int data){
	struct Node*node=(struct Node*)malloc(sizeof(struct Node));
	node->data=data;
	node->color=RED;
	node->left=NULL;
	node->right=NULL;
	node->parent=NULL;
	return node;
}

void leftRotate(struct Node*x){
	struct Node*y=x->right;
	x->right=y->left;
	if(y->left!=NULL)
		y->left->parent=x;
	y->parent=x->parent;
	if(x->parent==NULL)
		root=y;
	else if(x==x->parent->left)
		x->parent->left=y;
	else
		x->parent->right=y;
	y->left=x;
	x->parent=y;
}

void rightRotate(struct Node*y){
	struct Node*x=y->left;
	y->left=x->right;
	if(x->right!=NULL)
		x->right->parent=y;
	x->parent=y->parent;
	if(y->parent==NULL)
		root=x;
	else if(y==y->parent->left)
		y->parent->left=x;
	else
		y->parent->right=x;
	x->right=y;
	y->parent=x;
}

void fixInsert(struct Node*z){
	while(z!=root && z->parent->color==RED){
		if(z->parent==z->parent->parent->left){
			struct Node*y=z->parent->parent->right;
			if(y!=NULL && y->color==RED){
				z->parent->color=BLACK;
				y->color=BLACK;
				z->parent->parent->color=RED;
				z=z->parent->parent;
			}else{
				if(z==z->parent->right){
					z=z->parent;
					leftRotate(z);
				}
				z->parent->color=BLACK;
				z->parent->parent->color=RED;
				rightRotate(z->parent->parent);
			}
		}else{
			struct Node*y=z->parent->parent->left;
			if(y!=NULL && y->color==RED){
				z->parent->color=BLACK;
				y->color=BLACK;
				z->parent->parent->color=RED;
				z=z->parent->parent;
			}else{
				if(z==z->parent->left){
					z=z->parent;
					rightRotate(z);
				}
				z->parent->color=BLACK;
				z->parent->parent->color=RED;
				leftRotate(z->parent->parent);
			}
		}
	}
	root->color=BLACK;
}

void insert(int data){
	struct Node*z=newNode(data);
	struct Node*y=NULL;
	struct Node*x=root;

	while(x!=NULL){
		y=x;
		if(z->data<x->data)
			x=x->left;
		else
			x=x->right;
	}

	z->parent=y;

	if(y==NULL)
		root=z;
	else if(z->data<y->data)
		y->left=z;
	else
		y->right=z;

	fixInsert(z);
}

int treeHeight(struct Node*node){
	if(node==NULL)
		return 0;
	int lh=treeHeight(node->left);
	int rh=treeHeight(node->right);
	return (lh>rh?lh:rh)+1;
}

void printLevel(struct Node*node,int level){
	if(node==NULL)
		return;
	if(level==1)
		printf("%d(%c) ",node->data,node->color==RED?'R':'B');
	else{
		printLevel(node->left,level-1);
		printLevel(node->right,level-1);
	}
}

void printTree(){
	int h=treeHeight(root);
	for(int i=1;i<=h;i++){
		printf("Level %d: ",i-1);
		printLevel(root,i);
		printf("\n");
	}
}

int checkRootBlack(){
	if(root==NULL)
		return 1;
	return root->color==BLACK;
}

int checkNoRedRed(struct Node*node){
	if(node==NULL)
		return 1;

	if(node->color==RED){
		if((node->left!=NULL && node->left->color==RED) ||
		   (node->right!=NULL && node->right->color==RED))
			return 0;
	}

	return checkNoRedRed(node->left) && checkNoRedRed(node->right);
}

int main(){
	int keys[]={157,110,147,122,149,151,111,141,112,123,133,117};
	int n=sizeof(keys)/sizeof(keys[0]);

	for(int i=0;i<n;i++)
		insert(keys[i]);

	printf("Red-Black Tree Level-wise:\n");
	printTree();

	printf("\nCheck Conditions:\n");

	if(checkRootBlack())
		printf("(i) Root is Black: YES\n");
	else
		printf("(i) Root is Black: NO\n");

	if(checkNoRedRed(root))
		printf("(ii) No Red node has Red child: YES\n");
	else
		printf("(ii) No Red node has Red child: NO\n");

	return 0;
}
