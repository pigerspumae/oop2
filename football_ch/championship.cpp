#include "championship.hpp"


void Championship::create_vectorsMembers(std::istream &in) {
    std::string type;
    PlayerCreator pCreator;
    TeamCreator tCreator;
    MatchCreator mCreator;

    while (in >> type) {
        if (type == "team") {
            Team *t = tCreator.factoryMethod(in);
            std::shared_ptr<Team> t_sh(t);
            teams.push_back(t_sh);
        } else if (type == "player") {
            Player *p = pCreator.factoryMethod(in);
            std::shared_ptr<Player> p_sh(p);
            players.push_back(p_sh);
        } else if (type == "match") {
            Match *m = mCreator.factoryMethod(in);
            std::shared_ptr<Match> m_sh(m);
            matches.push_back(m_sh);
        }
    }
}

void Championship::restore_relationship() {
    for (auto player : players) {
        for (auto team : teams) {
            if (player->team_id == team->id) {
                player->team = team;
                break;
            }
        }
    }

    for (auto team : teams) {
        for (uint32_t id : team->id_players) {
            for (auto player : players) {
                if (player->id == id) {
                    team->players.push_back(player);
                    break;
                }
            }
        }
    }


    for (auto match : matches) {

        for (auto team : teams) {
            if (match->id_teams[0] == team->id) {
                match->team1 = team;
                break;
            } else if (match->id_teams[1] == team->id) {
                match->team2 = team;
                break;
            }
        }

        for (uint32_t id : match->id_players) {
            for (auto player : players) {
                if (player->id == id) {
                    match->players.push_back(player);
                    break;
                }
            }
        }
    }
}

void Championship::deserialize_members(std::istream &in) {
    create_vectorsMembers(in);
    restore_relationship();
}

void Championship::serialize_pvector(std::ostream &pout) {
    for (auto &player: players) {
        player->serialize(pout);
    }
}

void Championship::serialize_tvector(std::ostream &tout) {
    for (auto &team: teams) {
        team->serialize(tout);
    }
}

void Championship::serialize_mvector(std::ostream &mout) {
    for (auto &match: matches) {
        match->serialize(mout);
    }
}


