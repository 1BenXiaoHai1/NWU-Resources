/*
 * ex6_14.cpp
 *
 * 14. ��Ʋ�ʵ��һ���˿�����Card����ʾһ��ֽ�ƣ�Ҫ��
 ��1���������ʾһ��ֽ�ƣ�52�ţ�ÿ�����е����ͻ�ɫ�������5������K��
 ��2��֧��ϴ�Ʋ���shuffle()��
 ��3��֧�ֳ�ȡһ���ƵĲ���pick()��
 ��д���Գ��򣬴���һ��ֽ�ƣ�ϴ�ƣ�ģ��������Ҹ���ȡ3�ţ���ʾ˫��3���ƵĻ�ɫ�͵������������ܵ�����С�ж���Ӯ��
 *
 *
 */
#include <string>
#include <vector>
#include <iostream>
#include <random>
using namespace std;

class Card{
public:
	Card();
	void shuffle();
	int pick(int pos);
	static string getPoint(int c);
	static string getSuit(int c);
	static int getScore(int c);
private:
	vector<int> cards;
	const static vector<string> suits;
	const static vector<string> points;
	const static vector<int> scores;

};
const vector<string> Card::suits{"Spade", "Heart", "Diamond", "Club"};
const vector<string> Card::points{"A", "2", "3", "4", "5", "6",
	"7", "8", "9", "10", "J", "Q", "K"};
const vector<int> Card::scores{11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};


Card::Card() {
	for(int i = 0; i < 52; ++i)
		cards.push_back(i);
}

void Card::shuffle() {
	default_random_engine e;
	uniform_int_distribution<unsigned> u(0, 51);
	for(int i = 0; i < 52; ++i){
		int j = u(e);
		int t = cards[i];
		cards[i] = cards[j];
		cards[j] = t;
	}
}

int Card::pick(int pos) {
	return cards[pos - 1];
}

string Card::getPoint(int c) {
	return points[c % 13];
}

string Card::getSuit(int c) {
	return suits[c / 13];
}

int Card::getScore(int c) {
	return scores[c % 13];
}

int main()
{
	Card deck;
	vector<int> player1(3), player2(3);
	deck.shuffle();

	player1[0] = deck.pick(1);
	player2[0] = deck.pick(2);
	player1[1] = deck.pick(3);
	player2[1] = deck.pick(4);
	player1[2] = deck.pick(5);
	player2[2] = deck.pick(6);

	int count1 = 0, count2 = 0;
	cout << "Player 1 got: " << endl;
	for(auto e : player1){
		cout << deck.getSuit(e) << " " << deck.getPoint(e) << endl;
		count1 += deck.getScore(e);
	}
	cout << "total points: " << count1 << endl;

	cout << "\nPlayer 2 got: " << endl;
	for(auto e : player2){
		cout << deck.getSuit(e) << " " << deck.getPoint(e) << endl;
		count2 += deck.getScore(e);
	}
	cout << "total points: " << count2 << endl;

	if(count1 > count2)
		cout << "\nPlayer 1 wins!" << endl;
	else if(count1 < count2)
		cout << "\nPlayer 2 wins!" << endl;
	else
		cout << "\nDraw!" << endl;



	return 0;
}
