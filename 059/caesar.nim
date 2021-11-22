#[
caesar.nim

Implementation of a Caesar cipher encoder
and decoder for Nim learning purposes and
to do an easy /g/ challenge.
]#
proc caesarEncode(s: string, shift: int): string =
  var
    output: string
  for l in s:
    var c = char(((int(l)-int('a') + shift) mod 26) + int('a'))
    output &= c
  return output

var p = caesarEncode("abcdefg", 1)
echo p
