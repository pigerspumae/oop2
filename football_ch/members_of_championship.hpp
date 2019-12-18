#ifndef FOOTBALL_CH_MEMBERS_OF_CHAMPIONSHIP_HPP
#define FOOTBALL_CH_MEMBERS_OF_CHAMPIONSHIP_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <memory>

struct Player;
struct Team;
struct Match;

struct Member {
    uint32_t id;

    virtual void serialize(std::ostream &) = 0;
};


struct Team : Member {
    std::string name;
    std::vector<std::shared_ptr<Player>> players;
    std::vector<uint32_t> id_players;

    Team(std::istream &in);
    void serialize(std::ostream &out) override;

};


struct Match : Member {
    std::string data;
    std::string location;
    std::string result;
    std::shared_ptr<Team> team1; //TODO: week_ptr
    std::shared_ptr<Team> team2; //TODO: week_ptr
    std::vector<uint32_t> id_teams;
    std::vector<std::shared_ptr<Player>> players;
    std::vector<uint32_t> id_players;

    Match(std::istream &in);
    void serialize(std::ostream &out) override;
};



struct Player : Member {
    std::string name;
    std::shared_ptr<Team> team; //TODO: week_ptr
    std::shared_ptr<Match> match; //TODO: week_ptr
    uint32_t team_id;

    Player(std::istream &in);
    void serialize(std::ostream &out) override;
};



struct Creator {
    virtual Member *factoryMethod(std::istream &) = 0;
};

struct PlayerCreator : Creator {
    inline Player *factoryMethod(std::istream &in) { return new Player(in); }
};

struct TeamCreator : Creator {
    inline Team *factoryMethod(std::istream &in) { return new Team(in); }
};

struct MatchCreator : Creator {
    inline Match *factoryMethod(std::istream &in) { return new Match(in); }
};

#endif //FOOTBALL_CH_MEMBERS_OF_CHAMPIONSHIP_HPP
