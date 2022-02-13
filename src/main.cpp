#include <iostream>
#include "date/date.hpp"

int main()
{
	Date urodzinyKasia, urodzinyTomek;

	std::cout << "Podaj date urodzin Kasi: ";
	std::cin >> urodzinyKasia;

	std::cout << "Podaj date urodzin Tomka: ";
	std::cin >> urodzinyTomek;

	std::cout << "Urodziny Tomka: " << urodzinyTomek << ". Urodziny Kasi: " << urodzinyKasia << "." << std::endl;


	if (urodzinyTomek > urodzinyKasia) {
		int roznica = urodzinyTomek - urodzinyKasia;
		
		std::cout << "Tomek jest mlodszy o " << roznica << (roznica == 1 ? " dzien" : " dni") << " od Kasi" << std::endl;
	}

	urodzinyKasia++;
	std::cout << "Dzien po urodzinach Kasi jest: " << urodzinyKasia << std::endl;

	return 0;
}