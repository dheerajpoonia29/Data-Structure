#include <bits/stdc++.h>
#include "../tools/macros.h"
#include "../data_structure/binary_search_tree.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i;
    //int arr[] = {4,2,6,1,3,5,0,-1,-2};
    //int arr[] = {12,9,20,5,11,15,25,6,10,13,18,7,14,8};
    int arr[] = {4,2,6,1,3,5,7};
    //int arr[] = {4};
    /*----------------------------------
                    4
                  /  \
                 2    6
                / \  / \
               1   35   7

    preOrder = 4, 2, 1, 3, 6, 5, 7
    inOrder = 1, 2, 3, 4, 5, 6, 7
    postOrder =
    levelOrder =
    ----------------------------------*/

    int n = sizeof(arr)/sizeof(arr[0]);
    i=0;

    BinarySearchTree bst(arr,n);

    //-------------- BUILDING BST -------------------------------
    DBsep1()
    bst.build("recursive");
    bst.traversal("iterative","levelorder");
    bst.traversal("recursive","levelorder");
    DBsep2()
/*
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

*/
    //------------- DELETING A NODE----------------
    DBsep1()
    bst.traversal("iterative","levelorder");
    bst.removeNode("iterative",1);
    bst.traversal("iterative","levelorder");
    DBsep2()

    //------------- ADDITION --------------------
    DBsep1()
    DBx(bst.totalMaxSumOfEveryNode("recursive", 4))
    DBx(bst.maxSumPath("recursive"))
    DBsep2()

    return 0;
}
