#include <iostream>
#include <cstdlib>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode*, ListNode*);
void printListNode(ListNode*);

int main() {
	// List1 and List2 test examples (populated lists)
	// Setup different nodes of list1
	ListNode list1Node1(1);
	ListNode list1Node2(2);
	ListNode list1Node3(4);

	// Link nodes 1-3 of list 1 using the next pointers in each node
	list1Node1.next = &list1Node2;
	list1Node2.next = &list1Node3;
	list1Node3.next = nullptr;

	// Setup different nodes of list2
	ListNode list2Node1(1);
	ListNode list2Node2(3);
	ListNode list2Node3(4);

	// Link nodes 1-3 of list 2 using the next pointers in each node
	list2Node1.next = &list2Node2;
	list2Node2.next = &list2Node3;
	list2Node3.next = nullptr;

	// Attempty to merge previous two lists together and print results
	ListNode* mergedResult = mergeTwoLists(&list1Node1, &list2Node2);
	printListNode(mergedResult);


	// List3 and List4 test examples (null lists)
	// Setup empty nodes of each list
	ListNode list3Node1;
	ListNode list4Node1;

	// Attempt to merge previous two lists together and print
	mergedResult = mergeTwoLists(&list3Node1, &list4Node1);
	printListNode(mergedResult);


	// List5 and list 6 test examples (list5 with one node, and list6 empty)
	// Setup list 5 and 6
	ListNode list5Node1;
	ListNode list6Node1(0);

	// Attempty to merge previous two lists together and print results
	mergedResult = mergeTwoLists(&list5Node1, &list6Node1);
	printListNode(mergedResult);

	system("PAUSE");
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	ListNode dummy(0);
	ListNode* current = &dummy;

	while (list1 != nullptr && list2 != nullptr) {
		if (list1->val < list2->val) {
			current->next = list1;
			list1 = list1->next;
		}
		else {
			current->next = list2;
			list2 = list2->next;
		}
		current = current->next;
	}

	if (list1 != nullptr) {
		current->next = list1;
	}
	else if (list2 != nullptr) {
		current->next = list2; 
	}

	return dummy.next;
}

void printListNode(ListNode* list) {
	while (list != nullptr) {
		cout << list->val << " ";
		list = list->next;
	}
	cout << endl;
}