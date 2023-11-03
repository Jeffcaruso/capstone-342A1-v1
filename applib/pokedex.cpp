// Ian Frigillana
// Project 1
// CSS 342
// Professor Pisan

#include "pokedex.h"
#include <iostream>

using namespace std;

Pokedex::Pokedex() {}

int Pokedex::size() const { return msize; }

int Pokedex::max_size() { return MAX; }

bool Pokedex::empty() const { return size() == 0; }

// Returns pokemon at index 'n'
const string &Pokedex::at(int n) const {
  if (empty() || n > size() - 1 || n < 0) {
    cerr << "Error: Cannot access element at " << n << "\n";
    return pokemons[0];
  }
  return pokemons[n];
}

// Returns pokemon at the front
const string &Pokedex::front() const {
  if (empty()) {
    cerr << "Error: Cannot access front for empty Pokedex\n";
    return pokemons[0];
  }
  return at(0);
}

// Returns pokemon at the back
const string &Pokedex::back() const {
  if (empty()) {
    cerr << "Error: Cannot access back for empty Pokedex\n";
    return pokemons[0];
  }
  return at(size() - 1);
}

// Add pokemon to Pokedex, pokemon sorted alphabetically
void Pokedex::insert(const string &pokemon) {
  // If full, do not insert
  if (size() == max_size()) {
    cout << "Error: Cannot access insert for full Pokedex\n";
    return;
  }
  // If empty, insert at front
  if (empty()) {
    pokemons[0] = pokemon;
    msize++;
    return;
  }
  for (int i = 0; i < max_size(); i++) {
    // Check if pokemon is same or after the current one
    // ex. a < b, b > a
    if (pokemons[i] <= pokemon) {
      // If next one is empty, take that one
      if (pokemons[i + 1].empty()) {
        pokemons[i + 1] = pokemon;
        msize++;
        break;
      }
      // Check if pokemon is same or before the next one
      if (pokemon <= pokemons[i + 1]) {
        // Starting from back, shift all elements after by one space forward
        for (int j = max_size() - 1; j > i + 1; j--) {
          pokemons[j] = pokemons[j - 1];
        }
        // Insert pokemon
        pokemons[i + 1] = pokemon;
        msize++;
        break;
      }
      // If pokemon is before the first, shift down and insert
    } else {
      for (int k = max_size() - 1; k > 0; k--) {
        pokemons[k] = pokemons[k - 1];
      }
      pokemons[0] = pokemon;
      msize++;
      break;
    }
  }
}

// Delete the last element
void Pokedex::pop_back() {
  if (!empty()) {
    pokemons[size() - 1] = "";
    msize--;
  } else {
    cerr << "Error: Cannot pop_back for empty Pokedex\n";
  }
}

// Erase element at index 'n', move other elements
void Pokedex::erase(int n) {
  if (n > size() - 1 || n < 0) {
    cerr << "Error: Cannot erase element at " << n << "\n";
  } else if (!empty()) {
    if (n == size() - 1) {
      pop_back();
    } else {
      pokemons[n] = "";
      msize--;
      for (int i = n; i < size(); i++) {
        pokemons[i] = pokemons[i + 1];
      }
      pokemons[size()] = "";
    }
  }
}

ostream &operator<<(ostream &out, const Pokedex &pdx) {
  if (pdx.empty()) {
    out << "[]";
  } else {
    string str;
    str = "[" + pdx.at(0);
    for (int i = 1; i < pdx.size(); i++) {
      str = str + ", " + pdx.at(i);
    }
    str = str + "]";
    out << str;
  }
  return out;
};