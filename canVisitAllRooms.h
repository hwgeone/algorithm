#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <math.h>

int num;

void dfs(int** rooms, int* roomsColSize, int* vis, int x) {
    vis[x] = true;
    num++;
    for (int i = 0; i < roomsColSize[x]; i++) {
        if (!vis[rooms[x][i]]) {
            dfs(rooms, roomsColSize, vis, rooms[x][i]);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int vis[roomsSize];
    memset(vis, 0, sizeof(vis));
    num = 0;
    dfs(rooms, roomsColSize, vis, 0);
    return num == roomsSize;
}