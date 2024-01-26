#include <vector>
#include <stdexcept>

template <typename T>
class HeapMin {
private:
    std::vector<T> heap;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void heapify_down(int i) {
        int smallest = i;
        int left = this->left(i);
        int right = this->right(i);

        if (left < (int)heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }

        if (right < (int)heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != i) {
            std::swap(heap[i], heap[smallest]);
            heapify_down(smallest);
        }
    }

    void heapify_up(int i) {
        while (i != 0 && heap[parent(i)] > heap[i]) {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:
    void insert(const T& value) {
        heap.push_back(value);
        heapify_up(heap.size() - 1);
    }

    T extract_min() {
        if (heap.empty()) {
            throw std::runtime_error("Heap is empty");
        }

        T min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify_down(0);

        return min;
    }

    bool is_empty() const {
        return heap.empty();
    }

    size_t size() const {
        return heap.size();
    }
};
