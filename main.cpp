#include <iostream>

template <typename T1, typename T2>
class Pair
{
    T1 key;
    T2 values;

public:
    Pair(T1 inKey, T2 inValues) : key(inKey), values(inValues) {};

    void print ()
    {
        std::cout << key << " " << values;
    }
};

int main() {
    Pair<int, int> p(5, 10);

    p.print();

}
