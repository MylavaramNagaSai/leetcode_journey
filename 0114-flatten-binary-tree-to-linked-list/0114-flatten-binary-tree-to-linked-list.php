<?php
class Solution {
    function flatten($root) {
        $this->prev = null;
        $this->helper($root);
    }

    private function helper($node) {
        if ($node === null) return;

        $this->helper($node->right);
        $this->helper($node->left);

        $node->right = $this->prev;
        $node->left = null;
        $this->prev = $node;
    }
}
?>
