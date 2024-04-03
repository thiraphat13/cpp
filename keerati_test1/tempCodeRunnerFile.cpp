void rot(float s_y, float s_x, float e_y, float e_x, float max_y, float max_x) {
    int box_y_name;
    float box_y = max_y/4;
    int box_x_name;
    float box_x = max_x/4;

    int box_name;

    float rad = 41*M_PI/180;

    float dy = (e_y-s_y)*100000;
    float dx = (e_x-s_x)*100000;

    float dyp = dx*sin(rad)+dy*cos(rad);
    float dxp = dx*cos(rad)-dy*sin(rad);

    if (dyp < box_y) {
        box_y_name = 0;
    } else if (dyp < box_y*2) {
        box_y_name = 1;
    } else if (dyp < box_y*3) {
        box_y_name = 2;
    } else if (dyp < box_y*4) {
        box_y_name = 3;
    }

    if (dxp < box_x) {
        box_x_name = 0;
    } else if (dxp < box_x*2) {
        box_x_name = 1;
    } else if (dxp < box_x*3) {
        box_x_name = 2;
    } else if (dxp < box_x*4) {
        box_x_name = 3;
    }

    if (box_y_name == 0 && box_x_name == 0) {
        box_name = 0;
    } else if (box_y_name == 0 && box_x_name == 1) {
        box_name = 1;
    } else if (box_y_name == 0 && box_x_name == 2) {
        box_name = 2;
    } else if (box_y_name == 0 && box_x_name == 3) {
        box_name = 3;
    } else if (box_y_name == 1 && box_x_name == 3) {
        box_name = 4;
    } else if (box_y_name == 2 && box_x_name == 3) {
        box_name = 5;
    } else if (box_y_name == 3 && box_x_name == 3) {
        box_name = 6;
    } else if (box_y_name == 3 && box_x_name == 2) {
        box_name = 7;
    } else if (box_y_name == 3 && box_x_name == 1) {
        box_name = 8;
    } else if (box_y_name == 3 && box_x_name == 0) {
        box_name = 9;
    } else if (box_y_name == 2 && box_x_name == 0) {
        box_name = 10;
    } else if (box_y_name == 1 && box_x_name == 0) {
        box_name = 11;
    }

    cout << dyp << " " << box_y_name << " " << dxp << " " << box_x_name << " " << box_name;
}