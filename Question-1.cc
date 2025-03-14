#include <iostream>
#include <map>
#include <vector>
#include <initializer_list>
#include <cmath>
#include <memory>

const int values[] = { 1,2,3,4,5 };
const int val_size = sizeof(values) / sizeof(int);

class Foo {
    std::vector<int> mElements;
public:
    Foo(std::initializer_list<int> list)
        : mElements(list) {}

    Foo() = default;
};

struct Person {
    int age;
    float weight;
};

void show_output(const int** pp) {
    printf("%p : %p : %d", pp, *pp, **pp);
}

int main() {
    int x = -10;
    int y = 15;
    
    std::cout << " " << y << std::endl;

    while (x < y) {
        if (x != 0) {
            std::cout << "ratio: " << (y / x) << std::endl;
        } else {
            std::cout << "ratio: 0" << std::endl;
        }
        x++;
        y--;
    }

    int i = 1, j = 1; 
    if ((i = !3) && (j = 1)) {  
        std::cout << "j is 1 and i is not 3\n";
    } else {
        std::cout << "either j is NOT 1, or i is set to 3\n";
    }

    typedef std::map<int, double> valmap; 
    valmap m;

    for (int i = 0; i < val_size; i++) {
        m.insert(std::make_pair(values[i], std::pow(values[i], .5)));
    }

    m.insert(std::map<int, double>::value_type(1, 2));  

    int n = 1;
    int* p = &n;
    const int* cp = &n;
    const int** cpp = &cp; 
    show_output(cpp);

    // Use smart pointer for person allocation
    std::unique_ptr<Person> ptr(new Person());
    ptr->age = 10;
    ptr->weight = 55.5;

    // Initialise Foo with 5 integers
    Foo foo({1, 2, 3, 4, 5}); 

    return 0;
}