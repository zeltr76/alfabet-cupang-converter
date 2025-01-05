# Alfabet Cupang Converter

## Overview

Halo, silakan baca dan pahami sendiri fungsinya apa.

## Prerequisites

-   Node.js (16 or higher)
-   Git (if you want to clone the repository otherwise just download the zip)

## Installation

1. Clone

```bash
git clone https://github.com/zeltr76/alfabet-cupang-converter.git
cd alfabet-cupang-converter
```

2. Cek instalasi Node.js

```bash
node --version
```

## Usage

### Command-Line Syntax

```bash
node index.js <mode> <sentence>
```

### Modes

-   `local-to-cupang`: Convert from Local Alphabet to Cupang Alphabet
-   `cupang-to-local`: Convert from Cupang Alphabet to Local Alphabet

### Examples

#### Convert Local Alphabet to Cupang Alphabet

```bash
node index.js local-to-cupang "HELLO WORLD"
```

or

```bash
npm run convert local-to-cupang "HELLO WORLD"
```

#### Convert Cupang Alphabet to Local Alphabet

Use '|' to separate words

```bash
node index.js cupang-to-local "BLUK BULKBUL BULBUL BLUK BLUKBULBLUK | BULKBLUK BLUK BUL BLUK BLUBBUL"
```

or

```bash
npm run convert cupang-to-local "BLUK BULKBUL BULBUL BLUK BLUKBULBLUK | BULKBLUK BLUK BUL BLUK BLUBBUL"
```

## Troubleshooting

Kalo salah, cek spelling-nya.

## Dictionary

Definisi CUPANG dan LOCAL diambil dari `dict.js`.
