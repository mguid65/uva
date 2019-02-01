#include <cstdio>
#include <cmath>
#include <cctype>
#include <array>
#include <algorithm>
#include <numeric>
#include <iostream>

typedef std::array<float, 2> stopper;

const double PI = 3.14159265358979;

struct grid_point {
  grid_point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
  double x, y;
};

static std::array<stopper, 3> stopper_list;
static std::array<double, 3> triangle;
static std::array<grid_point, 3> vertices;
static std::array<double, 3> angles;

static const std::array<std::array<int, 3>, 6> possibilities {
  0, 1, 2,
  0, 2, 1,
  1, 0, 2,
  1, 2, 0,
  2, 0, 1,
  2, 1, 0
};

int main() {
  while(scanf(" %lf %lf %lf "
              " %f %f %f %f %f %f ",
              &triangle[0], &triangle[1], &triangle[2],
              &stopper_list[0][0], &stopper_list[0][1],
              &stopper_list[1][0], &stopper_list[1][1],
              &stopper_list[2][0], &stopper_list[2][1]) && triangle[0] != 0) {
//    printf(" %d %d %d  "
//              " %f %f   %f %f   %f %f\n",
//              triangle[0], triangle[1], triangle[2],
//              stopper_list[0][0], stopper_list[0][1],
//              stopper_list[1][0], stopper_list[1][1],
//              stopper_list[2][0], stopper_list[2][1]);
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
    printf("(%lf, %lf) (%lf, %lf) (%lf, %lf)\n", vertices[0].x, vertices[0].y, vertices[1].x, vertices[1].y, vertices[2].x, vertices[2].y);
//    printf("%lf %lf %lf\n", angles[0], angles[1], angles[2]);

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
      a.x = stopper_list[possibilities[i][0]][1]/tan((angles[0]/2.0) * PI / 180.0);
      a.y = stopper_list[possibilities[i][0]][1];
      //b.x = 
      //b.y =
      c.x = vertices[possibilities[i][2]].x;
      c.y = vertices[possibilities[i][2]].y - (cos((angles[2]/2.0) * PI / 180.0)/(stopper_list[possibilities[i][2]][1]/2.0));
      printf(" circle a center point: (%lf, %lf)\n", a.x, a.y);
      printf(" circle b center point: (%lf, %lf)\n", b.x, b.y);
      printf(" circle c center point: (%lf, %lf)\n", c.x, c.y);
      
    }
//    for(int i = 0; i < 6; i++) {
//      double tri_point_to_circle_center = (stopper_list[possibilities[i][j]][1]/2.0)/tan((angles[k]/2.0) * PI/ 180.0);
//      printf("%lf\n", tri_point_to_circle_center);
//    }
//    printf(" %d %d %d  "
//              " %f %f   %f %f   %f %f\n",
//              triangle[0], triangle[1], triangle[2],
//              stopper_list[0][0], stopper_list[0][1],
//              stopper_list[1][0], stopper_list[1][1],
//              stopper_list[2][0], stopper_list[2][1]);
//    std::sort(triangle.rbegin(), triangle.rend());
    
  }
}

