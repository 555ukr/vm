#ifndef IOPERAND
# define IOPERAND

#include "eOperandType.hpp"
#include <cstdint>
#include <string>

class IOperand {
	public:
		virtual int getPrecision( void ) const = 0; // Precision of the type of the instance
		virtual eOperandType getType( void ) const = 0; // Type of the instance
		// virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
		// virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
		// virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
		// virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
		//virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo
		virtual bool operator==( IOperand const & rhs ) const = 0;
		virtual std::string const & toString( void ) const = 0; // String representation of the instance
		virtual ~IOperand( void ) {};
		virtual	std::string const getValue(void) const = 0;
		virtual std::string makeNum(std::string str, std::string str1, int val, int sign) = 0;
};

#endif
