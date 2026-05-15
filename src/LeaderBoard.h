#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
// a struct defined for a pair of players:
//for example mehdiya and abeer are one player entry
struct PlayerEntry {
    std::string pairName;   // "FireboyName & WatergirlName"
    float timeSeconds;      // how long they took
    int gemsCollected;      // total gems both players collected
    int score;
    bool operator < (const PlayerEntry& other) const {
        return score < other.score;
    }
    bool operator == (const PlayerEntry& other) const {
        return score == other.score;
    }              
};

class Leaderboard {
private:

    std::vector<PlayerEntry> m_entries; //list of all players to be displayed on the screen(also gets sorted)
    const std::string m_filename = "leaderboard.txt";

    int computeScore(float time, int gems) const;
    void insertionSort(); //sorting algo. 

public:
    Leaderboard();
    void loadFromFile(); // reads leaderboard.txt into m_entries
    void saveToFile() const;  // writes sorted m_entries back to file
    void addEntry(const std::string& pairName, float timeSeconds, int gems); // adds, sorts, saves
    void render(sf::RenderWindow& window, const sf::Font& font) const; // draws the leaderboard screen
    const std::vector<PlayerEntry>& getEntries() const;
};