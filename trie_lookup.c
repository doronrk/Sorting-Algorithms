#include<stdio.h>
#include<stdlib.h>

struct trie {
  int number;
	struct trie** array;
};

struct trie *new_trie();
void insert(struct trie *t, unsigned char word[], int word_len);
//int count(struct trie *t, unsigned char word[], int word_len);

int main()
{
	struct trie *t = new_trie();
	insert(t, "a", 1);
	return 0;
}

struct trie *new_trie() {
	struct trie *t = malloc(sizeof(struct trie));
	t->number = 0;
	t->array = NULL;
	return t;
}

void insert(struct trie *t, unsigned char word[], int word_len) {
	if (word_len == 0) {
		t->number++;
	}
	else if (t->array == NULL)
	{
		struct trie *new_array = malloc(26*sizeof(struct trie*));
		t->array = new_array;
		insert(t->array[word[0]], word, word_len);
	}
	else {
		insert(t->array[word[0]], word + 1, word_len - 1);
	}
}
