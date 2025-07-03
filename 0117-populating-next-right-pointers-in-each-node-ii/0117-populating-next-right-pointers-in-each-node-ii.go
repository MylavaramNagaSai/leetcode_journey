func connect(root *Node) *Node {
    if root == nil {
        return nil
    }

    curr := root

    for curr != nil {
        dummy := &Node{}
        tail := dummy

        for curr != nil {
            if curr.Left != nil {
                tail.Next = curr.Left
                tail = tail.Next
            }
            if curr.Right != nil {
                tail.Next = curr.Right
                tail = tail.Next
            }
            curr = curr.Next
        }

        curr = dummy.Next
    }

    return root
}
