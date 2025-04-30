#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/System.hpp>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>
#include "Questions.h"
#include "Player.h"

using namespace std;

class Level1 {
private:
	sf::RectangleShape startButton;
	sf::Text startButtonText;
	sf::Clock clickClock;
	sf::RectangleShape timerBox;
	sf::Text time;
	sf::Font font;
	sf::RectangleShape anagramBox;
	sf::Text anagram;
	string anagramStr;
	sf::RectangleShape pointsBox;
	sf::Text points;
	vector<Questions>  questions;
	vector<sf::Sprite> hearts;
	sf::Texture heartTexture;
	sf::RectangleShape inputBox;
	sf::Text inputText;
	int incorrectAttempt;
	sf::Clock colorChangeClock;
	string inputStr;
	bool isInputActive;
	int currentHearts;
	sf::Text passcodeHint;
	string riddleText;
	sf::Text riddleDisplay;
	sf::Clock gameClock;
	bool gameStarted = false;
	float timeLimit;
	
	bool timerStarted;
	sf::Clock questionClock;
	sf::Texture lightBulbTexture;
	sf::Sprite lightBulb;
	sf::Texture hintTexture;
	sf::Sprite hintSprite;
	bool showHint = false;
	sf::RectangleShape gameButton;
	sf::Text gameButtonText;
	sf::Texture level1FailedTexture;
	sf::Sprite level1FailedSprite;
	sf::Texture shadowRulesTexture;
	sf::Sprite shadowRulesSprite;
	sf::RectangleShape playShadowStrikeButton;
	sf::Text playShadowStrikeButtonText;
	Player& player;
	vector<int>::iterator itr;
	struct TextComparator {
		bool operator()(const sf::Text& a, const sf::Text& b) const {
			return a.getString() < b.getString(); // compare based on text content
		}
	};

public:
	Level1(sf::RenderWindow& window, sf::Texture& texture, sf::Sprite& sprite, sf::Text text, Player& player);
	int play(sf::RenderWindow& window, sf::Texture& texture, sf::Sprite& sprite, sf::Text text);
	bool displayPicture(string picName, sf::Texture& texture, sf::Sprite& sprite);
	string timeConverter(float time);
	void drawWindow(sf::RenderWindow& window, vector<sf::Sprite> sprites);
	void drawWindow(sf::RenderWindow& window, vector<sf::Sprite> sprites, multimap<sf::Text, sf::RectangleShape, TextComparator> buttons);
	void drawWindow(sf::RenderWindow& window, vector<sf::Sprite> sprites, multimap<sf::Text, sf::RectangleShape, TextComparator> buttons, Questions question);
	void drawWindow(sf::RenderWindow& window, vector<sf::Sprite> sprites, sf::RectangleShape button, sf::Text text);
	void drawWindow(sf::RenderWindow& window, sf::Sprite sprite, sf::Text text);
	void drawWindow(sf::RenderWindow& window, vector<sf::Sprite> sprites, Questions question);
	/*void drawPasscodeWindow(sf::RenderWindow& window, sf::Sprite& sprite);
	void drawCongratsWindow(sf::RenderWindow& window, sf::Sprite& sprite);
	void drawRiddleWindow(sf::RenderWindow& window, sf::Sprite&);
	void drawGameOverWindow(sf::RenderWindow& window, sf::Sprite& sprite);
	void drawLevel1FailedWindow(sf::RenderWindow& window, sf::Sprite& sprite);
	void drawShadowRulesWindow(sf::RenderWindow& window, sf::Sprite& sprite);*/
};