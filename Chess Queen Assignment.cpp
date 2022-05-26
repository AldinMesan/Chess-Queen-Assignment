#include <cmath>
#include <iostream>
#include <vector>
#include <string>

typedef std::vector<std::vector<bool>> Ploca;
// false - ne napadaju, true - napadaju

bool DaLiSeNapadaju(Ploca& a) {
	//bool b; 
	if (a.size() <= 1)
		return false;

	//isti red

	int r(0);
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.at(i).size(); j++)
			if (a.at(i).at(j) == true)
				r++;
		if (r > 1)
			return true;
		else
			r = 0;
	}

	//grbava matrica

	int b(a.at(0).size());
	for (int i = 0; i < a.size(); i++) {
		// std::cout<<"red "<<i<<" clanova"<<a.at(i).size();
		if (a.at(i).size() > b)
			b = a.at(i).size();
	}
	for (int i = 0; i < a.at(0).size(); i++)
		a.at(i).resize(b); // sad više nije 
	//ista kolona
	r = 0;
	for (int i = 0; i < a.at(0).size(); i++) {
		for (int j = 0; j < a.size(); j++)
			if (a.at(j).at(i) == true)
				r++;
		if (r > 1)
			return false;
		else
			r = 0;
	}
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.at(i).size(); j++) {
			if (a.at(i).at(j) == true) {
				//gornja lijeva dijagonala
				if (i > 0 && j > 0) {
					int m = i - 1, n = j - 1;
					while (m >= 0 && n >= 0) {
						if (a.at(m).at(n))
							return true;
						m--;
						n--;
					}
				}
			// donja lijeva dijagonala
				/*if (i < a.size() && j>0) {
					int m = i + 1, n = j - 1;
					//std::cout<<i<<j<<m<<n;
					while (m < a.size() && n >= 0) {
						if (a.at(m).at(n)) return true; 
						m++;
						n--;
					}
				} */
			}
		}
	}
	return false;

}

int main() {

	Ploca a;
	std::cout << "Unesite opis sahovske ploce:" << std::endl;
	std::cout << "(Q za kraljicu, bilo sta drugo za prazno polje, ENTER naprazno za kraj unosa):" << std::endl;
	
	std::vector<bool> red;
	std::vector<std::string> unos; 
	int k = 0;
	std::string s;

	while (1) {
		std::getline(std::cin, s);
		if (s.length() != 0) {
			k++;
			unos.resize(k);
			unos.at(k - 1) = s;
		}
		if (s == "")
			break;
		s = "";
	}
	a.resize(unos.size());
	for (int i = 0; i < unos.size(); i++) {
		for (int j = 0; j < unos.at(i).length(); j++)
			if (unos.at(i).at(j) == 'q' || unos.at(i).at(j) == 'Q')
				a.at(i).push_back(true);
			else
				a.at(i).push_back(false);
	}
	std::cout << std::endl;

	if (DaLiSeNapadaju(a))
		std::cout << "Dame se medjusobno napadaju.";
	else
		std::cout << "Dame se medjusobno ne napadaju.";
	return 0;
}