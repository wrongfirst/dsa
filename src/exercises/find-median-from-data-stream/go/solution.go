type MedianFinder struct {
    small []int // maxHeap
    large []int // minHeap
}


func Constructor() MedianFinder {
    return MedianFinder{
        small: []int{},
        large: []int{},
    }
}


func (this *MedianFinder) AddNum(num int)  {
    if len(this.large) > 0 && num > this.large[0] {
        heap.Push(&minHeap{&this.large}, num)
    } else {
        heap.Push(&maxHeap{&this.small}, num)
    }
    
    if len(this.small) > len(this.large)+1 {
        val := heap.Pop(&maxHeap{&this.small}).(int)
        heap.Push(&minHeap{&this.large}, val)
    }
    if len(this.large) > len(this.small)+1 {
        val := heap.Pop(&minHeap{&this.large}).(int)
        heap.Push(&maxHeap{&this.small}, val)
    }
}


func (this *MedianFinder) FindMedian() float64 {
    if len(this.small) > len(this.large) {
        return float64(this.small[0])
    } else if len(this.large) > len(this.small) {
        return float64(this.large[0])
    }
    return (float64(this.small[0]) + float64(this.large[0])) / 2.0
}

type maxHeap struct {
    nums *[]int
}

func (h maxHeap) Len() int           { return len(*h.nums) }
func (h maxHeap) Less(i, j int) bool { return (*h.nums)[i] > (*h.nums)[j] }
func (h maxHeap) Swap(i, j int)      { (*h.nums)[i], (*h.nums)[j] = (*h.nums)[j], (*h.nums)[i] }

func (h *maxHeap) Push(x interface{}) {
    *h.nums = append(*h.nums, x.(int))
}

func (h *maxHeap) Pop() interface{} {
    old := *h.nums
    n := len(old)
    x := old[n-1]
    *h.nums = old[0 : n-1]
    return x
}

type minHeap struct {
    nums *[]int
}

func (h minHeap) Len() int           { return len(*h.nums) }
func (h minHeap) Less(i, j int) bool { return (*h.nums)[i] < (*h.nums)[j] }
func (h minHeap) Swap(i, j int)      { (*h.nums)[i], (*h.nums)[j] = (*h.nums)[j], (*h.nums)[i] }

func (h *minHeap) Push(x interface{}) {
    *h.nums = append(*h.nums, x.(int))
}

func (h *minHeap) Pop() interface{} {
    old := *h.nums
    n := len(old)
    x := old[n-1]
    *h.nums = old[0 : n-1]
    return x
}
