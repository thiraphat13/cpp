#include <iostream>
#include <cmath>
using namespace std;

// void rot(float s_y, float s_x, float e_y, float e_x, float max_y, float max_x) {
//     int box_y_name;
//     float box_y = max_y/4;
//     int box_x_name;
//     float box_x = max_x/4;

//     int box_name;

//     float rad = 41*M_PI/180;

//     float dy = (e_y-s_y)*100000;
//     float dx = (e_x-s_x)*100000;

//     float dyp = dx*sin(rad)+dy*cos(rad);
//     float dxp = dx*cos(rad)-dy*sin(rad);

//     if (dyp < box_y) {
//         box_y_name = 0;
//     } else if (dyp < box_y*2) {
//         box_y_name = 1;
//     } else if (dyp < box_y*3) {
//         box_y_name = 2;
//     } else if (dyp < box_y*4) {
//         box_y_name = 3;
//     }

//     if (dxp < box_x) {
//         box_x_name = 0;
//     } else if (dxp < box_x*2) {
//         box_x_name = 1;
//     } else if (dxp < box_x*3) {
//         box_x_name = 2;
//     } else if (dxp < box_x*4) {
//         box_x_name = 3;
//     }

//     if (box_y_name == 0 && box_x_name == 0) {
//         box_name = 0;
//     } else if (box_y_name == 0 && box_x_name == 1) {
//         box_name = 1;
//     } else if (box_y_name == 0 && box_x_name == 2) {
//         box_name = 2;
//     } else if (box_y_name == 0 && box_x_name == 3) {
//         box_name = 3;
//     } else if (box_y_name == 1 && box_x_name == 3) {
//         box_name = 4;
//     } else if (box_y_name == 2 && box_x_name == 3) {
//         box_name = 5;
//     } else if (box_y_name == 3 && box_x_name == 3) {
//         box_name = 6;
//     } else if (box_y_name == 3 && box_x_name == 2) {
//         box_name = 7;
//     } else if (box_y_name == 3 && box_x_name == 1) {
//         box_name = 8;
//     } else if (box_y_name == 3 && box_x_name == 0) {
//         box_name = 9;
//     } else if (box_y_name == 2 && box_x_name == 0) {
//         box_name = 10;
//     } else if (box_y_name == 1 && box_x_name == 0) {
//         box_name = 11;
//     }

//     cout << dyp << " " << box_y_name << " " << dxp << " " << box_x_name << " " << box_name;
// }

int rot(float s_y, float s_x, float e_y, float e_x, float max_y, float max_x) {
    float box_y = max_y / 4;
    float box_x = max_x / 4;

    float rad = 41 * M_PI / 180;
    float dy = (e_y - s_y) * 100000;
    float dx = (e_x - s_x) * 100000;
    float dyp = dx * sin(rad) + dy * cos(rad);
    float dxp = dx * cos(rad) - dy * sin(rad);

    // Determine positions in the grid
    int box_y_name = dyp / box_y;
    int box_x_name = dxp / box_x;

    // Ensure the position doesn't exceed grid bounds
    box_y_name = min(box_y_name, 3);
    box_x_name = min(box_x_name, 3);

    // Calculate box name based on grid position
    // Adjusted formula to map correctly into the specified 12-box grid
    int box_name = box_y_name * 4 + box_x_name; // This assumes a 0-indexed grid

    return box_name;
}

float travel(int a, int b) {
    float ro = 0;
    while (true)
    {
        a++;
        if (a==b) {
            break;
        }
        if (a < 4) {
            ro += 61.25;
        } else if (a < 7) {
            ro += 42.5;
        } else if (a < 10) {
            ro += 61.25;
        } else {
            ro += 42.5;
        }
        if (a > 11) {
            a=0;
        }
    }
    
    return ro;
}

int main() {
    float d_y_lo = 17.28771;
    float d_x_lo = 104.10656;
    float max_y = 245;
    float max_x = 170;
    float v = 10; //m/s
    float t = travel(4,2)/v;

    cout <<rot(d_y_lo, d_x_lo, 17.28695, 104.10814, max_y, max_x) <<endl;
    cout <<"distance : "<<travel(4,2) << " time : "<< t <<endl;
    return 0;
}