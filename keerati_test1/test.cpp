#include <iostream>
#include <string>
using namespace std;

void translate(string data,float N,float E) {
    string time = "";
    string E_lo = "";
    string N_lo = "";


    int i = 0;
    int C_cout = 0;

    while (data[i] != '.') {
        time += data[i];
        i++;
    }

    while (C_cout < 4) {
        if (data[i] == ',') {
            C_cout++;
        } else if (C_cout == 1) {
            N_lo +=data[i];
        } else if (C_cout == 3) {
            E_lo +=data[i];
        }
        i++;
    }

    cout << time << " " << int((std::stof(N_lo)-N)*10000) << " " << int((std::stof(E_lo)-E)*10000);
}

int main() {
    string data_test = "204536.356,3507.5596,N,13702.2202,E";
    float N_t = 3505.1167;
    float E_t = 13699.7024;
    translate(data_test,N_t,E_t);
    return 0;
}
