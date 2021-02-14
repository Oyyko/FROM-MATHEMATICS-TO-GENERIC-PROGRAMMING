#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::vector<int> x;
    x.emplace_back(2);
    x.emplace_back(3);
    x.emplace_back(6);

    cout << *(x.end() - 1);
}