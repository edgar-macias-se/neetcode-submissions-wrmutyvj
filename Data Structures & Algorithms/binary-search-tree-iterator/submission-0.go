type BSTIterator struct {
    stack []*TreeNode
}

func Constructor(root *TreeNode) BSTIterator {
    iterator := BSTIterator{
        stack: []*TreeNode{},
    }
    // Pushear todo el camino izquierdo desde root
    iterator.pushLeftPath(root)
    return iterator
}

// Helper: Pushear todo el camino izquierdo desde node
func (this *BSTIterator) pushLeftPath(node *TreeNode) {
    for node != nil {
        this.stack = append(this.stack, node)
        node = node.Left
    }
}

func (this *BSTIterator) Next() int {
    // Pop del stack
    n := len(this.stack)
    node := this.stack[n-1]
    this.stack = this.stack[:n-1]
    
    // Si tiene hijo derecho, pushear su camino izquierdo
    if node.Right != nil {
        this.pushLeftPath(node.Right)
    }
    
    return node.Val
}

func (this *BSTIterator) HasNext() bool {
    return len(this.stack) > 0
}