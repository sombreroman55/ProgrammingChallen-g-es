#[
caesar.nim

Implementation of a Caesar cipher encoder
and decoder for Nim learning purposes and
to do an easy /g/ challenge.
]#
import os
import std/strutils

proc isAlpha(c: char): bool =
  return c in Letters

proc caesarEncode(s: string, shift: int): string =
  var
    output: string
    c: char
    upper: int
  for l in s:
    if 'a' <= l and l <= 'z':
      upper = int('a')
    elif 'A' <= l and l <= 'Z':
      upper = int('A')
    c = char(((int(l) - upper + (shift mod 26)) mod 26) + upper)
    output &= c
  return output

proc caesarDecode(s: string, shift: int): string =
  var
    output: string
    c: char
    upper: int
  for l in s:
    if 'a' <= l and l <= 'z':
      upper = int('a')
    elif 'A' <= l and l <= 'Z':
      upper = int('A')
    c = char(((int(l) - upper + 26 - (shift mod 26)) mod 26) + upper)
    output &= c
  return output

proc caesarDumpAllPossibleDecodings(s: string): array[26, string] =
  var
    allDecodings: array[26, string]
  for i in 0 ..< 26:
    allDecodings[i] = caesarDecode(s, i)
  return allDecodings

proc printUsage(): void =
  echo "caesar usage:"
  echo "  Encode a string: ./caesar encode <string to encode> <shift (letter or number)>"
  echo "  Decode a string: ./caesar decode <string to decode> <shift (letter or number)>"
  echo "  Dump all possible decodings: ./caesar dump-all <string to decode>"

proc printError(error: string): void =
  echo "Error: ", error
  printUsage()

if paramCount() == 2:
  if paramStr(1) == "dump-all":
    echo caesarDumpAllPossibleDecodings(paramStr(2))
  else:
    printUsage()

elif paramCount() == 3:
  var
    shift: int = 0

  if paramStr(1) == "encode":
    try:
      shift = parseInt(string(paramStr(3)))
      echo caesarEncode(paramStr(2), shift)
    except ValueError:
      if isAlpha(paramStr(3)[0]):
        shift = int(toLowerAscii(paramStr(3)[0])) - int('a')
        echo caesarEncode(paramStr(2), shift)
      else:
        printError("Shift is not a letter or a number")

  elif paramStr(1) == "decode":
    try:
      shift = parseInt(string(paramStr(3)))
      echo caesarDecode(paramStr(2), shift)
    except ValueError:
      if isAlpha(paramStr(3)[0]):
        shift = int(toLowerAscii(paramStr(3)[0])) - int('a')
        echo caesarDecode(paramStr(2), shift)
      else:
        printError("Shift is not a letter or a number")

  else:
    printUsage()

else:
  printUsage()
