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

template <typename T1, typename T2>
class Operating
{
public:
    std::vector<Registry<T1, T2>> pairs;

    void add()
    {
        T1 key;
        T2 values;

        std::cout << "Enter key: ";
        std::cin >> key;
        std::cout << "Enter values: ";
        std::cin >> values;
        Registry<T1, T2> registry(key, values);
        pairs.push_back(registry);
    }

    void print()
    {
        for (int i = 0; i < pairs.size(); ++i)
        {
            std::cout << pairs[i].key << " " << pairs[i].values << std::endl;
        }
    }

    void remove()
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
    }

    void find()
    {
        T1 key;
        std::cout << "Enter key: ";
        std::cin >> key;
        for (int i = 0; i < pairs.size(); i++) {
            if (key == pairs[i].key)
                std::cout << pairs[i].values << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    //Operating<int, std::string> operating;
    //Operating<std::string, double> operating;
    Operating<double, int> operating;

    std::string command;
    while (command != "exit")
    {
        std::cout << "Enter the command (add, remove, print, find, exit): ";
        std::cin >> command;

        if (command == "add") operating.add();
        if (command == "remove") operating.remove();
        if (command == "print") operating.print();
        if (command == "find") operating.find();
    }
}
