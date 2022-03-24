"""
Given:
	1. Non empty arrays
Does the second array a subseq of the first one?
	?? sub sequence means that we preserve the order of elements?
	?? or just the first one contains all the elements of the second one regardless the order
Here we don't care about the ordering...

Does one element assert the condition?

compare all items with each others 
	--> Time compelexity O(mxn)
		- m ,n length of both arrays.

My solution:
 convert the big one into a tree(balanced) then search through it 
 which takes O(Log(n)) rather than O(n). 
 
 then go through and compare each element of subsequence m.
 
 exepected time complexity : O(log(n)) + O(m) rather than O(m*n)...
"""

# Binary tree construction
# binary tree properities:
# left child is smaller than the parent.
# right child is bigger than the parent.
# each node points to both childs left and right.
# each node has a value.


class Node:
    def __init__(self, val: int, arr_index: int):
        self.left = None
        self.right = None
        self.value = val
        self.index = arr_index
# Recursive technique


def insert(node, val: int, arr_index):
    # return new node if tree is empty
    if node == None:
        return Node(val, arr_index)

    if val > node.value:
        node.right = insert(node.right, val, arr_index)

    else:
        node.left = insert(node.left, val, arr_index)

    return node


def construct_binary_tree(array):
    root = None
    for item_index in range(len(array)):
        root = insert(root, array[item_index], item_index)
    return root


def bt_search(element, tree) -> int:
    while tree:
        if element < tree.value:
            tree = tree.left
        elif element > tree.value:
            tree = tree.right
        elif element == tree.value:
            return tree.index
    return None


def isValidSubsequence(array, sequence):
    tree = construct_binary_tree(array)
    visited = []
    for item in sequence:
        index = bt_search(item, tree)
        if (index == None) or (index in visited):
            return False
        if index not in visited:
            visited.append(index)

    return True


if __name__ == "__main__":
    a1 = [1, 1, 1, 1, 1]
    a2 = [1, 1, 1]
    s = isValidSubsequence(a1, a2)
    print(s)
