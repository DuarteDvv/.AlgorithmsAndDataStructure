import java.util.ArrayList;
import java.util.List;

public class Stack {
    private List<Integer> data;

    public Stack() {
        data = new ArrayList<>();
    }

    public void push(int value) {
        data.add(value);
    }

    
    public void pop() {
        if (!isEmpty()) {
            data.remove(data.size() - 1);
        }
    }

    
    public boolean isEmpty() {
        return data.isEmpty();
    }

    
    public int top() {
        if (!isEmpty()) {
            return data.get(data.size() - 1);
        }
        return -1;
    }

    public static void main(String[] args) {
        
        Stack myStack = new Stack();

        
        myStack.push(5);
        myStack.push(10);
        myStack.push(20);

        System.out.println("Top element: " + myStack.top());

      
        myStack.pop();

        
        if (myStack.isEmpty()) {
            System.out.println("Stack is empty.");
        } else {
            System.out.println("Stack is not empty.");
        }
    }
}
