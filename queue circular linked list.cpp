#include<iostream>
using namespace std;

struct Node {
	int value;
	Node* next;


};
class CircularQueue {
private:

	Node* back;
public:
	CircularQueue() {

		back = NULL;
	}

	~CircularQueue() {
		while (!isEmpty()) {
			deQueue();
		}
	}


	void enQueue(int element) {
		Node* newnode = new Node();
		newnode->value = element;
		newnode->next = NULL;

		if (back == NULL) {
			back = newnode;
			back->next = newnode;
		}
		else {
			newnode->next = back->next;
			back->next = newnode;
			back = newnode;
		}

	}
	bool isEmpty() {
		return back == NULL;
	}

	void deQueue() {

		if (isEmpty()) {
			cout << "Queue is empty! ";
			return;
		}
		Node* front = back->next;
		if (front == back) {
			delete front;
			back = NULL;
			return;
		}
		back->next = front->next;
		delete front;






	}
	void Display() {
		Node* temp = back->next;
		if (isEmpty()) {
			cout << "Queue is empty!";
			return;

		}

		
		do {

			cout << temp->value << " ";
			temp = temp->next;



		} while (temp != back->next);
	}



};
int main() {

	CircularQueue Q;
	Q.enQueue(1);
	Q.enQueue(2);
	Q.enQueue(3);
	Q.enQueue(4);
	Q.enQueue(5);


	Q.Display();

}
