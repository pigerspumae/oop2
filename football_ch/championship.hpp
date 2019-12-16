#ifndef FOOTBALL_CH_CHAMPIONSHIP_HPP
#define FOOTBALL_CH_CHAMPIONSHIP_HPP
#include "members_of_championship.hpp"

struct Championship {
    std::vector<std::shared_ptr<Player>> players;
    std::vector<std::shared_ptr<Team>> teams;
    std::vector<std::shared_ptr<Match>> matches;

    void create_vectorsMembers(std::istream &in);

    void restore_relationship();

    void deserialize_members(std::istream &in);

    void serialize_pvector(std::ostream &pout);

    void serialize_tvector(std::ostream &tout);

    void serialize_mvector(std::ostream &mout);
};



#endif //FOOTBALL_CH_CHAMPIONSHIP_HPP
