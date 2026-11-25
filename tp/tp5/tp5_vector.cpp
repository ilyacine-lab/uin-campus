#include <iostream>
#include <vector>

int main()
{
    std::vector<double> notes;

    for (int i = 0; i < 10; ++i) {
        notes.push_back(10.0 + i);

        std::cout << "Taille : " << notes.size()
                  << " | Capacite : " << notes.capacity()
                  << '\n';
    }

    std::cout << "Premier element : " << notes.at(0) << '\n';

    return 0;
}