#ifndef TYPE_H
# define TYPE_H

#include "IOperand.hpp"
#include <map>
#include <iostream>

template <typename T>
class Type: public IOperand{

public:
	Type(eOperandType type, T val):  _type(type), _value(val), _strValue(std::to_string(val)){
	};

	virtual int getPrecision( void ) const{
		return (_type);
	};

	virtual eOperandType getType( void ) const{ return (_type); };

	// virtual IOperand const * operator+( IOperand const & rhs ) const{
	// 	eOperandType	precision;
	// 	int	val;
	//
	// 	if (rhs.getType() > this->_type)
	// 		precision = rhs.getType();
	// 	else
	// 		precision = this->_type;
	// 	Type *tmp = new Type(precision, this->makeNum(this->getValue(), rhs.getValue(), precision, 1));
	//   return (tmp);
	// };

	// virtual IOperand const * operator-( IOperand const & rhs ) const{
	// 	eOperandType	precision;
	//
	// 	if (rhs.getType() > this->_type)
	// 		precision = rhs.getType();
	// 	else
	// 		precision = this->_type;
	// 	Type *tmp = new Type(precision, this->makeNum(this->getValue(), rhs.getValue(), precision, 2));
	//   return (tmp);
	// };
	//
	// virtual IOperand const * operator*( IOperand const & rhs ) const{
	// 	eOperandType	precision;
	//
	// 	if (rhs.getType() > this->_type)
	// 		precision = rhs.getType();
	// 	else
	// 		precision = this->_type;
	// 	Type *tmp = new Type(precision, this->makeNum(this->getValue(), rhs.getValue(), precision, 3));
	// 	return (tmp);
	// };
	//
	// virtual IOperand const * operator/( IOperand const & rhs ) const{
	// 	eOperandType	precision;
	//
	// 	if (rhs.getType() > this->_type)
	// 		precision = rhs.getType();
	// 	else
	// 		precision = this->_type;
	// 	Type *tmp = new Type(precision, this->makeNum(this->getValue(), rhs.getValue(), precision, 4));
	// 	return (tmp);
	// };

	virtual IOperand const * operator%( IOperand const & rhs ) const{
		eOperandType	precision;
		std::string 	str;

		if (rhs.getType() > this->_type)
			precision = rhs.getType();
		else
			precision = this->_type;
		str = this->makeNum(this->getValue(), rhs.getValue(), 1, 5);
		//if (precision == 1)
			Type *tmp = new Type(precision, static_cast<int8_t>(std::stoi(str)));
		return (tmp);
	}
	/*
	1 +
	2 -
	3 *
	4 /
	5 %
	 */
	virtual std::string makeNum(std::string str, std::string str1, int val, int sign){
		long long 	i1, i2;
		double 			d1, d2;

		if (val == 1 || val == 2 || val == 3){
			i1 = std::stoi(str);
			i2 = std::stoi(str1);
			if (sign == 1)
		  	return std::to_string((i1) + (i2));
			else if (sign == 2)
				return std::to_string((i1) - (i2));
			else if (sign == 3)
				return std::to_string((i1) * (i2));
			else if (sign == 4)
				return std::to_string((i1) / (i2));
			else
				return std::to_string((i1) % (i2));
		} else{
			d1 = std::stod(str);
			d2 = std::stod(str1);
			if (sign == 1)
		  	return std::to_string((d1) + (d2));
			else if (sign == 2)
				return std::to_string((d1) - (d2));
			else if (sign == 3)
				return std::to_string((d1) * (d2));
			else if (sign == 4)
				return std::to_string((d1) / (d2));
			else
				return std::to_string((d1) / (d2));
		}
		return "lol";
	}

	IOperand const & operator=(IOperand const & rhs) const{
		this->_value = rhs.getValue();
		return *this;
	}

	bool operator==( IOperand const & rhs ) const{
		if (this->_type == rhs.getType() && this->getValue() == rhs.getValue())
			return true;
		return false;
	}

	virtual const std::string			getValue(void) const{
		// eOperandType f = float_e;
		// eOperandType d = double_e;
		//
		// if (this->_type == f)
		// 	return static_cast <float> (_value);
		// if (this->_type == d)
		// 	return static_cast <float> (_value);
	  // return static_cast <int> (_value);
	  return _strValue;
	};

	virtual std::string const & toString( void ) const{
		return this->_strValue;
	}

	// T rtValue(){
	// 	return _value;
	// }

private:
	eOperandType 			_type;
	T									_value;
	const std::string _strValue;
};

#endif
