// StaffMember.hpp
#ifndef STAFFMEMBER_H
#define STAFFMEMBER_H

#include <string>
#include "Name.hpp" 
#include "Address.hpp" 

class StaffMember{
	private:
		Name fullName;
		Address address;
		Phone phoneNo;
	public:
		StaffMember(const Name& fullName = {},const Address& address={},const Phone& phoneNo={});
};

#endif //STAFFMEMBER_H


// StaffMember a;  // Uses all defaults
// StaffMember b(Name{"Alice", "Wong"});
// StaffMember c(Name{"Bob", "Smith"}, Address{123, "Queen", StreetType::Street, "Brisbane", "QLD", 4000});
// StaffMember d(Name{"Eve", "Nguyen"}, Address{456, "King", StreetType::Road, "Sydney", "NSW", 2000}, Phone{"0400123456", "0287654321"});


// https://chatgpt.com/g/g-p-67d9546753f08191adf65a2dc2e3f62a-oop-2800ict/c/68077b3c-d468-800c-a85e-6674a50bce9c