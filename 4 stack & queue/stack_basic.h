#include "../macro.h"

// ARRAY IMPLEMENTATION
class StackUsingArray{
	int MAX_SIZE = 101;
	int STACK[101]; 
	int top;  

	public:
	StackUsingArray(){
		top=-1;
	}

	void Push(int x) 
	{
		if(top == MAX_SIZE -1) { // overflow case. 
			printf("Error: stack overflow\n");
			return;
		}
		STACK[++top] = x;
	}

	void Pop() 
	{
		if(top == -1) { // If stack is empty, pop should throw error. 
			printf("Error: No element to pop\n");
			return;
		}
		top--;
	}

	// Top operation to return element at top of stack. 
	int Top() 
	{
		return STACK[top];
	}

	// This function will return 1 (true) if stack is empty, 0 (false) otherwise
	int IsEmpty()
	{
			if(top == -1) return 1;
			return 0;
	}

	int Print(){
		int i;
		printf("Stack: ");
		for(i = 0;i<=top;i++)
			printf("%d ",STACK[i]);
		printf("\n");
	}

};

// LINKED LIST IMPLEMENTATION 
struct STACK{
	int data;
	STACK *next;

	STACK(int val){
		this->data = val;
		this->next = nullptr;
	}
};

class StackUsingLinkedList{
	STACK *top;
	public:

	StackUsingLinkedList(){
		this->top = nullptr;
	}

	void Push(int val){
		STACK *new_node = new STACK(val);
		
		if(top==nullptr){
			top = new_node;
		}
		else{
			new_node->next = top;
			top = new_node;
		}
	}

	void Pop() 
	{
		if(top == nullptr) { // If stack is empty, pop should throw error. 
			printf("Error: No element to pop\n");
			return;
		}
		STACK* temp = top;
		top = top->next;
		delete temp;
	}

	// Top operation to return element at top of stack. 
	int Top() 
	{
		if(top == nullptr) { // If stack is empty, pop should throw error. 
			printf("Error: No element to pop\n");
			return -1;
		}
		return top->data;
	}

	// This function will return 1 (true) if stack is empty, 0 (false) otherwise
	int IsEmpty()
	{
			if(top == nullptr) return 1;
			return 0;
	}

	int Print(){
		STACK* temp = top;
		cout<<"Stack: ";
		while(temp!=nullptr){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<"\n";
	}

};


/*
Push(2);Print();
	Push(5);Print();
	Push(10);Print();
	Pop();Print();
	Push(12);Print();
*/


