#include "members_of_championship.hpp"

Team::Team(std::istream &in) {
    in >> id >> name;
    std::string tmp;
    std::getline(in, tmp);
    std::stringstream inbuf(tmp);
    int id;
    while (inbuf >> id) {
        id_players.push_back(id);
    }
}

void Team::serialize(std::ostream &out) {
    out << "team" << '\t'
        << id << '\t'
        << name << '\t';
    for (const auto player : players) {
        out << player->id << '\t';
    }
    out << std::endl;
}

Match::Match(std::istream &in) {
    uint32_t id_team1;
    uint32_t id_team2;
    in >> id >> data >> location >> result >> id_team1 >> id_team2;
    id_teams.push_back(id_team1);
    id_teams.push_back(id_team2);
    std::string tmp;
    std::getline(in, tmp);
    std::stringstream inbuf(tmp);
    int id;
    while (inbuf >> id) {
        id_players.push_back(id);
    }
}


void Match::serialize(std::ostream &out) {
    out << "match" << '\t'
        << id << '\t'
        << data << '\t'
        << location << '\t'
        << result << '\t'
        << id_teams[0] << '\t'
        << id_teams[1] << '\t';
    for (const auto player : players) {
        out << player->id << '\t';
    }
    out << std::endl;
}

Player::Player(std::istream &in) {
    in >> id >> name >> team_id;
}

void Player::serialize(std::ostream &out) {
    out << "player" << '\t'
        << id << '\t'
        << name << '\t'
        << team_id << std::endl;
}