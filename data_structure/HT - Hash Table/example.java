import java.util.ArrayList;
import java.util.List;

public class HashTable {
    private static final int hashGroups = 10;
    private List<Entry<String, String>>[] table;

    public HashTable() {
        table = new ArrayList[hashGroups];
        for (int i = 0; i < hashGroups; i++) {
            table[i] = new ArrayList<>();
        }
    }

    public boolean isEmpty() {
        int sum = 0;
        for (List<Entry<String, String>> cell : table) {
            sum += cell.size();
        }
        if (sum == 0) {
            return true;
        }
        return false;
    }

    private int hashFunction(String key) {
        int hash = 0;
        for (char character : key.toCharArray()) {
            hash += character;
        }
        return hash % hashGroups;
    }

    public void add(String key, String value) {
        int hashValue = hashFunction(key);
        List<Entry<String, String>> cell = table[hashValue];
        boolean keyExists = false;
        for (Entry<String, String> elem : cell) {
            if (elem.getKey().equals(key)) {
                keyExists = true;
                elem.setValue(value);
                System.out.println("[WARNING] Key exists, value replaced.");
                break;
            }
        }
        if (!keyExists) {
            cell.add(new SimpleEntry<>(key, value));
        }
    }

    public String recover(String key) {
        int hashValue = hashFunction(key);
        List<Entry<String, String>> cell = table[hashValue];
        for (Entry<String, String> elem : cell) {
            if (elem.getKey().equals(key)) {
                return elem.getValue();
            }
        }
        System.out.println("[WARNING] Key not found.");
        return "";
    }

    public void remove(String key) {
        int hashValue = hashFunction(key);
        List<Entry<String, String>> cell = table[hashValue];
        boolean keyExists = false;
        for (Entry<String, String> elem : cell) {
            if (elem.getKey().equals(key)) {
                keyExists = true;
                cell.remove(elem);
                System.out.println("[INFO] Key deleted.");
                break;
            }
        }
        if (!keyExists) {
            System.out.println("[WARNING] Key not found, not deleted.");
        }
    }

    public void printTable() {
        for (int i = 0; i < hashGroups; i++) {
            if (table[i].size() == 0) {
                continue;
            }
            System.out.print(i + ": ");
            for (Entry<String, String> elem : table[i]) {
                System.out.print(elem.getKey() + ":" + elem.getValue() + " ");
            }
            System.out.println();
        }
    }
}
