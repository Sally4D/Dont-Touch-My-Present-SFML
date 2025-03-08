#include "ResourceManager.h"
#include <iostream>

sf::Texture& ResourceManager::getTexture(const std::string& path) {
    auto it = textures.find(path);
    if (it == textures.end()) {
        auto texture = std::make_unique<sf::Texture>();
        if (!texture->loadFromFile(path)) {
            std::cout << "Error loading texture: " << path << "\n";
        }
        it = textures.emplace(path, std::move(texture)).first;
    }
    return *(it->second);
}

sf::Font& ResourceManager::getFont(const std::string& path) {
    auto it = fonts.find(path);
    if (it == fonts.end()) {
        auto font = std::make_unique<sf::Font>();
        if (!font->loadFromFile(path)) {
            std::cout << "Error loading font: " << path << "\n";
        }
        it = fonts.emplace(path, std::move(font)).first;
    }
    return *(it->second);
}

sf::Music* ResourceManager::getMusic(const std::string& path) {
    auto it = music.find(path);
    if (it == music.end()) {
        auto musicPtr = std::make_unique<sf::Music>();
        if (!musicPtr->openFromFile(path)) {
            std::cout << "Error loading music: " << path << "\n";
            return nullptr;
        }
        it = music.emplace(path, std::move(musicPtr)).first;
    }
    return it->second.get();
}

void ResourceManager::clear() {
    textures.clear();
    fonts.clear();
    music.clear();
}