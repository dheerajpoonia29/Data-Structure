#include "..\tools\macros.h"
using namespace std;

class RecursiveBinarySearchTree;

class BinarySearchTree;

class BstNode{
public:
    int data;
    BstNode* left, *right;

    BstNode(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Recursive{
public:

    BstNode* getNewNode(int data) {
        BstNode* newNode = new BstNode(data);
        return newNode;
    }

    BstNode* insertNodeRec(BstNode* root, int data){
        BstNode* new_node = getNewNode(data);

        if(root==nullptr)   return new_node;

        else if(data<=root->data){
            root->left = insertNodeRec(root->left, data);
        }
        else{
            root->right = insertNodeRec(root->right, data);
        }
    }

    bool searchRec(BstNode* root, int data){
        if(root==nullptr)   return false;

        else if(root->data == data)   return true;
        else if( data <= root->data )  searchRec(root->left, data);
        else   searchRec(root->right, data);
    }

    void levelorderRec(BstNode* root){

    }

    void preorderRec(BstNode* root){
        if(root==nullptr)   return;
        DBx_line(root->data);
        preorderRec(root->left);
        preorderRec(root->right);
    }

    void inorderRec(BstNode* root){
        if(root==nullptr)   return;
        preorderRec(root->left);
        DBx_line(root->data);
        preorderRec(root->right);
    }

    void postorderRec(BstNode* root){
        if(root==nullptr)   return;
        preorderRec(root->left);
        preorderRec(root->right);
        DBx_line(root->data);
    }

    int searchMaxRec(BstNode* root){
        if(root->right==nullptr)    return root->data;
        return (searchMaxRec(root->right));
    }

    int searchMinRec(BstNode* root){
        if(root->left==nullptr)       return root->data;
        return searchMinRec(root->left);
    }

    int heightRec(BstNode* root, int node){
        if(root==nullptr)    return -1;
        return max(heightRec(root->left, node)+1,heightRec(root->right, node)+1);
    }

    BstNode* FindMin(BstNode* root)
    {
        while(root->left != NULL) root = root->left;
        return root;
    }

    BstNode* deleteNodeRec(BstNode* root, int data){

        if(root == NULL) return root;
        else if(data < root->data) root->left = deleteNodeRec(root->left,data);
        else if (data > root->data) root->right = deleteNodeRec(root->right,data);
        // Wohoo... I found you, Get ready to be deleted
        else {
            // Case 1:  No child
            if(root->left == NULL && root->right == NULL) {
                delete root;
                root = NULL;
            }
            //Case 2: One child
            else if(root->left == NULL) {
                BstNode *temp = root;
                root = root->right;
                delete temp;
            }
            else if(root->right == NULL) {
                BstNode *temp = root;
                root = root->left;
                delete temp;
            }
            // case 3: 2 children
            else {
                BstNode *temp = FindMin(root->right);
                root->data = temp->data;
                root->right = deleteNodeRec(root->right,temp->data);
            }
        }
        return root;
    }

    int maxNodeSumRec(BstNode* root){
        if(root==nullptr) return 0;
        else root->data;
        // this function find out max sum till any root
        int sum  = root->data+max(maxNodeSumRec(root->left),maxNodeSumRec(root->right));
        //DBxy(root->data,sum);
        return sum;
    }
};


class BinarySearchTree: public Recursive{


  int *arr, n, i;

	public:

    BstNode* root;

    BinarySearchTree(int arr[], int n){
        this->n = n;
        this->arr = new int[this->n];
        this->arr = arr;

        root = nullptr;
    }

	
    build(){
        i=0;        
				root = insertNodeRec(root,arr[0]);
				i=1;
				fo(i,n)
						insertNodeRec(root,arr[i]);
    }

    traversal(string traversal_type){
        
            if(traversal_type.compare("preorder")==0){
                DBmsg("preorderRec: ")
                preorderRec(root);
            }
            else if(traversal_type.compare("inorder")==0){
                DBmsg("inorderRec: ")
                inorderRec(root);
            }
            else if(traversal_type.compare("postorder")==0){
                DBmsg("postorderRec: ")
                postorderRec(root);
            }
            else if(traversal_type.compare("levelorder")==0){
                DBmsg("leveleorderRec: ");
                levelorderRec(root);
            }
            else{
                DBmsg("Oops something wrong !\n");
            }

    }
	
    string searchEle(, int key){
        return searchRec(root, key)? "found" : "not found";
    }
	
    int searchMinMaxEle(int choice){
        if(choice) return searchMaxRec(root); else return searchMinRec(root);  
    }
	
    int heightOfNode(int node_x){
        return heightRec(root,node_x);        
    }

    void removeNode(int node_x){
        root = deleteNodeRec(root,node_x);        
    }

    int totalMaxSumOfEveryNode(int node_data){
        while(root){
            if(root->data==node_data){
                return maxNodeSumRec(root);
                else  return -5;
            }
            else if(root->data<node_data)   root = root->right;
            else    root = root->left;
        }
        return -1;
    }

    int maxSumPath(){
        //wrong
        return maxNodeSumRec(root->left) + root->data + maxNodeSumRec(root->right);
    }

    ~BinarySearchTree(){
        delete [] arr;
        arr = NULL;
    };
};

