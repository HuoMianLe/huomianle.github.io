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
