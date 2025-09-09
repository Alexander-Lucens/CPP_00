/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:19:23 by akuzmin           #+#    #+#             */
/*   Updated: 2025/09/07 13:43:35 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	std::time_t t = std::time(nullptr);
	std::tm *now = std::localtime(&t);
	std::cout << "[" << (now->tm_year + 1900)
			  << std::setfill('0') << std::setw(2) << (now->tm_mon + 1)
			  << std::setfill('0') << std::setw(2) << (now->tm_mday)
			  << "_"
			  << std::setfill('0') << std::setw(2) << (now->tm_hour)
			  << std::setfill('0') << std::setw(2) << (now->tm_min)
			  << std::setfill('0') << std::setw(2) << (now->tm_sec)
			  << "] ";
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" 
			  << "amount:" << _amount << ";" 
			  << "created" << std::endl;
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" 
			  << "amount:" << _amount << ";" 
			  << "created" << std::endl;
}

int		Account::getNbAccounts(void) { return (_nbAccounts); }

int		Account::getTotalAmount( void ) { return (_totalAmount); }

int		Account::getNbDeposits( void ) { return (_totalNbDeposits); }

int		Account::getNbWithdrawals( void ) { return (_totalNbWithdrawals); }

void	Account::displayAccountsInfos( void ) 
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

// index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";"; 
	std::cout << "deposits:" << deposit << ";";

	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << "amount:" << _amount << ";"; 
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

// index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";"; 
	std::cout << "withdrawal:" << withdrawal << ";";
	if (_amount < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << "amount:" << _amount << ";"; 
	std::cout << "nb_withdrawal:" << _nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const { return (_amount); }

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" ;
	std::cout << "amount:" << _amount << ";"; 
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}
