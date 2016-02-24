using namespace std;

// Class to store a Word object
class Term
{
private:
	int exponent;
	int coefficient;

public:

	Term(int coef, int exp);

	int getExp();
	int getCoef();

	void setExp(int exp);
	void setCoef(int coef);

	void Term::print(bool first);

	bool operator<(const Term& rhs) const
	{
		if (exponent < rhs.exponent){
			return false;
		}
		else{
			return true;
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