#pragma once
// Direct Cache F06.cpp contains the following:
//
// - a set of #define's representing the constants used for this code
// - the declaration of the memory array
// - the definition of the class DirectCache including the constructor
// - powerOfTwo() function which returns the power of two to an exponent
// - main() with the initialization of the memory array and the class
//#include "stdafx.h"

//#include "pch.h"
#include "TestAddressSequences.h"
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

// The next two defines represent the size of the cache.  The first one
// is simply the number of words the cache can hold.  Dividing this by
// the number of words per block should give us the number of lines in 
// the cache.  The second one, MAXIMUM_NUMBER_OF_LINE_BITS, is really
// a fudge.  It is actually equal to log2(CACHE_SIZE), i.e., the number
// of bits that would be used for a line id if the block size were 
// equal to 1.  Every time you double the size of the block, you take
// away one bit from the number of line bits.


#define CACHE_SIZE	4096
#define MAXIMUM_NUMBER_OF_LINE_BITS	12
#define EIGHT_BIT_MASK 0xff

// This allows us to define the memory array.
#define NUMBER_OF_BITS_IN_ADDRESS	16


// pow() function, to calculate powers.

int powerOfTwo(int);

// We also need our memory.  Since this is declared dynamically, we need
// to initialize it as a pointer to an array of char.


char* memory;

/////////////////////////// class DirectCache ////////////////////////////
// This class defines a simulated direct cache of variable block size.  //
// It includes the constructor and prototypes for the functions         //
// requestMemoryAddress() and getPercentageOfHits().                    //
//////////////////////////////////////////////////////////////////////////


class DirectCache
{
public:
	DirectCache(int number_of_word_bits);
	bool requestMemoryAddress(unsigned int address);
	unsigned int getPercentageOfHits(void);

private:
	// Since the number of lines varies depending on the declared
	// number of words per block, we need to dynamically declare an
	// array to hold the tags and the block of words. The arrays 
	// "tags" and "blocks" are declared in the constructor.
	int* tags;
	int* blocks;
	int number_of_hits;
	int number_of_memory_requests;
	int number_of_lines_in_cache;
	int number_of_words_in_block;
	unsigned int tag_mask;
	unsigned int line_mask;
	unsigned int word_mask;
};

// Constructor
DirectCache::DirectCache(int number_of_word_bits)
{
	int number_of_tag_bits, number_of_line_bits;

	// With no memory accesses yet, initialize both the access and hit counters.
	number_of_memory_requests = 0;
	number_of_hits = 0;

	// Initialize the cache arrays containing the tags and the blocks
	number_of_words_in_block = powerOfTwo(number_of_word_bits);
	number_of_lines_in_cache = CACHE_SIZE / number_of_words_in_block;
	tags = new (int[number_of_lines_in_cache]);

	//*****NOTE***** I had to change the syntax of this following declaration -
	//               Just changed the , to a *
	//               It would not run correctly for me the other way - created problems!!

	blocks = new (int[number_of_lines_in_cache * number_of_words_in_block]);

	// Now figure out how many bits there are for each component of the address, i.e.,
	// how many bits for the tag and how many bits for the line id.
	number_of_line_bits = MAXIMUM_NUMBER_OF_LINE_BITS - number_of_word_bits;
	number_of_tag_bits = NUMBER_OF_BITS_IN_ADDRESS - number_of_line_bits - number_of_word_bits;

	// From the number of bits in each address component, we can now create the 
	// bit masks that will be used to pull apart an address.
	tag_mask = 0;
	line_mask = 0;
	word_mask = 0;
	for (int i = 0; i < number_of_tag_bits; i++)
		tag_mask = (tag_mask << 1) + 1;

	for (int i = 0; i < number_of_line_bits; i++)
	{
		tag_mask = tag_mask << 1;
		line_mask = (line_mask << 1) + 1;
	}

	for (int i = 0; i < number_of_word_bits; i++)
	{
		tag_mask = tag_mask << 1;
		line_mask = line_mask << 1;
		word_mask = (word_mask << 1) + 1;
	}


	// Initialize the tags array to ensure that we don't accidentally record
	// a hit if the block has not actually been loaded yet.
	for (int i = 0; i < number_of_lines_in_cache; i++)
		tags[i] = -1;

}

bool DirectCache::requestMemoryAddress(unsigned int address)
{
	cout << "address sent: " << address << " ";
	unsigned int tag, index, offset;
	int words = number_of_words_in_block;


	if (number_of_memory_requests == 0) {
		//blocks = new (int[number_of_lines_in_cache * number_of_words_in_block]);
		// Initialize the cache, or blocks array
		for (int i = 0; i < number_of_lines_in_cache; i++) {
			for (int j = 0; j < words; j++) {
				*(blocks + i * words + j) = -1;
			}
		}
		/*
		for (int i = 0; i < number_of_lines_in_cache; i++) {
			for (int j = 0; j < words; j++) {
				cout << *(blocks + i * words + j);
			}
		}
		*/
	}


	// divide memory address into it's 3 parts:  tag, index(line number) and offset(word position)

	tag = address & tag_mask;
	index = (address & line_mask) / number_of_words_in_block;
	offset = address & word_mask;

	// this will be the total number of requests used to calculate hit percentage
	number_of_memory_requests++;
	cout << "number_of_memory_requests " << number_of_memory_requests << endl;

	cout << "tag " << tag << "  ";
	//cout << "tag_mask " << tag_mask << " ";
	cout << "index " << index << " ";
	//cout << "line_mask: " << line_mask << " ";
	cout << "offset " << offset << " ";
	//cout << "word_mask: " << word_mask << " ";

	// Two cases:  the cache spot referenced is "empty" (-1) OR it is already filled -
	//             perhaps it is filled with the data we are looking for (address hit) -
	//             or perhaps there is some other data there that will get replaced
	//             with the new data.

	cout << "memory contents: " << (unsigned int)memory[address] << endl;


	// Add new data to cache if the block referenced is "empty"

	if (*(blocks + index * words + offset) == -1)
	{
		// use index and offset to update cache
		*(blocks + index * words + offset) = memory[address];
		cout << "new cache data: " << *(blocks + index * words + offset) << endl;
		// save tag value to use as upper bits of memory address
		tags[index] = tag;
	}

	// search cache for current address
	else if (*(blocks + index * words + offset) != -1)  // spot is used - but is it a match?
	{
		if (tags[index] == tag)   // need to look at tag for upper bits of address
		//if (*(blocks + index + offset) == (unsigned int)memory[address])
		{  // memory match
			number_of_hits++;
			cout << "number_of_hits " << number_of_hits << endl;
			return true;
		}
		else
		{   // replace old data with new
			*(blocks + index * words + offset) = memory[address];
			// save tag value to use as upper bits of memory address
			tags[index] = tag;
		}
	}

	// default
	return false;
}

unsigned int DirectCache::getPercentageOfHits(void)
{
	// return value:  % hits = total hits/mem requests * 100

	double percent_hits;

	percent_hits = (double)number_of_hits / (double)number_of_memory_requests * 100.0;

	return (unsigned int)percent_hits;

}

////////////////////////////// powerOfTwo() //////////////////////////////
// powerOfTwo() returns the value of two raised to the power exponent.  //
// Only allows for positive exponents.  If exponent is less than zero,  //
// an error condition of -1 is returned.                                //
//////////////////////////////////////////////////////////////////////////


int powerOfTwo(int exponent)
{
	int return_value;
	if (exponent < 0)
		return_value = -1;
	else if (exponent == 0)
		return_value = 1;
	else
	{
		return_value = 1;
		for (int i = 0; i < exponent; i++)
			return_value *= 2;
	}
	return(return_value);
}

//int _tmain(int argc, _TCHAR* argv[])

int main(int argc, char* argv[])
{
	// Declare the array of memory.
	memory = new (char[powerOfTwo(NUMBER_OF_BITS_IN_ADDRESS)]);

	// Ask user for the number of bits for the word id
	int number_of_bits_defining_block_size;
	cout << "Enter number of word id bits (1, 2, 3, 4, or 5): ";
	cin >> number_of_bits_defining_block_size;

	// The int should truncate, but we need to limit the number of bits
	// defining a block.
	if ((number_of_bits_defining_block_size > 0) &&
		(number_of_bits_defining_block_size < 6))
	{
		// Declare the cache
		DirectCache* cache;
		cache = new DirectCache(number_of_bits_defining_block_size);

		// This is a simple loop to initialize the memory array.  We're just
		// putting computed garbage in here so that we can have something to
		// examine/check when it comes time to verifying the operation of the
		// cache.
		//cout << "Fill memory array";
		for (int i = 0; i < powerOfTwo(NUMBER_OF_BITS_IN_ADDRESS); i++) {
			memory[i] = (65535 - i) & EIGHT_BIT_MASK;
		}
		/*
		for (int i = 905; i < 1025; i++) {
			cout << "memory[" << i << "]" << (unsigned int)memory[i] << endl;
		}
		*/
		// ADD this from .txt file
		for (int i = 0; i < sizeof(instruction_sequence) / 4; i++) {
			//cout << "call requestMemoryAddress() ";
			cache->requestMemoryAddress(instruction_sequence[i]);
		}

		cout << "The percentage of hits is: " << cache->getPercentageOfHits() << "\n";

	}
	else
	{
		cout << "Error: The number of bits entered must be 1, 2, 3, 4, or 5.";
	}
	return 0;
}

