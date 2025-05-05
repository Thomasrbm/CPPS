/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:44:41 by throbert          #+#    #+#             */
/*   Updated: 2025/05/04 23:49:30 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void ClapTrap::setAttack(int new_attack)
{
    std::cout << "attack of " << this->name <<" has been set to " << new_attack << std::endl;
    this->attack_damage = new_attack;
}

const int& ClapTrap::getAttack() const
{
    return this->attack_damage;
}

const std::string& ClapTrap::getName() const
{
    return this->name;    
}

const int& ClapTrap::getEnergy_point() const
{
    return this->energy_point;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->energy_point > 0 && this->hit_points > 0 && this->attack_damage > 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing 1 points of damage !" << std::endl;
        this->energy_point -= 1;
    }
    else if (this->energy_point <= 0)
        std::cout << "/!\\ ClapTrap " << this->name << " cannot attack " << target << " because he lacks energy points : Feniantone... /!\\" << std::endl;
    else if (this->hit_points <= 0)
        std::cout << "/!\\ ClapTrap " << this->name << " cannot attack " << target << " because he's dead (0 hit points) : REPAIR IT ! /!\\" << std::endl;
    else if (this->attack_damage <= 0)
        std::cout << "/!\\ ClapTrap " << this->name << " cannot attack " << target << " because he deals no damage (0 attack) :  a weak bastard ;'( /!\\" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << this->name << " took "  << amount << " points of damage !" << std::endl;
    this->hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energy_point > 1 && this->hit_points < 10)
    {
        std::cout << "ClapTrap " << this->name << " has been repaired, and regained : "  << amount << " hit points !" << std::endl;    
        this->hit_points += amount;
        this->energy_point -= 1;
    }
    else if (this->energy_point == 0)
        std::cout << "/!\\ ClapTrap " << this->name << " cannot be repaired because he lacks energy points : Feniantone... /!\\" << std::endl;
    else if (this->hit_points == 10)
        std::cout << "/!\\ ClapTrap " << this->name << " cannot be repaired because he already is fully alive (10 hit points) /!\\" << std::endl;

    
}

ClapTrap::ClapTrap(std::string name) :
    name(name),
    hit_points(10),
    energy_point(10),
    attack_damage(0)
{
    std::cout << "Constructor has been called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_point = other.energy_point;
        this->attack_damage = other.attack_damage;
    }
    return *this;
}
    
ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
    std::cout << "Copy constructor has been called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor has been called" << std::endl;
}