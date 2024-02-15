#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data ;
    struct Node *lchild; 
    struct Node *rchild;
};



struct Node *Preorder(struct Node *root){
    
    if (root){
        printf("%d ",root -> data);
        Preorder(root -> lchild);
        Preorder(root -> rchild);
    }
}

struct Node *Inorder(struct Node *root){
    
    if (root){
        Inorder(root -> lchild);
        printf("%d ",root -> data);
        Inorder(root -> rchild);
    }
}

/*struct Node *DisplayPostorder(struct Node *root){
    
    if (root){
        Postorder(root -> lchild);
        Postorder(root -> rchild);
        printf("%d ",root -> data);
    }
}

struct Node *CreatePreorder(struct Node *root){
    
    if (root){
        struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
        printf("Enter the value of ",root -> data);
        Preorder(root -> lchild);
        Preorder(root -> rchild);
    }
}

struct Node *CreateInorder(struct Node *root){
    
    if (root){
        Inorder(root -> lchild);
        printf("%d ",root -> data);
        Inorder(root -> rchild);
    }
}

struct Node *CreatePostorder(struct Node *root){
    
    if (root){
        Postorder(root -> lchild);
        Postorder(root -> rchild);
        printf("%d ",root -> data);
    }
}*/

struct Node *BST_Search(struct Node *t,int key){
    if (t == NULL)
        return NULL;
    if(key == t -> data)
        return t;
    else if (key < t -> data)
        BST_Search(t -> lchild,key);
    else if (key > t -> data)
        BST_Search(t -> rchild,key);
}

struct Node *Insert(struct Node *p,int key){

    struct Node *t;

    if (p == NULL){
        t = (struct Node*) malloc (sizeof(struct Node));
        t -> data = key;
        t -> lchild = NULL;
        t -> rchild = NULL;
        return t;
    }

    if (key < p -> data)
        p -> lchild = Insert(p -> lchild,key);
    else if (key > p -> data)
        p -> rchild = Insert(p -> rchild,key);
    
    return t;
}

int Height(struct Node *p){

    int x,y;
    if (p = NULL)
        return 0;
    
    x = Height (p -> lchild);
    y = Height (p -> rchild);

    if (x > y)
        return x + 1;
    else
        return y + 1;
}

struct Node *InPre (struct Node *p){

    while (p && p -> rchild != NULL)
        p = p -> rchild;
    
    return p;
}

struct Node* InSucc (struct Node*p){

    while (p && p -> lchild != NULL)
        p = p -> lchild;
    
    return p;
}

struct Node *root = NULL;

struct Node *Delete(struct Node *p,int key)
{
    struct Node *q;
 
    if(p==NULL)
        return NULL;
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
            root=NULL;
        free(p);
        return NULL;
        
    }
 
    if(key < p->data)
        p->lchild=Delete(p->lchild,key);
    else if(key > p->data)
        p->rchild=Delete(p->rchild,key);
    else
    {
        if(Height(p->lchild)>Height(p->rchild))
        {
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
 
 
 }
    return p;
}




int main(){
    /*struct Node *A = (struct Node*) malloc(sizeof(struct Node));
    struct Node *B = (struct Node*) malloc(sizeof(struct Node));
    struct Node *C = (struct Node*) malloc(sizeof(struct Node));
    struct Node *D = (struct Node*) malloc(sizeof(struct Node));
    struct Node *E = (struct Node*) malloc(sizeof(struct Node));
    struct Node *F = (struct Node*) malloc(sizeof(struct Node));
    struct Node *G = (struct Node*) malloc(sizeof(struct Node));

    A -> data = 1;
    A -> lchild = B;
    A -> rchild = C;

    B -> data = 2;
    B -> lchild = D;
    B -> rchild = E;

    C -> data = 3;
    C -> lchild = F;
    C -> rchild = G;

    D -> data = 4;
    D -> lchild = NULL;
    D -> rchild = NULL;

    E -> data = 5;
    E -> lchild = NULL;
    E -> rchild = NULL;

    F -> data = 6;
    F -> lchild = NULL;
    F -> rchild = NULL;

    G -> data = 7;
    G -> lchild = NULL;
    G -> rchild = NULL;*/

    //struct Node *root = (struct Node*) malloc(sizeof(struct Node));
    root -> data = 6;
    root ->lchild = NULL;
    root -> rchild = NULL;
    //Preorder(root);
    Insert(root,4);
    Insert(root,3);
    printf("\n");
    Preorder(root);
    printf("\n");
    Delete(root,4);
    //Preorder(root);

    return 0;
}