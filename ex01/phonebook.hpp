/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:19:23 by akuzmin           #+#    #+#             */
/*   Updated: 2025/09/07 13:43:34 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <cctype>
#include <iostream>
#include <iomanip>

class Contact
{
private:
	std::string	f_name;
	std::string	l_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	secret;
public:
	std::string getFirstName() const { return f_name; }
	std::string getLastName() const { return l_name; }
	std::string getNickname() const { return nickname; }
	std::string getPhoneNumber() const { return phone_number; }
	std::string getSecret() const { return secret; }

	void fillContact();
};

class PhoneBook
{
private:
	Contact contacts[8];
	int		contactCounter;
	int		lastContact;

public:
	PhoneBook() : contactCounter(0), lastContact(0) {}
	void ADD();
	void SEARCH();

private:
	void displayColumn(const std::string &str) const;
};

#endif
