#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <vector>
#include <cstring>

using namespace std;

const map<char, string> localDict = { 
    {'A', "BLUK"},
    {'B', "BUL"},
    {'C', "BULK"},
    {'D', "BLUB"},
    {'E', "BLUKBLUK"},
    {'F', "BLUKBUL"},
    {'G', "BLUKBULK"},
    {'H', "BLUKBLUB"},
    {'I', "BULBLUK"},
    {'J', "BULBUL"},
    {'K', "BULBULK"},
    {'L', "BULBLUB"},
    {'M', "BULKBLUK"},
    {'N', "BULKBUL"},
    {'O', "BULKBULK"},
    {'P', "BULKBLUB"},
    {'Q', "BLUBBLUK"},
    {'R', "BLUBBUL"},
    {'S', "BLUBBULK"},
    {'T', "BLUBBLUB"},
    {'U', "BLUKBLUKBLUK"},
    {'V', "BLUKBLUKBUL"},
    {'W', "BLUKBLUKBULK"},
    {'X', "BLUKBLUKBLUB"},
    {'Y', "BLUKBULBLUK"},
    {'Z', "BLUKBULBUL"},
    {' ', "|"}
};

const map<string, char> cupangDict = {
    {"BLUK", 'A'},
    {"BUL", 'B'},
    {"BULK", 'C'},
    {"BLUB", 'D'},
    {"BLUKBLUK", 'E'},
    {"BLUKBUL", 'F'},
    {"BLUKBULK", 'G'},
    {"BLUKBLUB", 'H'},
    {"BULBLUK", 'I'},
    {"BULBUL", 'J'},
    {"BULBULK", 'K'},
    {"BULBLUB", 'L'},
    {"BULKBLUK", 'M'},
    {"BULKBUL", 'N'},
    {"BULKBULK", 'O'},
    {"BULKBLUB", 'P'},
    {"BLUBBLUK", 'Q'},
    {"BLUBBUL", 'R'},
    {"BLUBBULK", 'S'},
    {"BLUBBLUB", 'T'},
    {"BLUKBLUKBLUK", 'U'},
    {"BLUKBLUKBUL", 'V'},
    {"BLUKBLUKBULK", 'W'},
    {"BLUKBLUKBLUB", 'X'},
    {"BLUKBULBLUK", 'Y'},
    {"BLUKBULBUL", 'Z'},
    {"|", ' '} 
};

vector<string> splitSentence(string sentence, char delimiter) {
    size_t end = sentence.find(delimiter);
    size_t start = 0;

    vector<string> splittedSentence;

    while (end != string::npos) {
        splittedSentence.push_back(sentence.substr(start, end - start));
        start = end + 1;
        end = sentence.find(delimiter, start);
    }

    splittedSentence.push_back(sentence.substr(start));

    return splittedSentence;
}

string getCupangDefinition(char local) {
    // check if the local char exist
    if (localDict.count(local) == 1) {
        return localDict.at(local);
    } else {
        return "0";
    }
}

char getLocalDefinition(string cupang) {
    // check if the cupang word exist
    if (cupangDict.count(cupang) == 1) {
        return cupangDict.at(cupang);
    } else {
        return '0';
    }
}

string localToCupangAlphabet(string sentence) {
    // the only available option is by using the std library touppper() but it can only takes char as an argument.
    // so what i need to is i need to retrieve each char in the sentence and transform that into uppercase in order that to work.

    // create a NewSentence variable and initialize to have the same length as the sentence
    string uppercaseSentence;

    for (size_t i = 0; i < sentence.length(); i++) {
        if (isblank(sentence.at(i))) {
            uppercaseSentence += ' ';
        } else {
            uppercaseSentence += toupper(sentence.at(i));
        }
    }

    string convertedSentence;

    for (size_t i = 0; i < uppercaseSentence.length(); i++) {
        convertedSentence += getCupangDefinition(uppercaseSentence.at(i));
        convertedSentence += ' ';
    }

    return convertedSentence + "\n";
}

string cupangToLocalAlphabet(string sentence) {
    // to uppercase
    string uppercaseSentence;
    
    for (size_t i = 0; i < sentence.length(); i++) {
        if (isblank(sentence.at(i))) {
            uppercaseSentence += ' ';
        } else {
            uppercaseSentence += toupper(sentence.at(i));
        }
    }

    // split each Cupang Alphabet in uppercaseSentence
    vector<string> splittedWord = splitSentence(uppercaseSentence, ' ');

    // to local alphabet
    string convertedSentence;

    for (size_t i = 0; i < splittedWord.size(); i++) {
        convertedSentence += getLocalDefinition(splittedWord.at(i));
    }

    return convertedSentence + "\n";
}

int main(int argc, char* argv[]) {
    // check if the argc (argument count) is = 3 (including the program name argv[0]) because it needs 2 arguments.
    if (argc != 3) {
        cout << "\nYou need to provide 2 arguments.\n";
        cout << "\tUsage: ./main (Windows: main.exe) <mode> <sentence>\n";
        cout << "\tModes: local-to-cupang or cupang-to-local.\n";
        cout << "\nExample:\n1) local -> cupang: ./main local-to-cupang \"anjay\"\n2) cupang -> local: ./main cupang-to-local \"BLUK BULKBUL BULBUL BLUK BLUKBULBLUK | BULKBLUK BLUK BUL BLUK BLUBBUL\"\nWhere \"|\" is the demiliter (space).\n\n";
        
        return 1;
    }

    // check the second argument (the modes)
    // use strcmp from <cstring> to compare the contents of C-style strings Deepseek AI said (idk what is that). 
    if (strcmp(argv[1], "local-to-cupang") == 0) {
        cout << localToCupangAlphabet(argv[2]);
        return 0;
    }

    if (strcmp(argv[1], "cupang-to-local") == 0) {
        cout << cupangToLocalAlphabet(argv[2]);
        return 0;
    }

    cout << "Unknown error occurred\n";
    return 1;
}