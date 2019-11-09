#include<iostream>
#include <queue>
using namespace std;

class BinarySearchTree;
class BinarySearchTreeNode{
    friend class BinarySearchTree;
    BinarySearchTreeNode * left, * right;
    int value;
    BinarySearchTreeNode(int data):value(data),left(0),right(0){}
};

class BinarySearchTree{
    BinarySearchTreeNode * root;
    public:
    BinarySearchTree():root(0){}
    void Insert(int data){
        if(root == 0){
            root = new BinarySearchTreeNode(data);
        }
        else{
            BinarySearchTreeNode * child = root;
            BinarySearchTreeNode * parent = 0;
            while(child !=0 ){
                parent = child;
                if(child->value < data){                
                    child = child -> right;
                }
                else if(child->value > data){
                    child = child -> left;
                }
                else{
                    printf("Error\n");
                    return;
                }
            }            
            child = new BinarySearchTreeNode(data);
            if(child->value>parent->value){
                parent -> right = child;
            }
            else{
                parent -> left = child;
            }
        }

    }
    void InOrderTravel(BinarySearchTreeNode * target){
        if(target -> left !=0){
            InOrderTravel(target -> left);
        }
        printf("%d ", target -> value);
        if(target -> right !=0){
            InOrderTravel(target -> right);
        }
    }

    void InOrderPrint(){
        if(root == 0){
            printf("The BST is empty.\n");
        }
        else{
            InOrderTravel(root);
            printf("\n");
        }
    }

    void PreOrderTravel(BinarySearchTreeNode * target){
        printf("%d ", target -> value);
        if(target -> left !=0){
            PreOrderTravel(target -> left);
        }
        if(target -> right !=0){
            PreOrderTravel(target -> right);
        }
    }
    
    void PreOrderPrint(){
        if(root == 0){
            printf("The BST is empty.\n");
        }
        else{
            PreOrderTravel(root);
            printf("\n");
        }
    }

    void PostOrderTravel(BinarySearchTreeNode * target){
        if(target -> left !=0){
            PostOrderTravel(target -> left);
        }
        if(target -> right !=0){
            PostOrderTravel(target -> right);
        }
        printf("%d ", target -> value);
    }
    
    void PostOrderPrint(){
        if(root == 0){
            printf("The BST is empty.\n");
        }
        else{
            PostOrderTravel(root);
            printf("\n");
        }
    }

    void LevelOrderPrint(){
        if (root == 0){
            printf("The BST is empty.\n");            
        }
        else{
            queue<BinarySearchTreeNode *> node;
            node.push(root);
            while(node.size()>0){
                BinarySearchTreeNode * temp = node.front();
                printf("%d ",temp->value);
                if(temp->left!=0)
                    node.push(temp->left);
                if(temp->right!=0)
                    node.push(temp->right);
                node.pop();
            }
            printf("\n");
        }
    }            
};

int main(){
    BinarySearchTree exampleone;
    printf("InOrderTravel\n");
    exampleone.Insert(10);
    exampleone.InOrderPrint();
    exampleone.Insert(8);
    exampleone.InOrderPrint();
    exampleone.Insert(15);
    exampleone.InOrderPrint();
    exampleone.Insert(2);
    exampleone.InOrderPrint();
    BinarySearchTree exampletwo;
    printf("PreTravel\n");
    exampletwo.Insert(10);
    exampletwo.PreOrderPrint();
    exampletwo.Insert(8);
    exampletwo.PreOrderPrint();
    exampletwo.Insert(15);
    exampletwo.PreOrderPrint();
    exampletwo.Insert(2);
    exampletwo.PreOrderPrint();
    BinarySearchTree examplethree;
    printf("PostTravel\n");
    examplethree.Insert(10);
    examplethree.PostOrderPrint();
    examplethree.Insert(8);
    examplethree.PostOrderPrint();
    examplethree.Insert(15);
    examplethree.PostOrderPrint();
    examplethree.Insert(2);
    examplethree.PostOrderPrint();
    BinarySearchTree examplefour;
    printf("LevelOrderTravel\n");
    examplefour.Insert(10);
    examplefour.LevelOrderPrint();
    examplefour.Insert(8);
    examplefour.LevelOrderPrint();
    examplefour.Insert(15);
    examplefour.LevelOrderPrint();
    examplefour.Insert(2);
    examplefour.LevelOrderPrint();
    system("pause");
    return 0;
}