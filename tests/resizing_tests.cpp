#include "pch.h"
#include "../src/vector.h"
#include "../src/vector.cpp"

TEST(RESIZING_VECTOR, PUSH_BACK) {
	vector<int> tab;
	int x = 3;
	tab.push_back(x);
	EXPECT_EQ(1, tab.size());
	EXPECT_GE(tab.capacity(), 2);

	tab.push_back(x);
	EXPECT_EQ(2, tab.size());
	EXPECT_GE(tab.capacity(), 2);
	
	EXPECT_TRUE(tab[0] == x);
	EXPECT_TRUE(tab[1] == x);
}

TEST(RESIZING_VECTOR, POP_BACK) {
	vector<int> tab(2);

	tab.pop_back();
	EXPECT_EQ(1, tab.size());
	tab.pop_back();
	EXPECT_EQ(0, tab.size());

	tab.pop_back();
	tab.pop_back();
	EXPECT_EQ(0, tab.size());
}

TEST(RESIZING_VECTOR, RESERVE) {
	vector<int> tab(2);
	EXPECT_GE(tab.capacity(), 2);

	tab.reserve(50);
	EXPECT_EQ(tab.capacity(), 50);

	tab.reserve(52);
	EXPECT_EQ(tab.capacity(), 52);

	tab.reserve(31);
	EXPECT_EQ(tab.capacity(), 52);
}

TEST(RESIZING_VECTOR, RESIZE) {
	vector<int> tab(2);
	EXPECT_EQ(tab.size(), 2);

	tab.resize(50);
	EXPECT_EQ(tab.size(), 50);

	tab.resize(52);
	EXPECT_EQ(tab.size(), 52);

	tab.resize(31);
	EXPECT_EQ(tab.size(), 31);
}

TEST(RESIZING_VECTOR, CLEAR) {
	vector<int> tab(10);
	tab.clear();
	EXPECT_EQ(tab.size(), 0);
}

TEST(RESIZING_VECTOR, SHRINK_TO_FIT) {
	vector<int> tab(3);

	tab.shrink_to_fit();
	EXPECT_EQ(tab.capacity(), tab.size());

	tab.resize(50);
	tab.shrink_to_fit();
	EXPECT_EQ(tab.capacity(), tab.size());

	tab.reserve(70);
	tab.shrink_to_fit();
	EXPECT_EQ(tab.capacity(), tab.size());

	tab.push_back(70);
	tab.shrink_to_fit();
	EXPECT_EQ(tab.capacity(), tab.size());

	tab.pop_back();
	tab.shrink_to_fit();
	EXPECT_EQ(tab.capacity(), tab.size());
}