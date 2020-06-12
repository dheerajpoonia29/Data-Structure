#include "../macro.h"

// ARRAY IMPLEMENTATION
class QueueUsingArray
{
private:
	int MAX_SIZE = 101;
	int A[101];
	int front, rear; 

public:
	QueueUsingArray(){
		front = -1; 
		rear = -1;
	}

	bool IsEmpty()
	{
		return (front == -1 && rear == -1); 
	}

	bool IsFull()
	{
		return (rear+1)%MAX_SIZE == front ? true : false;
	}


	void Enqueue(int x)
	{
		cout<<"Enqueuing "<<x<<" \n";
		if(IsFull())
		{
			cout<<"Error: QueueUsingArray is Full\n";
			return;
		}
		if (IsEmpty())
		{ 
			front = rear = 0; 
		}
		else
		{
		    rear = (rear+1)%MAX_SIZE;
		}
		A[rear] = x;
	}

	// Removes an element in QueueUsingArray from front end. 
	void Dequeue()
	{
		cout<<"Dequeuing \n";
		if(IsEmpty())
		{
			cout<<"Error: QueueUsingArray is Empty\n";
			return;
		}
		else if(front == rear ) 
		{
			rear = front = -1;
		}
		else
		{
			front = (front+1)%MAX_SIZE;
		}
	}
	// Returns element at front of QueueUsingArray. 
	int Front()
	{
		if(front == -1)
		{
			cout<<"Error: cannot return front from empty QueueUsingArray\n";
			return -1; 
		}
		return A[front];
	}
	
	void Print()
	{
		// Finding number of elements in QueueUsingArray  
		int count = (rear+MAX_SIZE-front)%MAX_SIZE + 1;
		cout<<"QueueUsingArray       : ";
		for(int i = 0; i <count; i++)
		{
			int index = (front+i) % MAX_SIZE; // Index of element while travesing circularly from front
			cout<<A[index]<<" ";
		}
		cout<<"\n\n";
	}
};


struct Node{
	int data;
	Node *next;

	Node(int val){
		this->data = val;
		this->next = nullptr;
	}
};

class QueueUsingLL{

	// Two glboal variables to store address of front and rear nodes. 
	struct Node* front;
	struct Node* rear;

public:

	QueueUsingLL(){
		front = nullptr;
		rear = nullptr;
	}
	// To Enqueue an integer
	void Enqueue(int x) {
		Node* temp = new Node(x);

		temp->data =x; 
		temp->next = nullptr;
		if(front == nullptr && rear == nullptr){
			front = rear = temp;
			return;
		}
		rear->next = temp;
		rear = temp;
	}

	// To Dequeue an integer.
	void Dequeue() {
		struct Node* temp = front;
		if(front == nullptr) {
			printf("Queue is Empty\n");
			return;
		}
		if(front == rear) {
			front = rear = nullptr;
		}
		else {
			front = front->next;
		}
		free(temp);
	}

	int Front() {
		if(front == nullptr) {
			printf("Queue is empty\n");
			return -1;
		}
		return front->data;
	}

	void Print() {
		struct Node* temp = front;
		while(temp != nullptr) {
			printf("%d ",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
};


/*
Q.Enqueue(2);  Q.Print();  
   Q.Enqueue(4);  Q.Print();  
   Q.Enqueue(6);  Q.Print();
   Q.Dequeue();	  Q.Print();
   Q.Enqueue(8);  Q.Print();
*/