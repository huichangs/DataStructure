#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

typedef struct {
    short r;
    short c;
} element;

typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} S;

void init_stack(S* s) {
    s->top = -1;
}

int is_E(S* s) {
    return (s->top == -1);
}

int is_F(S* s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(S* s, element item) {
    if (is_F(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else s->data[++(s->top)] = item;
}

element pop(S* s) {
    if (is_E(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

element peek(S* s) {
    if (is_E(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[s->top];
}

element here = { 1,0 }, entry = { 1,0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
    { '1','1','1','1','1','1' },
    { 'e','0','1','0','0','1' },
    { '1','0','0','0','1','1' },
    { '1','0','1','0','1','1' },
    { '1','0','1','0','0','x' },
    { '1','1','1','1','1','1' },
};

void push_loc(S* s, int r, int c) {
    if (r < 0 || c < 0) return;
    if (maze[r][c] != '1' && maze[r][c] != '.') {
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s, tmp);
    }
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]) {
    printf("\n");
    for (int r = 0; r < MAZE_SIZE; r++) {
        for (int c = 0; c < MAZE_SIZE; c++) {
            printf("%c", maze[r][c]);
        }
        printf("\n");
    }
}

int main(void) {
    int r, c;
    S s;

    init_stack(&s);
    here = entry;
    while (maze[here.r][here.c] != 'x') {
        r = here.r;
        c = here.c;
        maze[r][c] = '.';
        maze_print(maze);
        push_loc(&s, r - 1, c);
        push_loc(&s, r + 1, c);
        push_loc(&s, r, c - 1);
        push_loc(&s, r, c + 1);
        if (is_E(&s)) {
            printf("실패\n");
            return 0;
        }
        else {
            here = pop(&s);
        }
    }
    printf("성공\n");
    return 0;
}
