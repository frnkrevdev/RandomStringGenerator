#ifndef CONSTANTS_H
#define CONSTANTS_H

// Using these because everybody hates magic numbers
inline namespace ASCIIChars {
	// Constants for valid input ASCII characters
	constexpr int startChar{ 33 };			// First visible character (!)
	constexpr int endChar{ 126 };			// End visible character (~)
}

#endif