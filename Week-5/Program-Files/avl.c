//CH.SC.U4CSE24140 - Rohith S
#include<stdio.h>
#include<stdlib.h>

struct Node{
	int key;
	struct Node*left;
	struct Node*right;
	int height;
};

int maximum(int a,int b){
	return(a>b)?a:b;
}

int height(struct Node*n){
	if(n==NULL)
		return 0;
	return n->height;
}

struct Node*newNode(int key){
	struct Node*node=(struct Node*)malloc(sizeof(struct Node));
	node->key=key;
	node->left=NULL;
	node->right=NULL;
	node->height=1;
	return node;
}

struct Node*rightRotate(struct Node*y){
	struct Node*x=y->left;
	struct Node*T2=x->right;
	x->right=y;
	y->left=T2;
	y->height=maximum(height(y->left),height(y->right))+1;
	x->height=maximum(height(x->left),height(x->right))+1;
	return x;
}

struct Node*leftRotate(struct Node*x){
	struct Node*y=x->right;
	struct Node*T2=y->left;
	y->left=x;
	x->right=T2;
	x->height=maximum(height(x->left),height(x->right))+1;
	y->height=maximum(height(y->left),height(y->right))+1;
	return y;
}

int getBalance(struct Node*n){
	if(n==NULL)
		return 0;
	return height(n->left)-height(n->right);
}

struct Node*insert(struct Node*node,int key){
	if(node==NULL)
		return newNode(key);

	if(key<node->key)
		node->left=insert(node->left,key);
	else if(key>node->key)
		node->right=insert(node->right,key);
	else
		return node;

	node->height=1+maximum(height(node->left),height(node->right));

	int balance=getBalance(node);

	if(balance>1&&key<node->left->key)
		return rightRotate(node);

	if(balance<-1&&key>node->right->key)
		return leftRotate(node);

	if(balance>1&&key>node->left->key){
		node->left=leftRotate(node->left);
		return rightRotate(node);
	}

	if(balance<-1&&key<node->right->key){
		node->right=rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

int isBalanced(struct Node*root){
	if(root==NULL)
		return 1;

	int bf=getBalance(root);

	if(bf>1||bf<-1)
		return 0;

	return isBalanced(root->left)&&isBalanced(root->right);
}

int treeHeight(struct Node*root){
	if(root==NULL)
		return 0;
	return 1+maximum(treeHeight(root->left),treeHeight(root->right));
}

void printLevel(struct Node*root,int level){
	if(root==NULL)
		return;

	if(level==1)
		printf("%d ",root->key);
	else{
		printLevel(root->left,level-1);
		printLevel(root->right,level-1);
	}
}

void printTreeLevels(struct Node*root){
	int h=treeHeight(root);
	for(int i=1;i<=h;i++){
		printf("Level %d: ",i-1);
		printLevel(root,i);
		printf("\n");
	}
}

int main(){
	struct Node*root=NULL;

	int keys[]={157,110,147,122,149,151,111,141,112,123,133,117};
	int n=sizeof(keys)/sizeof(keys[0]);

	for(int i=0;i<n;i++)
		root=insert(root,keys[i]);

	printf("AVL Tree Level-wise:\n");
	printTreeLevels(root);

	if(isBalanced(root))
		printf("\nAll nodes are balanced. AVL Tree is valid.\n");
	else
		printf("\nTree is NOT balanced.\n");

	return 0;
}
