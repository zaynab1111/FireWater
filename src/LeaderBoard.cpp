#include "Leaderboard.h"
#include <fstream>
#include <sstream>
#include <iostream>

int Leaderboard::computeScore(float time, int gems) const {
    // gems worth 100 points each, every second costs 1 point
    // higher score = better rank
    return (gems * 100) - static_cast<int>(time);
}

// greatest first. just basic insertion sort
void Leaderboard::insertionSort() {
    for (int i = 1; i < m_entries.size(); i++) {
        PlayerEntry key = m_entries[i];
        int j = i - 1;
        // shift entries with LOWER score one position to the right
        while (j >= 0 && m_entries[j] < key) {
            m_entries[j + 1] = m_entries[j];
            j--;
        }
        m_entries[j + 1] = key;
    }
    // result: m_entries[0] has the highest score = rank 1
}

Leaderboard::Leaderboard() {
    loadFromFile();
}

void Leaderboard::loadFromFile() {
    m_entries.clear(); //clear the vector before loading file content into it. warna the vector will keep storing the same objects baar baar every time it is run
    std::ifstream file(m_filename); //loading file

    if (!file.is_open()) {
        // if file doesnt exist yet.
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue; // just basic file handling


        std::stringstream ss(line);
        std::string name, timeStr, gemsStr;

        if (!std::getline(ss, name, ',')) continue;
        if (!std::getline(ss, timeStr, ',')) continue;
        if (!std::getline(ss, gemsStr, ',')) continue;
        //exception handling ofc
        try {
            PlayerEntry entry;
            entry.pairName = name;
            entry.timeSeconds = std::stof(timeStr);
            entry.gemsCollected = std::stoi(gemsStr);
            entry.score = computeScore(entry.timeSeconds, entry.gemsCollected);
            m_entries.push_back(entry);
        } catch (...) {
            std::cerr << "Skipping malformed leaderboard line: " << line << "\n";
        }
    }
}

void Leaderboard::saveToFile() const {
    std::ofstream file(m_filename); // overwrites the whole file each time because the sorting changes existing order

    if (!file.is_open()) {
        std::cerr << "Could not open leaderboard.txt for writing\n";
        return;
    }

    for (const auto& entry : m_entries) {
        file << entry.pairName << ","
             << entry.timeSeconds << ","
             << entry.gemsCollected << "\n";
    }
}

void Leaderboard::addEntry(const std::string& pairName, float timeSeconds, int gems) {
    PlayerEntry entry;
    entry.pairName= pairName;
    entry.timeSeconds= timeSeconds;
    entry.gemsCollected = gems;
    entry.score= computeScore(timeSeconds, gems);

    m_entries.push_back(entry);
    insertionSort(); //sort after every new entry
    saveToFile();    
}

void Leaderboard::render(sf::RenderWindow& window, const sf::Font& font) const {

    sf::RectangleShape bg({(float)window.getSize().x, (float)window.getSize().y});
    bg.setFillColor(sf::Color(20, 20, 40));
    window.draw(bg);

    // title
    sf::Text title(font, "LEADERBOARD", 70);
    title.setFillColor(sf::Color(255, 215, 0)); // gold
    title.setOutlineColor(sf::Color::Black);
    title.setOutlineThickness(4.f);
    sf::FloatRect tb = title.getLocalBounds();
    title.setOrigin({tb.position.x + tb.size.x / 2.f, tb.position.y + tb.size.y / 2.f});
    title.setPosition({window.getSize().x / 2.f, 80.f});
    window.draw(title);

    if (m_entries.empty()) {
        sf::Text empty(font, "No scores yet!", 40);
        empty.setFillColor(sf::Color::White);
        sf::FloatRect eb = empty.getLocalBounds();
        empty.setOrigin({eb.position.x + eb.size.x / 2.f, eb.position.y + eb.size.y / 2.f});
        empty.setPosition({window.getSize().x / 2.f, window.getSize().y / 2.f});
        window.draw(empty);
        return;
    }

    // column headers
    float startY = 180.f;
    float rowHeight = 60.f;

    sf::Text header(font, "#    NAME                    GEMS    TIME     SCORE", 32);
    header.setFillColor(sf::Color(200, 200, 200));
    header.setPosition({100.f, startY});
    window.draw(header);

    // divider line
    sf::RectangleShape divider({(float)window.getSize().x - 200.f, 2.f});
    divider.setFillColor(sf::Color(100, 100, 100));
    divider.setPosition({100.f, startY + 45.f});
    window.draw(divider);

    // each entry row
    int maxToShow = std::min((int)m_entries.size(), 8); // show top 8 only
    for (int i = 0; i < maxToShow; i++) {
        const auto& e = m_entries[i];

        sf::Color rowColor = sf::Color::White;
        if (i == 0) rowColor = sf::Color(255, 215, 0);   
        else if (i == 1) rowColor = sf::Color(192, 192, 192); 
        else if (i == 2) rowColor = sf::Color(205, 127, 50);  

        // build the row string (fixed-width feel)
        std::string timeStr = std::to_string((int)e.timeSeconds) + "s";
        std::string row = std::to_string(i + 1) + ".   " +
                          e.pairName + "          " +
                          std::to_string(e.gemsCollected) + "       " +
                          timeStr + "     " +
                          std::to_string(e.score);

        sf::Text rowText(font, row, 34);
        rowText.setFillColor(rowColor);
        rowText.setPosition({100.f, startY + 55.f + (i * rowHeight)});
        window.draw(rowText);
    }

    // "Press ESC to go back" hint
    sf::Text hint(font, "Press ESC to return to menu", 28);
    hint.setFillColor(sf::Color(150, 150, 150));
    sf::FloatRect hb = hint.getLocalBounds();
    hint.setOrigin({hb.position.x + hb.size.x / 2.f, 0.f});
    hint.setPosition({window.getSize().x / 2.f, window.getSize().y - 60.f});
    window.draw(hint);
}

const std::vector<PlayerEntry>& Leaderboard::getEntries() const {
    return m_entries; //getter for the entries 
}