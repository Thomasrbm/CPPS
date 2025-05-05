/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:12:21 by throbert          #+#    #+#             */
/*   Updated: 2025/05/02 17:32:13 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts         = 0;
int Account::_totalAmount        = 0;
int Account::_totalNbDeposits    = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp()
{
	std::time_t now_in_sec = std::time(NULL); // time en sec depuis epoch (nombre sec depuis 1er janvier 1970)
	std::tm*   prompted_time  = std::localtime(&now_in_sec); // remet le sec and YY MM DD + H Min SEC dans un objet tm (classe)
	char       buf[16];

	std::strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", prompted_time); // met l objet en string (tm to str)
	std::cout << '[' << buf << "] ";
}

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}



int	Account::getTotalAmount(void)
{
	return _totalAmount;
}



int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}



int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}



void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts  << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}


void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";deposit:"<< deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}



bool	Account::makeWithdrawal(int withdrawl)
{
	bool possible;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	if (_amount >= withdrawl)
	{
		possible = true;
		this->_amount -= withdrawl;
		this->_nbWithdrawals++;
		_totalAmount -= withdrawl;
		_totalNbWithdrawals++;
		std::cout << ";withdrawal:" << withdrawl << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	}
	else 
	{
		possible = false;
		std::cout << ";withdrawal:refused" << std::endl;
	}
	return possible;
}

int		Account::checkAmount(void) const
{
	return this->_amount;
}

Account::Account(void)
{
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this-> _amount = 0;
	_totalAmount += _amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_totalNbDeposits += _nbDeposits;
	_totalNbWithdrawals += _nbWithdrawals;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += _amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_totalNbDeposits += _nbDeposits;
	_totalNbWithdrawals += _nbWithdrawals;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}
