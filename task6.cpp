#include <iostream>
#include <string>

using namespace std;

void wrapText(const string& text, int lineWidth) {
    string words[100];
    int wordCount = 0;
    string word = "";
    for (char c : text) {
        if (c == ' ') {
            words[wordCount++] = word;
            word = "";
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        words[wordCount++] = word;
    }

    int currentLineWidth = 0;
    for (int i = 0; i < wordCount; i++) {
        if (currentLineWidth + words[i].size() <= lineWidth) {
            cout << words[i] << " ";
            currentLineWidth += words[i].size() + 1;
        } else {
            cout << endl;
            cout << words[i] << " ";
            currentLineWidth = words[i].size() + 1;
        }
    }
    cout << endl;
}

int main() {
    string text = "Mahmoud loves to code and play basketball.";
    int lineWidth = 10;
    wrapText(text, lineWidth);
    return 0;
}