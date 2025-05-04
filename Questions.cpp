#include "Questions.h"

Questions::Questions(const string& question, const vector<string> opts, int correctIndex, bool vertical) {
	this->question = question;
	this->options = opts;
	this->correctAnswerIndex = correctIndex;
	this->vertical = vertical;
	for (int i = 0; i < opts.size(); i++)
		optionColor.push_back(sf::Color::White);

	if (!font.loadFromFile("PixelifySans-Regular.ttf")) {  // Use an existing font file
		cout << "Error loading font!" << endl;
		return;
	}
}

sf::Text Questions::questionAsText() {
	sf::Text questionText;
	questionText.setFont(font);
	questionText.setString(question);
	questionText.setCharacterSize(50);
	questionText.setFillColor(sf::Color::White);
	questionText.setPosition(100, 350);
	return questionText;
}

vector<sf::Text> Questions::optionsAsText() {
	vector<sf::Text> optionsText;
	for (size_t i = 0; i < options.size(); ++i) {
		sf::Text optionText;
		optionText.setFont(font);
		optionText.setString(options[i]);
		optionText.setCharacterSize(50);
		optionText.setFillColor(optionColor[i]);
		if (!vertical) {
			if (i < 2) {
				optionText.setPosition(170, 600 + (i * 150));  // Left side
			}
			else {
				optionText.setPosition(815, 600 + ((i - 2) * 150));  // Right side
			}
		}
		else {
			optionText.setPosition(170, 600 + (i * 150));
		}
		optionsText.push_back(optionText);
	}
	return optionsText;
}