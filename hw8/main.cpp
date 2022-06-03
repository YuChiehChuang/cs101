#include <iostream>

using namespace std;

class Node {
	public:
		int data;
		Node* next;
		Node(int n) {
			data = n;
			next = NULL;
		}
};

class LinkedList {
	private:
		Node* head;
		
	public:
		LinkedList() {
			head = NULL;
		}
		
		~LinkedList() {
			Node* p;
			while(head != NULL) {
				p = head;
				head = head -> next;
				cout << "free([" << p->data << "])->";
				delete p;
			}
			cout << "null" << endl;
		}
		
		void append_node(int newData) {
			Node* newNode = new Node(newData);
			if(head == NULL) {
				head = newNode;
				cout << "[" << head->data << "]" << endl;
				return;
			}
			Node* list = head;
			while(list->next != NULL) {
				list = list->next;
			}
			list->next = newNode;
			
			Node* current = head;
			while(current != NULL) {
				cout << "[" << current->data <<"]->";
				current = current->next;
			}
			cout << "null" << endl;
		}
		
		void del_node(int n) {
			Node* hhead = new Node(0);
			hhead->next = head;
			
			int count = 0;
			Node* p = hhead;
			while(count != n) {
				p = p->next;
				count++;
			}
			Node* deleteNode = p->next;
			p->next = deleteNode->next;
			delete deleteNode;
			
			Node* current = head;
			while(current != NULL) {
				cout << "[" << current->data <<"]->";
				current = current->next;
			}
			cout << "null" << endl;
		}
		
};

int main() {
	LinkedList mylink;
	mylink.append_node(0);
	mylink.append_node(1);
	mylink.append_node(2);
	mylink.append_node(3);
	mylink.del_node(1);
	return 0;
}
