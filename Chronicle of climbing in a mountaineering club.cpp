#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Масиви з можливими значеннями
const string surnames[] = { "Iванов", "Петров", "Сидоров", "Кузнєцов", "Смирнов", "Попов", "Новiков", "Морозов", "Федоров", "Михайлов" };
const string names[] = { "Iван", "Петро", "Сергiй", "Михайло", "Олексiй", "Дмитро", "Андрiй", "Микола", "Володимир", "Олег" };
const string middle_names[] = { "Iванович", "Петрович", "Сергiйович", "Михайлович", "Олексiйович", "Дмитрович", "Андрiйович", "Миколайович", "Володимирович","Олегович" };
const string streets[] = { "Садова", "Шевченка", "Миру", "Шкiльна", "Молодiжна", "Гагарiна", "Лiсова", "1 Травня", "Котляревського", "Франка" };
const string cities[] = { "Чернiгiв", "Київ", "Харкiв", "Черкаси", "Вротцлав", "Львiв", "Чернобль", "Слобода", "Кременчуг", "Днепр" };
const string countrys[] = { "Ukraine", "Poland", "China", "Japan", "USA" };

// Функцiя для вибору випадкового елемента з масиву
string random_item(const string arr[], int size) {
	int random_index = rand() % size;
	return arr[random_index];
}

// Функцiя для генерацiї випадкової адреси
string generate_address() {
	string address = random_item(streets, 10) + ", " + to_string(rand() % 100) + ", " + random_item(cities, 10);
	return address;
}

// Функцiя для генерацiї випадкового телефонного номера
string generate_phone() {
	string phone = "+38 (0";
	phone += to_string(60 + rand() % (99-60));
	phone += ") ";
	phone += to_string(100 + rand() % 900);
	phone += "-";
	phone += to_string(10 + rand() % 90);
	phone += "-";
	phone += to_string(10 + rand() % 90);
	return phone;
}


//Клас дати для зручностi позначення дати
class Date {
public:
	Date() : day_(1 + rand() % 30), month_(1 + rand() % 11), year_(1990 + rand() % 25) {}
	Date(int day, int month, int year) : day_(day), month_(month), year_(year) {}
	~Date() {}

	int getDay() const { return day_; }
	void setDay(int day) { day_ = day; }
	int getMonth() const { return month_; }
	void setMonth(int month) { month_ = month; }
	int getYear() const { return year_; }
	void setYear(int year) { year_ = year_; }

	string getPrint() const { return to_string(day_) + "." + to_string(month_) + "." + to_string(year_); }
	int getFullDate() const { return (year_ * 10000) + (month_ * 100) + (day_); }

private:
	int day_;
	int month_;
	int year_;
};

//Клас вершини
class Peak {
public:
	// Конструктор за замовчуванням
	Peak() {}

	// Конструктор з параметрами
	Peak(int code, string name, string country, string region, int height) {
		code_ = code;
		name_ = name;
		country_ = country;
		region_ = region;
		height_ = height;
	}

	// Геттери i сеттери
	int getCode() const { return code_; }
	void setCode(int code) { code_ = code; }

	string getName() const { return name_; }
	void setName(string name) { name_ = name; }

	string getCountry() const { return country_; }
	void setCountry(string country) { country_ = country; }

	string getRegion() const { return region_; }
	void setRegion(string region) { region_ = region; }

	int getHeight() const { return height_; }
	void setHeight(int height) { height_ = height; }

private:
	int code_;
	string name_;
	string country_;
	string region_;
	int height_;
};

// Клас альпiнiста
class Climber {
public:
	// Конструктор за замовчуванням
	Climber() : code_(0), lastName_(""), firstName_(""), middleName_(""), address_(""), phoneNumber_("") {}

	// Конструктор з параметрами
	Climber(int code, const string& lastName, const string& firstName, const string& middleName, const string& address, const string& phoneNumber)
		: code_(code), lastName_(lastName), firstName_(firstName), middleName_(middleName), address_(address), phoneNumber_(phoneNumber) {}

	// Геттери i сеттери
	int getCode() const { return code_; }
	void setCode(int code) { code_ = code; }

	const string& getLastName() const { return lastName_; }
	void setLastName(const string& lastName) { lastName_ = lastName; }

	const string& getFirstName() const { return firstName_; }
	void setFirstName(const string& firstName) { firstName_ = firstName; }

	const string& getMiddleName() const { return middleName_; }
	void setMiddleName(const string& middleName) { middleName_ = middleName; }

	const string& getAddress() const { return address_; }
	void setAddress(const string& address) { address_ = address; }

	const string& getPhoneNumber() const { return phoneNumber_; }
	void setPhoneNumber(const string& phoneNumber) { phoneNumber_ = phoneNumber; }

private:
	int code_;
	string lastName_;
	string firstName_;
	string middleName_;
	string address_;
	string phoneNumber_;
};


class Climbing {
public:
	Climbing() : vertexCode_(0), climberCode_(0) {}
	Climbing(int vertexCode, int climberCode, const Date& startDate, const Date& endDate) : vertexCode_(vertexCode), climberCode_(climberCode), startDate_(startDate), endDate_(endDate) {}
	~Climbing() {}

	int getVertexCode() const { return vertexCode_; }
	void setVertexCode(int vertexCode) { vertexCode_ = vertexCode; }

	int getClimberCode() const { return climberCode_; }
	void setClimberCode(int climberCode) { climberCode_ = climberCode; }

	const Date& getStartDate() const { return startDate_; }
	void setStartDate(const Date& startDate) { startDate_ = startDate; }

	const Date& getEndDate() const { return endDate_; }
	void setEndDate(const Date& endDate) { endDate_ = endDate; }

	void checkDate() {
		if (startDate_.getFullDate() > endDate_.getFullDate()) {
			Date n = startDate_;
			startDate_ = endDate_;
			endDate_ = n;
		}
	}

private:
	int vertexCode_;
	int climberCode_;
	Date startDate_;
	Date endDate_;
};

int check(int OldNum, int NewNum) {
	if (NewNum == 0 || NewNum == -1)
	{
		return OldNum;
	}
	else return NewNum;
}


string check(string OldText, string NewText) {
	if (NewText == "." || NewText == ",")
	{
		return OldText;
	}
	else return NewText;
}

void print_climbers(vector<Climber> climbers) {
	// Альпiнiсти
	//Заголовок
	cout << endl << setfill(' ') << setw(60) << "Альпiнiсти" << setfill(' ') << endl;
	cout << setfill('-') << setw(106) << "-" << setfill(' ') << endl;
	cout << setw(6) << right << "Code" << setw(15) << right << "Last Name" << setw(15) << right << "First Name" << setw(15) << right << "Middle Name" << setw(30) << right << "Address" << setw(25) << right << "Phone Number" << endl;
	cout << setfill('-') << setw(106) << "-" << setfill(' ') << endl;

	// Даннi
	for (int i = 0; i < climbers.size(); i++) {
		cout << setw(6) << right << climbers[i].getCode()
			<< setw(15) << right << climbers[i].getLastName()
			<< setw(15) << right << climbers[i].getFirstName()
			<< setw(15) << right << climbers[i].getMiddleName()
			<< setw(30) << right << climbers[i].getAddress()
			<< setw(25) << right << climbers[i].getPhoneNumber()
			<< endl;
	}
	cout << endl;
}

void print_peaks(vector<Peak> peaks) {
	// Вершини
	//Заголовок
	cout << endl << setfill(' ') << setw(50) << "Вершини" << setfill(' ') << endl;
	cout << setfill('-') << setw(91) << "-" << setfill(' ') << endl;
	cout << setw(6) << right << "Code" << setw(30) << right << "Name" << setw(20) << right << "Country" << setw(20) << right << "Region" << setw(15) << right << "Height" << endl;
	cout << setfill('-') << setw(91) << "-" << setfill(' ') << endl;

	// Даннi
	for (int i = 0; i < peaks.size(); i++) {
		cout << setw(6) << right << peaks[i].getCode()
			<< setw(30) << right << peaks[i].getName()
			<< setw(20) << right << peaks[i].getCountry()
			<< setw(20) << right << peaks[i].getRegion()
			<< setw(15) << right << peaks[i].getHeight()
			<< endl;
	}
	cout << endl;
}

void print_climbs(vector<Climbing> climbs) {
	// Сходження
	//Заголовок
	cout << endl << setfill(' ') << setw(40) << "Сходження" << setfill(' ') << endl;
	cout << setfill('-') << setw(70) << "-" << setfill(' ') << endl;
	cout << setw(15) << right << "PeaksCode" << setw(15) << right << "ClimberCode" << setw(20) << right << "Start" << setw(20) << right << "End" << endl;
	cout << setfill('-') << setw(70) << "-" << setfill(' ') << endl;

	// Даннi
	for (int i = 0; i < climbs.size(); i++) {
		cout << setw(15) << right << climbs[i].getVertexCode()
			<< setw(15) << right << climbs[i].getClimberCode()
			<< setw(20) << right << climbs[i].getStartDate().getPrint()
			<< setw(20) << right << climbs[i].getEndDate().getPrint()
			<< endl;
	}
	cout << endl;
}

void print(vector<Climber> climbers, vector<Peak> peaks, vector<Climbing> climbs) {
	int menu;
	while (true)
	{
		system("cls");
		cout << "1. Друк альпiнiста\n"
			<< "2. Друк вершин\n"
			<< "3. Друк сходження\n"
			<< "4. Друк усiх\n"
			<< "0. До головного меню\n"
			<< " >>> ";
		cin >> menu;
		switch (menu)
		{
		case 0:
			return;
		case 1:
			//Альпiнiсти
			print_climbers(climbers);
			break;
		case 2:
			//Вершини 
			print_peaks(peaks);
			break;
		case 3:
			//Заходи
			print_climbs(climbs);
			break;
		case 4:
			//Альпiнiсти
			print_climbers(climbers);
			//Вершини 
			print_peaks(peaks);
			//Заходи
			print_climbs(climbs);
			break;
		default:
			cout << "Oops... Error 404! Page not found!\n";
			break;
		}
		system("pause");
	}
}

void menu_peaks(vector<Peak>& peaks) {
	int menu, pos, Height;
	//назва, країна, район, висота гори
	string Name, Country, Region;


	while (true)
	{
		system("cls");
		cout << " --- Вершини ---\n"
			<< "1. Друк\n"
			<< "2. Додати вершину\n"
			<< "3. Редагувати вершину\n"
			<< "4. Видалити вершину\n"
			<< "5. RandomData вершина\n"
			<< "0. Вихiд\n"
			<< " >>> ";
		cin >> menu;
		switch (menu)
		{
		case 0:
			return;
		case 1:
			print_peaks(peaks);
			break;
		case 2:
			cout << "Name: ";
			cin >> Name;
			cout << "Country: ";
			cin >> Country;
			cout << "Region: ";
			cin >> Region;
			cout << "Height: ";
			cin >> Height;
			peaks.push_back(Peak(peaks.size() + 1, Name, Country, Region, Height));
			break;
		case 3:
			print_peaks(peaks);
			cout << "Code: ";
			cin >> pos;
			if (pos > peaks.size())
			{
				cout << "!!! ERROR 404 !!!\nВведенi неправильнi даннi" << endl;
				break;
			}
			cout << "Name old=(" + peaks[pos - 1].getName() + "), new(. = no edit): ";
			cin >> Name;
			peaks[pos - 1].setName(check(peaks[pos - 1].getName(), Name));

			cout << "Country old=(" + peaks[pos - 1].getCountry() + "), new(. = no edit): ";
			cin >> Country;
			peaks[pos - 1].setCountry(check(peaks[pos - 1].getCountry(), Country));

			cout << "Region old=(" + peaks[pos - 1].getRegion() + "), new(. = no edit): ";
			cin >> Region;
			peaks[pos - 1].setRegion(check(peaks[pos - 1].getRegion(), Region));

			cout << "Height old=(" + to_string(peaks[pos - 1].getHeight()) + "), new(0 = no edit): ";
			cin >> Height;
			peaks[pos - 1].setHeight(check(peaks[pos - 1].getHeight(), Height));


			print_peaks(peaks);
			break;
		case 4:
			print_peaks(peaks);
			cout << "Code: ";
			cin >> pos;
			if (pos > peaks.size())
			{
				cout << "!!! ERROR 404 !!!\nВведенi неправильнi даннi" << endl;
				break;
			}
			peaks.erase(peaks.begin() + pos - 1);

			print_peaks(peaks);
			break;
		case 5:
			srand(time(NULL));
			peaks.push_back(Peak(peaks.size() + 1, random_item(surnames, 10), random_item(countrys, 5), random_item(streets, 10), 500 + (rand() % 3000)));
			print_peaks(peaks);
			break;
		default:
			cout << "Oops... Error 404! Page not found!\n";
			break;
		}
		system("pause");
	}
}

void menu_climbs(vector<Climber>& climbers, vector<Peak>& peaks, vector<Climbing>& climbs) {
	int menu, pos, climberCode, peaksCode, DayStart, DayEnd, MounthStart, MounthEnd, YearStart, YearEnd;

	while (true)
	{
		system("cls");
		cout << " --- Сходження ---\n"
			<< "1. Друк\n"
			<< "2. Додати сходження\n"
			<< "3. Редагувати сходження\n"
			<< "4. Видалити сходження\n"
			<< "5. RandomData сходження\n"
			<< "0. Вихiд\n"
			<< " >>> ";
		cin >> menu;
		switch (menu)
		{
		case 0:
			return;
		case 1:
			print_climbs(climbs);
			break;
		case 2:
			cout << "Код вершини: ";
			cin >> peaksCode;
			cout << "Код альпiнiста: ";
			cin >> climberCode;
			cout << "Дата початку: День: \n";
			cin >> DayStart;
			cout << "Мiсяць: ";
			cin >> MounthStart;
			cout << "Рiк: ";
			cin >> YearStart;
			cout << "Дата закiнчення: День: \n";
			cin >> DayEnd;
			cout << "Мiсяць: ";
			cin >> MounthEnd;
			cout << "Рiк: ";
			cin >> YearEnd;
			climbs.push_back(Climbing(peaksCode, climberCode, Date(DayStart, MounthStart, YearStart), Date(DayEnd, MounthEnd, YearEnd)));
			climbs[climbs.size() - 1].checkDate();
			break;
		case 3:
			print_climbs(climbs);
			cout << "Code: ";
			cin >> pos;
			if (pos > climbs.size())
			{
				cout << "!!! ERROR 404 !!!\nВведенi неправильнi даннi" << endl;
				break;
			}
			cout << "Код вершини old=(" + to_string(climbs[pos - 1].getVertexCode()) + "), new(0 = no edit): ";
			cin >> peaksCode;
			climbs[pos - 1].setVertexCode(check(climbs[pos - 1].getVertexCode(), peaksCode));

			cout << "Код альпiнiста old=(" + to_string(climbs[pos - 1].getClimberCode()) + "), new(0 = no edit): ";
			cin >> climberCode;
			climbs[pos - 1].setClimberCode(check(climbs[pos - 1].getClimberCode(), climberCode));

			cout << "Початок old=(" + climbs[pos - 1].getStartDate().getPrint() + "), new(0 = no edit): ";
			cout << "День: \n";
			cin >> DayStart;
			cout << "Мiсяць: ";
			cin >> MounthStart;
			cout << "Рiк: ";
			cin >> YearStart;
			climbs[pos - 1].setStartDate(Date(check(climbs[pos - 1].getStartDate().getDay(), DayStart), check(climbs[pos - 1].getStartDate().getMonth(), MounthStart), check(climbs[pos - 1].getStartDate().getYear(), YearStart)));

			cout << "Кiнець old=(" + climbs[pos - 1].getEndDate().getPrint() + "), new(0 = no edit): ";
			cout << "День: \n";
			cin >> DayStart;
			cout << "Мiсяць: ";
			cin >> MounthStart;
			cout << "Рiк: ";
			cin >> YearStart;
			climbs[pos - 1].setEndDate(Date(check(climbs[pos - 1].getStartDate().getDay(), DayStart), check(climbs[pos - 1].getStartDate().getMonth(), MounthStart), check(climbs[pos - 1].getStartDate().getYear(), YearStart)));
			climbs[climbs.size() - 1].checkDate();
			print_climbs(climbs);
			break;
		case 4:

			print_climbs(climbs);
			cout << "Code: ";
			cin >> pos;
			if (pos > climbs.size())
			{
				cout << "!!! ERROR 404 !!!\nВведенi неправильнi даннi" << endl;
				break;
			}
			climbs.erase(climbs.begin() + pos - 1);
			print_climbs(climbs);
			break;
		case 5:
			srand(time(NULL));
			climbs.push_back(Climbing(1 + (rand() % peaks.size()), 1 + (rand() % climbers.size()), Date(), Date()));
			climbs[climbs.size() - 1].checkDate();
			print_climbs(climbs);
			break;
		default:
			cout << "Oops... Error 404! Page not found!\n";
			break;
		}
		system("pause");
	}
}

void menu_climbers(vector<Climber>& climbers) {
	int menu, pos;
	string LName, FName, MName, Addr, Phone;

	while (true)
	{
		system("cls");
		cout << " --- Альпiнiсти ---\n"
			<< "1. Друк\n"
			<< "2. Додати альпiнiста\n"
			<< "3. Редагувати альпiнiста\n"
			<< "4. Видалити альпiнiста\n"
			<< "5. RandomData альпiнiст\n"
			<< "0. Вихiд\n"
			<< " >>> ";
		cin >> menu;
		switch (menu)
		{
		case 0:
			return;
		case 1:
			print_climbers(climbers);
			break;
		case 2:
			cout << "Last Name: ";
			cin >> LName;
			cout << "First Name: ";
			cin >> FName;
			cout << "Middle Name: ";
			cin >> MName;
			cout << "Addres: ";
			cin >> Addr;
			cout << "Phone: ";
			cin >> Phone;
			climbers.push_back(Climber(climbers.size() + 1, LName, FName, MName, Addr, Phone));
			break;
		case 3:
			print_climbers(climbers);
			cout << "Code: ";
			cin >> pos;
			if (pos > climbers.size())
			{
				cout << "!!! ERROR 404 !!!\nВведенi неправильнi даннi" << endl;
				break;
			}
			cout << "Last Name old=(" + climbers[pos - 1].getLastName() + "), new(. = no edit): ";
			cin >> LName;
			climbers[pos - 1].setLastName(check(climbers[pos - 1].getLastName(), LName));

			cout << "First Name old=(" + climbers[pos - 1].getFirstName() + "), new(. = no edit): ";
			cin >> FName;
			climbers[pos - 1].setFirstName(check(climbers[pos - 1].getFirstName(), FName));

			cout << "Middle Name old=(" + climbers[pos - 1].getMiddleName() + "), new(. = no edit): ";
			cin >> MName;
			climbers[pos - 1].setMiddleName(check(climbers[pos - 1].getMiddleName(), MName));

			cout << "Addres old=(" + climbers[pos - 1].getAddress() + "), new(. = no edit): ";
			cin >> Addr;
			climbers[pos - 1].setAddress(check(climbers[pos - 1].getAddress(), Addr));

			cout << "Phone old=(" + climbers[pos - 1].getPhoneNumber() + "), new(. = no edit): ";
			cin >> Phone;
			climbers[pos - 1].setPhoneNumber(check(climbers[pos - 1].getPhoneNumber(), Phone));

			print_climbers(climbers);
			break;
		case 4:
			print_climbers(climbers);
			cout << "Code: ";
			cin >> pos;
			if (pos > climbers.size())
			{
				cout << "!!! ERROR 404 !!!\nВведенi неправильнi даннi" << endl;
				break;
			}
			climbers.erase(climbers.begin() + pos - 1);

			print_climbers(climbers);
			break;
		case 5:
			srand(time(NULL));
			climbers.push_back(Climber(climbers.size() + 1, random_item(surnames, 10), random_item(names, 10), random_item(middle_names, 10), generate_address(), generate_phone()));
			print_climbers(climbers);
			break;
		default:
			cout << "Oops... Error 404! Page not found!\n";
			break;
		}
		system("pause");
	}
}

bool comp_Peak(Peak i, Peak j) {
	return i.getHeight() > j.getHeight();
}

bool comp_Climber(Climber i, Climber j) {
	return i.getFirstName() < j.getFirstName();
}

bool comp_peaks(Peak i, Peak j) {
	return i.getCode() < j.getCode();
}

void BigPeaks(vector<Climber> climbers, vector<Peak> peaks, vector<Climbing> climbs) {
	vector<Climber> top_climbers;
	bool s = false;
	sort(peaks.begin(), peaks.end(), comp_Peak);
	for (int i = 0; i < peaks.size(); i++)
	{
		for (int x = 0; x < climbs.size(); x++)
		{
			if (climbs[x].getVertexCode() == peaks[i].getCode()) {
				for (int y = 0; y < climbers.size(); y++)
				{
					if (climbs[x].getClimberCode() == climbers[y].getCode()) {
						top_climbers.push_back(climbers[y]);
						bool s = true;
					}

				}

			}
		}
		if (!s) break;
	}
	sort(top_climbers.begin(), top_climbers.end(), comp_Climber);
	print_climbers(top_climbers);
}

void long_time_peak(vector<Peak> peaks, vector<Climbing> climbs) {
	vector<Climbing> top_climb;
	int long_time_climbs = 0;
	for (int i = 0; i < climbs.size(); i++)
	{
		if (long_time_climbs < (climbs[i].getEndDate().getFullDate() - climbs[i].getStartDate().getFullDate())) long_time_climbs = i;

	}
	top_climb.push_back(climbs[long_time_climbs]);
	vector<Peak> top_peak;
	for (int i = 0; i < peaks.size(); i++)
	{
		if (peaks[i].getCode() == top_climb[0].getVertexCode())
		{
			top_peak.push_back(peaks[i]);
			break;
		}
	}
	print_peaks(top_peak);
	print_climbs(top_climb);
}

void more_climbs(vector<Climber> climbers, vector<Climbing> climbs) {
	int max = 0, max_pos = 0, temp;
	vector<Climbing> max_climbs;


	for (int i = 0; i < climbers.size(); i++)
	{
		temp = 0;
		for (int x = 0; x < climbs.size(); x++)
		{
			if (climbers[i].getCode() == climbs[x].getClimberCode()) temp++;
		}
		if (max < temp)
		{
			max = temp;
			max_pos = i;
		}
	}

	for (int i = 0; i < climbs.size(); i++)
	{
		if (climbs[i].getClimberCode() == max_pos + 1) {
			max_climbs.push_back(climbs[i]);
		}
	}

	vector<Climber> climber = { climbers[max_pos] };

	print_climbs(max_climbs);
	print_climbers(climber);
}

void position_peaks(vector<Peak> peaks, vector<Climbing> climbs) {
	set<string> position;

	for (int i = 0; i < peaks.size(); i++)
	{
		position.insert(peaks[i].getRegion());
	}
	cout << "Виберiть мiсце: \n";
	int i = 1, pos;
	for (auto& pos : position)
	{
		cout << i << ". " << pos << endl;
		i++;
	}
	cout << " >>> ";
	cin >> pos;

	vector<Peak> news;
	i = 0;
	for (auto& posit : position)
	{
		if ((pos - 1) == i)
		{
			for (int x = 0; x < peaks.size(); x++)
			{
				if (peaks[x].getRegion() == posit)
				{
					news.push_back(peaks[x]);
				}
			}
			break;
		}
		i++;
	}

	//sort(news.begin(), news.end(), comp_peaks);
	print_peaks(news);

}

void menu(vector<Climber>& climbers, vector<Peak>& peaks, vector<Climbing>& climbs) {
	int menu;
	while (true)
	{
		system("cls");
		cout << " --- MENU ---\n"
			<< "1. Друк таблиць\n"
			<< "2. Меню альпiнiста\n"
			<< "3. Меню вершин\n"
			<< "4. Меню сходження\n"
			<< "5. Альпiнiст який пiдкорив найвищу вершину\n"
			<< "6. Вершина з найтривалiшим часом\n"
			<< "7. Найбiльша кiлькiсть сходжень\n"
			<< "8. Вершини, розташованi в певному мiсцi\n"
			<< "9. Test add data (+3)\n"
			<< "0. Вихiд\n"
			<< " >>> ";
		cin >> menu;
		switch (menu)
		{
		case 0:
			return;
		case 1:
			print(climbers, peaks, climbs);
			break;
		case 2:
			menu_climbers(climbers);
			break;
		case 3:
			menu_peaks(peaks);
			break;
		case 4:
			menu_climbs(climbers, peaks, climbs);
			break;
		case 5:
			BigPeaks(climbers, peaks, climbs);
			break;
		case 6:
			long_time_peak(peaks, climbs);
			break;
		case 7:
			more_climbs(climbers, climbs);
			break;
		case 8:
			position_peaks(peaks, climbs);
			break;
		case 9:
			for (int i = 0; i < 3; i++)
			{
				climbers.push_back(Climber(climbers.size() + 1, random_item(surnames, 10), random_item(names, 10), random_item(middle_names, 10), generate_address(), generate_phone()));
				peaks.push_back(Peak(peaks.size() + 1, random_item(surnames, 10), random_item(countrys, 5), random_item(streets, 10), 500 + (rand() % 3000)));
				climbs.push_back(Climbing(1 + (rand() % peaks.size()), 1 + (rand() % climbers.size()), Date(), Date()));
				climbs[climbs.size() - 1].checkDate();
			}
			break;
		default:
			cout << "Oops... Error 404! Page not found!\n";
			break;
		}

		system("pause");
	}

}


int main()
{
	setlocale(LC_ALL, "ukr");
	system("title Chronicle of climbing in a mountaineering club");
	vector<Climber> climbers = {
		//{1, "Iванов", "Iван", "Iванович", "вул. Пушкiна, д. 10", "+38 (068) 123-45-67"},
		//{2, "Петров", "Петро", "Петрович", "вул. Лермонтова, д. 20", "+38 (097) 234-56-78"},
		//{3, "Сидоров", "Сидор", "Сидорович", "вул. Толстого, д. 30", "+38 (095) 345-67-89"}
	};
	vector<Peak> peaks = {
		//int code, string name, string country, string region, int height
		//{1, "Пушкiна", "Ukraine", "Karpati", 155},
		//{2, "Лермонтова", "Ukraine", "Сидорович", 100},
		//{3, "ПуТолстого", "Ukraine", "Петрович", 200}
	};
	vector<Climbing> climbs = {
		//{1, 1, Date(), Date()},
		//{2, 1, Date(15,4,2023), Date(15,5,2023)}
	};
	menu(climbers, peaks, climbs);
	return 0;
}
