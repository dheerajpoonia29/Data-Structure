#include "../macro.h"

struct singlyNode{
	int data;
	singlyNode *next;

	singlyNode(int val){
		this->data = val;
		this->next = nullptr;
	}
};

class SinglyLinkedList{
	singlyNode *head;
	public:

	SinglyLinkedList(){
		this->head = nullptr;
	}
	
	singlyNode* getHead(){
		return head;
	}

	void insertNode(int val){
		// CREATING NEW NODE 
		singlyNode *new_singly_node = new singlyNode(val);
		/*
		IN C 
		singlyNode *new_node = (singlyNode*)malloc(sizeof(singlyNode));
		*/
		
		// INSERT NEW NODE 
		if(head==nullptr)
			head = new_singly_node;
		else{
			singlyNode *temp = head;
			while(temp->next!=nullptr)
				temp = temp->next;
			temp->next = new_singly_node;
		}
	}

	void traverseLList(int check){
		if(check==1){
			// FORWARD TRAVERSE
			singlyNode *temp = head;
			while(temp!=nullptr){
				cout<<temp->data<<" ";
				temp = temp->next;
			}
		}else{
			// BACKWARD TRAVERSE 
			stack<int> st;
			singlyNode *temp = head;
			while(temp!=nullptr){
				st.push(temp->data);
				temp = temp->next;
			}
			while(!st.empty()){
				cout<<st.top()<<" ";
				st.pop();
			}
		}
		cout<<"\n";
	}

	void deleteNode(int val){
		
		// CASE 1: head is target
		if(head->data==val){
			/*
			head->data = 0;
			head = head->next;
			*/
			// now previously head pointer still exist - DOUBT!
			// 13:10 check this <https://www.youtube.com/watch?v=A5_XdiK4J8A&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=24>
			singlyNode* temp = head;
			head->data = 0;
			head = head->next;
			delete temp;
		}
		else{
			// CASE 2: target present in middle or last of linked SinglyLinkedList
			singlyNode *temp = head;
			while(temp->next!=nullptr){
				if(temp->next->data==val){
					temp->next->data = 0;
					temp->next = temp->next->next;
					break;
				}
				temp = temp->next;
			}
		}
		
	}

	void reverseLList(){
		/*
		//APPROCH 1: REVERSE ITERATIVE USING STACK
		// tc(O(n+n)) sc(n)
		singlyNode* temp = head;
		stack<int> st;
		while(temp!=nullptr){
			st.push(temp->data);
			temp = temp->next;
		}

		// FILLING REVERSE DATA
		temp = head;
		while(temp!=nullptr){
			temp->data = st.top();
			temp = temp->next;
		}
		*/

		//APPROACH 2: REVERSE THE LINK/NEXT 
		// medium level difficulty
		singlyNode* temp1;
		singlyNode* temp2; 

		temp1 = head->next; // temp1=20 node
		temp2 = temp1->next; // temp2=30
		temp1->next = head;
		head->next = nullptr;
		head = temp1;

		while(temp2!=nullptr){
			temp1 = temp2;
			temp2 = temp1->next;
			temp1->next = head;
			head = temp1;
		}		
	}
};



struct doublyNode{
	doublyNode *prev;
	int data;
	doublyNode *next;

	doublyNode(int val){
		this->prev = nullptr;
		this->data = val;
		this->next = nullptr;
	}
};

class DoublyLinkedList{
	doublyNode *head;
	doublyNode *tail;
	public:

	DoublyLinkedList(){
		this->head = nullptr;
	}
	
	void insertNode(int val){
		// CREATING NEW NODE 
		doublyNode *new_doubly_node = new doublyNode(val);
		
		// INSERT NEW NODE 
		if(head==nullptr){
			head = new_doubly_node;
			tail = head;
		}
		else{
			doublyNode *parent_node = head;
			doublyNode *child_node = parent_node->next;
			// 					(null)HEAD(*) -> (*)NODE(*) -> (*)NODE(*) -> (*)NODE(null)
			while(child_node!=nullptr){
				parent_node = child_node;
				child_node = child_node->next;
			}			
			child_node = new_doubly_node;
			parent_node->next = child_node;
			child_node->prev = parent_node;
			tail = child_node;
		}
	}

	void traverseLList(int check){
		if(check==1){
			// FORWARD TRAVERSE
			doublyNode *temp = head;
			while(temp!=nullptr){
				cout<<temp->data<<" ";
				temp = temp->next;
			}
		}else{
			// BACKWARD TRAVERSE 
			doublyNode *temp = tail;
			while(temp!=nullptr){
				cout<<temp->data<<" ";
				temp = temp->prev;
			}
		}
		cout<<"\n";
	}

	void deleteNode(int val){
		
		// CASE 1: target is head
		if(head->data==val){
			head = head->next;
			head->prev = nullptr;
		}
		else{
			// CASE 2: target present in middle or last of linked SinglyLinkedList
			doublyNode *parent=head;
			doublyNode *child=parent->next;
			while(child!=nullptr){
				if(child->data==val)
					break;
				else{
					parent = child;
					child = child->next;
				}
			}
			
			if(child->data==val && child->next==nullptr){
				// CASE 2: target is tail 
				parent->next = nullptr;
				tail = parent;
				delete child;
			}

			else{
				// CASE 3: target is in middle 
				parent->next = child->next;
				child->next->prev = parent;
				delete child;
			}
		}
		
	}

	void reverseLList(){
		doublyNode *start=head;
		doublyNode *end=tail;

		while(start!=end){
			swap(start->data, end->data);
			start = start->next;
			end = end->prev;
		}
	}

};