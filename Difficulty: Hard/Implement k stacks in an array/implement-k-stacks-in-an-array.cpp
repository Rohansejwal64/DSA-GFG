class kStacks {
    int *arr;      // stores actual elements
    int *top;      // top index of each stack
    int *next;     // next free index or next element index in a stack
    int freespot;  // head of free list
    int n, k;

public:
    kStacks(int n, int k) {
        this->n = n;
        this->k = k;
        arr = new int[n];
        top = new int[k];
        next = new int[n];

        // all stacks empty
        for (int i = 0; i < k; ++i) top[i] = -1;

        // initialize free list
        for (int i = 0; i < n - 1; ++i) next[i] = i + 1;
        next[n - 1] = -1;
        freespot = 0;
    }

    ~kStacks() {
        delete[] arr;
        delete[] top;
        delete[] next;
    }

private:
    // convert incoming index to zero-based internal index.
    // Accepts either 0..k-1 or 1..k. Returns -1 if invalid.
    int normalizeIndex(int i) {
        if (i >= 0 && i < k) return i;        // already 0-based
        if (i >= 1 && i <= k) return i - 1;   // 1-based -> convert
        return -1;                            // invalid
    }

public:
    void push(int x, int i) {
        int idx = normalizeIndex(i);
        if (idx == -1) return;            // invalid stack number, ignore
        if (freespot == -1) return;       // overflow, no space

        int insertAt = freespot;
        freespot = next[insertAt];        // advance free list

        arr[insertAt] = x;
        next[insertAt] = top[idx];        // link to previous top
        top[idx] = insertAt;              // new top
    }

    int pop(int i) {
        int idx = normalizeIndex(i);
        if (idx == -1) return -1;         // invalid stack number

        if (top[idx] == -1) return -1;    // underflow

        int topIndex = top[idx];
        int value = arr[topIndex];

        top[idx] = next[topIndex];        // move top to next element
        // add freed slot to free list
        next[topIndex] = freespot;
        freespot = topIndex;

        return value;
    }
};