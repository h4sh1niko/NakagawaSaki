#include <iostream>
#include <stdbool.h>

#define MEIRO_WIDTH 8
#define MEIRO_HEIGHT 8

#define PATH 0 
#define WALL 1 
#define GOAL 2 
#define PASSED 3 

#define MAX_NUM (MEIRO_WIDTH * MEIRO_HEIGHT)

#define QUEUE_SIZE (MAX_NUM + 1)

using namespace std;

typedef struct POS {
    int i; 
    int j;
} POS_T;

typedef struct QUEUE {
    int head;
    int tail;
    POS_T data[QUEUE_SIZE];
} QUEUE_T;

QUEUE_T queue;

static int maze[MEIRO_HEIGHT][MEIRO_WIDTH] = 
{
    {0,0,1,0,0,0,0,0},
    {0,1,1,0,1,0,1,0},
    {0,1,1,0,1,0,1,0},
    {0,0,0,0,1,0,1,0},
    {0,1,0,1,1,1,0,0},
    {0,1,0,1,1,0,0,1},
    {0,0,0,1,1,1,0,1},
    {0,1,0,0,0,1,0,1}
};

void initQueue(QUEUE_T *queue){
    queue->head = 0;
    queue->tail = -1;
}

void enqueue(QUEUE_T *queue, POS_T *input){
    if((queue->tail + 2) % QUEUE_SIZE == queue->head){
        cout << "Queue is full" << endl;
        return;
    }
    queue->tail = (queue->tail + 1) % QUEUE_SIZE;
    queue->data[queue->tail] = *input;
}

POS_T *dequeue(QUEUE_T *queue){
    POS_T *ret;
    if((queue->tail + 1) % QUEUE_SIZE == queue->head){
        cout << "Queue is empty" << endl;
        return NULL;
    }
    ret = &(queue->data[queue->head]);
    queue->head = (queue->head + 1) % QUEUE_SIZE;
    return ret;
}

bool check(int i, int j) {
    bool ret = true;
    if (i < 0 || i >= MEIRO_WIDTH || j < 0 || j >= MEIRO_HEIGHT) {
        ret = false;
    }
    if (maze[j][i] == WALL) {
        ret = false;
    }
    if (maze[j][i] == PASSED) {
        ret = false;
    }
    return ret;
}

bool search(int s_i, int s_j) {
    POS_T pos;
    bool ret;

    if (check(s_i, s_j)) {
        pos.i = s_i; 
        pos.j = s_j; 
        enqueue(&queue, &pos); 
        cout << "Starting Position: (" << s_i << "," << s_j << ")" << endl;
    }

    while (true) {
        int i, j;

        POS_T *next = dequeue(&queue);
        if (next == NULL) {
            ret = false;
            break;
        }
        i = next->i;
        j = next->j;

        if (maze[j][i] == GOAL) {
            cout << "GOAL" << endl;
            ret = true;
            break;
        }

        maze[j][i] = PASSED;

        if (check(i, j - 1)) {
            pos.i = i; 
            pos.j = j - 1; 
            enqueue(&queue, &pos);
            cout << "Current Position: (" << pos.i << "," << pos.j << ")" << endl;
        }

        if (check(i, j + 1)) {
            pos.i = i; 
            pos.j = j + 1; 
            enqueue(&queue, &pos);
            cout << "Current Position: (" << pos.i << "," << pos.j << ")" << endl;
        }

        if (check(i - 1, j)) {
            pos.i = i - 1; 
            pos.j = j; 
            enqueue(&queue, &pos);
            cout << "Current Position: (" << pos.i << "," << pos.j << ")" << endl;
        }
        
        if (check(i + 1, j)) {
            pos.i = i + 1;
            pos.j = j; 
            enqueue(&queue, &pos);
            cout << "Current Position: (" << pos.i << "," << pos.j << ")" << endl;
        }
    }

    return ret;
}

void printPath() {
    for (int i = 0; i < queue.tail; ++i) {
        cout << "(" << queue.data[i].i << "," << queue.data[i].j << ") -> ";
    }
    cout << "(" << queue.data[queue.tail].i << "," << queue.data[queue.tail].j << ")" << endl;
}

int main(void) {

    initQueue(&queue);

    maze[5][3] = GOAL;

    if (search(1, 3)) {
        cout << "Goal reached!" << endl;
        cout << "Path: ";
        printPath();
    } else {
        cout << "Goal not reached." << endl;
    }

    return 0;
}
