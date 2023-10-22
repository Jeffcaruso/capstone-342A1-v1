#include "Inc/pokedex.h"

Pokedex::Pokedex()
{
    msize = 0;
}

int Pokedex::size() const
{
    return 0;
}

bool Pokedex::empty() const
{
    return false;
}

ostream &operator<<(ostream &out, const Pokedex &pdx)
{
    return cout << "not correct result (intentional)" << endl;
}
