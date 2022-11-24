#include "Administrator.h"

string Administrator::getCorrectExistingLogin(std::istream& s, const char* message, Repository r)
{
	string adminInput;
	while (true)
	{
		try
		{
			std::cout << message;
			getline(std::cin, adminInput);

			int role = stoi(login.substr(0, 2));
			if (adminInput.length() != 16 ||
				role != 2 && role != 3)
			{
				throw -1;
			}
			if (role == 1) throw false;

			bool inVector = false;
			if (role == 2)
			{
				for (Doctor doctor : r.vectorOfAllDoctors)
				{
					if (adminInput == doctor.getLogin())
					{
						inVector = true;
						break;
					}
				}
			}
			else
			{
				for (Patient patient : r.vectorOfAllPatients)
				{
					if (adminInput == patient.getLogin())
					{
						inVector = true;
						break;
					}
				}
			}
			
			if (!inVector)
			{
				throw inVector;
			}
			return adminInput;
		}
		catch (bool)
		{
			std::cin.clear();
			std::cout << "��������� ������ �����������! ������������ � ����� �������" <<
				"�� ��������������� � �������.\n ��������� ����.\n\n";
		}
		catch (std::invalid_argument)
		{
			std::cin.clear();
			std::cout << "��������� ������ �����������! ������ �������� �����.\n" <<
				"��������� ����.\n\n";
		}
		catch (int)
		{
			std::cin.clear();
			std::cout << "��������� ������ �����������! ������ �������� �����.\n" <<
				"��������� ����.\n\n";
		}
	}
}

Administrator::Administrator()
{
	login = "0107112022134542";
	encryptedPassword = "Qi1Yld";
	access = true;
}

Administrator::~Administrator()
{

}

void Administrator::logInSystem()
{
	while (true)
	{
		std::cout << "\n��� �� ������ �������? �������� ��������������� �����.\n"
			"1 - ������ � �������� ������;\n"
			"2 - ������ � ����������;\n"
			"3 - �����.\n\n";

		int choice = getCorrectMenuInput(3);
		switch (choice)
		{
		case 1:
			
			break;
		case 2: 

			break;
		case 3: 
			return;
		}
		endCase();
	}
}



void Administrator::workWithAccounts()
{
	while (true)
	{
		std::cout << "\n��� �� ������ �������? �������� ��������������� �����.\n"
			"1 - ����������� ���������� ��� ���� ������;\n"
			"2 - ����������� ���������� ��� ���� ���������;\n"
			"3 - ����������� ���������� ��� ���� ������������������ ���������;\n"
			"4 - �������������� �������;\n"
			"5 - �������������� �������;\n"
			"6 - ����� ������� �� ������;\n"
			"7 - �����.\n\n";

		int choice = getCorrectMenuInput(7);
		switch (choice)
		{
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

		case 5:

			break;
		case 6:

			break;
		case 7:
			return;
		}
		endCase();
	}
}

void Administrator::workWithServices()
{
	while (true)
	{
		std::cout << "\n��� �� ������ �������? �������� ��������������� �����.\n"
			"1 - ����������� ���������� ��� ���� �������;\n"
			"2 - �������� ����� ������;\n"
			"3 - ������� ������;\n"
			"4 - ������������� ������ �� ������;\n"
			"5 - ������ ���� �� �������� ������;\n"
			"6 - �����.\n\n";

		int choice = getCorrectMenuInput(3);
		switch (choice)
		{
		case 1:

			break;
		case 2:

			break;
		case 3:
			return;
		}
		endCase();
	}
}









