/* Structure of linked list Node
class Node {
	public:
	int data;
	Node* next;
	
	Node(int x) {
		data = x;
		next = nullptr;
	}
}; */

class Solution {
	public:
	int cntNodes(Node* head) {
		int cnt = 0;
		Node* curr = head;
		while (curr) {
			cnt += 1;
			curr = curr->next;
		}
		return cnt;
	}
	Node *reverseKGroup(Node *head, int k) {
		if (!head || !head->next)
			return head;
		int len = cntNodes(head);
		
		Node* dummy = new Node(-1);
		dummy->next = head;
		Node* curr = head;
		
		Node* start = dummy;
		while (len >= k) {
			Node* end = start->next;
			Node* prev = nullptr, *curr = end;
			Node* nxt = nullptr;
			for (int i = 0; i < k; i++) {
				nxt = curr->next;
				curr->next = prev;
				prev = curr;
				curr = nxt;
			}
			start->next = prev;
			end->next = curr;
			start = end;
			len -= k;
		}
		if(len > 0) {
			Node* end = start->next;
			Node* prev = nullptr, *curr = end;
			Node* nxt = nullptr;
			for (int i = 0; i < len; i++) {
				nxt = curr->next;
				curr->next = prev;
				prev = curr;
				curr = nxt;
			}
			start->next = prev;
			end->next = curr;
			start = end;
		}
		return dummy->next;
	}
};
