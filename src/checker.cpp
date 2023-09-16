#include <bits/stdc++.h>
using namespace std; 

int main() {
	int s, t;
	while (1) {
        system("data > data.in");
        s = clock();
        system("mycode < data.in > mycode.out");
        t = clock();
        system("T2 < data.in > data.out");
        
        if (system("fc mycode.out data.out")) break;
        else cout << "AC. time: " << t - s << "ms" << endl;
    }
    cout << "WA. time: " << t - s << "ms" << endl;
    return 0;
}
