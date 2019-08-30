class Solution {

    fun medianSlidingWindow(nums: IntArray, k: Int): DoubleArray {

        var maxHeap = Heap(compareBy<Int> { it })
        var minHeap = Heap(compareBy<Int> { it }.reversed())

        var prev = MutableList<Heap.Node<Int>?>(nums.size) { null }
        var even = k.rem(2) == 0
        var finalArr = DoubleArray(nums.size - k + 1)


        for (i in 0 until k) {
            if (maxHeap.size == 0 || nums[i] < maxHeap.nodes[0]!!.info) {
                prev[i] = maxHeap.add(nums[i], i)
            } else {
                prev[i] = minHeap.add(nums[i], i)
            }
            if (maxHeap.size < minHeap.size) {
                val topRight = minHeap.nodes[0]
                val topRightValue = topRight!!.info
                val topRightExtra = topRight.extra
                prev[topRightExtra] = maxHeap.add(topRightValue, topRightExtra)
                minHeap.remove(topRight)
            } else if (maxHeap.size - 1 > minHeap.size) {
                val topLeft = maxHeap.nodes[0]
                val topLeftValue = topLeft!!.info
                val topLeftExtra = topLeft.extra
                prev[topLeftExtra] = minHeap.add(topLeftValue, topLeftExtra)
                maxHeap.remove(topLeft)
            }
        }


        for (i in k until nums.size) {


            if (even)
                finalArr[i - k] = (maxHeap.nodes[0]!!.info.toDouble() + minHeap.nodes[0]!!.info.toDouble()) / 2.0
            else
                finalArr[i - k] = maxHeap.nodes[0]!!.info.toDouble()

            if (maxHeap.size == 0 || nums[i] < maxHeap.nodes[0]!!.info) {
                prev[i] = maxHeap.add(nums[i], i)
            } else {
                prev[i] = minHeap.add(nums[i], i)
            }
            minHeap.remove(prev[i - k]!!)
            maxHeap.remove(prev[i - k]!!)
            while (maxHeap.size < minHeap.size) {
                val topRight = minHeap.nodes[0]
                val topRightValue = topRight!!.info
                val topRightExtra = topRight.extra
                prev[topRightExtra] = maxHeap.add(topRightValue, topRightExtra)
                minHeap.remove(topRight)
            }
            while (maxHeap.size - 1 > minHeap.size) {
                val topLeft = maxHeap.nodes[0]
                val topLeftValue = topLeft!!.info
                val topLeftExtra = topLeft.extra
                prev[topLeftExtra] = minHeap.add(topLeftValue, topLeftExtra)
                maxHeap.remove(topLeft)
            }
        }
        if (even)
            finalArr[nums.size - k] = (maxHeap.nodes[0]!!.info.toDouble() + minHeap.nodes[0]!!.info.toDouble()) / 2.0
        else
            finalArr[nums.size - k] = maxHeap.nodes[0]!!.info.toDouble()

       return finalArr
    }

    class Heap<T>(var comparator: Comparator<T>) {
        var nodes = ArrayList<Node<T>?>();
        var size = 0

        data class Node<T>(var info: T, var pos: Int, var extra: Int) {}

        fun add(value: T, extra: Int): Node<T> {
            size += 1
            val newNode = Node<T>(value, nodes.size, extra)
            nodes.add(newNode)
            while (newNode.pos > 0) {
                val parentIdx = (newNode.pos - 1) / 2
                val parent = nodes[parentIdx]
                if (parent == null) {
                    nodes[newNode.pos] = null
                    nodes[parentIdx] = newNode
                    newNode.pos = parentIdx
                } else if (comparator.compare(newNode.info, parent.info) > 0) {
                    parent.pos = newNode.pos
                    newNode.pos = parentIdx
                    nodes[newNode.pos] = newNode
                    nodes[parent.pos] = parent
                } else {
                    break;
                }
            }
            return newNode
        }

        fun remove(node: Node<T>) {
            if (node.pos < nodes.size && node == nodes[node.pos]) {
                size -= 1
                var leftIdx = node.pos * 2 + 1
                var rightIdx = node.pos * 2 + 2
                var leftNode = if (leftIdx < nodes.size) nodes[leftIdx] else null
                var rightNode = if (rightIdx < nodes.size) nodes[rightIdx] else null
                while (leftNode != null || rightNode != null) {
                    if (leftNode == null || (rightNode != null && comparator.compare(rightNode.info, leftNode.info) > 0)) {
                        nodes[node.pos] = rightNode
                        nodes[rightIdx] = node
                        rightNode!!.pos = node.pos
                        node.pos = rightIdx
                    } else {
                        nodes[node.pos] = leftNode
                        nodes[leftIdx] = node
                        leftNode.pos = node.pos
                        node.pos = leftIdx
                    }
                    leftIdx = node.pos * 2 + 1
                    rightIdx = node.pos * 2 + 2
                    leftNode = if (leftIdx < nodes.size) nodes[leftIdx] else null
                    rightNode = if (rightIdx < nodes.size) nodes[rightIdx] else null
                }
                nodes[node.pos] = null
            }
        }
    }
}
