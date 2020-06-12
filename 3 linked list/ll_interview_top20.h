//https://dzone.com/articles/20-linked-list-interview-questions-for-java-progra
// DOUBT q3: 54 LINE, implementation
// DOUBT q6,	q18: wrong ans,
// TO-DO q8, q13


// Q1 : FIND MIDDLE ELEMENT OF SINGLY LINKED LIST IN ONE PASS
/*
m1: tc(n+n) sc(n)
		* store in array
		* return array[n/2]
m2: tc(n)	sc(1)
		* slow fast 
		* Fast pointer moves two nodes in each iteration
*/
int q1(singlyNode* head){
	singlyNode* slow = head;
	singlyNode* fast = head->next;

	int k=2;

	while(fast->next!=nullptr){
		int jump = k;
		while(fast->next!=nullptr && jump--)
			fast = fast->next;

		slow = slow->next;
	}

	return slow->data;
}

// Q2: REVERSE SINGLY LINKED LIST WITHOUT RECURSION
/*
done in [ll_basic.h]
approach: swap the pointer link/next 
*/

// Q3: REMOVE ALL DUPLICATE NODE IN UNSORTED LINKED LIST OR MAKE LINKED LIST UNIQUE
/*
m1: tc(n^2) sc(1)
		* two loop over ll 
		* lp1 for picking ele 
		* lp2 for deleting that picked ele
	
m2: tc(n) sc(hashtable/checkArray)
		* hashtable return the ele is visited or not

m3: tc(nlogn) sc(n)
		* sort linked list using merge sort - nlogn
		* while adjacent redundancy remove those ele - n 
*/
void q3(singlyNode* head){
	unordered_set<int> uset;
	while(head!=nullptr){

		if(isKeyExist(uset, head->data)){
			// duplicate find delete it 
			//deleteNode(head->data);
			// ***************************!******************************
			//how to access class method curr object in main.cpp in other header file by calling header file function
		}
		else{
			uset.insert(head->data);
		}
		
		head = head->next;
	}	
}

// Q4: LENGTH OF SINGLY LINKED LIST 
/*
m1: tc(n) sc(1)
		* iterate head till nullptr and count
m2: lets do with recursion
*/
int q4(singlyNode* head){
	if(head==nullptr)
		return 0;
	return 1+q4(head->next);
}


// Q5: DETECT CYCLE AND RETURN STARTING NODE OF CYCLE 
/*
question not clear
m1:
		* fast & slow pointer
*/


// Q6: REVERSE LINKED LIST USING RECURSION 
/*
medium level difficulty
*/
singlyNode* q6(singlyNode* head, singlyNode* node) 
{ 
	if (node == nullptr) 
			return nullptr; 
	if (node->next == nullptr) { 
			head = node; 
			return node; 
	} 
	singlyNode* node1 = q6(head, node->next); 
	node1->next = node; 
	node->next = nullptr; 
	return node; 
} 


// 	Q7: FIND k-th NODE FROM THE END IN LINKED LIST oor return kth node
/*
m1: 
		* wa brute force
m1: 
		* fast slow pointer
*/
int q7(singlyNode* head, int k){
	if(k==0){
		return head->data;
	}
	singlyNode* slow=head;
	singlyNode* fast=head;
	int n=0;
	while(fast!=nullptr){
		fast = fast->next;
		if(n>=k){
			slow = slow->next;
		}
		n+=1;
	}
	
	return slow->data;
}


// Q8: REPRESENT SUM OF TWO LIN LIST USING STACK
/*
to-do
Input:
  First List: 5->6->3  // represents number 563
  Second List: 8->4->2 //  represents number 842
Output
  Resultant list: 1->4->0->5  // represents number 1405
*/


// Q9: REVERSE LINKED INPLACE 
/*
done 
when we use recursion or pointer swap tech they are inplace 
*/

// Q10: REMOVE NTH NODE FROM END OF LINKED LIST IN ONE PASS
/*
m1:
		* first access k-th node from last using previous question technique
		* then delete it
*/


// Q11: MERGE TWO SORTED LINKED LIST
/*
easy
*/


// Q12: ADD ELEMENT AT MIDDLE OF LINKED LIST
/*
m1: tc(n) sc(1)
		* use fast slow pointer tech 
		* add ele at slow pointer 
*/

// Q13: SORT A LINKED LIST 
/*
to-do 
using mergesort
*/


// Q14: DIFFERENCE BETWEEN ARRAY & LINKED LIST 
/*
done
*/


// Q15: CONVERT SORTED LINKED LIST IN BINARY SEARCH TREE 
/*
m1:
		* traverse linked list 
		* just insertBst(head->data);
		note: this is not a question this will make splay tree 
m2:
		* linked list/ array is sorted then always think first BINARY SEARCH 
		* left mid right 
		* left goes on bst left 
		* right goes on bst right 
*/


// Q16: RETURN A NODE IN WHICH BEFORE ALL NODE ARE LESSER AND AFTER ALL NODE ARE GREATER


// Q17: REMOVE ALL VALUE IN LINKED LIST WHICH MATCH WITH GIVEN VALUE 
/*
already done 
*/


// Q18: FIND NODE AT WHICH INTERSECTION OF TWO LINKED LIST BEGIN  or MERGE POINT OF TWO LINKED LIST SO WE CAN SAVE TIME TO MERGE THEM INTO ONE ADDRESS AFTER FIND MERGE
/*
m1:
		* use two stack st1 for ll1, st2 for ll2
		* while st1 & st2 not empty and st1.ele == st2.ele 
				curr intersection = st1 or st2 any 
				pop st1, st2 
		* after while loop curr have intersection node 
		* but this aproach don't work i don't know why
m2:
		* if both linked list are same lenghth then cool 
		* if not then find how many step longer linked list ahead 
		* just dist ahead = len(ll1)-len(ll2) 
		* then traver ahead dis of longer linked list 
		* and form here both are at same pos we start from here for checking ll1.val==ll2.val then return ll1 or ll2
		* https://www.youtube.com/watch?v=gE0GopCq378&list=PL2_aWCzGMAwLPEZrZIcNEq9ukGWPfLT4A&index=14
*/


// Q19: CHECK LINKED LIST IS PALINDROME 
/*
m1:
		* use two stack 
		* again traverse ll and check ll.data == st.top
m2:
		*slow fast pointer tech
		* when slow at mid and fast at last 
		* at slow make next = null 
		* and reverse ll front fast till that null 
		* make slow at head 
		* now traver slow & fast 
		* at each iteration if slow->val!=fast->val return false
*/

// Q20: REMOVE DUPLICATE FROM SORTED LINKED LIST 
/*
easy
*/

