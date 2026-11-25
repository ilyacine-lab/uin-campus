#include "calculs.hpp"
#include <cmath>

namespace uin {

double arrondir(double valeur, int decimales)
{
    double facteur = std::pow(10.0, decimales);
    return std::round(valeur * facteur) / facteur;
}

}
