#include <iostream>

int main()
{
    double* a = nullptr;

    std::cout << "Hello World\n";  // buffered (stdout)

    for (int i = 0; i < 10; i++) {
        // std::cout << "cout: " << i;  // buffered, which will not output anything on the terminal
        std::cerr << "cerr: " << i << '\n'; // unbuffered, which will output on the terminal before the segfault
        a[i] = 1.0; // deliberate crash with segfault
    }

    return 1;
}