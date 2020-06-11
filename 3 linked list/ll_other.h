
// LINKED LIST TO NUMBER
// to-do
int linkedListToNum(singlyNode *head, int t, int number){
	if(head==nullptr)
		return 1;
	number += t*linkedListToNum(head->next, t/10, number);
	//number+=head->data*t;
	cout<<head->data<<" "<<number<<"\n";
	return number;
}


// SWAP LINKED LIST BY K PLACES
singlyNode* swapByK(singlyNode* head, int k){
	if(k==0){
		return head; // return head
	}

	 int ln=0;
    singlyNode* temp = head;
    while(temp!=nullptr){
        ln++;
        temp = temp->next;
    }
    
    if(k>ln){
        k = k%ln;
    }

		if(k==0){
		return head; // return head
	}

  singlyNode* slow=head;
	singlyNode* fast=head;
	int n=1;
	while(fast->next!=nullptr){
		fast = fast->next;
		if((n)>=k){
			slow = slow->next;
		}
		n+=1;
	}

	fast->next = head;
	while(head->next!=slow){
		head = head->next;
	}
	head->next = nullptr;

	head = slow;

	return slow;
}


// REVERSE LINKED BETWEEN START AND END NODE 
singlyNode* reverseBetweenStartEndValue(singlyNode* head, int start_val, int end_val){
	singlyNode* left = head;
	stack<singlyNode*> right;

	while(left!=nullptr && left->data!=start_val){
		left = left->next;
	}

	singlyNode* temp = left;
	temp = left;
	while(temp!=nullptr && temp->data!=end_val){
		right.push(temp);
		temp = temp->next;
	}
	right.push(temp);

	pxy(left->data, right.top());

	// reverse
	while((left!=nullptr && !right.empty()) && left!=right.top()){
		swap(left->data, right.top()->data);
		left = left->next;
		right.pop();
	}

	
	return head;
}


singlyNode* reverseByK(singlyNode* head, int k){
	if(k==0 || k==1){
		return head;
	}

	int len=0;
	
	// checking overflow
	singlyNode* temp = head;
	while(temp!=nullptr){
		len++;
		temp = temp->next;
	}
	if(k>len)
		k = k%len;

	if(k==0 || k==1){
		return head;
	}
    
		temp = head;
    while(temp!=nullptr){
        singlyNode* start = temp;
        stack<int> end;
        
        int p = k-1;
        while(p>0 && temp!=nullptr){
            temp = temp->next;
            end.push(temp->data);
						p-=1;
        }		
        //pxy(k,p);				
				if(p>1 || start==nullptr || end.top()==nullptr)
					break;
        
				// logic to swap
        while((start!=temp && !end.empty()) && start!=end.top()){
            cout<<"*"<<start->data<<" "<<end.top()->data<<"\n";
            start->data = end.top();

            start = start->next;
            end.pop();					

        }
        
        if(temp!=nullptr)
        temp = temp->next;
    }
    
    
    
    return head;
}