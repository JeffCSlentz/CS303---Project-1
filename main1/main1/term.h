
using namespace std;

// Class to store a Word object
class Term
{
private:
	int exponent;
	int coefficient;

public:
	int getExp();
	int getCoef();

	void setExp(int exp);
	void setCoef(int coef);

	bool operator>( const Term& rhs) const
	{
		if (exponent > rhs.exponent){
			return true;
		}
		else{
			return false;
		}
	}

	bool operator==(const Term& rhs) const
	{
		if (exponent == rhs.exponent){
			return true;
		}
		else{
			return false;
		}
	}
};
