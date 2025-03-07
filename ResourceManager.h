#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <memory>
#include <string>

class ResourceManager {
public:
    ResourceManager() = default;
    ~ResourceManager() = default;

    // Getters for resources (load if not already cached)
    sf::Texture& getTexture(const std::string& path);
    sf::Font& getFont(const std::string& path);
    sf::Music* getMusic(const std::string& path); // Music is streamed, so use pointer
    static ResourceManager& getInstance() {
        static ResourceManager instance;
        return instance;
    }

    // Optional: Clear resources if needed (not used here but good practice)
    void clear();

private:
    std::unordered_map<std::string, std::unique_ptr<sf::Texture>> textures;
    std::unordered_map<std::string, std::unique_ptr<sf::Font>> fonts;
    std::unordered_map<std::string, std::unique_ptr<sf::Music>> music;
};



#endif // RESOURCEMANAGER_H