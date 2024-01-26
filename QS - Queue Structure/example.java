import java.util.EmptyStackException;

public class Queue<T> {
    private static final int CAPACITY = 10;
    private int front, rear;
    private T[] data;

    public Queue() {
        data = (T[]) new Object[CAPACITY];
        front = 0;
        rear = -1;
    }

    public void enqueue(T value) {
        if (rear == CAPACITY - 1) {
            throw new RuntimeException("Queue is full!");
        } else {
            data[++rear] = value;
        }
    }

    public T dequeue() {
        if (front > rear) {
            throw new EmptyStackException();
        }
        return data[front++];
    }

    public boolean isEmpty() {
        return (front > rear);
    }
}

public class Main {
    public static void main(String[] args) {
        Queue<Integer> q = new Queue<>();
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);

        System.out.println(q.dequeue());
        System.out.println(q.dequeue());
        System.out.println(q.dequeue());
    }
}
