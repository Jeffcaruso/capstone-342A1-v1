#include "Inc/pokedex.h"

int Pokedex::size()
{
    return 0;
}

bool Pokedex::empty()
{
    return false;
}

ostream Pokedex::&operator<<(ostream &out, const Pokedex &pdx)
{
    cout << "not correct result (intentional)" << endl;
}
