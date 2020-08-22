#include "pch.h"
#include "../src/vector.h"
#include "../src/vector.cpp"

TEST(CONSTRUCTOR, NO_ARGUMENTS) {
	vector<int> tab;

	EXPECT_EQ(0, tab.size());
	EXPECT_GE(0, tab.capacity());
}

TEST(CONSTRUCTOR, ONE_ARGUMENT) {
	size_t size = 5;
	vector<int> tab(size);

	EXPECT_EQ(size, tab.size());
	EXPECT_GE(size, tab.capacity());

	size_t size2 = 0;
	vector<int> tab2(size2);

	EXPECT_EQ(size2, tab2.size());
	EXPECT_GE(size2, tab2.capacity());
}

TEST(CONSTRUCTOR, TWO_ARGUMENTS) {
	size_t size = 5;
	int filler = 3;
	vector<int> tab(size, filler);

	EXPECT_EQ(size, tab.size());
	EXPECT_GE(size, tab.capacity());

	for (size_t i = 0; i < tab.size(); ++i)
		EXPECT_TRUE(tab[i] == filler);
}

TEST(CONSTRUCTOR, INITIALIZER_LIST) {
	vector<int> tab{};

	EXPECT_EQ(0, tab.size());
	EXPECT_GE(0, tab.capacity());

	vector<int> vec{ 1,2,3 };

	EXPECT_EQ(3, vec.size());
	EXPECT_GE(3, vec.capacity());

	EXPECT_TRUE(vec[0] == 1);
	EXPECT_TRUE(vec[1] == 2);
	EXPECT_TRUE(vec[2] == 3);
}

TEST(CONSTRUCTOR, COPY_CONSTURCTOR)
{
	vector<int> tab{ 3,1,2 };
	vector<int> vec = tab;

	EXPECT_EQ(tab.size(), vec.size());
	for (size_t i = 0; i < tab.size(); ++i)
		vec[i] == tab[i];
}

TEST(CONSTRUCTOR, MOVE_CONSTURCTOR)
{
	vector<int> tab{ 3,1,2 };
	vector<int> temp = tab;
	vector<int> vec = std::move(tab);

	EXPECT_EQ(tab.size(), 0);
	EXPECT_EQ(temp.size(), vec.size());
	for (size_t i = 0; i < tab.size(); ++i)
		vec[i] == temp[i];
}

TEST(CONSTRUCTOR, COPY_CONSTURCTOR_OPERATOR)
{
	vector<int> tab{ 3,1,2 };
	vector<int> vec;
	vec = tab;

	EXPECT_EQ(tab.size(), vec.size());
	for (size_t i = 0; i < tab.size(); ++i)
		vec[i] == tab[i];
}

TEST(CONSTRUCTOR, MOVE_CONSTURCTOR_OPERATOR)
{
	vector<int> tab{ 3,1,2 };
	vector<int> temp = tab;
	vector<int> vec;
	vec = std::move(tab);

	EXPECT_EQ(tab.size(), 0);
	EXPECT_EQ(temp.size(), vec.size());
	for (size_t i = 0; i < tab.size(); ++i)
		vec[i] == temp[i];
}