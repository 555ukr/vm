#ifndef TYPE_H
# define TYPE_H

#include "IOperand.hpp"
#include <map>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <math.h>

template <typename T>
class Type: public IOperand{

public:
	Type(eOperandType type, T val):  _type(type), _value(val){
		std::ostringstream out;

		if (type == 1 || type == 2 || type == 3)
			 this->_strValue = (std::to_string(val));
		else{
    	out << std::fixed << std::setprecision(2) << val;
			this->_strValue = out.str();
			if (!val)
				this->_strValue = "0";
		}
	};

	virtual int getPrecision( void ) const{
		return (_type);
	};

	virtual eOperandType getType( void ) const{ return (_type); };

	virtual IOperand const * operator+( IOperand const & rhs ) const{
		eOperandType	precision;
		std::string 	str;

		if (rhs.getType() > this->_type)
			precision = rhs.getType();
		else
			precision = this->_type;
		//std::cout << precision << std::endl;
		str = makeNum(this->getValue(), rhs.getValue(), precision, 1);
		return (makeType(precision, str));
	};

	virtual IOperand const * operator-( IOperand const & rhs ) const{
		eOperandType	precision;
		std::string 	str;

		if (rhs.getType() > this->_type)
			precision = rhs.getType();
		else
			precision = this->_type;
		str = makeNum(this->getValue(), rhs.getValue(), precision, 2);
		return (makeType(precision, str));
	};

	virtual IOperand const * operator*( IOperand const & rhs ) const{
		eOperandType	precision;
		std::string 	str;

		if (rhs.getType() > this->_type)
			precision = rhs.getType();
		else
			precision = this->_type;
		str = makeNum(this->getValue(), rhs.getValue(), precision, 3);
		return (makeType(precision, str));
	};

	virtual IOperand const * operator/( IOperand const & rhs ) const{
		eOperandType	precision;
		std::string 	str;

		if (rhs.getType() > this->_type)
			precision = rhs.getType();
		else
			precision = this->_type;
		str = makeNum(this->getValue(), rhs.getValue(), precision, 4);
		return (makeType(precision, str));
	};

	virtual IOperand const * operator%( IOperand const & rhs ) const{
		eOperandType	precision;
		std::string 	str;

		if (rhs.getType() > this->_type)
			precision = rhs.getType();
		else
			precision = this->_type;
		str = makeNum(this->getValue(), rhs.getValue(), precision, 5);
		return (makeType(precision, str));

	}

	virtual Type const * makeType(eOperandType tmp, std::string str) const{
		//std::cout << "makeType " << std::stof(str) << std::endl;
		if (tmp == 1)
			return (new Type(tmp, static_cast<int8_t>(std::stoi(str))));
		else if (tmp == 2)
			return (new Type(tmp, static_cast<int16_t>(std::stoi(str))));
		else if (tmp == 3)
			return (new Type(tmp, static_cast<int32_t>(std::stoi(str))));
		else if (tmp == 4)
			return (new Type(tmp, static_cast<float>(std::stof(str))));
		else
			return (new Type(tmp, static_cast<double>(std::stod(str))));
	}
	/*
	1 +
	2 -
	3 *
	4 /
	5 %
	 */
	virtual std::string makeNum(std::string str, std::string str1, int val, int sign) const{
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
			// std::cout << "lol" << std::endl;
			d1 = std::stod(str);
			d2 = std::stod(str1);
			// std::cout << d1 << std::endl;
			// std::cout << d2 << std::endl;
			if (sign == 1){
				//std::cout << std::to_string((d1) + (d2)) << std::endl;
				return std::to_string((d1) + (d2));
			}
			else if (sign == 2)
				return std::to_string((d1) - (d2));
			else if (sign == 3)
				return std::to_string((d1) * (d2));
			else if (sign == 4){
				return std::to_string((d1) / (d2));
			}
			else
				return std::to_string(fmod(d1, d2));
		}
		return "lol";
	}

	IOperand const & operator=(IOperand const & rhs) const{
		this->_type = rhs.getType();
		this->_strValue = rhs.getValue();
		this->setValue(this->_type, this->_strValue);
		return *this;
	}

	virtual void setValue(eOperandType type, std::string str){
		if (type == 1)
			this->_value = static_cast <int8_t> (std::stoi(str));
		else if (type == 2)
			this->_value = static_cast <int16_t> (std::stoi(str));
		else if (type == 3)
			this->_value = static_cast <int32_t> (std::stoi(str));
		else if (type == 4)
			this->_value = static_cast <float> (std::stof(str));
		else
			this->_value = static_cast <double> (std::stod(str));
	}

	bool operator==( IOperand const & rhs ) const{
		if (this->_type == rhs.getType() && this->getValue() == rhs.getValue())
			return true;
		return false;
	}

	virtual const std::string			getValue(void) const{
	  return _strValue;
	};

	virtual std::string const & toString( void ) const{
		return this->_strValue;
	}

 	T rtValue(){
		return _value;
	}

private:
	eOperandType 			_type;
	T									_value;
	std::string _strValue;
};

#endif
