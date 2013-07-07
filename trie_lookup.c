#include<stdio.h>
#include<stdlib.h>

struct trie {
	int number;				// number is an int that stores number of times word appears
	struct trie** array;	// array is a pointer to an array of pointers, each of which points to a trie					// 
};							// array should be set to null when trie has no children


struct trie *new_trie();
void insert(struct trie *t, int *word, int word_len);
//int count(struct trie *t, unsigned char word[], int word_len);

int main()
{
	struct trie *t = new_trie(); // t is a pointer to a trie
	int word[4] = {1,2,3,4};
	insert(t, word, 1);
	return 0;
}

struct trie *new_trie() {
	struct trie *t = malloc(sizeof(struct trie));
	t->number = 0;
	t->array = NULL;
	return t;
}


// takes pointer to trie as an argument, iterates recursively across word[]
void insert(struct trie *t, int *word, int word_len) {
	if (word_len == 0) {
		t->number++;		// the end of the word is reached
	}
	else if (t->array == NULL)
	{
		// new_array is a pointer to an array of 26 pointers, each of which points to a trie
		struct trie *new_array = malloc(26*sizeof(struct trie*));
		// array is now set to the pointer to the array of pointers
		t->array = new_array;
		// insert is called with a trie pointer 
		// whose index in the array corresponds with the first element of the word[]
		// ex. [3,5,2] would go to array[word[3]], the value of which is a pointer to a trie;
		insert(t->array[word[0]], word, word_len);
	}
	else {
		// same as above insert call except iterated arguments
		insert(t->array[word[0]], word + 1, word_len - 1);
	}
}


// int count(struct trie *t, unsigned char word[], int word_len)
// {
// 	if (word_len == 0) {
// 		return t->number;
// 	}
// 	else
// 	{
// 		return count(&t->array[word[0]], word + 1, word_len - 1);
// 	}
// }
