# TextInsight

A text analysis web application built with a C++ backend and an HTML, CSS, and JavaScript frontend.

## Features

- Count characters, including spaces
- Count words separated by whitespace
- Count characters excluding ordinary spaces
- Count consecutive sentence-ending punctuation marks as one sentence
- Responsive result cards
- Prevent empty submissions

## Technologies

- C++17
- cpp-httplib
- HTML
- CSS
- JavaScript
- HTTP and JSON

## How to Run

Open a terminal in the project folder.

Compile:

```bash
clang++ -std=c++17 -pthread main.cpp -o textinsight
```

Start the server:

```bash
./textinsight
```

Open http://localhost:8080 in your browser.

Keep the terminal open while using the application.
Press Control + C to stop the server.

## Limitations

- Character counting is intended for ASCII text. UTF-8 characters may count as multiple bytes.
- Sentence counting uses groups of `.`, `!`, and `?`; it does not perform grammatical analysis.
- Only ordinary spaces are excluded from the character count without spaces.

## Third-Party Library

This project uses cpp-httplib, distributed under the MIT license.