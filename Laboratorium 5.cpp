#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stdexcept>
#include <cstdlib>

using std::out_of_range;
using std::get;
using std::swap;
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::array;
using std::vector;

/*
int* temp; //Tablica pomocnicza potrzebna przy scalaniu

void scalanie(int array[], int lewo, int srodek, int prawo)
{
	int i = lewo, j = srodek + 1;
	for (int i = lewo; i <= prawo; i++) // Kopiujemy lewą i prawą częśćtablicy do tablicy pomocniczej
	{
		temp[i] = array[i];
	}
	for (int n = lewo; n <= prawo; n++) //Scalenie dwóch podtablic pomocniczych i zapisanie ich we właściwej tablicy
	{
		if (i <= srodek)
			if (j <= prawo)
				if (temp[j] < temp[i])
					array[n] = temp[j++];
				else
					array[n] = temp[i++];
			else
				array[n] = temp[i++];
		else
			array[n] = temp[j++];
	}
}
void scalanieSortowanie(int arr[], int lewo, int prawo)
{
	if (prawo <= lewo) return;
	int srodek = (prawo + lewo) / 2; // Znajdujemy środek podtablicy
	scalanieSortowanie(arr, lewo, srodek);//Dzielimy tablice na część lewą i prawą
	scalanieSortowanie(arr, srodek + 1, prawo);
	scalanie(arr, lewo, srodek, prawo); // Scalamy dwie już posortowane tablice
}
*/
void szybkieSortowanie(int* array, int lewo, int prawo)
{
	if(prawo <= lewo) return;

	int i = lewo - 1, j = prawo + 1;
	int axis = array[(lewo + prawo) / 2]; //Wybieramy punkt odniesienia (axis-oś)
	while(1)
	{
		while (axis > array[++i]); // Szukam elementu wiekszego lub rownego axis stojacego po prawej stronie wartosci axis
		while (axis < array[--j]); // Szukam elementu mniejszego lub rownego axis stojacego po lewej stronie wartosci axis
		if (i <= j) // Jeśli liczniki się nie minęły to zamień elementy ze sobą stojace po niewłaściwej stronie elementu axis
			swap(array[i], array[j]); //Funkcja swap zamienia wartości array[i] z array[j]
		else
			break;
	}
	if (j > lewo)
		szybkieSortowanie(array, lewo, j);
	if (j < prawo)
		szybkieSortowanie(array, i, prawo);
}
void kolejnaTablica()
{
	cout << endl;
}
void rysowanieTablicy(array<int, 5>& arr)
{
	//Drukowanie tablicy
	for (auto& elem : arr)
	{
		cout << elem << " , ";
	}
}

int main()
{
	//Wypisywanie elementów tablicy array
	/*
	//Niezainicjowany obiekt tablicy zawiera elementy - śmieciowe wartości
	array<int, 5> arr1;
	rysowanieTablicy(arr1);

	kolejnaTablica();

	//Zainicjowana tablica
	array<int, 5> arr2 = { 1,2,3,4,5 };
	rysowanieTablicy(arr2);

	kolejnaTablica();

	//Pierwsze dwie wartości będą zainicjalizowane, a reszta będzie 0
	array<int, 5> arr3 = { 21,56 };
	rysowanieTablicy(arr3);

	kolejnaTablica();

	//Uzupełnianie tablicy tą samą wartością
	array<int, 5>arr4;
	arr4.fill(4);
	rysowanieTablicy(arr4);
	*/

	/*
	//3 Sposoby uzyskiwania dostępu do elementów tablic array<>

	//Tworzenie i inicjowanie tablicy o rozmiarze 10.
	array<int, 10> arr = { 1,2,3,4,5,6,7,8,9,10 };

	//Operator [] pozwalający na pobranie dowolnego elementu tablicy

	int n = arr[4];
	cout << "n = " << n;

	kolejnaTablica();

	//Próba uzyskania dostepu do elementu spoza zakresu przy pomocy operatora []

	//int x = arr[25];
	//cout << "x = " << x;		Wyskakuje błąd 

	//Dostęp do elementu za pomocą funkcji at

	int y = arr.at(7);
	cout << "y = " << y;
	//Próba uzyskania dostepu do elementu spoza zakresu przy pomocy funkcji at

	kolejnaTablica();
	
	//try
	//{
	//	y = arr.at(63);
	//}
	//catch (const out_of_range& exp)					Błąd Invalid array<T, N> subscript
	//{
	//	cerr << exp.what() << endl;
	//}

	//Dostęp do elementów za pomocą funkcji get<>().

	int z = get<9>(arr);
	cout << "z = " << z;

	//Próba uzyskania dostępu do elementu spoza zakresu przy użyciu get<>()
	//z = get<12>(arr);			Błąd. Nie pokazuje nic
	*/

	//Pobieranie liczb całkowitych do momentu napotkania wartości 0 i wypisywanie ich w odwroconej kolejnosci
	/*
	vector<int>vec;
	int wartosc;

	cout << "Podaj zmienna" << endl;
	cin >> wartosc;
	while(wartosc!=0) //Program bedzie prosil o wartosci dopoki nie podamy 0
	{
		//dodanie elementu do wektora
		vec.push_back(wartosc);		//push_back dodaje wartosc na koncu wektora
		cout << "Podaj zmienna" << endl;
		cin >> wartosc;
	}

	//pierwszy sposob wypisania liczb w odwroconej kolejnosci

	//for(int i=vec.size()-1;i>=0;i--)
	//{
	//	cout << vec[i] << ' ';
	//}

	//drugi sposob wypisania liczb w odwroconej kolejnosci
	while(!vec.empty())				//dopóki wektor zawiera jakieś elementy (nie jest pusty)
	{
		cout << vec.back() << ' ';	//Wypisanie elementu na koncu wektora (wypisujemy elementy od ostatniego do pierwszego)
		vec.pop_back();				//Usunięcie ostatniego elementu w wektorze(usuwamy ostatni element, czyli w tym przypadku 0)
	}
	*/

	//Program wykorzystujący funkcję Reserve

	/*
	vector<int>::size_type size;

	vector<int> vec1;
	size = vec1.capacity();		//capacity-pojemność
	cout << "Pierwszy rozmiar: " << size << endl;
	cout << "vec1 rosnie" << endl;

	for(int i=0; i<100; i++)
	{
		//Metoda void push_back(const value_type& val) dodaje nowy element na końcu wektora, po jego ostatnim, bieżącym elemencie
		//zawartość val jest kopiowana (lub przenoszona) do nowego elementu
		vec1.push_back(i);
		if(size != vec1.capacity())		//Jeśli rozmiar jest różny od pojemności
		{
			size = vec1.capacity();
			cout << "Zmieniona pojemnosc: " << size << endl;
		}
	}

	cout << endl << endl;

	vector<int> vec2;
	size = vec2.capacity();		
	cout << "Drugi rozmiar: " << size << endl;
	vec2.reserve(100); // Jedyna różnica nad powyższym kodem
	cout << "vec2 rosnie" << endl;

	for (int i = 0; i < 100; i++)
	{
		vec1.push_back(i);
		if (size != vec1.capacity())	
		{
			size = vec2.capacity();
			cout << "Zmieniona pojemnosc: " << size << endl;
		}
	}
	*/

	/*
	//Program wykorzystujący funkcję do losowania liczb pseudolosowych
	cout << "Pierwsza losowa liczba: " << rand() << endl;
	int liczba = rand();
	cout << "Druga losowa liczba: " << liczba << endl;
	liczba = rand();
	cout << "Trzecia losowa liczba: " << liczba << endl;
	*/

	/*
	//Tablica 10 elementów
	int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	// Range-based pętla for do iteracji po tablicy
	cout << "Range-based petla for do iteracji po tablicy: " << endl;
	for (int y : x) { // Dostęp według wartości przy użyciu kopii zadeklarowanej jako określony typ
					   // To rozwiązanie nie jest preferowane
		cout << y << " ";
	}
	cout << endl;

	//Słowo kluczowe auto jest preferowane, pozwala na wnioskowanie jaki typ powinien zostać użyty
	cout << "Preferowanie slowa kluczowego 'auto' w petli for" << endl;
	for (auto y : x) { // Kopia „x”, prawie zawsze niepożądana
		cout << y << " ";
	}
	cout << endl;
	cout << "Wnioskowanie typu przez referencje" << endl;
	for (auto& y : x) { // Wnioskowanie typu przez referencje
		cout << y << " ";
	}
	cout << endl;
	cout << "Wnioskowanie przez stała referencje do typu" << endl;
	for (const auto& y : x) { // Wnioskowanie przez stałą referencję do typu
		cout << y << " ";
	}

	cout << endl << "Koniec testowej tablicy" << endl << endl;


	// Stworzenie wektora złożonego z 10 elementów
	vector<double> v;
	for (int i = 0; i < 10; ++i) {
		v.push_back(i + 0.11223);
	}

	// Range-based pętla for do iteracji po wektorze
	for (const auto& j : v) {
		cout << j << " ";
	}
	cout << endl;
	cout << "Koniec testowego wektora" << endl;
	*/

	/*
	//Program implementujący sortowanie bąbelkowe
	int i, j, tymczasowy, liczba = 0;
	int array[10] = { 15,7,1,6,2,59,123,1586,169,20 };
	cout << "Tablica nieposortowana :" << endl;
	for(int i=0; i<10; i++)
	{
		cout << array[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = i+1; j < 10; j++)
		{
			if(array[j]<array[i])
			{
				tymczasowy = array[i];
				array[i] = array[j];
				array[j] = tymczasowy;
			}
		}
		liczba++;
	}
	cout << "Tablica posortowana: " << endl;
	for (i = 0; i < 10; i++)
	{
		cout << array[i] << "\t";
	}
	cout << endl << endl << "Liczba przebiegow wykonanych w celu posortowania tablicy: " << liczba << endl;
	*/
	/*
	//Program implementujący algorytm sortowania przez scalanie
	int* tab, n;
	cout << "Podaj liczbe elementow tablicy: ";
	cin >> n;
	tab = new int[n];	//Przydzielanie oamięci na tablicę liczb
	temp = new int[n];	//Przydzielanie oamięci na tablicę pomocniczą
	cout << "Wczytaj elementy tablicy: " << endl; //Wczytywanie elementów tablicy
	for (int i = 0; i < n; i++)
	{
		cin >> tab[i];
	}
	scalanieSortowanie(tab, 0, n - 1);	//Sortowanie wczytanej tablicy
	cout << endl << "Posortowana tablica: " << endl; // Wypisanie wyników
	for (int i = 0; i < n; i++)
	{
		cout << tab[i] << " " << endl;
	}
	*/

	//Program implementujący algorytm sortowania szybkiego

	int* arr, c;
	cout << "Liczba liczb do posortowania: ";
	cin >> c;
	cout << endl;
	arr = new int[c]; //Przydzielanie pamięci o wartości c na elementy tablicy
	cout << "wczytaj liczby";
	for (int i = 0; i < c; i++)
		cin >> arr[i];

	szybkieSortowanie(arr, 0, c - 1);

	cout << "Posortowana tablica: ";
	for (int i = 0; i < c; i++)
		cout << arr[i] << " ";

	cin.ignore();
	cin.get();
	return 0;
}