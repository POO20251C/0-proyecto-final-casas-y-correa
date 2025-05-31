#include "../include/Score.h"
#include "../include/json.hpp"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

using json = nlohmann::json;

Score::Score() {
    this -> dir = "../Data/scores.json";
    loadScores();
}

void Score::loadScores() {
    std::ifstream inFile(dir);
    if (inFile.is_open()) {
        json j;
        inFile >> j;
        records.clear();

        for (const auto &item: j) {
            GameRecord r;
            r.name = item["Name"];
            r.date = item["Date"];
            r.rooms = item["Rooms"];
            r.health = item["Health"];
            r.score = item["Score"];
            records.push_back(r);
        }
        inFile.close();
    } else {
        std::cout << "No se encontro ese archivo :/" << std::endl;
        // No encontro el archivo
    }
}

void Score::addScore(const std::string &alias, const std::string &dateTime, int maxRoomCleared, int totalHealthLost,
                     int score) {
    GameRecord r;
    r.name = alias;
    r.date = dateTime;
    r.rooms = maxRoomCleared;
    r.health = totalHealthLost;
    r.score = score;

    records.push_back(r);
    saveScores();
}

void Score::saveScores() {
    std::ofstream outFile(dir);
    if (outFile.is_open()) {
        json j;
        for (const auto &r: records) {
            j.push_back({
                {"Name", r.name},
                {"Date", r.date},
                {"Rooms", r.rooms},
                {"Health", r.health},
                {"Score", r.score}
            });
        }
        outFile << std::setw(4) << j << std::endl;
        outFile.close();
    } else {
        std::cerr << "Error al guardar el archivo." << std::endl;
    }
}

std::vector<Score::GameRecord> Score::getTop(int n) const {
    std::vector<GameRecord> sorted = records;

    std::sort(sorted.begin(), sorted.end(), [](const GameRecord &a, const GameRecord &b) {
        if (a.score != b.score)
            return a.score > b.score;
        return a.rooms > b.rooms;
    });

    if (sorted.size() > size_t(n))
        sorted.resize(n);

    return sorted;
}