#include <iostream>
#include <stdbool.h>

#define MEIRO_WIDTH 8
#define MEIRO_HEIGHT 8

#define PATH 0 
#define WALL 1 
#define GOAL 2 
#define PASSED 3 

#define MAX_NUM (MEIRO_WIDTH * MEIRO_HEIGHT)

#define STACK_SIZE MAX_NUM

using namespace std;

typedef struct POS {
    int i;
    int j;
} POS_T;

typedef struct STACK {
    int tail;
    POS_T data[STACK_SIZE];
} STACK_T;

STACK_T stack;

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

void initStack(STACK_T* stack) {
    stack->tail = -1;
}

void push(STACK_T* stack, POS_T* input) {
    if (stack->tail >= STACK_SIZE - 1) {
        cout << "error : stack is full" << endl;
        return;
    }
    stack->data[stack->tail + 1] = *input;
    stack->tail = stack->tail + 1;
}

POS_T* pop(STACK_T* stack) {
    POS_T* ret;
    if (stack->tail == -1) {
        cout << "error : stack is empty" << endl;
        return NULL;
    }
    ret = &(stack->data[stack->tail]);
    stack->tail = stack->tail - 1;
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
    bool ret = false;
    if (check(s_i, s_j)) {
        pos.i = s_i;
        pos.j = s_j;
        push(&stack, &pos);
    }
    while (true) {
        int i, j;
        POS_T* next = pop(&stack);
        if (next == NULL) {
            break;
        }
        i = next->i;
        j = next->j;
        cout << "Current Position: (" << i << "," << j << ")" << endl;  // 修正: 現在の座標を表示
        if (maze[j][i] == GOAL) {
            cout << "GOAL" << endl;
            ret = true;
            break;
        }
        maze[j][i] = PASSED;
        if (check(i, j - 1)) {
            pos.i = i;
            pos.j = j - 1;
            push(&stack, &pos);
        }
        if (check(i, j + 1)) {
            pos.i = i;
            pos.j = j + 1;
            push(&stack, &pos);
        }
        if (check(i - 1, j)) {
            pos.i = i - 1;
            pos.j = j;
            push(&stack, &pos);
        }
        if (check(i + 1, j)) {
            pos.i = i + 1;
            pos.j = j;
            push(&stack, &pos);
        }
    }
    return ret;
}

void printPath() {
    for (int i = 0; i < stack.tail; ++i) {
        cout << "(" << stack.data[i].i << "," << stack.data[i].j << ") -> ";
    }
    cout << "(" << stack.data[stack.tail].i << "," << stack.data[stack.tail].j << ")" << endl;
}

int main(void) {
    initStack(&stack);
    maze[6][6] = GOAL;
    if (search(2, 3)) {
        cout << "GOAL reached!" << endl;
        cout << "Path: ";
        printPath();
    }
    else {
        cout << "Goal not reached." << endl;
    }
    return 0;
}

