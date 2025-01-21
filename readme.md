# Alfabet Cupang Converter

## Overview

Halo.

## Prerequisites

-   Linux, unless you want to compile the file yourself to Windows (exe).
-   Git (if you want to clone the repository otherwise just download the zip).

## Installation

1. Clone

```bash
git clone https://github.com/zeltr76/alfabet-cupang-converter.git
cd alfabet-cupang-converter
```

2. Look for `main`

## Usage

### Command-Line Syntax

```bash
./main <mode> "<sentence>"
```

### Modes

-   `local-to-cupang`: Convert from Local Alphabet to Cupang Alphabet
-   `cupang-to-local`: Convert from Cupang Alphabet to Local Alphabet

### Examples

#### Convert Local Alphabet to Cupang Alphabet

```bash
./main local-to-cupang "HELLO WORLD"
```

#### Convert Cupang Alphabet to Local Alphabet

Use '|' to separate words

```bash
./main cupang-to-local "BLUK BULKBUL BULBUL BLUK BLUKBULBLUK | BULKBLUK BLUK BUL BLUK BLUBBUL"
```

## Troubleshooting

If it returns **0**, it means you have spelling error.