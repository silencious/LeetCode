#include <cstddef>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class AddTwoNumbers {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if(l1==NULL){
			return l2;
		}else if(l2==NULL){
			return l1;
		}
		int v1=l1->val,v2=l2->val;
		bool one=(v1+v2)>=10;
		l1->val=(v1+v2)%10;
		if(one){
			l1->next=addTwoNumbers(l1->next,new ListNode(1));
		}
		l1->next=addTwoNumbers(l1->next,l2->next);
		return l1;
	}
	ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
		ListNode* p1=l1,*p2=l2,hd(0),*tl=&hd;
		int acc=0;
		while(p1!=NULL||p2!=NULL){
			if(p1!=NULL){
				acc+=p1->val;
				p1=p1->next;
			}
			if(p2!=NULL){
				acc+=p2->val;
				p2=p2->next;
			}
			tl->next=new ListNode(acc%10);
			tl=tl->next;
			acc/=10;
		}
		if(acc>0){
			tl->next=new ListNode(acc);
		}
		return hd.next;
	}
	ListNode* addTwoNumbers3(ListNode* l1, ListNode* l2) {
		ListNode hd(0),*tl=&hd;
		int acc=0;
		while(l1||l2||acc){
			acc=(l1?l1->val:0)+(l2?l2->val:0)+acc;
			tl->next=new ListNode(acc%10);
			tl=tl->next;
			acc/=10;
			l1=l1?l1->next:l1;
			l2=l2?l2->next:l2;
		}
		return hd.next;
	}
};