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
	Queue() {
		
		back = NULL;
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

	void deQueue() {

		if (isEmpty()) {
			cout << "Queue is empty! ";
			return;
		}
		Node* temp = back->next;
		back->next = temp->next;
		delete temp;






	}
	void Display() {
		Node* temp = back->next;
		if (isEmpty()) {
			cout << "Queue is empty!";

		}
		else {

			while (temp != NULL) {
				cout << temp->value << " ";
				temp = temp->next;
			}


		}
	}



};
int main() {
	
	CircularQueue Q;
	Q.enQueue(1);

	Q.Display();

}