#include<bits/stdc++.h>
using namespace std;

void dfile() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

// Structure of Node in Doubly Linked List.
class node {
public:
	int data;
	node *next;

	node(int val) {
		data = val;
		next = NULL;
	}
};

void insertAtTail(node* &head, int val) { // Here, head is taken as reference as we will modify the list.
	node* n = new node(val); // Created a new node n.

	// If our list doesn't contain any value, then the elemnet at first will be our element at tail.
	if (head == NULL)
	{
		head = n;
		return;
	}

	node* temp = head; // New node n,pointing to head.

	// Traversing the list
	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = n;
}

// To calculate length of List
int length(node* &head) {
	int count = 0;
	node* temp = head;
	while (temp != NULL) {
		count++;
		temp = temp->next;
	}
	return count;
}

void appendLastKnodes(node* &head, int k) {

	/* BRUTE FORCE METHOD */

	/*  node* temp = head;
		node* prevTemp;
		node* lastTemp;
		k--;
		while (temp != NULL and k > 0) {
			prevTemp = temp;
			temp = temp->next;
			k--;
		}

		lastTemp = temp;
		while (lastTemp->next != NULL) {
			lastTemp = lastTemp->next;
		}
		lastTemp->next = head;
		head = temp;
		prevTemp->next = NULL; */


	/* OPTIMAL METHOD */

	node* newHead;
	node* newTail;
	node* tail = head;

	int l = length(head);
	k = k % l; // For edge case
	int count = 1;
	while (tail->next != NULL) {
		if (count == l - k)
		{
			newTail = tail;
		}
		if (count == l - k + 1)
		{
			newHead = tail;
		}
		tail = tail->next;
		count++;
	}
	tail->next = head;
	head = newHead;
	newTail->next = NULL;
}

// To display the list
void displayList(node* head) {
	node* temp = head;
	while (temp != NULL) {
		cout << temp->data << "->";
		temp = temp->next;
	} cout << "NULL\n";
}

int main()
{
	dfile();

	int n; cin >> n;
	node* head = NULL;
	for (int i = 0; i < n; ++i) { int val; cin >> val; insertAtTail(head, val);}
	displayList(head);

	appendLastKnodes(head, 3);
	displayList(head);

	return 0;
}
