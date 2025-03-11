const { localDict, cupangDict } = require("./dict.js");

const getCupangDefinition = (char) => {
  return localDict[char] ?? "<check-your-spelling>";
};

const getLocalDefinition = (char) => {
  return cupangDict[char] ?? "<check-your-spelling>";
};

const localAlphabetToCupangAlphabet = (sentence) => {
  sentence = sentence.toUpperCase();
  let convertedSentence = "";
  for (let i = 0; i < sentence.length; i++) {
    convertedSentence += getCupangDefinition(sentence[i]) + " ";
  }
  return convertedSentence.trim();
};

const cupangAlphabetToLocalAlphabet = (sentence) => {
  sentence = sentence.toUpperCase();
  let convertedSentence = "";
  let split = sentence.split(" ");
  for (let i = 0; i < split.length; i++) {
    convertedSentence += getLocalDefinition(split[i]);
  }
  return convertedSentence;
};

module.exports = {
  localAlphabetToCupangAlphabet,
  cupangAlphabetToLocalAlphabet,
};
