#include <iostream>

using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;
    
    if(a >= -100000 && b <= 100000)
    {
        cout << "a = "; cout << a << endl;
        cout << "b = "; cout << b;
    }
    
    return 0;
}
