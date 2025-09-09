/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:19:23 by akuzmin           #+#    #+#             */
/*   Updated: 2025/09/07 13:43:35 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void Contact::fillContact()
{
	std::cout << "Enter First Name: ";
	std::cin >> f_name;
	std::cout << "Enter Last Name: ";
	std::cin >> l_name;
	std::cout << "Enter Nickname: ";
	std::cin >> nickname;
	std::cout << "Enter phone number: ";
	std::cin >> phone_number;
	std::cout << "Enter You Darkest Secret: ";
	std::cin >> secret;
}

void PhoneBook::displayColumn(const std::string &str) const
{
    if (str.length() <= 10)
        std::cout << std::setw(10) << str;
    else
        std::cout << str.substr(0, 9) << '.';
}

void PhoneBook::ADD(void)
{
	int index = contactCounter < 8 ? contactCounter : lastContact;

	contacts[index].fillContact();

	if (contactCounter < 8)
		contactCounter++;
	else
		lastContact = (lastContact + 1) % 8;
}

void PhoneBook::SEARCH()
{
	if (contactCounter == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return ;
	}

	std::cout << std::setw(10) << "Index" << '|';
	std::cout << std::setw(10) << "First Name" << '|';
	std::cout << std::setw(10) << "Last Name" << '|';
	std::cout << std::setw(10) << "Nickname" << '|' << std::endl;

	for (int i = 0; i < contactCounter; i++)
	{
		std::cout << std::setw(10) << i << '|';
		displayColumn(contacts[i].getFirstName());
		std::cout << '|';
		displayColumn(contacts[i].getLastName());
		std::cout << '|';
		displayColumn(contacts[i].getNickname());
		std::cout << '|' << std::endl;
	}
	int index;
	std::cout << "Enter index of contact: ";
	std::cin >> index;

	if (std::cin.fail() || index < 0 || index > contactCounter)
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Invalid index!" << std::endl;
		return ;
	}
	std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getSecret() << std::endl;
}

int main(void)
{
	PhoneBook phoneBook;
	std::string CMD;

	while (true)
	{
		std::cout << "Enter Command (ADD, SEARCH, EXIT): ";
		std::cin >> CMD;
		std::cout << std::endl;

		if (CMD == "ADD")
			phoneBook.ADD();
		else if (CMD == "SEARCH")
			phoneBook.SEARCH();
		else if (CMD == "EXIT")
			break ;
		else
			std::cout << "Invalid command!" << std::endl;
	}
	return (0);
}
