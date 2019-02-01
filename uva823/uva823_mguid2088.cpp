#include <cstdio>
#include <cmath>
#include <cctype>
#include <array>
#include <algorithm>
#include <numeric>
#include <iostream>

typedef std::array<float, 2> stopper;

const float PI = 3.14159265358979;
const float EPSILON = 1E-9;
//const float EPSILON = 0.0;
struct grid_point {
  grid_point(float x = 0.0, float y = 0.0) : x(x), y(y) {}
  float x, y;
};

static std::array<stopper, 3> stopper_list;
static std::array<float, 3> triangle;
static std::array<grid_point, 3> vertices;
static std::array<float, 3> angles;

static const std::array<std::array<int, 3>, 6> possibilities {
  0, 1, 2,
  0, 2, 1,
  1, 0, 2,
  1, 2, 0,
  2, 0, 1,
  2, 1, 0
};

int main() {
  int count = 1;
  while(scanf(" %f %f %f "
              " %f %f %f %f %f %f ",
              &triangle[0], &triangle[1], &triangle[2],
              &stopper_list[0][0], &stopper_list[0][1],
              &stopper_list[1][0], &stopper_list[1][1],
              &stopper_list[2][0], &stopper_list[2][1]) && triangle[0] != 0) {
    std::sort(triangle.begin(), triangle.end());
    if(triangle[0] == triangle[1] && triangle[1] == triangle[2]) {
      angles[0] = angles[1] = angles[2] = 60.0; //equilateral triangle, angles always 60
    } else {
      angles[0] = acos((triangle[0] * triangle[0] + triangle[1] * triangle[1] - triangle[2] * triangle[2])/(2.0 * triangle[0] * triangle[1])); //law of cosines for first angle
      angles[1] = asin(triangle[0] / triangle[2] * sin(angles[0])) * (180.0 / PI); //law of sines for second angle
      angles[0] *= (180.0 / PI);                   //convert angle 0 to degrees
      angles[2] = 180.0 - (angles[0] + angles[1]); //subtraction for last angle
      std::sort(angles.begin(), angles.end());     //sort them
    }
    vertices[0].x = 0; //vertices for 0 points always 0
    vertices[0].y = 0; //vertices for 0 points always 0
    vertices[1].x = triangle[2]; //vertices for second point made up of (triangle2, 0)
    vertices[1].y = 0;
    vertices[2].x = cos(angles[0] * PI/180.0) * triangle[1]; // have to calculate last point, it may not touch an axis
    vertices[2].y = sin(angles[0] * PI/180.0) * triangle[1]; // have to calculate last point, it may not touch an axis
//    printf("(%f, %f) (%f, %f) (%f, %f)\n", vertices[0].x, vertices[0].y, vertices[1].x, vertices[1].y, vertices[2].x, vertices[2].y);

    if(stopper_list[0][1] == stopper_list[1][1] && stopper_list[1][1] == stopper_list[2][1]) {
      size_t index = std::distance(stopper_list.begin(), std::min_element(stopper_list.begin(), stopper_list.end(), [] (const stopper& a, const stopper& b) {
        return a[0] < b[0];
      }));
      std::swap(stopper_list[index][0], stopper_list[index][1]);
    } else {
      size_t index = std::distance(stopper_list.begin(), std::max_element(stopper_list.begin(), stopper_list.end(), [] (const stopper& a, const stopper& b) {
        return a[1] < b[1];
      }));
      std::swap(stopper_list[index][0], stopper_list[index][1]);
    }

    bool good = false;
    for(int i = 0; i < 6; i++) {
      grid_point a, b, c;
      //GET CENTER POINTS FOR THIS COMBINATION OF CIRCLES PLACED IN THEIR RESPECTIVE CORNERS
      //CIRCLE IN CORNER (0,0) JUST DO TAN RELATIVE TO THE SMALLEST ANGLE
      a.x = (stopper_list[possibilities[i][0]][1]/2.0)/tan((angles[0]/2.0) * PI / 180.0); //get x of center point of first circle
      a.y = (stopper_list[possibilities[i][0]][1]/2.0); //get y of center point of first circle
      //CIRCLE IN CORNER (SIDE_LENGTH_A, 0) X IS SIDE_LENGTH_A - THE ADJACENT LENGTH
      b.x = triangle[2] - ((stopper_list[possibilities[i][1]][1]/2.0)/tan((angles[1]/2.0) * PI / 180.0)); //get x of center point of second circle
      b.y = (stopper_list[possibilities[i][1]][1]/2.0); //get y of center point of second circle
      //CIRCLE IN THE LAST CORNER, THIS ONE IS THE WORST, CALCULATE THE X, Y AS IF IT WAS AT 0,0 THEN ROTATE IT AND ADD THE X,Y OFFSET OF THE CORNER POINT
      float tmp_cx = (stopper_list[possibilities[i][2]][1]/2.0)/tan((angles[2]/2.0) * PI / 180.0); //get x of center point of first circle
      float tmp_cy = (stopper_list[possibilities[i][2]][1]/2.0); //get y of center point of first circle
      //printf("tmp cx: %f, tmp cy: %f\n", tmp_cx, tmp_cy);
      //THE ROTATION ANGLE IS 180 + ( 90.0 - THE ANGLE OF THE LEFT SIDE OF THE TRIANGLE AS IF IT WERE A RIGHT TRIANGLE )
      float rotation_angle = 180.0 + (90.0 - (acos(vertices[2].y/triangle[1]) * 180.0/PI));
      //PERFORM THE ROTATION AND ADD THE OFFSET
      c.x = ((tmp_cx) * cos((rotation_angle) * PI / 180.0)) - ((tmp_cy) * sin((rotation_angle) * PI/180.0)) + vertices[2].x;
      c.y = ((tmp_cy) * cos((rotation_angle) * PI / 180.0)) + ((tmp_cx) * sin((rotation_angle) * PI/180.0)) + vertices[2].y;
      //c.y = vertices[possibilities[i][2]].y - (cos((angles[2]/2.0) * PI / 180.0)/(stopper_list[possibilities[i][2]][1]/2.0));
      printf(" circle a radius: %f, circle b radius: %f, circle c radius: %f\n", stopper_list[possibilities[i][0]][1]/2.0, stopper_list[possibilities[i][1]][1]/2.0, stopper_list[possibilities[i][2]][1]/2.0);
      printf(" circle a center point: (%f, %f)\n", a.x, a.y);
      printf(" circle b center point: (%f, %f)\n", b.x, b.y);
      printf(" circle c center point: (%f, %f)\n", c.x, c.y);
      float tmp_lhs, tmp_rhs;

      printf("CASE %d\n", i);

      tmp_lhs = sqrt(pow(b.x - a.x,2.0) + pow(b.y - a.y,2.0));
      tmp_rhs = stopper_list[possibilities[i][0]][1]/2.0 + stopper_list[possibilities[i][1]][1]/2.0;
      printf("SIDE 1 a - b distance %f %f\n", tmp_lhs, tmp_rhs);
      if(tmp_lhs <= (tmp_rhs + EPSILON)) {
        continue;
      }
      tmp_lhs = sqrt(pow(c.x - b.x,2.0) + pow(c.y - b.y,2.0));
      tmp_rhs = stopper_list[possibilities[i][1]][1]/2.0 + stopper_list[possibilities[i][2]][1]/2.0;
      printf("SIDE 1 b - c distance %f %f\n", tmp_lhs, tmp_rhs);
      if(tmp_lhs <= (tmp_rhs + EPSILON)) {
        continue;
      }
      tmp_lhs = sqrt(pow(a.x - c.x,2.0) + pow(a.y - c.y,2.0));
      tmp_rhs = stopper_list[possibilities[i][2]][1]/2.0 + stopper_list[possibilities[i][0]][1]/2.0;
      printf("SIDE 1 c - a distance %f %f\n", tmp_lhs, tmp_rhs);
      if(tmp_lhs <= (tmp_rhs + EPSILON)) {
        continue;
      }
      tmp_lhs = sqrt(pow(b.x - a.x,2.0) + pow(b.y - a.y,2.0));
      tmp_rhs = stopper_list[possibilities[i][0]][0]/2.0 + stopper_list[possibilities[i][1]][0]/2.0;
      printf("SIDE 2 a - b distance %f %f\n", tmp_lhs, tmp_rhs);
      if(tmp_lhs <= (tmp_rhs + EPSILON)) {
        continue;
      }
      tmp_lhs = sqrt(pow(c.x - b.x,2.0) + pow(c.y - b.y,2.0));
      tmp_rhs = stopper_list[possibilities[i][1]][0]/2.0 + stopper_list[possibilities[i][2]][0]/2.0;
      printf("SIDE 2 b - c distance %f %f\n", tmp_lhs, tmp_rhs);
      if(tmp_lhs <= (tmp_rhs + EPSILON)) {
        continue;
      }
      tmp_lhs = sqrt(pow(a.x - c.x,2.0) + pow(a.y - c.y,2.0));
      tmp_rhs = stopper_list[possibilities[i][2]][0]/2.0 + stopper_list[possibilities[i][0]][0]/2.0;
      printf("SIDE 2 c - a distance %f %f\n", tmp_lhs, tmp_rhs);
      if(tmp_lhs <= (tmp_rhs + EPSILON)) {
        continue;
      }
      good = true;
      break;
    }
    printf("Triangle number %d:\n", count);
    count++;
    if(good) puts("All three stoppers will fit in the triangular space");
    else puts("Stoppers will not fit in the triangular space");
  }
}

