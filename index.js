import { localDict, cupangDict } from "./dict.js"

const getCupangDefinition = (char) => {
    return localDict[char] ?? "<check-your-spelling>"
}

const getLocalDefinition = (char) => {
    return cupangDict[char] ?? "<check-your-spelling>"
}

const localAlphabetToCupangAlphabet = (sentence) => {
    sentence = sentence.toUpperCase()
    let convertedSentence = ""
    for (let i = 0; i < sentence.length; i++) {
        convertedSentence += getCupangDefinition(sentence[i]) + " "
    }
    console.log(convertedSentence.trim())
}

const cupangAlphabetToLocalAlphabet = (sentence) => {
    sentence = sentence.toUpperCase()
    let convertedSentence = ""
    let split = sentence.split(" ")
    for (let i = 0; i < split.length; i++) {
        convertedSentence += getLocalDefinition(split[i])
    }
    console.log(convertedSentence)
}

const args = process.argv.slice(2)
const mode = args[0]
const input = args[1]

if (!mode || !input) {
    console.log("Usage: node index.js <mode> <sentence>")
    console.log("Modes: local-to-cupang or cupang-to-local")
    process.exit(1)
}

if (mode === "local-to-cupang") {
    localAlphabetToCupangAlphabet(input)
} else if (mode === "cupang-to-local") {
    cupangAlphabetToLocalAlphabet(input)
} else {
    console.log("Invalid mode. Use 'local-to-cupang' or 'cupang-to-local'")
    process.exit(1)
}
