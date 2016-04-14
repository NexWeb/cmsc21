#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct {
  int row;
  int col;
} Coord;



bool isWithinMap(int map_size_rows, int map_size_cols, Coord curr) {
  return 0 <= curr.row && curr.row < map_size_rows
    && 0 <= curr.col && curr.col < map_size_cols;
}

bool equalsCoord(Coord a, Coord b) {
  return a.row == b.row && a.col == b.col;
}

#define ONPATH 1

bool isOnPath(int map_size_rows, int map_size_cols, int** map, Coord curr) {
  return isWithinMap(map_size_rows, map_size_cols, curr) && map[curr.row][curr.col] == ONPATH;
}

bool hasNext(int map_size_rows, int map_size_cols, int** map, Coord prev, Coord curr) {    
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      Coord neighbor = {curr.row + i, curr.col + j};
      if (!equalsCoord(neighbor, curr) && isOnPath(map_size_rows, map_size_cols, map, neighbor) && !equalsCoord(neighbor, prev)) {
        return true;
      }
    }
  }

  return false;
}

Coord getNext(int map_size_rows, int map_size_cols, int** map, Coord prev, Coord curr) {    
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      Coord neighbor = {curr.row + i, curr.col + j};
      if (!equalsCoord(neighbor, curr) && isOnPath(map_size_rows, map_size_cols, map, neighbor) && !equalsCoord(neighbor, prev)) {
        return neighbor;
      }
    }
  }

  return curr;
}


/*
 * Complete the function below.
 */
Coord findEnd(int map_size_rows, int map_size_cols, int** map) {
  Coord curr = {0, 0};
  Coord prev = {0, 0};
  while(hasNext(map_size_rows, map_size_cols, map, prev, curr)) {
    Coord pastPrev = curr;
    curr = getNext(map_size_rows, map_size_cols, map, prev, curr);
    prev = pastPrev;
  }
  return curr;
}


void displayCoord(Coord curr) {
  printf("%d %d\n", curr.row, curr.col);
}

void displayMap(int map_size_rows, int map_size_cols, int** map) {
  for (int i = 0; i < map_size_rows; i++) {
    for (int j = 0; j < map_size_cols; j++) {
      printf("%d ", map[i][j]);
    }
    printf("\n");
  }
}

void displayInMap(int map_size_rows, int map_size_cols, int** map) {
  Coord curr = {0, 0};
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      Coord neighbor = {curr.row + i, curr.col + j};
      displayCoord(neighbor);
      printf(isWithinMap(map_size_rows, map_size_cols, neighbor) ? "in map\n" : "not in map\n");
    }
  }

}

void displayIsOnPath(int map_size_rows, int map_size_cols, int** map) {
  Coord curr = {0, 0};
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      Coord neighbor = {curr.row + i, curr.col + j};
      displayCoord(neighbor);
      printf(isOnPath(map_size_rows, map_size_cols, map, neighbor) ? "on path\n" : "not on path\n");
    }
  }

}


int main() {

  FILE *f = fopen("trace-path-input", "r");
  Coord res;

  int _map_rows = 0;
  int _map_cols = 0;
  fscanf(f,"%d", &_map_rows);
  fscanf(f,"%d", &_map_cols);

  int** _map = (int**)malloc(_map_rows*sizeof(int*));
  int _map_init_i=0;
  for(_map_init_i=0 ; _map_init_i<_map_rows ; ++_map_init_i)
  {
    _map[_map_init_i] = (int*)malloc(_map_cols*(sizeof(int)));
  }

  int _map_i, _map_j;
  for(_map_i = 0; _map_i < _map_rows; _map_i++) {
    for(_map_j = 0; _map_j < _map_cols; _map_j++) {
      int _map_item;
      fscanf(f,"%d", &_map_item);

      _map[_map_i][_map_j] = _map_item;
    }
  }

  printf("%d %d\n", _map_rows, _map_cols);

  /* displayMap(_map_rows, _map_cols, _map); */
  /* displayIsOnPath(_map_rows, _map_cols, _map); */
  /* displayCoord(getNext(_map_rows, _map_cols, _map, (Coord) {0, 0}, (Coord) {1, 1})); */

  res = findEnd(_map_rows, _map_cols, _map);
  printf("%d %d\n", res.row, res.col);

  fclose(f);
  return 0;
}
