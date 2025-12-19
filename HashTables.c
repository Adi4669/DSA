#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int HTsize;

struct Employee {
    int key;
    int data;
};

struct Employee HT[MAX];

int hashFunction(int key) {
    return key % HTsize;
}

void initHT(int size) {
    HTsize = size;
    for (int i = 0; i < size; i++) {
        HT[i].key = -1;
        HT[i].data = 0;
    }
}

void insert(int key, int data) {
    int index = hashFunction(key);
    while (HT[index].key != -1) {
        // if (HT[index].key == key) {
        //     HT[index].data = data;
        //     return;
        // }
        index = (index + 1) % HTsize;
    }
    HT[index].key = key;
    HT[index].data = data;
}

int search(int key) {
    int index = hashFunction(key);
    while (HT[index].key != -1) {
        if (HT[index].key == key) {
            return index;
        }
        index = (index + 1) % HTsize;
    }
    return -1;
}

void printHT() {
    for (int i = 0; i < HTsize; i++) {
        if (HT[i].key != -1) {
            printf("Index %d: Key %d, Data %d\n", i, HT[i].key, HT[i].data);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
}

int main() {
    int m = 10;
    initHT(m);

    insert(1234, 1001);
    insert(1232, 1002);
    insert(1357, 1003);
    insert(1345, 1004);
    insert(1234, 1005);

    printf("Hash Table contents:\n");
    printHT();

    int keyToSearch = 1357;
    int index = search(keyToSearch);
    if (index != -1) {
        printf("Found key %d at index %d with data %d\n", keyToSearch, index, HT[index].data);
    } else {
        printf("NOT FOUND.\n");
    }

    return 0;
}