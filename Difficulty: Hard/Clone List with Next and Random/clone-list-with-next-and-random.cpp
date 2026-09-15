/* Structure of Linked List Node
class Node {
	public:
	int data;
	Node* next;
	Node* random;
	
	Node(int x) {
		data = x;
		next = random = nullptr;
	}
}; */

class Solution {
	public:
	Node* insertNodesinBetween(Node* head) {
		Node* curr = head;
		while (curr) {
			Node* copyNode = new Node(curr->data);
			Node* nxt = curr->next;
			copyNode->next = nxt;
			curr->next = copyNode;
			curr = nxt;
		}
		return head;
	}
	Node* setRandomPointers(Node* head) {
		Node* curr = head;
		while (curr) {
			Node* copyNode = curr->next;
			copyNode->random = (!curr->random ? nullptr : curr->random->next);
			curr = copyNode->next;
		}
		return head;
	}
	Node* setNextPointers(Node* head) {
		Node* curr = head;
		if (!head || !head->next)
			return head;
		Node* copyHead = head->next;
		while (curr) {
			Node* copy = curr->next;
			curr->next = copy->next;
			copy->next = (copy->next ? copy->next->next : nullptr);
			curr = curr->next;
		}
		return copyHead;
	}
	void displayList(Node* head) {
		Node* curr = head;
		while (curr) {
			cout << curr->data << " ";
			curr = curr->next;
		}
	}
	Node* cloneLinkedList(Node* head) {
		insertNodesinBetween(head);
		// 		displayList(head);
		setRandomPointers(head);
		return setNextPointers(head);
	}
};
