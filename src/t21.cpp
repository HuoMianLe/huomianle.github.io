// t21: Merge Two Sorted Linked Lists

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *ptr) : val(x), next(ptr) {}
};

class LinkList {
public:
  ListNode *mergeTwoList(ListNode *list1, ListNode *list2) {
    ListNode dummy(-1), *p = &dummy;
    ListNode *p1 = list1, *p2 = list2;
    while (p1 != nullptr && p2 != nullptr) {
      if (p1->val <= p2->val) {
        p->next = p1;
        p1 = p1->next;
      } else {
        p->next = p2;
        p2 = p2->next;
      }
      p = p->next;
    }
    if (p1 != nullptr) {
      p->next = p1;
    }
    if (p2 != nullptr) {
      p->next = p2;
    }
    return dummy.next;
  }
};

int main() {
  ListNode *list1 = new ListNode(2);
  list1->next = new ListNode(4);
  list1->next->next = new ListNode(6);

  ListNode *list2 = new ListNode(1);
  list2->next = new ListNode(3);
  list2->next->next = new ListNode(5);

  LinkList linkList;
  ListNode *merged_list = linkList.mergeTwoList(list1, list2);

  while (merged_list != nullptr) {
    std::cout << merged_list->val;
    merged_list = merged_list->next;
    if (merged_list != nullptr)
      std::cout << " ";
    else
      std::cout << std::endl;
  }
  getchar();
  return 0;
}
