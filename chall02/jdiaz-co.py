#!/usr/bin/python3

import sys

def morse(string):
	letters = {
	" ":" ",
	"a":".-", 
	"b":"-...", 
	"c":"-.-.", 
	"d":"-..", 
	"e":".", 
	"f":"..-.", 
	"g":"--.", 
	"h":"....",
	"i":"..", 
	"j":".---", 
	"k":"-.-", 
	"l":".-..", 
	"m":"--", 
	"n":"-.", 
	"o":"---", 
	"p":".--.", 
	"q":"--.-",
	"r":".-.", 
	"s":"...", 
	"t":"-", 
	"u":"..-", 
	"v":"...-", 
	"w":".--", 
	"x":"-..-", 
	"y":"-.--", 
	"z":"--.."}

	for char in string:
		if char not in letters.keys():
			sys.stderr.write("usage: ./jdiaz-co.py <a-zA-Z string>\n") 
	for char in string:
		sys.stdout.write(letters[char])
	sys.stdout.write("\n")

def main():
	if not len(sys.argv) == 2 or not sys.argv[1]:
		sys.stderr.write("usage: ./jdiaz-co.py <a-zA-Z string>\n") 
	else:
		morse(sys.argv[1].lower())

if __name__ == "__main__":
	main()