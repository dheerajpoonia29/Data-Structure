#include "..\macro.h"
using namespace std;

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

class Iterative{
	public:

    BstNode* getNewNode(int data) {
        BstNode* newNode = new BstNode(data);
        return newNode;
    }

    BstNode* insertNodeIte(BstNode* root, int data){
        BstNode* new_node = getNewNode(data);

        if(root==nullptr)   return new_node;

        BstNode* head = root;
        BstNode* temp = root;
        BstNode* parent = nullptr;
        while(temp){
            parent = temp;
            if(data<=temp->data)    temp = temp->left;
            else    temp = temp->right;
        }
        if(data<=parent->data)  parent->left = new_node;
        else    parent->right = new_node;

        return head;
    }

    bool searchIte(BstNode*root, int key){
        BstNode* itr;
        itr = root;
        while(itr){
            if(itr->data==key)  return true;
            else if(key < itr->data) itr = itr->left;
            else itr = itr->right;
        }
        return false;
    }

    void levelorderIte(BstNode* root){
        BstNode* parent;
        queue<BstNode*> qu;
        qu.push(root);
        DBx_line(root->data);
        while(!qu.empty()){
            parent = qu.front();
            qu.pop();
            if(parent->left){
                qu.push(parent->left);
                DBx_line(parent->left->data);
            }
            if(parent->right){
                qu.push(parent->right);
                DBx_line(parent->right->data);
            }
        }
    }

    void preorderIte(BstNode* root){
    }

    void inorderIte(BstNode* root){
    }

    void postorderIte(BstNode* root){
    }

    int searchMaxIte(BstNode* root){
        BstNode* parent;
        while(root){
            parent = root;
            root = root->right;
        }
        return parent->data;
    }

    int searchMinIte(BstNode* root){
        BstNode* parent;
        while(root){
            parent = root;
            root = root->left;
        }
        return parent->data;
    }

    int heightIte(BstNode* root, int node){
        int level = 0;

        queue<BstNode*> q1, q2;
        q1.push(root);
        if(root->left)  q2.push(root->left);
        if(root->right)     q2.push(root->right);

        if(root->left || root->right)
            level = 1;

        while(!q2.empty()){
            q1 = q2;
            while(!q2.empty())  q2.pop();

            while(!q1.empty()){
                if(q1.front()->left)    q2.push(q1.front()->left);
                if(q1.front()->right)   q2.push(q1.front()->right);
                q1.pop();
            }
            if(!q2.empty())
                level++;
        }
        return level;
    }

    BstNode* deleteNodeIte(BstNode* root, int data){

        return root;
    }

    BstNode* lcs(BstNode* root, int v1, int v2){
    	if(root==nullptr)   return root;

        while(root){
            if(root->data==v1 || root->data==v2)
                return ans;
            else if(root->data>v1 && root->data>v2){
                ans = root;
                root = root->left;
            }
            else if(root->data<v1 && root->data<v2){
                ans = root;
                root = root->right;
            }
            else{
                return root;
            }
        }
        return root;
    }

};

class BinarySearchTree: public Recursive, public Iterative{
	
	int *arr, n, i;

	public:

    BstNode* root;

    BinarySearchTree(int arr[], int n){
        this->n = n;
        this->arr = new int[this->n];
        this->arr = arr;

        root = nullptr;
    }

	
    build(string implement_choice){
        i=0;
            //iterative implementation
            root = insertNodeIte(root,arr[0]);
            for(int i=1; i<n; i++)
                insertNodeIte(root,arr[i]);        
    }

    traversal(string implement_choice, string traversal_type){
        
            //iterative implementation
            if(traversal_type.compare("preorder")==0){
                DBmsg("preorderIte: ")
                preorderIte(root);
            }
            else if(traversal_type.compare("inorder")==0){
                DBmsg("inorderIte: ")
                inorderIte(root);
            }
            else if(traversal_type.compare("postorder")==0){
                DBmsg("postorderIte: ")
                postorderIte(root);
            }
            else if(traversal_type.compare("levelorder")==0){
                DBmsg("levelorderIte: ");
                levelorderIte(root);
            }
            else{
                DBmsg("Oops something wrong !");
    }
	
    string searchEle(string implement_choice, int key){
        return searchIte(root,key)? "found" : "not found";
    }
	
    int searchMinMaxEle(string implement_choice, int choice){
        return searchMaxIte(root); else return searchMinIte(root);
    }
	
    int heightOfNode(string implement_choice, int node_x){
        return heightIte(root,node_x);
    }

    void removeNode(string implement_choice, int node_x){
        deleteNodeIte(root,node_x);
    }

    int totalMaxSumOfEveryNode(string implement_choice, int node_data){
        
    }

    int maxSumPath(string implement_choice){
        
    }

    ~BinarySearchTree(){
        delete [] arr;
        arr = NULL;
    };
};

