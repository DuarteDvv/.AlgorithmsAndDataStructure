<!DOCTYPE html>
<html>

<body>
    <h1>Heap Data Structure</h1>
    <p>
        A heap is a tree-like data structure that satisfies the heap property. It can be divided into two main types: min heap and max heap. In a min heap, the value of the parent is always less than or equal to the value of the children. In a max heap, the value of the parent is always greater than or equal to the value of the children.
    </p>
    <p>
        The heap property is maintained by the "heapify" process. This means that for any node present in the heap, its value is always less than or equal to the value of its children. This is useful for various operations, such as finding the minimum element in a min heap or inserting a new element.
    </p>
    <h2>Advantages of Heap</h2>
    <ul>
        <li>Efficient for determining the minimum or maximum element (for min heap and max heap, respectively).</li>
        <li>Efficient for inserting elements (insertion into a heap can be done in O(log n) time).</li>
        <li>Allows for efficient implementation of algorithms such as HeapSort, Dijkstra, and Prim.</li>
    </ul>
    <h2>Disadvantages of Heap</h2>
    <ul>
        <li>Complex removal of arbitrary elements.</li>
        <li>Complex dynamic memory allocation for heap nodes.</li>
        <li>Data organization in the heap may consume extra space.</li>
    </ul>
    <p>
        To address some of these disadvantages, heap implementations sometimes include a linked representation. In this case, each node in the heap stores a reference to the left child and, optionally, to the right sibling. This representation allows for the insertion and removal of elements in O(log n) time, in addition to providing direct access to the elements stored in the heap.
    </p>
    <p>
        The heap implementation shown in the example above uses an array-based representation. The parent and child nodes are indexed by simple formulas, simplifying heap manipulation. The time complexity for basic operations (inserting and extracting the minimum element) is maintained at O(log n), where n is the number of elements in the heap.
    </p>
