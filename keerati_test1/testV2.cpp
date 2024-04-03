#include <iostream>
#include <string>
#include <bitset>
#include <tuple>
using namespace std;

// tuple<bitset<32>, bitset<32>, bitset<32>> translate(string data, long long int N, long long int E) {
//     string time = "", E_lo = "", N_lo = "";
//     int i = 0, C_cout = 0;

//     while (C_cout < 8) {
//         if (data[i] == ',' || data[i] == '.') {
//             C_cout++;
//         } else if (C_cout < 3) {
//             time += data[i];
//         } else if (C_cout > 3 && C_cout < 6) {
//             N_lo += data[i];
//         } else if (C_cout > 5) {
//             E_lo += data[i];
//         }
//         i++;
//     }

//     bitset<32> T_binary(stoll(time));
//     bitset<32> N_binary(stoll(N_lo) - N);
//     bitset<32> E_binary(stoll(E_lo) - E);

//     return {T_binary, N_binary, E_binary};
// }

// string retranslate(bitset<32> T, bitset<32> N, bitset<32> E, long long int N_t, long long int E_t) {
//     string T_T = "";
//     string time = to_string(T.to_ulong());
//     long long N_val = N.to_ulong() + N_t;
//     long long E_val = E.to_ulong() + E_t;
//     string N_lo = to_string(N_val*0.000001);
//     string E_lo = to_string(E_val*0.000001);
//     int i = 0;


//     while (i < 8)
//     {   
//         if (i==2||i==4) {
//             T_T += ".";
//         }
//         T_T += time[i];
//         i++;
//     }

//     return T_T+","+N_lo+","+E_lo+",";
// }

string translate(string data, long long int N, long long int E) {
    string time = "", E_lo = "", N_lo = "";
    int i = 0, C_cout = 0;

    while (C_cout < 8) {
        if (data[i] == ',' || data[i] == '.') {
            C_cout++;
        } else if (C_cout < 3) {
            time += data[i];
        } else if (C_cout > 3 && C_cout < 6) {
            N_lo += data[i];
        } else if (C_cout > 5) {
            E_lo += data[i];
        }
        i++;
    }

    bitset<32> T_binary(stoll(time));
    bitset<32> N_binary(stoll(N_lo) - N);
    bitset<32> E_binary(stoll(E_lo) - E);

    return T_binary.to_string()+N_binary.to_string()+E_binary.to_string();
}

// string retranslate(string data, long long int N_t, long long int E_t) {
//     int set_cout = 0;
//     int i = 0;
//     bitset<32> T, N, E;
//     while (set_cout < 3)
//     {
//         if (i%32==0) {
//             set_cout++;
//         }
        
//         if (set_cout==0)
//         {
//             T += data[i];
//         }
        
//         i++;
//     }
    
//     string T_T = "";
//     string time = to_string(T.to_ulong());
//     long long N_val = N.to_ulong() + N_t;
//     long long E_val = E.to_ulong() + E_t;
//     string N_lo = to_string(N_val*0.000001);
//     string E_lo = to_string(E_val*0.000001);
//     i = 0;


    // while (i < 8)
    // {   
    //     if (i==2||i==4) {
    //         T_T += ".";
    //     }
    //     T_T += time[i];
    //     i++;
    // }

//     return T_T+","+N_lo+","+E_lo+",";
// }

string retranslate(const string& data, long long int N_t, long long int E_t) {
    string T_T = "";
    int i = 0;

    bitset<32> T_bitset(data.substr(0, 32));
    bitset<32> N_bitset(data.substr(32, 32));
    bitset<32> E_bitset(data.substr(64, 32));

    long long T_val = T_bitset.to_ulong();
    long long N_val = N_bitset.to_ulong() + N_t;
    long long E_val = E_bitset.to_ulong() + E_t;

    string time = to_string(T_val);
    string N_lo = to_string(N_val * 0.000001);
    string E_lo = to_string(E_val * 0.000001);

    // while (i < 8){   
    //     if (i==2||i==4) {
    //         T_T += ".";
    //     }
    //     T_T += time[i];
    //     i++;
    // }

    return time + "," + N_lo + "," + E_lo + ",";
}

int main() {
    string data_test = "20.45.36.356,3507.550106,13702.220210,";
    long long int N_t = 3505116711;
    long long int E_t = 13699702411;

    // auto [T_binary, N_binary, E_binary] = translate(data_test, N_t, E_t);

    // cout << "T binary: " << T_binary << endl;
    // cout << "N binary: " << N_binary << endl;
    // cout << "E binary: " << E_binary << endl;

    // string data = retranslate(T_binary, N_binary, E_binary, N_t, E_t);
    // cout << "data : " << data << endl;

    string binary = translate(data_test, N_t, E_t);
    cout << "binary : " << binary << endl;

    string data = retranslate(binary, N_t, E_t);
    cout << "data : " << data << endl;

    return 0;
}

// #include <iostream>
// #include <string>
// #include <bitset>
// using namespace std;

// char translate(string data,long long int N,long long int E) {
//     string time = "";
//     string E_lo = "";
//     string N_lo = "";

//     int i = 0;
//     int C_cout = 0;

//     while (C_cout < 8) {
//         if (data[i] == ','||data[i] == '.') {
//             C_cout++;
//         }else if (C_cout < 3) {
//             time += data[i];
//         } else if (C_cout > 3 && C_cout < 6) {
//             N_lo +=data[i];
//         } else if (C_cout > 5) {
//             E_lo +=data[i];
//         }
//         i++;
//     }

//     std::bitset<32> N_binary(std::stoll(N_lo)-N);
//     std::bitset<32> E_binary(std::stoll(E_lo)-E);
//     std::bitset<32> T_binary(std::stoll(time));

//     return T_binary+N_binary+E_binary;
// }

// int main() {
//     string data_test = "20.45.36.356,3507.559106,13702.220210,";
//     long long int N_t = 3505116711;
//     long long int E_t = 13699702411;

//     cout << translate(data_test,N_t,E_t);
//     return 0;
// }
