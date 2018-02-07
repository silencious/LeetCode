
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class LinkedListCycle {
public:
	bool hasCycle(ListNode *head) {
		if(!head) return false;
		auto p=head;
		while(p->next){
			if(p->next->next==head){
				return true;
			}
			auto t=p;
			p=p->next;
			t->next=head;
		}
		return false;
	}
};