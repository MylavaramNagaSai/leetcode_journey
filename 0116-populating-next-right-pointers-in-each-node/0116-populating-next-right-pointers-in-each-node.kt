class Solution {
    fun connect(root: Node?): Node? {
        var leftmost = root

        while (leftmost?.left != null) {
            var head: Node? = leftmost

            while (head != null) {
                // Safe access since it's a perfect binary tree
                head.left!!.next = head.right

                if (head.next != null) {
                    head.right!!.next = head.next!!.left
                }

                head = head.next
            }

            leftmost = leftmost.left
        }

        return root
    }
}
