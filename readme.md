# Alfabet Cupang Converter

## Overview

Halo, ini merupakan script untuk melakukan konversi Alfabet Cupang ke Alfabet atau sebaliknya. Ini dibuat dengan dasar "hanya untuk bersenang-senang".

<img src="./img/alfabet_cupang.jpg" alt="Alfabet Cupang" style="max-height: 400px;">

## Prerequisites

- Node.js (18 or higher)
- Git (if you want to clone the repository otherwise just download the zip)

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
npm run convert <mode> "<sentence>"
```

### Modes

- `local-to-cupang`: Convert from Local Alphabet to Cupang Alphabet
- `cupang-to-local`: Convert from Cupang Alphabet to Local Alphabet

### Examples

#### Convert Local Alphabet to Cupang Alphabet

```bash
node src/index.js local-to-cupang "HELLO WORLD"
```

or **(recommended)**

```bash
npm run convert local-to-cupang "HELLO WORLD"
```

#### Convert Cupang Alphabet to Local Alphabet

Use '|' to separate words and a space in before and after.

```bash
node src/index.js cupang-to-local "BLUK BULKBUL BULBUL BLUK BLUKBULBLUK | BULKBLUK BLUK BUL BLUK BLUBBUL"
```

or **(recommended)**

```bash
npm run convert cupang-to-local "BLUK BULKBUL BULBUL BLUK BLUKBULBLUK | BULKBLUK BLUK BUL BLUK BLUBBUL"
```

## Troubleshooting

Kalo salah, cek spelling pada masing-masing Alfabet.

## Dictionary

Definisi `CUPANG` dan `LOCAL` diambil dari `src/dict.js`.
