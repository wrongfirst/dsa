package main

import (
	"fmt"
	"os"
	"reflect"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type Node struct {
	Val       int
	Neighbors []*Node
}

type Interval struct {
	start int
	end   int
}


func MakeInt(v int) *int {
	return &v
}

func ListToLinkedList(arr []int) *ListNode {
	if len(arr) == 0 {
		return nil
	}
	head := &ListNode{Val: arr[0]}
	curr := head
	for i := 1; i < len(arr); i++ {
		curr.Next = &ListNode{Val: arr[i]}
		curr = curr.Next
	}
	return head
}

func LinkedListToList(head *ListNode) []int {
	res := []int{}
	curr := head
	visited := make(map[*ListNode]bool)
	for curr != nil {
		if visited[curr] {
			break
		}
		visited[curr] = true
		res = append(res, curr.Val)
		curr = curr.Next
	}
	return res
}

func IntsToTree(vals ...int) *TreeNode {
	if len(vals) == 0 {
		return nil
	}
	root := &TreeNode{Val: vals[0]}
	queue := []*TreeNode{root}
	i := 1
	for len(queue) > 0 && i < len(vals) {
		node := queue[0]
		queue = queue[1:]
		if i < len(vals) {
			node.Left = &TreeNode{Val: vals[i]}
			queue = append(queue, node.Left)
		}
		i++
		if i < len(vals) {
			node.Right = &TreeNode{Val: vals[i]}
			queue = append(queue, node.Right)
		}
		i++
	}
	return root
}

func TreeToInts(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}
	res := []int{}
	queue := []*TreeNode{root}
	for len(queue) > 0 {
		node := queue[0]
		queue = queue[1:]
		if node != nil {
			res = append(res, node.Val)
			queue = append(queue, node.Left)
			queue = append(queue, node.Right)
		}
	}
	for len(res) > 0 && res[len(res)-1] == 0 && len(res) > 1 {
		// trim trailing zeroes if needed or handle simple trees
	}
	return res
}

func ListToTree(arr []*int) *TreeNode {
	if len(arr) == 0 || arr[0] == nil {
		return nil
	}
	root := &TreeNode{Val: *arr[0]}
	queue := []*TreeNode{root}
	i := 1
	for len(queue) > 0 && i < len(arr) {
		node := queue[0]
		queue = queue[1:]
		if i < len(arr) && arr[i] != nil {
			node.Left = &TreeNode{Val: *arr[i]}
			queue = append(queue, node.Left)
		}
		i++
		if i < len(arr) && arr[i] != nil {
			node.Right = &TreeNode{Val: *arr[i]}
			queue = append(queue, node.Right)
		}
		i++
	}
	return root
}

func TreeToList(root *TreeNode) []*int {
	if root == nil {
		return []*int{}
	}
	res := []*int{}
	queue := []*TreeNode{root}
	for len(queue) > 0 {
		node := queue[0]
		queue = queue[1:]
		if node != nil {
			val := node.Val
			res = append(res, &val)
			queue = append(queue, node.Left)
			queue = append(queue, node.Right)
		} else {
			res = append(res, nil)
		}
	}
	for len(res) > 0 && res[len(res)-1] == nil {
		res = res[:len(res)-1]
	}
	return res
}

type TestHarness struct{}

var Tests TestHarness

func (t TestHarness) BoolCheck(msg string, b bool) {
	if b {
		fmt.Printf("Test passed: %s\n", msg)
	} else {
		fmt.Printf("Test failed: %s\n", msg)
		os.Exit(1)
	}
}

func (t TestHarness) EqualCheck(msg string, expected, actual interface{}) {
	if reflect.DeepEqual(expected, actual) {
		fmt.Printf("Test passed: %s\n", msg)
	} else {
		fmt.Printf("Test failed: %s\nExpected: %#v\nActual:   %#v\n", msg, expected, actual)
		os.Exit(1)
	}
}

