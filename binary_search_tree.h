#include "..\tools\macros.h"
using namespace std;

class RecursiveBinarySearchTree;
/*-----------------------------------
    BinarySearchTree bst(arr,n);

    //-------------- BUILDING BST -------------------------------
    DBsep1()
    bst.build("recursive");
    bst.traversal("iterative","levelorder");
    bst.traversal("recursive","levelorder");
    DBsep2()

    //-------------- TRAVERSAL BST -------------------------------
    DBsep1()
    bst.traversal("recursive","preorder");
    bst.traversal("recursive","inorder");
    bst.traversal("recursive","postorder");
    DBsep2()

    //------------- SEARCHING IN BST ----------------------------
    DBsep1()
    DBx(bst.searchEle("recursive", 9))
    DBx(bst.searchEle("iterative", 2))
    DBsep2()

    //------------- FINDING MIN & MAX ELE IN BST ----------------
    DBsep1()
    DBx(bst.searchMinMaxEle("recursive",0)) //1 max
    DBx(bst.searchMinMaxEle("recursive",1)) //1 max
    DBx(bst.searchMinMaxEle("iterative",0)) //0 min
    DBx(bst.searchMinMaxEle("iterative",1)) //0 min
    DBsep2()

    //------------- FINDING HEIGHT OF NODE----------------
    // height of node = no of edges from longest path from node to lead
    // height of root = no of edges from longest path from root to leaf
    DBsep1()
    DBx(bst.heightOfNode("iterative", 4));
    DBx(bst.heightOfNode("recursive", 4));
    DBsep2();
------------------------------------*/
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
//done
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
//done
    bool searchRec(BstNode* root, int data){
        if(root==nullptr)   return false;

        else if(root->data == data)   return true;
        else if( data <= root->data )  searchRec(root->left, data);
        else   searchRec(root->right, data);
    }

    void levelorderRec(BstNode* root){

    }
//done
    void preorderRec(BstNode* root){
        if(root==nullptr)   return;
        DBx_line(root->data);
        preorderRec(root->left);
        preorderRec(root->right);
    }
//done
    void inorderRec(BstNode* root){
        if(root==nullptr)   return;
        preorderRec(root->left);
        DBx_line(root->data);
        preorderRec(root->right);
    }
//done
    void postorderRec(BstNode* root){
        if(root==nullptr)   return;
        preorderRec(root->left);
        preorderRec(root->right);
        DBx_line(root->data);
    }
//done
    int searchMaxRec(BstNode* root){
        if(root->right==nullptr)    return root->data;
        return (searchMaxRec(root->right));
    }
//done
    int searchMinRec(BstNode* root){
        if(root->left==nullptr)       return root->data;
        return searchMinRec(root->left);
    }
//done
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

class Iterative{
public:

    BstNode* getNewNode(int data) {
        BstNode* newNode = new BstNode(data);
        return newNode;
    }
//done
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
//done
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
//done
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
//done
    int searchMaxIte(BstNode* root){
        BstNode* parent;
        while(root){
            parent = root;
            root = root->right;
        }
        return parent->data;
    }
//done
    int searchMinIte(BstNode* root){
        BstNode* parent;
        while(root){
            parent = root;
            root = root->left;
        }
        return parent->data;
    }
//done
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
};

class BinarySearchTree: public Recursive, public Iterative{


    string data_st_name = "BinarySearchTree";
    string space_complexity = "bigO(logn)";
    string time_complexity = "bigO(logn)";

    int *arr, n, i;

public:

    BstNode* root;

    BinarySearchTree(int arr[], int n){
        this->n = n;
        this->arr = new int[this->n];
        this->arr = arr;

        root = nullptr;

        DBsep1()
        DBx(data_st_name)
        i=0;
        DBarr(arr,i,n)
        DBsep2()
    }

//done
    build(string implement_choice){
        i=0;
        if(implement_choice.compare("recursive")==0){
            //recursive implementation
            root = insertNodeRec(root,arr[0]);
            i=1;
            fo(i,n)
                insertNodeRec(root,arr[i]);
        }
        else{
            //iterative implementation
            root = insertNodeIte(root,arr[0]);
            for(int i=1; i<n; i++)
                insertNodeIte(root,arr[i]);
        }
    }

    traversal(string implement_choice, string traversal_type){
        //preorder = data, left, right
        //inorder = left, data, right
        //postorder = left ,right, data
        if(implement_choice.compare("recursive")==0){
            //recursive implementation
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
        else{
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
        }
        cout<<"\n";
    }
//done
    string searchEle(string implement_choice, int key){
        if(implement_choice.compare("recursive")==0)    return searchRec(root, key)? "found" : "not found";
        else    return searchIte(root,key)? "found" : "not found";
    }
//done
    int searchMinMaxEle(string implement_choice, int choice){
        if(implement_choice.compare("recursive")==0)  if(choice) return searchMaxRec(root); else return searchMinRec(root);
        else  if(choice) return searchMaxIte(root); else return searchMinIte(root);
    }
//done
    int heightOfNode(string implement_choice, int node_x){
        if(implement_choice.compare("recursive")==0)  return heightRec(root,node_x);
        else  return heightIte(root,node_x);
    }

    void removeNode(string implement_choice, int node_x){
        if(implement_choice.compare("recursive")==0) root = deleteNodeRec(root,node_x);
        else  root =  deleteNodeIte(root,node_x);
    }

    int totalMaxSumOfEveryNode(string implement_choice, int node_data){
        while(root){
            if(root->data==node_data){
                if(implement_choice.compare("recursive")==0)  return maxNodeSumRec(root);
                else  return -5;
            }
            else if(root->data<node_data)   root = root->right;
            else    root = root->left;
        }
        return -1;
    }

    int maxSumPath(string implement_choice){
        //wrong
        if(implement_choice.compare("recursive")==0)  return maxNodeSumRec(root->left) + root->data + maxNodeSumRec(root->right);
        else  return -5;
    }

    ~BinarySearchTree(){
        delete [] arr;
        arr = NULL;
    };
};

