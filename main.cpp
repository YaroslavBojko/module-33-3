#include <iostream>
#include <vector>

template <typename T1, typename T2>
class Registry
{
public:
    T1 key;
    T2 values;

    Registry(T1 inKey, T2 inValues) : key(inKey), values(inValues) {};
};

template<typename T1, typename T2>
std::vector<Registry<T1, T2>> add(std::vector<Registry<T1, T2>>& pairs)
{
    T1 key;
    T2 values;

    std::cout << "Enter key: ";
    std::cin >> key;
    std::cout << "Enter values: ";
    std::cin >> values;
    Registry<T1, T2> registry(key, values);
    pairs.push_back(registry);
    return pairs;
}

template<typename T1, typename T2>
std::vector<Registry<T1, T2>> remove(std::vector<Registry<T1, T2>>& pairs)
{
    T1 key;
    std::cout << "Enter key: ";
    std::cin >> key;
    for (int i = 0; i < pairs.size(); i++)
    {
        auto it = pairs.cbegin();
        if (key == pairs[i].key)
        {
            pairs.erase(it + i);
            i--;
        }
    }
    return pairs;
}

template<typename T1, typename T2>
void print(std::vector<Registry<T1, T2>>& pairs)
{
    for (int i = 0; i < pairs.size(); ++i)
    {
        std::cout << pairs[i].key << " " << pairs[i].values << std::endl;
    }
}

template<typename T1, typename T2>
void find(std::vector<Registry<T1, T2>>& pairs)
{
    T1 key;
    std::cout << "Enter key: ";
    std::cin >> key;
    for (int i = 0; i < pairs.size(); i++)
    {
        if (key == pairs[i].key)
            std::cout << pairs[i].values << " ";
    }
    std::cout << std::endl;
}

int main() {
    //std::vector<Registry<int, std::string>> pairs;
    //std::vector<Registry<std::string, double>> pairs;
    std::vector<Registry<double, int>> pairs;

    std::string command;
    while (command != "exit")
    {
        std::cout << "Enter the command (add, remove, print, find, exit): ";
        std::cin >> command;

        if (command == "add") add(pairs);
        if (command == "remove") remove(pairs);
        if (command == "print") print(pairs);
        if (command == "find") find(pairs);
    }
}
