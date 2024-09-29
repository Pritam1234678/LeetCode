class MyCircularQueue {
public:
    int f, b, c, size;
    vector<int> arr;
    MyCircularQueue(int k) {
        f = b = size = 0;
        c = k;
        arr.resize(k);
        c = k;
    }

    bool enQueue(int value) {
        if (size == c) {
            return false;
        }

        arr[b] = value;
        b = (b + 1) % c;
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {

            return false;
        } else {
            f = (f + 1) % c;
            size--;
        }
        return true;
    }

    int Front() {
        if (isEmpty()) {

            return -1;
        }
        return arr[f];
    }

    int Rear() {
        if (isEmpty()) {

            return -1;
        }
        return arr[(b - 1 + c) % c];
    }

    bool isFull() {
        if (size == arr.size()) {
            return true;
        }
        return false;
    }
    bool isEmpty() {
        if (size == 0) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
