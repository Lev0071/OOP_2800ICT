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
		StaffMember(const fullName& name = {},const Address& address={},const Phone& phoneNo={});
};

#endif //STAFFMEMBER_H