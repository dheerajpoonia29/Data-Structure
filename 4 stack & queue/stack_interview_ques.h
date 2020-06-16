//https://codinginterviewquestionsans.blogspot.com/p/top-20-stack-interview-questions.html
#good question : ques1, ques4, ques7, ques11, ques17, ques19
#to-do : ques15(done)

// Q1: CODE SPECIAL STACK (GETMIN()->RETURN MIN ELE IN o(1), ELSE SIMILAR AS STACK)
/*_________________________________________________________________________________
m1: tc(1):for getting min ele,  sc(n)
	* we use 2 stack 
	* 1st is main stack 
	* 2nd is min stack 
		* it will store the current min till top of main stack 
		* when we pop main stack we look into min stack if top of main stack == top of min stack
		* in this case we pop from both of them 

better approach: tc(1) sc(1):spaced optimzed version
	* reference = https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/
	* vidoe : https://www.youtube.com/watch?v=ZvaRHYYI0-4&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=11
	* instead of using min stack (auxilliary stack) we use variable minEle variable 
	* idea:
		* push x 
			 case 1: x>minEle push(x)
			 case 2: x<minEle push(2x-minEle)
		* pop 
			 // logic is here 
			 // we have to reterive previous min element 
			 previous min = 2*minEle-st.top() 
			 st.pop()



// Q2: IMPLEMENT QUEUE USING STACK 
/*_______________________________
m1: tc(same) sc(auxilliary stack)
	* st1: for push at the end - first in 
	* st2: for pop from front - first out 

m2: tc(same) sc(recursion)
	* push same 
	* now pop when base condition reach we have queue.front() 
	* now backtracking from recursion stack pop() ele again push them into stack



// Q3: IMPLEMENT TWO STACK IN ARRAY
/*__________________________________
m1: not efficient idea 
	* divide array into two halves
	* stack1 from 0 to n/2 
	* stack2 from n/2 to n 
	* note: m1 is inefficient because let stack1 size 3 and stack 2 size is 1 
	  and we array size if 6 here we add 2 more ele on stack1 but it show overflow but we have space on stack 2

better approach:  
	* stack1 from top = 0  top grow 
	* stack2 from top = n top shrink



// Q4: STOCK SPAN PROBLEM : simply for each height count smaller previous height
/*_________________________________________________________________________________
#medium level difficulty

stock is heigher or slower for ith day is cal by looking previous stock height 
d0  d1 d2 d3 d4 d5 
100 10 70 64 75 90
span of d4 = 4 (d1, d2, d3, d4)

m1: tc(n^2) sc(1)
	* pick 1 
	* traver back till back<pic 1 => count++ 
	* for pick 1 this is ans = count 
	* this will done for each 

better approach: tc(n) sc(n) 
	* idea: maintain decereasing order of price in stack 
	* stack - store the day no 
	* iterate over price on ith day
		* if price[st.top()]<=price[i] at i-th day 
				 st.pop() 
		* else 
		     st.push(ith day)
		* do above if else until price[st.top()]>price at ith day 
		* ans at ith day => current day(i-thday) - st.top()(the day in history which having the stock larger then current day)
		* when we sub previous stock highes price day - current day we get middle day where price is lesser then current day



// Q5: CHECK BALANCED PARENTHESES IN EXPRESSION 
/*_____________________________________________
m1: tc(n) sc(n) 
	* curr is opening braces - push 
	* curr is closing braces - top!=curr 	return false else pop() and continue



// Q6: NEXT GREATER LEFT, ELEMENT 
/*_________________________
m1: tc(1) sc(stack)
	* iterate array
	* if(st.top()<curr)
		greater ele of st.top() is curr 
		st.pop()
		st.push(curr)
	* else 
		st.push(curr)
	* at the end what if ele not have grater ele?
		they remain in stack and we pop() then and mark there GE = -1 as question say



// Q7: CELEBRITY PROBLEM - find a person in party who know no one but everyone in party know him
/*______________________________________________________________________________________________
MATRIX = { {0, 0, 1, 0},
           {0, 0, 1, 0},
           {0, 0, 0, 0},
           {0, 0, 1, 0} }
Output:id = 2 person is CELEBRITY
CELEBRITY is person who know by everyone but he may or may not know other
doubt1: is 2 celebrity in this question ?
		 -> now if some one is celebrity then his row is completely filled with 0

m1: tc(n^2) sc(1)
	* visit every row and if row is complete filled with zero that row id is ans
m2: tc(n)
	* tc(n) is point here which make this question different 
	* video : https://www.youtube.com/watch?v=CiiXBvrX-5A
	* idea: elimination approach 
		* s1: push all people in array 1 to n 
		* s2: on each iteration over stack, pop two people 
				* p1 = pop(), p2 = pop()
				* check in matrix check arr[p1][p2]=1 it mean p1 know p2 then p1 won't celebrity because it know p2 
				* in this way there are 2 case 
					case 1: either both know each other - won't push any of them 
					case 2: one of them don't know other push again ( person who don't know other but other know him )
		* s3: repeat s2 until stack empty or we left with only 1 ele in stack 
		* s4: celebrity 
				* if stack == empty know one celebrity 
				* else celebrity = stack.pop()


	
// Q8: INFIX TO POSTFIX 
/*_____________________
m1: already know 
	* start from starting of expression 
	* <operand> <operator> <operand> 
	* postfix string s 
	* if curr is operator push into stack 
			* special case if stack.top() precedence > curr operator 
			* s+=stack.top() (which is operator) pop() until precedence < curr operator 
			* then push(curr operator)
	* if curr is operand s+=operand 



// Q9: IMPLEMENT STACK USING QUEUE 
/*________________________________
m1: 
	* just won't use the front of queue for deletion then it work same like stack 
m2: 
	* m1 is wrong we misleading the properties of queue
	* use 2 queue q1,q2 
	* enqueue -> q1 at front 
	* pop -> dequeue all element from q1 to q2  except front element 
		* now we dequeue which return second last pushed element in q1 
	* above method is done using making pop operation costly 
	* similary we do by making push operation costly



// Q10: LARGEST RECTANGULAR AREA IN HISTORGRAM
/*____________________________________________
problem explantion : https://www.geeksforgeeks.org/largest-rectangle-under-histogram/
earliery problem i failed to do is : maximum sheet we cover the largest area of contigous building  
m1: tc(n^2) sc(1)
	* brute force 
	* fix one tower and check all other tower with this 
	* do for all

better approach: tc(n) sc(stack)
	* ans = min(ans, minHeight*(curr b_id - st.top() b_id + 1))
					st.top() b_id is the leftmost heigher building id 
					minHeight is leftmost min building height in stack life
	* push => if b[top]<b[curr b_id]
							then push(curr b_id)
						else 
							goto pop

	* pop  => while(b[top]>b[curr b_id])
						note: on every pop, update minHeight = min(minHeight, st.top())
						after while 
						take ans step1
m2: 
	* given height[] array
	* find pattern nsl, lsr, lgl, lgr 
	* in this question we find nsl, nsr 
	* find width array width[i] = nsr[i]-nsl[i]-1 
	* find area[i] = width[i]*height[i]
	* return max_element(arr.all)



// Q11: FIND MAXIMUM AND MINIMUM IN EVERY WINDOW SIZE OF ARRAY 
/*____________________________________________________________
m1: tc(n^3) dc(1)
	* brute force 
	* generate window tc(n^2)
	* iterate over it tc(n)
m2: tc(n) sc(2 dequeue)
	* done already 
	* dq1 for maximum 
	* dq2 for minimum 
	* at each ele of array 	
		* dequeue remove ele from front (ele) then update currmin = min(currmin, newele)
		* insert newlele into dq 
better approach: we also use doulbly linked list

# difficulty medium

note: above method are wrong, according to question its ask to find maximum of minimum of window size k 
maximum of minimum 
Input:  arr[] = {10, 20, 30, 50, 10, 70, 30}
Output: ans = {70, 30, 20, 10, 10, 10, 10}
				70 for wc=1, 30 wc=2, 20 wc=3, 10 wc=4, 10 wc=5, 10 wc=6, 10 wc=7
			
better approach: tc(n) sc(2 array + stack)
	* broad idea: https://www.geeksforgeeks.org/find-the-maximum-of-minimums-for-every-window-size-in-a-given-array/
		* preprocessing (used 2 auxilliary array + 1 stac)
			* build two array by using 1 stack 
			* Find indexes of next smaller (Next smaller is the nearest smallest element on right side)
			* Find indexes of Previous smaller (Previous smaller element is the nearest smallest element on the left side of arr[i])
				for every element  of arr[i].
				using approach used in quesiton6 above 
				For input {10, 20, 30, 50, 10, 70, 30}, array of indexes of next smaller, right = {7, 4, 4, 4, 7, 6, 7}.
				For input {10, 20, 30, 50, 10, 70, 30}, array of indexes of previous smaller, left = {-1, 0, 1, 2, -1, 4, 4}
			* fill array3 pp = right[i] – left[i] – 1 
				pp =  {7, 3, 2, 1, 7, 1, 2} // window size filled 
				

		* finding maximum of minimum 
			* for i to n 				
						ans[wc] = min
					> i=1, pp[1] = 7, array[1]=10 : for wc=7 min=10
						ans[7] = 10
					> i=2, pp[2] = 3, array[2]=20 : for wc=3 min=20
					  ans[3] = 20
					> i=3, pp[3] = 2, array[3]=30 : for wc=2 min=30
						ans[2] = 30
					> i=4, pp[4] = 1, array[4]=50 : for wc=1 min=50
						ans[1] =  here i'm stuck, but understood approach 
		


// Q12: PRINT ALL COMBINATIONS OF BALANCED PARENTHESES
/*____________________________________________________
n-1 [{}]
n-2 [{{}},{}{}]
n-3 [{{{}}}, {}{}{}, {{}{}}, {{}}{}, {}{{}}]

note: this is problem of backtracking
why come under stack ?
because backtracking use recursion = stack

better approach: tc(2^N) where n is length of total bracket, sc(stack)
	* backtracking / dfs (both use stack)
	* 3 key of backtracking	
		k1. CHOICE : place '{' or '}'
		k2. CONTRAINTS : parentheses is valid, cannot close until we have open brackets
		k3. GOAL :  n*2 lenght of each string, n*2 placement then backtrack 
	* idea: https://www.youtube.com/watch?v=sz1qaKt0KGQ



// Q13: DESIGN A STACK WITH OPERATIONS ON MIDDLE ELEMENT 
/*______________________________________________________ 
question is traditional stack {push, pop} + 2 additional functionality {findMiddle(), deleteMiddle}
m1: tc(n) sc(n)
	* array implementation 
	* deletemiddle(n) findMiddle(1), delete- because it need swap after deletion 
	* findMiddle(1)
m2: tc(n) sc(n)
	* linked list implementation 
	* deleteMiddle(1) findMiddle(n), getmiddle - we use technique called slow & fast pointer to get in one pass
	* findMiddle(n)
better approach: tc(1) sc(n)
	* doubly linked list implementation + with one extra pointer middle which point on middle 
	* so how it difference from m2 ?
		in m2 if we have ptr middle we can't move previous and next on next insertion 
		but in m3 we adjact middle ptr back and next when new element is insert 



// Q14: CREATE A MERGABLE STACK 
problem: traditional stack (push, pop in O(1)) + additional functionality merge(stack2 with stack1 in O(1))
m1: tc(n) sc(auxilliary array)
	* array implementation
m2: tc(1) sc(3 pointer)
	* linked list with 3 extra pointer, pt1->stk1_top(), pt2->stk2_front(), pt2->st3->stk2_rear()
	* then merege(ptr1->next = ptr2, pt1 = ptr3)
better approach: tc(1) sc(1)
	* circular linked list 
	* ll2.rear()->next = ll1.head()
	* ll1.rear()->next = ll2.head()



// Q15: REMOVE BRACKETS 
"a-(b+c)" => "a-b-c"
"a-(b-c-(d+e))-f" => "a-b+c+d+e-f" 
m1: tc(1) sc(auxilliary string ns)
	* if(s[curr]!='(' || ')' )
		* ns+=s[curr]
	* Note: wrong according to question 
	* this is my first obervation ! i don't repeat this again 
m2: tc(1) sc(stack) to-do
	* this question not purely of stack 
	* https://www.geeksforgeeks.org/remove-brackets-algebraic-string-containing-operators/
	* in place of stack ve use check variable 
	* idea:	
			- toggle sign + to - or - to + if check is '-'
			- other not toggle just insert operator same when check = '+'
			- how to set toggle check 
			- toggle check is set before starting of opening bracket '('
			- +( check=0 not to toggle 
			- -( check=1 toggle 
	


// Q16: FIND EXPRESSION HAVING DUPLICATION PARENTHESES OR NOT 
m1: tc(1) sc(stack)
	* push('(')
	* if curr=')' then pop until '(' and count++ 
	* if count>1 return ture 
	* else after loop return false 



// Q17: REVERSE STACK WITHOUT USING EXTRA SPACE IN O(N) 
m1: tc(1) sc(1)
	* if stack is implemented using linked list  
	* top->next = nullptr;
	* top = head
note: array implmenetation of stack 

m2: tc(n) sc(1 auxilliary stack) 
	* iterative + auxilliary stack
	* while(st.empty()!=0)
			* ast.push(st.top())
	* ast is reverse stack 

note: if ask only to do this using recursion 
m3: tc(n+n) sc(2 recursion stack) 
	*https://www.youtube.com/watch?v=dQsZP8UvHVk
	* recursion + 2 recursion stack 
	* |1 2 3 4 
	* call reverse recursion 
	* this will return 4, 3, 2 ,1(most current pop)
	* revers(){
		if(st.empty!=1){
			x = st.top()
			st.pop()
			reverse()
			insert(x)
		}
	}
	* problem: 1 is most current pop if we just push into stack then it goes again at bottom so we need one more recursive stack 
	* call another function name as insert 
	* insert recieve pop element from reverse function receive in this order 4(begg reach this), 3, 2, 1(last reached)
	* so now we have to use another recursion on insert function so that we receive in this ordre 1, 2, 3, 4(last reached)
	* insert(int x){
		a = st.top()
		st.pop()
		insert(x)
		st.push(a)
	}

note: if we ask only to this sc(1)
m4: tc(n) sc(1)
	* linked list 
	* so method 1 is voilating the condition of stack
	* because in stack there is only 1 pointer names as top in linked list 
	* now simple but we do is reverse linked list in O(n)
	* technique used in swap/changing the pointer 



// Q18: NEAREST SMALLEST ELEMENT 
m1: tc(n) sc(stack) 
	* already done 



// Q19: RAIN WATER TRAPPED 
compute how much water it is able to trap after raining.
m1: 
	* https://www.youtube.com/watch?v=FbGG2qpNp4U&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=9
	* find water bound 2 building using ngl & ngr 
	* actual water store between these two building water[i] = min(ngl,ngr) - build_height[i]
	* note: ngl, ngr is wrong because we take heighest building height on right but ngr give next grater right



// Q20: SIMPLIFY DIRECTORY PATH
