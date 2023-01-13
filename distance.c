#include <stdio.h>
#include <math.h>

#define NUM_POINTS 5

// Struct to represent a point in 2D space
struct Point {
  int x;
  int y;
};

// Calculates the distance between two points using the formula:
// distance = sqrt((point1.x - point2.x)^2 + (point1.y - point2.y)^2)
double distance(struct Point point1, struct Point point2) {
  return sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
}

int main() {
  // Array to store the points
  struct Point points[NUM_POINTS];

  // Read in the coordinates of the points from the user
  printf("Enter the coordinates of the points:\n");
  for (int i = 0; i < NUM_POINTS; i++) {
    printf("Point %d: ", i+1);
    scanf("%d %d", &points[i].x, &points[i].y);
  }

  // Calculate the distance between the points "as the crow flies"
  double crow_flies_distance = distance(points[0], points[NUM_POINTS-1]);
  printf("The optional distance between the start and end points is %.3f\n", crow_flies_distance);

  // Calculate the length of the chain formed by the lines connecting the points
  double chain_length = 0;
  for (int i = 0; i < NUM_POINTS-1; i++) {
    chain_length += distance(points[i], points[i+1]);
  }
  printf("The distance by meandering is %.3f\n", chain_length);

  return 0;
}
