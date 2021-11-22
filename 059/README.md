# Challenge 059 - Caesar Cipher Cracker

## Goals for This Challenge
- A small scale program to learn some Nim basics

## Summary
This program is a small Caesar cipher decoder/cracker, but also an encoder.
You can encode/decode with a known shift, and also dump all possible decodings.
The implementation of the Caesar cipher is case insensitive, though it will
maintain case during encoding/decoding.

## Dependencies
As this program is written in Nim, Nim needs to be installed on your machine.

## Implementation
The program is just a straightforward implementation of the [Caesar
cipher](https://en.wikipedia.org/wiki/Caesar_cipher).
No gory details necessary.

## Installation
No installation necessary. Compile the program normally and run it as detailed below.

## Usage
To encode a string:
```bash
./caesar encode <string to encode> <shift (letter or number)>
```

```bash
./caesar decode <string to decode> <shift (letter or number)>
```

```bash
./caesar dump-all <string to decode>
```

## Things That Can Be Improved
I'm sure my Nim is very sloppy, but it was my first attempt. Not really sure how I feel
about Nim based on first impressions, but hopefully my usage would improve with further
practice.

I also did not spend a lot of time doing input validation/sanitization because that stuff
is very tedious and boring to be quite honest.

## License
This code is licensed under the GNU GPL3 license.
