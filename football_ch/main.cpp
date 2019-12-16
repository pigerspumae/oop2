#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <memory>
#include "championship.hpp"


int main() {
    std::ifstream in("data.tsv");
    Championship a;
    a.deserialize_members(in);
    std::ofstream tout("teams.tsv");
    a.serialize_tvector(tout);
    std::ofstream pout("players.tsv");
    a.serialize_pvector(pout);
    std::ofstream mout("matches.tsv");
    a.serialize_mvector(mout);
    return 0;
}