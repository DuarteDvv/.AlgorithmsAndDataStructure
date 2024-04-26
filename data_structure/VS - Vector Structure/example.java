import java.util.ConcurrentModificationException;

public class Vector {
    private int[] arr;
    private int capacity;
    private int size;
    private int modCount;

    public Vector() {
        capacity = 1;
        arr = new int[capacity];
        size = 0;
        modCount = 0;
    }

    public Vector(Vector other) {
        this.arr = other.arr;
        this.capacity = other.capacity;
        this.size = other.size;
        this.modCount = other.modCount;
        this.arr = new int[capacity];
        System.arraycopy(other.arr, 0, this.arr, 0, size);
    }

    public Vector& operator=(Vector other) {
        if (this != &other) {
            this.arr = other.arr;
            this.capacity = other.capacity;
            this.size = other.size;
            this.modCount = other.modCount;
            this.arr = new int[capacity];
            System.arraycopy(other.arr, 0, this.arr, 0, size);
        }
        return *this;
    }

    public void push_back(int value) {
        if (size == capacity) {
            capacity *= 2;
            int[] newArr = new int[capacity];
            System.arraycopy(arr, 0, newArr, 0, size);
            arr = newArr;
        }
        arr[size] = value;
        size++;
        modCount++;
    }

    public void remove(int index) {
        if (index < 0 || index >= size) {
            throw new ConcurrentModificationException("Index out of range");
        }
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        modCount++;
    }

    public int at(int index) {
        if (index < 0 || index >= size) {
            throw new ConcurrentModificationException("Index out of range");
        }
        return arr[index];
    }

    public int size() {
        return size;
    }

    public int getModCount() {
        return modCount;
    }
}

public class Main {
    public static void main(String[] args) {
        Vector v1 = new Vector();
        v1.push_back(10);
        v1.push_back(20);
        v1.push_back(30);

        Vector v2 = new Vector(v1);
        Vector v3 = v1;

        for (int i = 0; i < v1.size(); i++) {
            System.out.print(v1.at(i) + " ");
        }
        System.out.println();

        v1.remove(1);

        for (int i = 0; i < v1.size(); i++) {
            System.out.print(v1.at(i) + " ");
        }
        System.out.println();

        System.out.println(v1.getModCount());
        System.out.println(v2.getModCount());
        System.out.println(v3.getModCount());
    }
}
