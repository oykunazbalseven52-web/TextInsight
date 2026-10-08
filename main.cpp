#include <iostream>
#include <string>
#include <sstream>
#include "httplib.h"
using namespace std;

int countWords(const string &text)
{

    istringstream stream(text);
    string word;
    int wordCount = 0;

    while (stream >> word)
    {
        wordCount++;
    }
    return wordCount;
}

int countSentences(const string &text)
{
    int sentenceCount = 0;
    bool previousWasSentenceEnd = false;

    for (char character : text)
    {
        bool isSentenceEnd =
            character == '.' || character == '!' || character == '?';

        if (isSentenceEnd && !previousWasSentenceEnd)
        {
            sentenceCount++;
        }

        previousWasSentenceEnd = isSentenceEnd;
    }

    return sentenceCount;
}

int countCharacterWithoutSpaces(const string &text)
{
    int characterCountWithoutSpace = 0;

    for (char character : text)
    {
        if (character != ' ')
        {
            characterCountWithoutSpace++;
        }
    }
    return characterCountWithoutSpace;
}

string analyzeText(const string &text)
{
    ostringstream result;

    result << "{"
           << "\"characterCount\":" << text.length() << ","
           << "\"wordCount\":" << countWords(text) << ","
           << "\"characterCountWithoutSpaces\":" << countCharacterWithoutSpaces(text) << ","
           << "\"sentenceCount\":" << countSentences(text)
           << "}";

    return result.str();
}

int main()
{
    httplib::Server server;

    if (!server.set_mount_point("/", "./public"))
    {
        cerr << "Could not find the public folder." << endl;
        return 1;
    }

    server.Post("/analyze", [](const httplib::Request &request,
                               httplib::Response &response)
                {
        string text = request.body;
        string result = analyzeText(text);

        response.set_content(result, "application/json"); });

    cout << "Open http://localhost:8080 in your browser." << endl;

    if (!server.listen("127.0.0.1", 8080))
    {
        cerr << "Could not start the server." << endl;
        return 1;
    }

    return 0;
}