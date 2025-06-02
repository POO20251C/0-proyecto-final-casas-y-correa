#ifndef SCORE_H
#define SCORE_H

#include <string>
#include <vector>

class Score {
private:
    struct GameRecord {
        std::string name;
        std::string date;
        int rooms;
        int health;
        int score;
    };

    std::string dir;
    std::vector<GameRecord> records;

    void saveScores();

public:
    Score();
    void loadScores();
    void addScore(const std::string& name, const std::string& date, int rooms, int health, int score);
    std::vector<GameRecord> getTop(int n) const;
};



#endif //SCORE_H
