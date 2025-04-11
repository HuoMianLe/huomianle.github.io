### 题目要求

按照升序顺序合并两个递增链表

[题目连接](https://leetcode.cn/problems/merge-two-sorted-lists/description/)



### C++代码

```c++
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

```



### Python代码

```python
class ListNode:
    def __init__(self, val=-1, next=None):
        self.val = val
        self.next = next


class LinkList:
    def create_list(self, values):
        dummy = ListNode()
        current = dummy
        for val in values:
            current.next = ListNode(val)
            current = current.next
        return dummy.next

    def merge_list(self, list1: ListNode, list2: ListNode):
        dummy = ListNode()
        current = dummy
        p1 = list1
        p2 = list2

        while p1 and p2:
            if p1.val < p2.val:
                current.next = p1
                p1 = p1.next
            else:
                current.next = p2
                p2 = p2.next
            current = current.next

        if p1 is not None:
            current.next = p1

        if p2 is not None:
            current.next = p2

        return dummy.next

    def print_list(self, list: ListNode):
        values = []
        current = list
        while current:
            values.append(str(current.val))
            current = current.next
        print("->".join(values))


if __name__ == "__main__":
    linkList = LinkList()
    list1 = linkList.create_list([1, 3, 5])
    list2 = linkList.create_list([2, 4, 6])
    merged_list = linkList.merge_list(list1, list2)
    linkList.print_list(merged_list)

```

