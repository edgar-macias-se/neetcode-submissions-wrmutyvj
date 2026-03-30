//Max Heap Logic
type IntMaxHeap []int

func (h IntMaxHeap) Len() int           { return len(h) }
func (h IntMaxHeap) Less(i, j int) bool { return h[i] > h[j] } // Max heap logic
func (h IntMaxHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntMaxHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntMaxHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

//Min Heap Logic
type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] } // Min heap logic
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

type MedianFinder struct {
    minHeap *IntHeap
    maxHeap *IntMaxHeap
}


func Constructor() MedianFinder {
    return MedianFinder {
        minHeap: &IntHeap{},
        maxHeap: &IntMaxHeap{},
    }
}


func (this *MedianFinder) AddNum(num int)  {
    
    if this.minHeap.Len() > 0 {
        largeTop := (*this.minHeap)[0]
        if num > largeTop {
            heap.Push(this.minHeap, num)
        } else {
            heap.Push(this.maxHeap, num)
        }
    } else {
        heap.Push(this.maxHeap, num)
    }
    

    if(this.maxHeap.Len() > this.minHeap.Len() + 1){
        tmpVar := heap.Pop(this.maxHeap)
        heap.Push(this.minHeap, tmpVar)
    } else if (this.minHeap.Len() > this.maxHeap.Len()) {
        tmpVar := heap.Pop(this.minHeap)
        heap.Push(this.maxHeap, tmpVar)
    }
}


func (this *MedianFinder) FindMedian() float64 {
    if this.maxHeap.Len() > this.minHeap.Len() {
        return float64((*this.maxHeap)[0])
    }
    
    if this.minHeap.Len() > this.maxHeap.Len() {
        return float64((*this.minHeap)[0])
    }
    
    return float64((*this.minHeap)[0] + (*this.maxHeap)[0]) / 2.0
    
}