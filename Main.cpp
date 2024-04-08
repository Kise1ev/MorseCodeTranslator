#include "MorseCodeTranslator.h"

unordered_map<string, string> morseTranslations = {
    {".-", "A"},   {"-...", "B"}, {"-.-.", "C"}, {"-..", "D"},  {".", "E"},
    {"..-.", "F"}, {"--.", "G"},  {"....", "H"}, {"..", "I"},   {".---", "J"},
    {"-.-", "K"},  {".-..", "L"}, {"--", "M"},   {"-.", "N"},   {"---", "O"},
    {".--.", "P"}, {"--.-", "Q"}, {".-.", "R"},  {"...", "S"},  {"-", "T"},
    {"..-", "U"},  {"...-", "V"}, {".--", "W"},  {"-..-", "X"}, {"-.--", "Y"},
    {"--..", "Z"}, {"-----", "0"}, {".----", "1"}, {"..---", "2"}, {"...--", "3"},
    {"....-", "4"}, {".....", "5"}, {"-....", "6"}, {"--...", "7"}, {"---..", "8"},
    {"----.", "9"}, {"----", "CH"}
};

vector<string> split(const string& value, char delimiter) {
    vector<string> tokens;
    istringstream iss(value);
    string token;
    while (getline(iss, token, delimiter))
        if (!token.empty()) 
            tokens.push_back(token);
    return tokens;
}

vector<string> translateMorseToLatin(const string& message) {
    vector<string> latinWords;
    vector<string> morseWords = split(message, '/');

    for (const string& morseWord : morseWords) {
        vector<string> morseLetters = split(morseWord, ' ');
        
        string latinWord = "";
        for (const string& morseLetter : morseLetters) {
            auto it = morseTranslations.find(morseLetter);
            if (it != morseTranslations.end()) 
                latinWord += it->second;
        }

        if (!latinWord.empty()) 
            latinWords.push_back(latinWord);
    }

    return latinWords;
}

int main() {
    string message;
    cout << "Enter the morse code message: ";
    getline(cin, message);

    vector<string> latinWords = translateMorseToLatin(message);
    cout << "Translated message: ";
    for (const string& word : latinWords) 
        cout << word << ' ';

    cout << endl << endl;

    system("pause");
    return 0;
}
